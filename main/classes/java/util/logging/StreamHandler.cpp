#include <java/util/logging/StreamHandler.h>

#include <java/io/OutputStream.h>
#include <java/io/OutputStreamWriter.h>
#include <java/io/UnsupportedEncodingException.h>
#include <java/io/Writer.h>
#include <java/lang/Error.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Objects.h>
#include <java/util/logging/ErrorManager.h>
#include <java/util/logging/Formatter.h>
#include <java/util/logging/Handler.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/LogRecord.h>
#include <java/util/logging/SimpleFormatter.h>
#include <java/util/logging/StreamHandler$1.h>
#include <jcpp.h>

#undef CLOSE_FAILURE
#undef FLUSH_FAILURE
#undef FORMAT_FAILURE
#undef INFO
#undef WRITE_FAILURE

using $PermissionArray = $Array<::java::security::Permission>;
using $OutputStream = ::java::io::OutputStream;
using $OutputStreamWriter = ::java::io::OutputStreamWriter;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Objects = ::java::util::Objects;
using $ErrorManager = ::java::util::logging::ErrorManager;
using $Formatter = ::java::util::logging::Formatter;
using $Handler = ::java::util::logging::Handler;
using $Level = ::java::util::logging::Level;
using $LogManager = ::java::util::logging::LogManager;
using $LogRecord = ::java::util::logging::LogRecord;
using $SimpleFormatter = ::java::util::logging::SimpleFormatter;
using $StreamHandler$1 = ::java::util::logging::StreamHandler$1;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _StreamHandler_FieldInfo_[] = {
	{"output", "Ljava/io/OutputStream;", nullptr, $PRIVATE, $field(StreamHandler, output)},
	{"doneHeader", "Z", nullptr, $PRIVATE, $field(StreamHandler, doneHeader)},
	{"writer", "Ljava/io/Writer;", nullptr, $PRIVATE | $VOLATILE, $field(StreamHandler, writer)},
	{}
};

$MethodInfo _StreamHandler_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(StreamHandler::*)()>(&StreamHandler::init$))},
	{"<init>", "(Ljava/io/OutputStream;Ljava/util/logging/Formatter;)V", nullptr, $PUBLIC, $method(static_cast<void(StreamHandler::*)($OutputStream*,$Formatter*)>(&StreamHandler::init$))},
	{"<init>", "(Ljava/util/logging/Level;Ljava/util/logging/Formatter;Ljava/util/logging/Formatter;)V", nullptr, 0, $method(static_cast<void(StreamHandler::*)($Level*,$Formatter*,$Formatter*)>(&StreamHandler::init$))},
	{"close", "()V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.lang.SecurityException"},
	{"flush", "()V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"flushAndClose", "()V", nullptr, $PRIVATE | $SYNCHRONIZED, $method(static_cast<void(StreamHandler::*)()>(&StreamHandler::flushAndClose)), "java.lang.SecurityException"},
	{"isLoggable", "(Ljava/util/logging/LogRecord;)Z", nullptr, $PUBLIC},
	{"publish", "(Ljava/util/logging/LogRecord;)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"setEncoding", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.lang.SecurityException,java.io.UnsupportedEncodingException"},
	{"setOutputStream", "(Ljava/io/OutputStream;)V", nullptr, $PROTECTED | $SYNCHRONIZED, nullptr, "java.lang.SecurityException"},
	{"setOutputStreamPrivileged", "(Ljava/io/OutputStream;)V", nullptr, $FINAL, $method(static_cast<void(StreamHandler::*)($OutputStream*)>(&StreamHandler::setOutputStreamPrivileged))},
	{}
};

