#include <java/util/logging/Handler.h>

#include <java/io/UnsupportedEncodingException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/IllegalCharsetNameException.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Objects.h>
#include <java/util/logging/ErrorManager.h>
#include <java/util/logging/Filter.h>
#include <java/util/logging/Formatter.h>
#include <java/util/logging/Handler$1.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/LogRecord.h>
#include <jcpp.h>

#undef ALL
#undef OFF

using $PermissionArray = $Array<::java::security::Permission>;
using $PrintStream = ::java::io::PrintStream;
using $UnsupportedEncodingException = ::java::io::UnsupportedEncodingException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $Charset = ::java::nio::charset::Charset;
using $IllegalCharsetNameException = ::java::nio::charset::IllegalCharsetNameException;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Objects = ::java::util::Objects;
using $ErrorManager = ::java::util::logging::ErrorManager;
using $Filter = ::java::util::logging::Filter;
using $Formatter = ::java::util::logging::Formatter;
using $Handler$1 = ::java::util::logging::Handler$1;
using $Level = ::java::util::logging::Level;
using $LogManager = ::java::util::logging::LogManager;
using $LogRecord = ::java::util::logging::LogRecord;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _Handler_FieldInfo_[] = {
	{"offValue", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Handler, offValue)},
	{"manager", "Ljava/util/logging/LogManager;", nullptr, $PRIVATE | $FINAL, $field(Handler, manager)},
	{"filter", "Ljava/util/logging/Filter;", nullptr, $PRIVATE | $VOLATILE, $field(Handler, filter)},
	{"formatter", "Ljava/util/logging/Formatter;", nullptr, $PRIVATE | $VOLATILE, $field(Handler, formatter)},
	{"logLevel", "Ljava/util/logging/Level;", nullptr, $PRIVATE | $VOLATILE, $field(Handler, logLevel)},
	{"errorManager", "Ljava/util/logging/ErrorManager;", nullptr, $PRIVATE | $VOLATILE, $field(Handler, errorManager)},
	{"encoding", "Ljava/lang/String;", nullptr, $PRIVATE | $VOLATILE, $field(Handler, encoding)},
	{}
};

$MethodInfo _Handler_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(static_cast<void(Handler::*)()>(&Handler::init$))},
	{"<init>", "(Ljava/util/logging/Level;Ljava/util/logging/Formatter;Ljava/util/logging/Formatter;)V", nullptr, 0, $method(static_cast<void(Handler::*)($Level*,$Formatter*,$Formatter*)>(&Handler::init$))},
	{"checkPermission", "()V", nullptr, 0, nullptr, "java.lang.SecurityException"},
	{"close", "()V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.lang.SecurityException"},
	{"flush", "()V", nullptr, $PUBLIC | $ABSTRACT},
	{"getEncoding", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getErrorManager", "()Ljava/util/logging/ErrorManager;", nullptr, $PUBLIC},
	{"getFilter", "()Ljava/util/logging/Filter;", nullptr, $PUBLIC},
	{"getFormatter", "()Ljava/util/logging/Formatter;", nullptr, $PUBLIC},
	{"getLevel", "()Ljava/util/logging/Level;", nullptr, $PUBLIC},
	{"isLoggable", "(Ljava/util/logging/LogRecord;)Z", nullptr, $PUBLIC},
	{"publish", "(Ljava/util/logging/LogRecord;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"reportError", "(Ljava/lang/String;Ljava/lang/Exception;I)V", nullptr, $PROTECTED},
	{"setEncoding", "(Ljava/lang/String;)V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.lang.SecurityException,java.io.UnsupportedEncodingException"},
	{"setErrorManager", "(Ljava/util/logging/ErrorManager;)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"setFilter", "(Ljava/util/logging/Filter;)V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.lang.SecurityException"},
	{"setFormatter", "(Ljava/util/logging/Formatter;)V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.lang.SecurityException"},
	{"setLevel", "(Ljava/util/logging/Level;)V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.lang.SecurityException"},
	{}
};

$InnerClassInfo _Handler_InnerClassesInfo_[] = {
	{"java.util.logging.Handler$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Handler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.util.logging.Handler",
	"java.lang.Object",
	nullptr,
	_Handler_FieldInfo_,
	_Handler_MethodInfo_,
	nullptr,
	nullptr,
	_Handler_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.logging.Handler$1"
};

$Object* allocate$Handler($Class* clazz) {
	return $of($alloc(Handler));
}

int32_t Handler::offValue = 0;

void Handler::init$() {
	$set(this, manager, $LogManager::getLogManager());
	$init($Level);
	$set(this, logLevel, $Level::ALL);
	$set(this, errorManager, $new($ErrorManager));
}

void Handler::init$($Level* defaultLevel, $Formatter* defaultFormatter, $Formatter* specifiedFormatter) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$set(this, manager, $LogManager::getLogManager());
	$init($Level);
	$set(this, logLevel, $Level::ALL);
	$set(this, errorManager, $new($ErrorManager));
	$var($LogManager, manager, $LogManager::getLogManager());
	$var($String, cname, $of(this)->getClass()->getName());
	$var($Level, level, $nc(manager)->getLevelProperty($$str({cname, ".level"_s}), defaultLevel));
	$var($Filter, filter, manager->getFilterProperty($$str({cname, ".filter"_s}), nullptr));
	$var($Formatter, formatter, specifiedFormatter == nullptr ? manager->getFormatterProperty($$str({cname, ".formatter"_s}), defaultFormatter) : specifiedFormatter);
	$var($String, encoding, manager->getStringProperty($$str({cname, ".encoding"_s}), nullptr));
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Handler$1, this, level, filter, formatter, encoding)), ($AccessControlContext*)nullptr, $$new($PermissionArray, {$LogManager::controlPermission}));
}

