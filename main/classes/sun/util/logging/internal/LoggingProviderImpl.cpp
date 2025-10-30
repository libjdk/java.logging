#include <sun/util/logging/internal/LoggingProviderImpl.h>

#include <java/io/Serializable.h>
#include <java/lang/Module.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/System$Logger.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/BasicPermission.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/Logger.h>
#include <java/util/logging/LoggingPermission.h>
#include <jdk/internal/logger/DefaultLoggerFinder.h>
#include <sun/util/logging/internal/LoggingProviderImpl$JULWrapper.h>
#include <sun/util/logging/internal/LoggingProviderImpl$LogManagerAccess.h>
#include <jcpp.h>

#undef LOGGERFINDER_PERMISSION
#undef LOGGING_CONTROL_PERMISSION

using $PermissionArray = $Array<::java::security::Permission>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $System$Logger = ::java::lang::System$Logger;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $BasicPermission = ::java::security::BasicPermission;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $LogManager = ::java::util::logging::LogManager;
using $Logger = ::java::util::logging::Logger;
using $LoggingPermission = ::java::util::logging::LoggingPermission;
using $DefaultLoggerFinder = ::jdk::internal::logger::DefaultLoggerFinder;
using $LoggingProviderImpl$JULWrapper = ::sun::util::logging::internal::LoggingProviderImpl$JULWrapper;
using $LoggingProviderImpl$LogManagerAccess = ::sun::util::logging::internal::LoggingProviderImpl$LogManagerAccess;

namespace sun {
	namespace util {
		namespace logging {
			namespace internal {

class LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0 : public $PrivilegedAction {
	$class(LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($LogManager* manager, $String* name, $Module* module) {
		$set(this, manager, manager);
		$set(this, name, name);
		$set(this, module, module);
	}
	virtual $Object* run() override {
		 return $of(LoggingProviderImpl::lambda$demandJULLoggerFor$0(manager, name, module));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0>());
	}
	$LogManager* manager = nullptr;
	$String* name = nullptr;
	$Module* module = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0::fieldInfos[4] = {
	{"manager", "Ljava/util/logging/LogManager;", nullptr, $PUBLIC, $field(LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0, manager)},
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0, name)},
	{"module", "Ljava/lang/Module;", nullptr, $PUBLIC, $field(LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0, module)},
	{}
};
$MethodInfo LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/logging/LogManager;Ljava/lang/String;Ljava/lang/Module;)V", nullptr, $PUBLIC, $method(static_cast<void(LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0::*)($LogManager*,$String*,$Module*)>(&LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.logging.internal.LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0::load$($String* name, bool initialize) {
	$loadClass(LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0::class$ = nullptr;

$FieldInfo _LoggingProviderImpl_FieldInfo_[] = {
	{"LOGGERFINDER_PERMISSION", "Ljava/lang/RuntimePermission;", nullptr, $STATIC | $FINAL, $staticField(LoggingProviderImpl, LOGGERFINDER_PERMISSION)},
	{"LOGGING_CONTROL_PERMISSION", "Ljava/util/logging/LoggingPermission;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LoggingProviderImpl, LOGGING_CONTROL_PERMISSION)},
	{"logManagerAccess", "Lsun/util/logging/internal/LoggingProviderImpl$LogManagerAccess;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(LoggingProviderImpl, logManagerAccess)},
	{}
};

$MethodInfo _LoggingProviderImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(LoggingProviderImpl::*)()>(&LoggingProviderImpl::init$))},
	{"demandJULLoggerFor", "(Ljava/lang/String;Ljava/lang/Module;)Ljava/util/logging/Logger;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Logger*(*)($String*,$Module*)>(&LoggingProviderImpl::demandJULLoggerFor))},
	{"demandLoggerFor", "(Ljava/lang/String;Ljava/lang/Module;)Ljava/lang/System$Logger;", nullptr, $PROTECTED},
	{"getLogManagerAccess", "()Lsun/util/logging/internal/LoggingProviderImpl$LogManagerAccess;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$LoggingProviderImpl$LogManagerAccess*(*)()>(&LoggingProviderImpl::getLogManagerAccess))},
	{"lambda$demandJULLoggerFor$0", "(Ljava/util/logging/LogManager;Ljava/lang/String;Ljava/lang/Module;)Ljava/util/logging/Logger;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Logger*(*)($LogManager*,$String*,$Module*)>(&LoggingProviderImpl::lambda$demandJULLoggerFor$0))},
	{"setLogManagerAccess", "(Lsun/util/logging/internal/LoggingProviderImpl$LogManagerAccess;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($LoggingProviderImpl$LogManagerAccess*)>(&LoggingProviderImpl::setLogManagerAccess))},
	{}
};

$InnerClassInfo _LoggingProviderImpl_InnerClassesInfo_[] = {
	{"sun.util.logging.internal.LoggingProviderImpl$LogManagerAccess", "sun.util.logging.internal.LoggingProviderImpl", "LogManagerAccess", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.util.logging.internal.LoggingProviderImpl$JULWrapper", "sun.util.logging.internal.LoggingProviderImpl", "JULWrapper", $STATIC | $FINAL},
	{}
};

$ClassInfo _LoggingProviderImpl_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"sun.util.logging.internal.LoggingProviderImpl",
	"jdk.internal.logger.DefaultLoggerFinder",
	nullptr,
	_LoggingProviderImpl_FieldInfo_,
	_LoggingProviderImpl_MethodInfo_,
	nullptr,
	nullptr,
	_LoggingProviderImpl_InnerClassesInfo_,
	nullptr,
	nullptr,
	"sun.util.logging.internal.LoggingProviderImpl$LogManagerAccess,sun.util.logging.internal.LoggingProviderImpl$JULWrapper"
};

$Object* allocate$LoggingProviderImpl($Class* clazz) {
	return $of($alloc(LoggingProviderImpl));
}

$RuntimePermission* LoggingProviderImpl::LOGGERFINDER_PERMISSION = nullptr;
$LoggingPermission* LoggingProviderImpl::LOGGING_CONTROL_PERMISSION = nullptr;
$volatile($LoggingProviderImpl$LogManagerAccess*) LoggingProviderImpl::logManagerAccess = nullptr;

void LoggingProviderImpl::init$() {
	$DefaultLoggerFinder::init$();
}

$Logger* LoggingProviderImpl::demandJULLoggerFor($String* name, $Module* module) {
	$init(LoggingProviderImpl);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($LogManager, manager, $LogManager::getLogManager());
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm == nullptr) {
		return $nc(LoggingProviderImpl::logManagerAccess)->demandLoggerFor(manager, name, module);
	} else {
		$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0, manager, name, module)));
		return $cast($Logger, $AccessController::doPrivileged(pa, ($AccessControlContext*)nullptr, $$new($PermissionArray, {static_cast<$Permission*>(LoggingProviderImpl::LOGGING_CONTROL_PERMISSION)})));
	}
}

$System$Logger* LoggingProviderImpl::demandLoggerFor($String* name, $Module* module) {
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission(LoggingProviderImpl::LOGGERFINDER_PERMISSION);
	}
	return $LoggingProviderImpl$JULWrapper::of($(demandJULLoggerFor(name, module)));
}

$LoggingProviderImpl$LogManagerAccess* LoggingProviderImpl::getLogManagerAccess() {
	$init(LoggingProviderImpl);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission(LoggingProviderImpl::LOGGING_CONTROL_PERMISSION);
	}
	if (LoggingProviderImpl::logManagerAccess == nullptr) {
		$LogManager::getLogManager();
	}
	return LoggingProviderImpl::logManagerAccess;
}