$InnerClassInfo _StreamHandler_InnerClassesInfo_[] = {
	{"java.util.logging.StreamHandler$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _StreamHandler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.logging.StreamHandler",
	"java.util.logging.Handler",
	nullptr,
	_StreamHandler_FieldInfo_,
	_StreamHandler_MethodInfo_,
	nullptr,
	nullptr,
	_StreamHandler_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.logging.StreamHandler$1"
};

$Object* allocate$StreamHandler($Class* clazz) {
	return $of($alloc(StreamHandler));
}

void StreamHandler::init$() {
	$init($Level);
	$Handler::init$($Level::INFO, $$new($SimpleFormatter), nullptr);
}

void StreamHandler::init$($OutputStream* out, $Formatter* formatter) {
	$init($Level);
	$Handler::init$($Level::INFO, nullptr, $cast($Formatter, $Objects::requireNonNull(formatter)));
	setOutputStreamPrivileged(out);
}

void StreamHandler::init$($Level* defaultLevel, $Formatter* defaultFormatter, $Formatter* specifiedFormatter) {
	$Handler::init$(defaultLevel, defaultFormatter, specifiedFormatter);
}

void StreamHandler::setOutputStream($OutputStream* out) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (out == nullptr) {
			$throwNew($NullPointerException);
		}
		flushAndClose();
		$set(this, output, out);
		this->doneHeader = false;
		$var($String, encoding, getEncoding());
		if (encoding == nullptr) {
			$set(this, writer, $new($OutputStreamWriter, this->output));
		} else {
			try {
				$set(this, writer, $new($OutputStreamWriter, this->output, encoding));
			} catch ($UnsupportedEncodingException& ex) {
				$throwNew($Error, $$str({"Unexpected exception "_s, ex}));
			}
		}
	}
}

void StreamHandler::setEncoding($String* encoding) {
	$synchronized(this) {
		$Handler::setEncoding(encoding);
		if (this->output == nullptr) {
			return;
		}
		flush();
		if (encoding == nullptr) {
			$set(this, writer, $new($OutputStreamWriter, this->output));
		} else {
			$set(this, writer, $new($OutputStreamWriter, this->output, encoding));
		}
	}
}

void StreamHandler::publish($LogRecord* record) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (!isLoggable(record)) {
			return;
		}
		$var($String, msg, nullptr);
		try {
			$assign(msg, $nc($(getFormatter()))->format(record));
		} catch ($Exception& ex) {
			reportError(nullptr, ex, $ErrorManager::FORMAT_FAILURE);
			return;
		}
		try {
			if (!this->doneHeader) {
				$nc(this->writer)->write($($nc($(getFormatter()))->getHead(this)));
				this->doneHeader = true;
			}
			$nc(this->writer)->write(msg);
		} catch ($Exception& ex) {
			reportError(nullptr, ex, $ErrorManager::WRITE_FAILURE);
		}
	}
}

bool StreamHandler::isLoggable($LogRecord* record) {
	if (this->writer == nullptr || record == nullptr) {
		return false;
	}
	return $Handler::isLoggable(record);
}

void StreamHandler::flush() {
	$synchronized(this) {
		if (this->writer != nullptr) {
			try {
				$nc(this->writer)->flush();
			} catch ($Exception& ex) {
				reportError(nullptr, ex, $ErrorManager::FLUSH_FAILURE);
			}
		}
	}
}

void StreamHandler::flushAndClose() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		checkPermission();
		if (this->writer != nullptr) {
			try {
				if (!this->doneHeader) {
					$nc(this->writer)->write($($nc($(getFormatter()))->getHead(this)));
					this->doneHeader = true;
				}
				$nc(this->writer)->write($($nc($(getFormatter()))->getTail(this)));
				$nc(this->writer)->flush();
				$nc(this->writer)->close();
			} catch ($Exception& ex) {
				reportError(nullptr, ex, $ErrorManager::CLOSE_FAILURE);
			}
			$set(this, writer, nullptr);
			$set(this, output, nullptr);
		}
	}
}

void StreamHandler::close() {
	$synchronized(this) {
		flushAndClose();
	}
}

void StreamHandler::setOutputStreamPrivileged($OutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$init($LogManager);
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($StreamHandler$1, this, out)), ($AccessControlContext*)nullptr, $$new($PermissionArray, {$LogManager::controlPermission}));
}

StreamHandler::StreamHandler() {
}

$Class* StreamHandler::load$($String* name, bool initialize) {
	$loadClass(StreamHandler, name, initialize, &_StreamHandler_ClassInfo_, allocate$StreamHandler);
	return class$;
}

$Class* StreamHandler::class$ = nullptr;

		} // logging
	} // util
} // java