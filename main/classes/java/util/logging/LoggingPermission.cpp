#include <java/util/logging/LoggingPermission.h>

#include <java/security/BasicPermission.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $BasicPermission = ::java::security::BasicPermission;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LoggingPermission_FieldInfo_[] = {
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LoggingPermission, serialVersionUID)},
	{}
};

$MethodInfo _LoggingPermission_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(LoggingPermission::*)($String*,$String*)>(&LoggingPermission::init$)), "java.lang.IllegalArgumentException"},
	{}
};

$ClassInfo _LoggingPermission_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.util.logging.LoggingPermission",
	"java.security.BasicPermission",
	nullptr,
	_LoggingPermission_FieldInfo_,
	_LoggingPermission_MethodInfo_
};

$Object* allocate$LoggingPermission($Class* clazz) {
	return $of($alloc(LoggingPermission));
}

void LoggingPermission::init$($String* name, $String* actions) {
	$useLocalCurrentObjectStackCache();
	$BasicPermission::init$(name);
	if (!$nc(name)->equals("control"_s)) {
		$throwNew($IllegalArgumentException, $$str({"name: "_s, name}));
	}
	if (actions != nullptr && actions->length() > 0) {
		$throwNew($IllegalArgumentException, $$str({"actions: "_s, actions}));
	}
}

LoggingPermission::LoggingPermission() {
}

$Class* LoggingPermission::load$($String* name, bool initialize) {
	$loadClass(LoggingPermission, name, initialize, &_LoggingPermission_ClassInfo_, allocate$LoggingPermission);
	return class$;
}

$Class* LoggingPermission::class$ = nullptr;

		} // logging
	} // util
} // java