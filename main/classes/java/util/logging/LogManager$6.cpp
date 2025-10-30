#include <java/util/logging/LogManager$6.h>

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

$FieldInfo _LogManager$6_FieldInfo_[] = {
	{"val$parent", "Ljava/util/logging/Logger;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$6, val$parent)},
	{"val$logger", "Ljava/util/logging/Logger;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$6, val$logger)},
	{}
};

$MethodInfo _LogManager$6_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/Logger;Ljava/util/logging/Logger;)V", "()V", 0, $method(static_cast<void(LogManager$6::*)($Logger*,$Logger*)>(&LogManager$6::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _LogManager$6_EnclosingMethodInfo_ = {
	"java.util.logging.LogManager",
	"doSetParent",
	"(Ljava/util/logging/Logger;Ljava/util/logging/Logger;)V"
};

$InnerClassInfo _LogManager$6_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$6", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LogManager$6_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.logging.LogManager$6",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_LogManager$6_FieldInfo_,
	_LogManager$6_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Object;>;",
	&_LogManager$6_EnclosingMethodInfo_,
	_LogManager$6_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$6($Class* clazz) {
	return $of($alloc(LogManager$6));
}

void LogManager$6::init$($Logger* val$logger, $Logger* val$parent) {
	$set(this, val$logger, val$logger);
	$set(this, val$parent, val$parent);
}

$Object* LogManager$6::run() {
	$nc(this->val$logger)->setParent(this->val$parent);
	return $of(nullptr);
}

LogManager$6::LogManager$6() {
}

$Class* LogManager$6::load$($String* name, bool initialize) {
	$loadClass(LogManager$6, name, initialize, &_LogManager$6_ClassInfo_, allocate$LogManager$6);
	return class$;
}

$Class* LogManager$6::class$ = nullptr;

		} // logging
	} // util
} // java