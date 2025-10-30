#include <java/util/logging/LogManager$3.h>

#include <java/util/logging/LogManager.h>
#include <java/util/logging/Logger.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $LogManager = ::java::util::logging::LogManager;
using $Logger = ::java::util::logging::Logger;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LogManager$3_FieldInfo_[] = {
	{"this$0", "Ljava/util/logging/LogManager;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$3, this$0)},
	{"val$sysLogger", "Ljava/util/logging/Logger;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$3, val$sysLogger)},
	{"val$l", "Ljava/util/logging/Logger;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$3, val$l)},
	{}
};

$MethodInfo _LogManager$3_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/LogManager;Ljava/util/logging/Logger;Ljava/util/logging/Logger;)V", "()V", 0, $method(static_cast<void(LogManager$3::*)($LogManager*,$Logger*,$Logger*)>(&LogManager$3::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _LogManager$3_EnclosingMethodInfo_ = {
	"java.util.logging.LogManager",
	"demandSystemLogger",
	"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Module;)Ljava/util/logging/Logger;"
};

$InnerClassInfo _LogManager$3_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$3", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LogManager$3_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.logging.LogManager$3",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_LogManager$3_FieldInfo_,
	_LogManager$3_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_LogManager$3_EnclosingMethodInfo_,
	_LogManager$3_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$3($Class* clazz) {
	return $of($alloc(LogManager$3));
}

void LogManager$3::init$($LogManager* this$0, $Logger* val$l, $Logger* val$sysLogger) {
	$set(this, this$0, this$0);
	$set(this, val$l, val$l);
	$set(this, val$sysLogger, val$sysLogger);
}

$Object* LogManager$3::run() {
	$nc(this->val$l)->mergeWithSystemLogger(this->val$sysLogger);
	return $of(nullptr);
}

LogManager$3::LogManager$3() {
}

$Class* LogManager$3::load$($String* name, bool initialize) {
	$loadClass(LogManager$3, name, initialize, &_LogManager$3_ClassInfo_, allocate$LogManager$3);
	return class$;
}

$Class* LogManager$3::class$ = nullptr;

		} // logging
	} // util
} // java