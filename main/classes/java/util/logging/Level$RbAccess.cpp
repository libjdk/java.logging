#include <java/util/logging/Level$RbAccess.h>

#include <java/util/logging/Level.h>
#include <jdk/internal/access/JavaUtilResourceBundleAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jcpp.h>

#undef RB_ACCESS

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Level = ::java::util::logging::Level;
using $JavaUtilResourceBundleAccess = ::jdk::internal::access::JavaUtilResourceBundleAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _Level$RbAccess_FieldInfo_[] = {
	{"RB_ACCESS", "Ljdk/internal/access/JavaUtilResourceBundleAccess;", nullptr, $STATIC | $FINAL, $staticField(Level$RbAccess, RB_ACCESS)},
	{}
};

$MethodInfo _Level$RbAccess_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Level$RbAccess::*)()>(&Level$RbAccess::init$))},
	{}
};

$InnerClassInfo _Level$RbAccess_InnerClassesInfo_[] = {
	{"java.util.logging.Level$RbAccess", "java.util.logging.Level", "RbAccess", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _Level$RbAccess_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.logging.Level$RbAccess",
	"java.lang.Object",
	nullptr,
	_Level$RbAccess_FieldInfo_,
	_Level$RbAccess_MethodInfo_,
	nullptr,
	nullptr,
	_Level$RbAccess_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.Level"
};

$Object* allocate$Level$RbAccess($Class* clazz) {
	return $of($alloc(Level$RbAccess));
}

$JavaUtilResourceBundleAccess* Level$RbAccess::RB_ACCESS = nullptr;

void Level$RbAccess::init$() {
}

void clinit$Level$RbAccess($Class* class$) {
	$assignStatic(Level$RbAccess::RB_ACCESS, $SharedSecrets::getJavaUtilResourceBundleAccess());
}

Level$RbAccess::Level$RbAccess() {
}

$Class* Level$RbAccess::load$($String* name, bool initialize) {
	$loadClass(Level$RbAccess, name, initialize, &_Level$RbAccess_ClassInfo_, clinit$Level$RbAccess, allocate$Level$RbAccess);
	return class$;
}

$Class* Level$RbAccess::class$ = nullptr;

		} // logging
	} // util
} // java