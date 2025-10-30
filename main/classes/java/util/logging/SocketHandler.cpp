#include <java/util/logging/SocketHandler.h>

#include <java/io/BufferedOutputStream.h>
#include <java/io/FilterOutputStream.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/net/Socket.h>
#include <java/util/logging/Formatter.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/LogRecord.h>
#include <java/util/logging/StreamHandler.h>
#include <java/util/logging/XMLFormatter.h>
#include <jcpp.h>

#undef ALL

using $BufferedOutputStream = ::java::io::BufferedOutputStream;
using $FilterOutputStream = ::java::io::FilterOutputStream;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Socket = ::java::net::Socket;
using $Formatter = ::java::util::logging::Formatter;
using $Level = ::java::util::logging::Level;
using $LogManager = ::java::util::logging::LogManager;
using $LogRecord = ::java::util::logging::LogRecord;
using $StreamHandler = ::java::util::logging::StreamHandler;
using $XMLFormatter = ::java::util::logging::XMLFormatter;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _SocketHandler_FieldInfo_[] = {
	{"sock", "Ljava/net/Socket;", nullptr, $PRIVATE, $field(SocketHandler, sock)},
	{"host", "Ljava/lang/String;", nullptr, $PRIVATE, $field(SocketHandler, host)},
	{"port", "I", nullptr, $PRIVATE, $field(SocketHandler, port)},
	{}
};

$MethodInfo _SocketHandler_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SocketHandler::*)()>(&SocketHandler::init$)), "java.io.IOException"},
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $method(static_cast<void(SocketHandler::*)($String*,int32_t)>(&SocketHandler::init$)), "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.lang.SecurityException"},
	{"connect", "()V", nullptr, $PRIVATE, $method(static_cast<void(SocketHandler::*)()>(&SocketHandler::connect)), "java.io.IOException"},
	{"publish", "(Ljava/util/logging/LogRecord;)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{}
};

$ClassInfo _SocketHandler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.logging.SocketHandler",
	"java.util.logging.StreamHandler",
	nullptr,
	_SocketHandler_FieldInfo_,
	_SocketHandler_MethodInfo_
};

$Object* allocate$SocketHandler($Class* clazz) {
	return $of($alloc(SocketHandler));
}

void SocketHandler::init$() {
	$useLocalCurrentObjectStackCache();
	$init($Level);
	$StreamHandler::init$($Level::ALL, $$new($XMLFormatter), nullptr);
	$var($LogManager, manager, $LogManager::getLogManager());
	$var($String, cname, $of(this)->getClass()->getName());
	this->port = $nc(manager)->getIntProperty($$str({cname, ".port"_s}), 0);
	$set(this, host, manager->getStringProperty($$str({cname, ".host"_s}), nullptr));
	try {
		connect();
	} catch ($IOException& ix) {
		$nc($System::err)->println($$str({"SocketHandler: connect failed to "_s, this->host, ":"_s, $$str(this->port)}));
		$throw(ix);
	}
}

void SocketHandler::init$($String* host, int32_t port) {
	$init($Level);
	$StreamHandler::init$($Level::ALL, $$new($XMLFormatter), nullptr);
	this->port = port;
	$set(this, host, host);
	connect();
}

void SocketHandler::connect() {
	$useLocalCurrentObjectStackCache();
	if (this->port == 0) {
		$throwNew($IllegalArgumentException, $$str({"Bad port: "_s, $$str(this->port)}));
	}
	if (this->host == nullptr) {
		$throwNew($IllegalArgumentException, $$str({"Null host name: "_s, this->host}));
	}
	$set(this, sock, $new($Socket, this->host, this->port));
	$var($OutputStream, out, $nc(this->sock)->getOutputStream());
	$var($BufferedOutputStream, bout, $new($BufferedOutputStream, out));
	setOutputStreamPrivileged(bout);
}

void SocketHandler::close() {
	$synchronized(this) {
		$StreamHandler::close();
		if (this->sock != nullptr) {
			try {
				$nc(this->sock)->close();
			} catch ($IOException& ix) {
			}
		}
		$set(this, sock, nullptr);
	}
}

void SocketHandler::publish($LogRecord* record) {
	$synchronized(this) {
		if (!isLoggable(record)) {
			return;
		}
		$StreamHandler::publish(record);
		flush();
	}
}

SocketHandler::SocketHandler() {
}

$Class* SocketHandler::load$($String* name, bool initialize) {
	$loadClass(SocketHandler, name, initialize, &_SocketHandler_ClassInfo_, allocate$SocketHandler);
	return class$;
}

$Class* SocketHandler::class$ = nullptr;

		} // logging
	} // util
} // java