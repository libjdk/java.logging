#include <java/util/logging/Logger$SystemLoggerHelper$1.h>

#include <java/util/logging/Logger$SystemLoggerHelper.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Logger$SystemLoggerHelper = ::java::util::logging::Logger$SystemLoggerHelper;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _Logger$SystemLoggerHelper$1_FieldInfo_[] = {
	{"val$key", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(Logger$SystemLoggerHelper$1, val$key)},
	{}
};

$MethodInfo _Logger$SystemLoggerHelper$1_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", "()V", 0, $method(static_cast<void(Logger$SystemLoggerHelper$1::*)($String*)>(&Logger$SystemLoggerHelper$1::init$))},
	{"run", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _Logger$SystemLoggerHelper$1_EnclosingMethodInfo_ = {
	"java.util.logging.Logger$SystemLoggerHelper",
	"getBooleanProperty",
	"(Ljava/lang/String;)Z"
};

$InnerClassInfo _Logger$SystemLoggerHelper$1_InnerClassesInfo_[] = {
	{"java.util.logging.Logger$SystemLoggerHelper", "java.util.logging.Logger", "SystemLoggerHelper", $PRIVATE | $STATIC},
	{"java.util.logging.Logger$SystemLoggerHelper$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _Logger$SystemLoggerHelper$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.logging.Logger$SystemLoggerHelper$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_Logger$SystemLoggerHelper$1_FieldInfo_,
	_Logger$SystemLoggerHelper$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/String;>;",
	&_Logger$SystemLoggerHelper$1_EnclosingMethodInfo_,
	_Logger$SystemLoggerHelper$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.Logger"
};

$Object* allocate$Logger$SystemLoggerHelper$1($Class* clazz) {
	return $of($alloc(Logger$SystemLoggerHelper$1));
}

void Logger$SystemLoggerHelper$1::init$($String* val$key) {
	$set(this, val$key, val$key);
}

$Object* Logger$SystemLoggerHelper$1::run() {
	return $of($System::getProperty(this->val$key));
}

Logger$SystemLoggerHelper$1::Logger$SystemLoggerHelper$1() {
}

$Class* Logger$SystemLoggerHelper$1::load$($String* name, bool initialize) {
	$loadClass(Logger$SystemLoggerHelper$1, name, initialize, &_Logger$SystemLoggerHelper$1_ClassInfo_, allocate$Logger$SystemLoggerHelper$1);
	return class$;
}

$Class* Logger$SystemLoggerHelper$1::class$ = nullptr;

		} // logging
	} // util
} // java