void Handler::setFormatter($Formatter* newFormatter) {
	$synchronized(this) {
		checkPermission();
		$set(this, formatter, $cast($Formatter, $Objects::requireNonNull(newFormatter)));
	}
}

$Formatter* Handler::getFormatter() {
	return this->formatter;
}

void Handler::setEncoding($String* encoding) {
	$synchronized(this) {
		checkPermission();
		if (encoding != nullptr) {
			try {
				if (!$Charset::isSupported(encoding)) {
					$throwNew($UnsupportedEncodingException, encoding);
				}
			} catch ($IllegalCharsetNameException& e) {
				$throwNew($UnsupportedEncodingException, encoding);
			}
		}
		$set(this, encoding, encoding);
	}
}

$String* Handler::getEncoding() {
	return this->encoding;
}

void Handler::setFilter($Filter* newFilter) {
	$synchronized(this) {
		checkPermission();
		$set(this, filter, newFilter);
	}
}

$Filter* Handler::getFilter() {
	return this->filter;
}

void Handler::setErrorManager($ErrorManager* em) {
	$synchronized(this) {
		checkPermission();
		if (em == nullptr) {
			$throwNew($NullPointerException);
		}
		$set(this, errorManager, em);
	}
}

$ErrorManager* Handler::getErrorManager() {
	checkPermission();
	return this->errorManager;
}

void Handler::reportError($String* msg, $Exception* ex, int32_t code) {
	try {
		$nc(this->errorManager)->error(msg, ex, code);
	} catch ($Exception& ex2) {
		$nc($System::err)->println("Handler.reportError caught:"_s);
		ex2->printStackTrace();
	}
}

void Handler::setLevel($Level* newLevel) {
	$synchronized(this) {
		if (newLevel == nullptr) {
			$throwNew($NullPointerException);
		}
		checkPermission();
		$set(this, logLevel, newLevel);
	}
}

$Level* Handler::getLevel() {
	return this->logLevel;
}

bool Handler::isLoggable($LogRecord* record) {
	$useLocalCurrentObjectStackCache();
	int32_t levelValue = $nc($(getLevel()))->intValue();
	if (record == nullptr) {
		return false;
	}
	if ($nc($($nc(record)->getLevel()))->intValue() < levelValue || levelValue == Handler::offValue) {
		return false;
	}
	$var($Filter, filter, getFilter());
	if (filter == nullptr) {
		return true;
	}
	return $nc(filter)->isLoggable(record);
}

void Handler::checkPermission() {
	$nc(this->manager)->checkPermission();
}

void clinit$Handler($Class* class$) {
	$init($Level);
	Handler::offValue = $nc($Level::OFF)->intValue();
}

Handler::Handler() {
}

$Class* Handler::load$($String* name, bool initialize) {
	$loadClass(Handler, name, initialize, &_Handler_ClassInfo_, clinit$Handler, allocate$Handler);
	return class$;
}

$Class* Handler::class$ = nullptr;

		} // logging
	} // util
} // java