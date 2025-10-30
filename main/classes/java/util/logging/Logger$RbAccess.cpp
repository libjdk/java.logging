#include <java/util/logging/Logger$RbAccess.h>

#include <java/util/logging/Logger.h>
#include <jdk/internal/access/JavaUtilResourceBundleAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

#undef RB_ACCESS

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Logger = ::java::util::logging::Logger;
using $JavaUtilResourceBundleAccess = ::jdk::internal::access::JavaUtilResourceBundleAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _Logger$RbAccess_FieldInfo_[] = {
	{"RB_ACCESS", "Ljdk/internal/access/JavaUtilResourceBundleAccess;", nullptr, $STATIC | $FINAL, $staticField(Logger$RbAccess, RB_ACCESS)},
	{}
};

$MethodInfo _Logger$RbAccess_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Logger$RbAccess::*)()>(&Logger$RbAccess::init$))},
	{}
};

$InnerClassInfo _Logger$RbAccess_InnerClassesInfo_[] = {
	{"java.util.logging.Logger$RbAccess", "java.util.logging.Logger", "RbAccess", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _Logger$RbAccess_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.logging.Logger$RbAccess",
	"java.lang.Object",
	nullptr,
	_Logger$RbAccess_FieldInfo_,
	_Logger$RbAccess_MethodInfo_,
	nullptr,
	nullptr,
	_Logger$RbAccess_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.Logger"
};

$Object* allocate$Logger$RbAccess($Class* clazz) {
	return $of($alloc(Logger$RbAccess));
}

$JavaUtilResourceBundleAccess* Logger$RbAccess::RB_ACCESS = nullptr;

void Logger$RbAccess::init$() {
}

void clinit$Logger$RbAccess($Class* class$) {
	$assignStatic(Logger$RbAccess::RB_ACCESS, $SharedSecrets::getJavaUtilResourceBundleAccess());
}

Logger$RbAccess::Logger$RbAccess() {
}

$Class* Logger$RbAccess::load$($String* name, bool initialize) {
	$loadClass(Logger$RbAccess, name, initialize, &_Logger$RbAccess_ClassInfo_, clinit$Logger$RbAccess, allocate$Logger$RbAccess);
	return class$;
}

$Class* Logger$RbAccess::class$ = nullptr;

		} // logging
	} // util
} // java