#include <java/util/logging/LogManager$5.h>

#include <java/util/logging/Level.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/Logger.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Level = ::java::util::logging::Level;
using $LogManager = ::java::util::logging::LogManager;
using $Logger = ::java::util::logging::Logger;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LogManager$5_FieldInfo_[] = {
	{"val$level", "Ljava/util/logging/Level;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$5, val$level)},
	{"val$logger", "Ljava/util/logging/Logger;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$5, val$logger)},
	{}
};

$MethodInfo _LogManager$5_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/Logger;Ljava/util/logging/Level;)V", "()V", 0, $method(static_cast<void(LogManager$5::*)($Logger*,$Level*)>(&LogManager$5::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _LogManager$5_EnclosingMethodInfo_ = {
	"java.util.logging.LogManager",
	"doSetLevel",
	"(Ljava/util/logging/Logger;Ljava/util/logging/Level;)V"
};

$InnerClassInfo _LogManager$5_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$5", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LogManager$5_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.logging.LogManager$5",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_LogManager$5_FieldInfo_,
	_LogManager$5_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Object;>;",
	&_LogManager$5_EnclosingMethodInfo_,
	_LogManager$5_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$5($Class* clazz) {
	return $of($alloc(LogManager$5));
}

void LogManager$5::init$($Logger* val$logger, $Level* val$level) {
	$set(this, val$logger, val$logger);
	$set(this, val$level, val$level);
}

$Object* LogManager$5::run() {
	$nc(this->val$logger)->setLevel(this->val$level);
	return $of(nullptr);
}

LogManager$5::LogManager$5() {
}

$Class* LogManager$5::load$($String* name, bool initialize) {
	$loadClass(LogManager$5, name, initialize, &_LogManager$5_ClassInfo_, allocate$LogManager$5);
	return class$;
}

$Class* LogManager$5::class$ = nullptr;

		} // logging
	} // util
} // java