void LoggingProviderImpl::setLogManagerAccess($LoggingProviderImpl$LogManagerAccess* accesLoggers) {
	$init(LoggingProviderImpl);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission(LoggingProviderImpl::LOGGING_CONTROL_PERMISSION);
	}
	$assignStatic(LoggingProviderImpl::logManagerAccess, accesLoggers);
}

$Logger* LoggingProviderImpl::lambda$demandJULLoggerFor$0($LogManager* manager, $String* name, $Module* module) {
	$init(LoggingProviderImpl);
	return $nc(LoggingProviderImpl::logManagerAccess)->demandLoggerFor(manager, name, module);
}

void clinit$LoggingProviderImpl($Class* class$) {
	$assignStatic(LoggingProviderImpl::LOGGERFINDER_PERMISSION, $new($RuntimePermission, "loggerFinder"_s));
	$assignStatic(LoggingProviderImpl::LOGGING_CONTROL_PERMISSION, $new($LoggingPermission, "control"_s, nullptr));
}

LoggingProviderImpl::LoggingProviderImpl() {
}

$Class* LoggingProviderImpl::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0::classInfo$.name)) {
			return LoggingProviderImpl$$Lambda$lambda$demandJULLoggerFor$0::load$(name, initialize);
		}
	}
	$loadClass(LoggingProviderImpl, name, initialize, &_LoggingProviderImpl_ClassInfo_, clinit$LoggingProviderImpl, allocate$LoggingProviderImpl);
	return class$;
}

$Class* LoggingProviderImpl::class$ = nullptr;

			} // internal
		} // logging
	} // util
} // sun