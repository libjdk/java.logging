#include <java/util/logging/LogManager$LoggingProviderAccess.h>

#include <java/lang/Module.h>
#include <java/lang/SecurityManager.h>
#include <java/security/Permission.h>
#include <java/util/Objects.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/Logger.h>
#include <jdk/internal/logger/DefaultLoggerFinder.h>
#include <sun/util/logging/internal/LoggingProviderImpl$LogManagerAccess.h>
#include <sun/util/logging/internal/LoggingProviderImpl.h>
#include <jcpp.h>

#undef INSTANCE
#undef SYSTEM_LOGGER_RB_NAME

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $SecurityManager = ::java::lang::SecurityManager;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Objects = ::java::util::Objects;
using $LogManager = ::java::util::logging::LogManager;
using $Logger = ::java::util::logging::Logger;
using $DefaultLoggerFinder = ::jdk::internal::logger::DefaultLoggerFinder;
using $LoggingProviderImpl = ::sun::util::logging::internal::LoggingProviderImpl;
using $LoggingProviderImpl$LogManagerAccess = ::sun::util::logging::internal::LoggingProviderImpl$LogManagerAccess;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LogManager$LoggingProviderAccess_FieldInfo_[] = {
	{"INSTANCE", "Ljava/util/logging/LogManager$LoggingProviderAccess;", nullptr, $STATIC | $FINAL, $staticField(LogManager$LoggingProviderAccess, INSTANCE)},
	{}
};

$MethodInfo _LogManager$LoggingProviderAccess_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(LogManager$LoggingProviderAccess::*)()>(&LogManager$LoggingProviderAccess::init$))},
	{"demandLoggerFor", "(Ljava/util/logging/LogManager;Ljava/lang/String;Ljava/lang/Module;)Ljava/util/logging/Logger;", nullptr, $PUBLIC},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _LogManager$LoggingProviderAccess_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$LoggingProviderAccess", "java.util.logging.LogManager", "LoggingProviderAccess", $PRIVATE | $STATIC | $FINAL},
	{"sun.util.logging.internal.LoggingProviderImpl$LogManagerAccess", "sun.util.logging.internal.LoggingProviderImpl", "LogManagerAccess", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _LogManager$LoggingProviderAccess_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.logging.LogManager$LoggingProviderAccess",
	"java.lang.Object",
	"sun.util.logging.internal.LoggingProviderImpl$LogManagerAccess,java.security.PrivilegedAction",
	_LogManager$LoggingProviderAccess_FieldInfo_,
	_LogManager$LoggingProviderAccess_MethodInfo_,
	"Ljava/lang/Object;Lsun/util/logging/internal/LoggingProviderImpl$LogManagerAccess;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	nullptr,
	_LogManager$LoggingProviderAccess_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$LoggingProviderAccess($Class* clazz) {
	return $of($alloc(LogManager$LoggingProviderAccess));
}

int32_t LogManager$LoggingProviderAccess::hashCode() {
	 return this->$LoggingProviderImpl$LogManagerAccess::hashCode();
}

bool LogManager$LoggingProviderAccess::equals(Object$* arg0) {
	 return this->$LoggingProviderImpl$LogManagerAccess::equals(arg0);
}

$Object* LogManager$LoggingProviderAccess::clone() {
	 return this->$LoggingProviderImpl$LogManagerAccess::clone();
}

$String* LogManager$LoggingProviderAccess::toString() {
	 return this->$LoggingProviderImpl$LogManagerAccess::toString();
}

void LogManager$LoggingProviderAccess::finalize() {
	this->$LoggingProviderImpl$LogManagerAccess::finalize();
}

LogManager$LoggingProviderAccess* LogManager$LoggingProviderAccess::INSTANCE = nullptr;

void LogManager$LoggingProviderAccess::init$() {
}

$Logger* LogManager$LoggingProviderAccess::demandLoggerFor($LogManager* manager, $String* name, $Module* module) {
	if (manager != $LogManager::getLogManager()) {
		$throwNew($IllegalArgumentException, "manager"_s);
	}
	$Objects::requireNonNull(name);
	$Objects::requireNonNull(module);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($LogManager::controlPermission);
	}
	if ($DefaultLoggerFinder::isSystem(module)) {
		$init($Logger);
		return $nc(manager)->demandSystemLogger(name, $Logger::SYSTEM_LOGGER_RB_NAME, module);
	} else {
		return $nc(manager)->demandLogger(name, ($String*)nullptr, module);
	}
}

$Object* LogManager$LoggingProviderAccess::run() {
	$LoggingProviderImpl::setLogManagerAccess(LogManager$LoggingProviderAccess::INSTANCE);
	return $of(nullptr);
}

void clinit$LogManager$LoggingProviderAccess($Class* class$) {
	$assignStatic(LogManager$LoggingProviderAccess::INSTANCE, $new(LogManager$LoggingProviderAccess));
}

LogManager$LoggingProviderAccess::LogManager$LoggingProviderAccess() {
}

$Class* LogManager$LoggingProviderAccess::load$($String* name, bool initialize) {
	$loadClass(LogManager$LoggingProviderAccess, name, initialize, &_LogManager$LoggingProviderAccess_ClassInfo_, clinit$LogManager$LoggingProviderAccess, allocate$LogManager$LoggingProviderAccess);
	return class$;
}

$Class* LogManager$LoggingProviderAccess::class$ = nullptr;

		} // logging
	} // util
} // java