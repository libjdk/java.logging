#include <java/util/logging/Logger$SystemLoggerHelper.h>

#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/logging/Logger$SystemLoggerHelper$1.h>
#include <java/util/logging/Logger.h>
#include <jcpp.h>

using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Logger = ::java::util::logging::Logger;
using $Logger$SystemLoggerHelper$1 = ::java::util::logging::Logger$SystemLoggerHelper$1;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _Logger$SystemLoggerHelper_FieldInfo_[] = {
	{"disableCallerCheck", "Z", nullptr, $STATIC, $staticField(Logger$SystemLoggerHelper, disableCallerCheck)},
	{}
};

$MethodInfo _Logger$SystemLoggerHelper_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Logger$SystemLoggerHelper::*)()>(&Logger$SystemLoggerHelper::init$))},
	{"getBooleanProperty", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)($String*)>(&Logger$SystemLoggerHelper::getBooleanProperty))},
	{}
};

$InnerClassInfo _Logger$SystemLoggerHelper_InnerClassesInfo_[] = {
	{"java.util.logging.Logger$SystemLoggerHelper", "java.util.logging.Logger", "SystemLoggerHelper", $PRIVATE | $STATIC},
	{"java.util.logging.Logger$SystemLoggerHelper$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Logger$SystemLoggerHelper_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.logging.Logger$SystemLoggerHelper",
	"java.lang.Object",
	nullptr,
	_Logger$SystemLoggerHelper_FieldInfo_,
	_Logger$SystemLoggerHelper_MethodInfo_,
	nullptr,
	nullptr,
	_Logger$SystemLoggerHelper_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.Logger"
};

$Object* allocate$Logger$SystemLoggerHelper($Class* clazz) {
	return $of($alloc(Logger$SystemLoggerHelper));
}

bool Logger$SystemLoggerHelper::disableCallerCheck = false;

void Logger$SystemLoggerHelper::init$() {
}

bool Logger$SystemLoggerHelper::getBooleanProperty($String* key) {
	$init(Logger$SystemLoggerHelper);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, s, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($Logger$SystemLoggerHelper$1, key)))));
	return $Boolean::parseBoolean(s);
}

void clinit$Logger$SystemLoggerHelper($Class* class$) {
	Logger$SystemLoggerHelper::disableCallerCheck = Logger$SystemLoggerHelper::getBooleanProperty("sun.util.logging.disableCallerCheck"_s);
}

Logger$SystemLoggerHelper::Logger$SystemLoggerHelper() {
}

$Class* Logger$SystemLoggerHelper::load$($String* name, bool initialize) {
	$loadClass(Logger$SystemLoggerHelper, name, initialize, &_Logger$SystemLoggerHelper_ClassInfo_, clinit$Logger$SystemLoggerHelper, allocate$Logger$SystemLoggerHelper);
	return class$;
}

$Class* Logger$SystemLoggerHelper::class$ = nullptr;

		} // logging
	} // util
} // java