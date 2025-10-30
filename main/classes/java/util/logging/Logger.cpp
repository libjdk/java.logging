#include <java/util/logging/Logger.h>

#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/InternalError.h>
#include <java/lang/Module.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/WeakReference.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/Locale.h>
#include <java/util/MissingResourceException.h>
#include <java/util/Objects.h>
#include <java/util/ResourceBundle.h>
#include <java/util/concurrent/CopyOnWriteArrayList.h>
#include <java/util/function/Supplier.h>
#include <java/util/logging/Filter.h>
#include <java/util/logging/Handler.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/LogManager$LoggerWeakRef.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/LogRecord.h>
#include <java/util/logging/Logger$ConfigurationData.h>
#include <java/util/logging/Logger$LoggerBundle.h>
#include <java/util/logging/Logger$RbAccess.h>
#include <java/util/logging/Logger$SystemLoggerHelper.h>
#include <jdk/internal/access/JavaUtilResourceBundleAccess.h>
#include <jdk/internal/logger/DefaultLoggerFinder.h>
#include <jdk/internal/reflect/Reflection.h>
#include <jcpp.h>

#undef CONFIG
#undef FINE
#undef FINER
#undef FINEST
#undef GLOBAL_LOGGER_NAME
#undef INFO
#undef NO_RESOURCE_BUNDLE
#undef OFF
#undef RB_ACCESS
#undef SEVERE
#undef SYSTEM_BUNDLE
#undef SYSTEM_LOGGER_RB_NAME
#undef WARNING

using $HandlerArray = $Array<::java::util::logging::Handler>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NullPointerException = ::java::lang::NullPointerException;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Reference = ::java::lang::ref::Reference;
using $WeakReference = ::java::lang::ref::WeakReference;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $Locale = ::java::util::Locale;
using $MissingResourceException = ::java::util::MissingResourceException;
using $Objects = ::java::util::Objects;
using $ResourceBundle = ::java::util::ResourceBundle;
using $CopyOnWriteArrayList = ::java::util::concurrent::CopyOnWriteArrayList;
using $Supplier = ::java::util::function::Supplier;
using $Filter = ::java::util::logging::Filter;
using $Handler = ::java::util::logging::Handler;
using $Level = ::java::util::logging::Level;
using $LogManager = ::java::util::logging::LogManager;
using $LogManager$LoggerWeakRef = ::java::util::logging::LogManager$LoggerWeakRef;
using $LogRecord = ::java::util::logging::LogRecord;
using $Logger$ConfigurationData = ::java::util::logging::Logger$ConfigurationData;
using $Logger$LoggerBundle = ::java::util::logging::Logger$LoggerBundle;
using $Logger$RbAccess = ::java::util::logging::Logger$RbAccess;
using $Logger$SystemLoggerHelper = ::java::util::logging::Logger$SystemLoggerHelper;
using $JavaUtilResourceBundleAccess = ::jdk::internal::access::JavaUtilResourceBundleAccess;
using $DefaultLoggerFinder = ::jdk::internal::logger::DefaultLoggerFinder;
using $Reflection = ::jdk::internal::reflect::Reflection;

namespace java {
	namespace util {
		namespace logging {

class Logger$$Lambda$lambda$findResourceBundle$0 : public $PrivilegedAction {
	$class(Logger$$Lambda$lambda$findResourceBundle$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($Module* callerModule) {
		$set(this, callerModule, callerModule);
	}
	virtual $Object* run() override {
		 return $of(Logger::lambda$findResourceBundle$0(callerModule));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Logger$$Lambda$lambda$findResourceBundle$0>());
	}
	$Module* callerModule = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Logger$$Lambda$lambda$findResourceBundle$0::fieldInfos[2] = {
	{"callerModule", "Ljava/lang/Module;", nullptr, $PUBLIC, $field(Logger$$Lambda$lambda$findResourceBundle$0, callerModule)},
	{}
};
$MethodInfo Logger$$Lambda$lambda$findResourceBundle$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Module;)V", nullptr, $PUBLIC, $method(static_cast<void(Logger$$Lambda$lambda$findResourceBundle$0::*)($Module*)>(&Logger$$Lambda$lambda$findResourceBundle$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Logger$$Lambda$lambda$findResourceBundle$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.Logger$$Lambda$lambda$findResourceBundle$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* Logger$$Lambda$lambda$findResourceBundle$0::load$($String* name, bool initialize) {
	$loadClass(Logger$$Lambda$lambda$findResourceBundle$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Logger$$Lambda$lambda$findResourceBundle$0::class$ = nullptr;

$CompoundAttribute _Logger_FieldAnnotations_global[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Logger_MethodAnnotations_getAnonymousLogger27[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Logger_MethodAnnotations_getLogger34[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Logger_MethodAnnotations_getLogger36[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$CompoundAttribute _Logger_MethodAnnotations_logrb62[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Logger_MethodAnnotations_logrb63[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Logger_MethodAnnotations_logrb64[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$CompoundAttribute _Logger_MethodAnnotations_logrb67[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$FieldInfo _Logger_FieldInfo_[] = {
	{"emptyHandlers", "[Ljava/util/logging/Handler;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Logger, emptyHandlers)},
	{"offValue", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Logger, offValue)},
	{"SYSTEM_LOGGER_RB_NAME", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Logger, SYSTEM_LOGGER_RB_NAME)},
	{"SYSTEM_BUNDLE", "Ljava/util/logging/Logger$LoggerBundle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Logger, SYSTEM_BUNDLE)},
	{"NO_RESOURCE_BUNDLE", "Ljava/util/logging/Logger$LoggerBundle;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Logger, NO_RESOURCE_BUNDLE)},
	{"config", "Ljava/util/logging/Logger$ConfigurationData;", nullptr, $PRIVATE | $VOLATILE, $field(Logger, config$)},
	{"manager", "Ljava/util/logging/LogManager;", nullptr, $PRIVATE | $VOLATILE, $field(Logger, manager)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Logger, name)},
	{"loggerBundle", "Ljava/util/logging/Logger$LoggerBundle;", nullptr, $PRIVATE | $VOLATILE, $field(Logger, loggerBundle)},
	{"anonymous", "Z", nullptr, $PRIVATE, $field(Logger, anonymous)},
	{"catalogRef", "Ljava/lang/ref/WeakReference;", "Ljava/lang/ref/WeakReference<Ljava/util/ResourceBundle;>;", $PRIVATE, $field(Logger, catalogRef)},
	{"catalogName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Logger, catalogName)},
	{"catalogLocale", "Ljava/util/Locale;", nullptr, $PRIVATE, $field(Logger, catalogLocale)},
	{"treeLock", "Ljava/lang/Object;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Logger, treeLock)},
	{"parent", "Ljava/util/logging/Logger;", nullptr, $PRIVATE | $VOLATILE, $field(Logger, parent)},
	{"kids", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<Ljava/util/logging/LogManager$LoggerWeakRef;>;", $PRIVATE, $field(Logger, kids)},
	{"callerModuleRef", "Ljava/lang/ref/WeakReference;", "Ljava/lang/ref/WeakReference<Ljava/lang/Module;>;", $PRIVATE, $field(Logger, callerModuleRef)},
	{"isSystemLogger", "Z", nullptr, $PRIVATE | $FINAL, $field(Logger, isSystemLogger)},
	{"GLOBAL_LOGGER_NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Logger, GLOBAL_LOGGER_NAME)},
	{"global", "Ljava/util/logging/Logger;", nullptr, $PUBLIC | $STATIC | $FINAL | $DEPRECATED, $staticField(Logger, global), _Logger_FieldAnnotations_global},
	{}
};

$MethodInfo _Logger_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PROTECTED, $method(static_cast<void(Logger::*)($String*,$String*)>(&Logger::init$))},
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Module;Ljava/util/logging/LogManager;Z)V", nullptr, 0, $method(static_cast<void(Logger::*)($String*,$String*,$Module*,$LogManager*,bool)>(&Logger::init$))},
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(Logger::*)($String*)>(&Logger::init$))},
	{"accessCheckedHandlers", "()[Ljava/util/logging/Handler;", nullptr, 0},
	{"addHandler", "(Ljava/util/logging/Handler;)V", nullptr, $PUBLIC, nullptr, "java.lang.SecurityException"},
	{"catalog", "()Ljava/util/ResourceBundle;", nullptr, $PRIVATE, $method(static_cast<$ResourceBundle*(Logger::*)()>(&Logger::catalog))},
	{"checkPermission", "()V", nullptr, $PRIVATE, $method(static_cast<void(Logger::*)()>(&Logger::checkPermission)), "java.lang.SecurityException"},
	{"config", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"config", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"demandLogger", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class;)Ljava/util/logging/Logger;", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class<*>;)Ljava/util/logging/Logger;", $PRIVATE | $STATIC, $method(static_cast<Logger*(*)($String*,$String*,$Class*)>(&Logger::demandLogger))},
	{"doLog", "(Ljava/util/logging/LogRecord;)V", nullptr, $PRIVATE, $method(static_cast<void(Logger::*)($LogRecord*)>(&Logger::doLog))},
	{"doLog", "(Ljava/util/logging/LogRecord;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(Logger::*)($LogRecord*,$String*)>(&Logger::doLog))},
	{"doLog", "(Ljava/util/logging/LogRecord;Ljava/util/ResourceBundle;)V", nullptr, $PRIVATE, $method(static_cast<void(Logger::*)($LogRecord*,$ResourceBundle*)>(&Logger::doLog))},
	{"doSetParent", "(Ljava/util/logging/Logger;)V", nullptr, $PRIVATE, $method(static_cast<void(Logger::*)(Logger*)>(&Logger::doSetParent))},
	{"entering", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"entering", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"entering", "(Ljava/lang/String;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"exiting", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"exiting", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"findResourceBundle", "(Ljava/lang/String;Z)Ljava/util/ResourceBundle;", nullptr, $PRIVATE | $SYNCHRONIZED, $method(static_cast<$ResourceBundle*(Logger::*)($String*,bool)>(&Logger::findResourceBundle))},
	{"fine", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"fine", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"finer", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"finer", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"finest", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"finest", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"getAnonymousLogger", "()Ljava/util/logging/Logger;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Logger*(*)()>(&Logger::getAnonymousLogger))},
	{"getAnonymousLogger", "(Ljava/lang/String;)Ljava/util/logging/Logger;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Logger*(*)($String*)>(&Logger::getAnonymousLogger)), nullptr, nullptr, _Logger_MethodAnnotations_getAnonymousLogger27},
	{"getCallerModule", "()Ljava/lang/Module;", nullptr, $PRIVATE, $method(static_cast<$Module*(Logger::*)()>(&Logger::getCallerModule))},
	{"getEffectiveLoggerBundle", "()Ljava/util/logging/Logger$LoggerBundle;", nullptr, $PRIVATE, $method(static_cast<$Logger$LoggerBundle*(Logger::*)()>(&Logger::getEffectiveLoggerBundle))},
	{"getFilter", "()Ljava/util/logging/Filter;", nullptr, $PUBLIC},
	{"getGlobal", "()Ljava/util/logging/Logger;", nullptr, $PUBLIC | $STATIC | $FINAL, $method(static_cast<Logger*(*)()>(&Logger::getGlobal))},
	{"getHandlers", "()[Ljava/util/logging/Handler;", nullptr, $PUBLIC},
	{"getLevel", "()Ljava/util/logging/Level;", nullptr, $PUBLIC},
	{"getLogger", "(Ljava/lang/String;)Ljava/util/logging/Logger;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Logger*(*)($String*)>(&Logger::getLogger)), nullptr, nullptr, _Logger_MethodAnnotations_getLogger34},
	{"getLogger", "(Ljava/lang/String;Ljava/lang/Class;)Ljava/util/logging/Logger;", "(Ljava/lang/String;Ljava/lang/Class<*>;)Ljava/util/logging/Logger;", $PRIVATE | $STATIC, $method(static_cast<Logger*(*)($String*,$Class*)>(&Logger::getLogger))},
	{"getLogger", "(Ljava/lang/String;Ljava/lang/String;)Ljava/util/logging/Logger;", nullptr, $PUBLIC | $STATIC, $method(static_cast<Logger*(*)($String*,$String*)>(&Logger::getLogger)), nullptr, nullptr, _Logger_MethodAnnotations_getLogger36},
	{"getLogger", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class;)Ljava/util/logging/Logger;", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class<*>;)Ljava/util/logging/Logger;", $PRIVATE | $STATIC, $method(static_cast<Logger*(*)($String*,$String*,$Class*)>(&Logger::getLogger))},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getParent", "()Ljava/util/logging/Logger;", nullptr, $PUBLIC},
	{"getPlatformLogger", "(Ljava/lang/String;)Ljava/util/logging/Logger;", nullptr, $STATIC, $method(static_cast<Logger*(*)($String*)>(&Logger::getPlatformLogger))},
	{"getResourceBundle", "()Ljava/util/ResourceBundle;", nullptr, $PUBLIC},
	{"getResourceBundleName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getUseParentHandlers", "()Z", nullptr, $PUBLIC},
	{"info", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"info", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"isLevelInitialized", "()Z", nullptr, $FINAL, $method(static_cast<bool(Logger::*)()>(&Logger::isLevelInitialized))},
	{"isLoggable", "(Ljava/util/logging/Level;)Z", nullptr, $PUBLIC},
	{"lambda$findResourceBundle$0", "(Ljava/lang/Module;)Ljava/lang/ClassLoader;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$ClassLoader*(*)($Module*)>(&Logger::lambda$findResourceBundle$0))},
	{"log", "(Ljava/util/logging/LogRecord;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/util/logging/Level;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/util/logging/Level;Ljava/util/function/Supplier;)V", "(Ljava/util/logging/Level;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"log", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/util/logging/Level;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/util/logging/Level;Ljava/lang/Throwable;Ljava/util/function/Supplier;)V", "(Ljava/util/logging/Level;Ljava/lang/Throwable;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"logp", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"logp", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/function/Supplier;)V", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"logp", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"logp", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"logp", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"logp", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;Ljava/util/function/Supplier;)V", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"logrb", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, nullptr, nullptr, _Logger_MethodAnnotations_logrb62},
	{"logrb", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, nullptr, nullptr, _Logger_MethodAnnotations_logrb63},
	{"logrb", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, nullptr, nullptr, _Logger_MethodAnnotations_logrb64},
	{"logrb", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/ResourceBundle;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT},
	{"logrb", "(Ljava/util/logging/Level;Ljava/util/ResourceBundle;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT},
	{"logrb", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, nullptr, nullptr, _Logger_MethodAnnotations_logrb67},
	{"logrb", "(Ljava/util/logging/Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/ResourceBundle;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"logrb", "(Ljava/util/logging/Level;Ljava/util/ResourceBundle;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"mergeWithSystemLogger", "(Ljava/util/logging/Logger;)V", nullptr, $FINAL, $method(static_cast<void(Logger::*)(Logger*)>(&Logger::mergeWithSystemLogger))},
	{"removeChildLogger", "(Ljava/util/logging/LogManager$LoggerWeakRef;)V", nullptr, $FINAL, $method(static_cast<void(Logger::*)($LogManager$LoggerWeakRef*)>(&Logger::removeChildLogger))},
	{"removeHandler", "(Ljava/util/logging/Handler;)V", nullptr, $PUBLIC, nullptr, "java.lang.SecurityException"},
	{"setCallerModuleRef", "(Ljava/lang/Module;)V", nullptr, $PRIVATE, $method(static_cast<void(Logger::*)($Module*)>(&Logger::setCallerModuleRef))},
	{"setFilter", "(Ljava/util/logging/Filter;)V", nullptr, $PUBLIC, nullptr, "java.lang.SecurityException"},
	{"setLevel", "(Ljava/util/logging/Level;)V", nullptr, $PUBLIC, nullptr, "java.lang.SecurityException"},
	{"setLogManager", "(Ljava/util/logging/LogManager;)V", nullptr, 0},
	{"setParent", "(Ljava/util/logging/Logger;)V", nullptr, $PUBLIC},
	{"setResourceBundle", "(Ljava/util/ResourceBundle;)V", nullptr, $PUBLIC},
	{"setUseParentHandlers", "(Z)V", nullptr, $PUBLIC},
	{"setupResourceInfo", "(Ljava/lang/String;Ljava/lang/Class;)V", "(Ljava/lang/String;Ljava/lang/Class<*>;)V", $PRIVATE, $method(static_cast<void(Logger::*)($String*,$Class*)>(&Logger::setupResourceInfo))},
	{"setupResourceInfo", "(Ljava/lang/String;Ljava/lang/Module;)V", nullptr, $PRIVATE | $SYNCHRONIZED, $method(static_cast<void(Logger::*)($String*,$Module*)>(&Logger::setupResourceInfo))},
	{"severe", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"severe", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"throwing", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"updateEffectiveLevel", "()V", nullptr, $PRIVATE, $method(static_cast<void(Logger::*)()>(&Logger::updateEffectiveLevel))},
	{"warning", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"warning", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{}
};

$InnerClassInfo _Logger_InnerClassesInfo_[] = {
	{"java.util.logging.Logger$SystemLoggerHelper", "java.util.logging.Logger", "SystemLoggerHelper", $PRIVATE | $STATIC},
	{"java.util.logging.Logger$ConfigurationData", "java.util.logging.Logger", "ConfigurationData", $PRIVATE | $STATIC | $FINAL},
	{"java.util.logging.Logger$RbAccess", "java.util.logging.Logger", "RbAccess", $PRIVATE | $STATIC | $FINAL},
	{"java.util.logging.Logger$LoggerBundle", "java.util.logging.Logger", "LoggerBundle", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _Logger_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.logging.Logger",
	"java.lang.Object",
	nullptr,
	_Logger_FieldInfo_,
	_Logger_MethodInfo_,
	nullptr,
	nullptr,
	_Logger_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.logging.Logger$SystemLoggerHelper,java.util.logging.Logger$SystemLoggerHelper$1,java.util.logging.Logger$ConfigurationData,java.util.logging.Logger$RbAccess,java.util.logging.Logger$LoggerBundle"
};

$Object* allocate$Logger($Class* clazz) {
	return $of($alloc(Logger));
}

$HandlerArray* Logger::emptyHandlers = nullptr;
int32_t Logger::offValue = 0;
$String* Logger::SYSTEM_LOGGER_RB_NAME = nullptr;
$Logger$LoggerBundle* Logger::SYSTEM_BUNDLE = nullptr;
$Logger$LoggerBundle* Logger::NO_RESOURCE_BUNDLE = nullptr;
$Object* Logger::treeLock = nullptr;
$String* Logger::GLOBAL_LOGGER_NAME = nullptr;
Logger* Logger::global = nullptr;

Logger* Logger::getGlobal() {
	$init(Logger);
	$LogManager::getLogManager();
	return Logger::global;
}

void Logger::init$($String* name, $String* resourceBundleName) {
	Logger::init$(name, resourceBundleName, nullptr, $($LogManager::getLogManager()), false);
}

void Logger::init$($String* name, $String* resourceBundleName, $Module* caller, $LogManager* manager, bool isSystemLogger) {
	$set(this, loggerBundle, Logger::NO_RESOURCE_BUNDLE);
	$set(this, manager, manager);
	this->isSystemLogger = isSystemLogger;
	$set(this, config$, $new($Logger$ConfigurationData));
	$set(this, name, name);
	setupResourceInfo(resourceBundleName, caller);
}

void Logger::mergeWithSystemLogger(Logger* system) {
	if (!$nc(system)->isSystemLogger || this->anonymous || this->name == nullptr || !$nc(this->name)->equals($nc(system)->name)) {
		$throwNew($InternalError, "invalid logger merge"_s);
	}
	checkPermission();
	$var($Logger$ConfigurationData, cfg, this->config$);
	if (cfg != $nc(system)->config$) {
		$set(this, config$, $nc(cfg)->merge(system));
	}
}

void Logger::setCallerModuleRef($Module* callerModule) {
	if (callerModule != nullptr) {
		$set(this, callerModuleRef, $new($WeakReference, callerModule));
	}
}

$Module* Logger::getCallerModule() {
	return (this->callerModuleRef != nullptr) ? $cast($Module, $nc(this->callerModuleRef)->get()) : ($Module*)nullptr;
}

void Logger::init$($String* name) {
	$set(this, loggerBundle, Logger::NO_RESOURCE_BUNDLE);
	$set(this, name, name);
	this->isSystemLogger = true;
	$set(this, config$, $new($Logger$ConfigurationData));
}

void Logger::setLogManager($LogManager* manager) {
	$set(this, manager, manager);
}

void Logger::checkPermission() {
	if (!this->anonymous) {
		if (this->manager == nullptr) {
			$set(this, manager, $LogManager::getLogManager());
		}
		$nc(this->manager)->checkPermission();
	}
}

Logger* Logger::demandLogger($String* name, $String* resourceBundleName, $Class* caller) {
	$init(Logger);
	$useLocalCurrentObjectStackCache();
	$var($LogManager, manager, $LogManager::getLogManager());
	$init($Logger$SystemLoggerHelper);
	if (!$Logger$SystemLoggerHelper::disableCallerCheck) {
		if ($DefaultLoggerFinder::isSystem($($nc(caller)->getModule()))) {
			return $nc(manager)->demandSystemLogger(name, resourceBundleName, caller);
		}
	}
	return $nc(manager)->demandLogger(name, resourceBundleName, caller);
}

Logger* Logger::getLogger($String* name) {
	$init(Logger);
	return Logger::getLogger(name, $Reflection::getCallerClass());
}

Logger* Logger::getLogger($String* name, $Class* callerClass) {
	$init(Logger);
	return demandLogger(name, nullptr, callerClass);
}

Logger* Logger::getLogger($String* name, $String* resourceBundleName) {
	$init(Logger);
	return Logger::getLogger(name, resourceBundleName, $Reflection::getCallerClass());
}

Logger* Logger::getLogger($String* name, $String* resourceBundleName, $Class* callerClass) {
	$init(Logger);
	$var(Logger, result, demandLogger(name, resourceBundleName, callerClass));
	$nc(result)->setupResourceInfo(resourceBundleName, callerClass);
	return result;
}

Logger* Logger::getPlatformLogger($String* name) {
	$init(Logger);
	$useLocalCurrentObjectStackCache();
	$var($LogManager, manager, $LogManager::getLogManager());
	$var(Logger, result, $nc(manager)->demandSystemLogger(name, Logger::SYSTEM_LOGGER_RB_NAME, ($Module*)nullptr));
	return result;
}

Logger* Logger::getAnonymousLogger() {
	$init(Logger);
	$beforeCallerSensitive();
	return getAnonymousLogger(nullptr);
}

Logger* Logger::getAnonymousLogger($String* resourceBundleName) {
	$init(Logger);
	$useLocalCurrentObjectStackCache();
	$var($LogManager, manager, $LogManager::getLogManager());
	$nc(manager)->drainLoggerRefQueueBounded();
	$Class* callerClass = $Reflection::getCallerClass();
	$var($Module, module, $nc(callerClass)->getModule());
	$var(Logger, result, $new(Logger, nullptr, resourceBundleName, module, manager, false));
	result->anonymous = true;
	$var(Logger, root, manager->getLogger(""_s));
	result->doSetParent(root);
	return result;
}

$ResourceBundle* Logger::getResourceBundle() {
	return findResourceBundle($(getResourceBundleName()), true);
}

$String* Logger::getResourceBundleName() {
	return $nc(this->loggerBundle)->resourceBundleName;
}

void Logger::setFilter($Filter* newFilter) {
	checkPermission();
	$nc(this->config$)->setFilter(newFilter);
}

$Filter* Logger::getFilter() {
	return $nc(this->config$)->filter;
}

void Logger::log($LogRecord* record) {
	$useLocalCurrentObjectStackCache();
	if (!isLoggable($($nc(record)->getLevel()))) {
		return;
	}
	$var($Filter, theFilter, $nc(this->config$)->filter);
	if (theFilter != nullptr && !theFilter->isLoggable(record)) {
		return;
	}
	$var(Logger, logger, this);
	while (logger != nullptr) {
		$var($HandlerArray, loggerHandlers, this->isSystemLogger ? logger->accessCheckedHandlers() : logger->getHandlers());
		{
			$var($HandlerArray, arr$, loggerHandlers);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Handler, handler, arr$->get(i$));
				{
					$nc(handler)->publish(record);
				}
			}
		}
		bool useParentHdls = this->isSystemLogger ? $cast(bool, $nc(logger->config$)->useParentHandlers) : logger->getUseParentHandlers();
		if (!useParentHdls) {
			break;
		}
		$assign(logger, this->isSystemLogger ? $cast(Logger, logger->parent) : logger->getParent());
	}
}

void Logger::doLog($LogRecord* lr) {
	$useLocalCurrentObjectStackCache();
	$nc(lr)->setLoggerName(this->name);
	$var($Logger$LoggerBundle, lb, getEffectiveLoggerBundle());
	$var($ResourceBundle, bundle, $nc(lb)->userBundle);
	$var($String, ebname, lb->resourceBundleName);
	if (ebname != nullptr && bundle != nullptr) {
		lr->setResourceBundleName(ebname);
		lr->setResourceBundle(bundle);
	}
	log(lr);
}

void Logger::log($Level* level, $String* msg) {
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	doLog(lr);
}

void Logger::log($Level* level, $Supplier* msgSupplier) {
	$useLocalCurrentObjectStackCache();
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, $cast($String, $($nc(msgSupplier)->get()))));
	doLog(lr);
}

void Logger::log($Level* level, $String* msg, Object$* param1) {
	$useLocalCurrentObjectStackCache();
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	$var($ObjectArray, params, $new($ObjectArray, {param1}));
	lr->setParameters(params);
	doLog(lr);
}

void Logger::log($Level* level, $String* msg, $ObjectArray* params) {
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	lr->setParameters(params);
	doLog(lr);
}

void Logger::log($Level* level, $String* msg, $Throwable* thrown) {
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	lr->setThrown(thrown);
	doLog(lr);
}

void Logger::log($Level* level, $Throwable* thrown, $Supplier* msgSupplier) {
	$useLocalCurrentObjectStackCache();
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, $cast($String, $($nc(msgSupplier)->get()))));
	lr->setThrown(thrown);
	doLog(lr);
}

void Logger::logp($Level* level, $String* sourceClass, $String* sourceMethod, $String* msg) {
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	lr->setSourceClassName(sourceClass);
	lr->setSourceMethodName(sourceMethod);
	doLog(lr);
}

void Logger::logp($Level* level, $String* sourceClass, $String* sourceMethod, $Supplier* msgSupplier) {
	$useLocalCurrentObjectStackCache();
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, $cast($String, $($nc(msgSupplier)->get()))));
	lr->setSourceClassName(sourceClass);
	lr->setSourceMethodName(sourceMethod);
	doLog(lr);
}

void Logger::logp($Level* level, $String* sourceClass, $String* sourceMethod, $String* msg, Object$* param1) {
	$useLocalCurrentObjectStackCache();
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	lr->setSourceClassName(sourceClass);
	lr->setSourceMethodName(sourceMethod);
	$var($ObjectArray, params, $new($ObjectArray, {param1}));
	lr->setParameters(params);
	doLog(lr);
}

void Logger::logp($Level* level, $String* sourceClass, $String* sourceMethod, $String* msg, $ObjectArray* params) {
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	lr->setSourceClassName(sourceClass);
	lr->setSourceMethodName(sourceMethod);
	lr->setParameters(params);
	doLog(lr);
}

void Logger::logp($Level* level, $String* sourceClass, $String* sourceMethod, $String* msg, $Throwable* thrown) {
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	lr->setSourceClassName(sourceClass);
	lr->setSourceMethodName(sourceMethod);
	lr->setThrown(thrown);
	doLog(lr);
}

void Logger::logp($Level* level, $String* sourceClass, $String* sourceMethod, $Throwable* thrown, $Supplier* msgSupplier) {
	$useLocalCurrentObjectStackCache();
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, $cast($String, $($nc(msgSupplier)->get()))));
	lr->setSourceClassName(sourceClass);
	lr->setSourceMethodName(sourceMethod);
	lr->setThrown(thrown);
	doLog(lr);
}

void Logger::doLog($LogRecord* lr, $String* rbname) {
	$nc(lr)->setLoggerName(this->name);
	if (rbname != nullptr) {
		lr->setResourceBundleName(rbname);
		lr->setResourceBundle($(findResourceBundle(rbname, false)));
	}
	log(lr);
}

void Logger::doLog($LogRecord* lr, $ResourceBundle* rb) {
	$nc(lr)->setLoggerName(this->name);
	if (rb != nullptr) {
		lr->setResourceBundleName($(rb->getBaseBundleName()));
		lr->setResourceBundle(rb);
	}
	log(lr);
}

void Logger::logrb($Level* level, $String* sourceClass, $String* sourceMethod, $String* bundleName, $String* msg) {
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	lr->setSourceClassName(sourceClass);
	lr->setSourceMethodName(sourceMethod);
	doLog(lr, bundleName);
}

void Logger::logrb($Level* level, $String* sourceClass, $String* sourceMethod, $String* bundleName, $String* msg, Object$* param1) {
	$useLocalCurrentObjectStackCache();
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	lr->setSourceClassName(sourceClass);
	lr->setSourceMethodName(sourceMethod);
	$var($ObjectArray, params, $new($ObjectArray, {param1}));
	lr->setParameters(params);
	doLog(lr, bundleName);
}

void Logger::logrb($Level* level, $String* sourceClass, $String* sourceMethod, $String* bundleName, $String* msg, $ObjectArray* params) {
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	lr->setSourceClassName(sourceClass);
	lr->setSourceMethodName(sourceMethod);
	lr->setParameters(params);
	doLog(lr, bundleName);
}

void Logger::logrb($Level* level, $String* sourceClass, $String* sourceMethod, $ResourceBundle* bundle, $String* msg, $ObjectArray* params) {
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	lr->setSourceClassName(sourceClass);
	lr->setSourceMethodName(sourceMethod);
	if (params != nullptr && params->length != 0) {
		lr->setParameters(params);
	}
	doLog(lr, bundle);
}

void Logger::logrb($Level* level, $ResourceBundle* bundle, $String* msg, $ObjectArray* params) {
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	if (params != nullptr && params->length != 0) {
		lr->setParameters(params);
	}
	doLog(lr, bundle);
}

void Logger::logrb($Level* level, $String* sourceClass, $String* sourceMethod, $String* bundleName, $String* msg, $Throwable* thrown) {
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	lr->setSourceClassName(sourceClass);
	lr->setSourceMethodName(sourceMethod);
	lr->setThrown(thrown);
	doLog(lr, bundleName);
}

void Logger::logrb($Level* level, $String* sourceClass, $String* sourceMethod, $ResourceBundle* bundle, $String* msg, $Throwable* thrown) {
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	lr->setSourceClassName(sourceClass);
	lr->setSourceMethodName(sourceMethod);
	lr->setThrown(thrown);
	doLog(lr, bundle);
}

void Logger::logrb($Level* level, $ResourceBundle* bundle, $String* msg, $Throwable* thrown) {
	if (!isLoggable(level)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, level, msg));
	lr->setThrown(thrown);
	doLog(lr, bundle);
}

void Logger::entering($String* sourceClass, $String* sourceMethod) {
	$init($Level);
	logp($Level::FINER, sourceClass, sourceMethod, "ENTRY"_s);
}

void Logger::entering($String* sourceClass, $String* sourceMethod, Object$* param1) {
	$init($Level);
	logp($Level::FINER, sourceClass, sourceMethod, "ENTRY {0}"_s, param1);
}

void Logger::entering($String* sourceClass, $String* sourceMethod, $ObjectArray* params) {
	$useLocalCurrentObjectStackCache();
	$var($String, msg, "ENTRY"_s);
	if (params == nullptr) {
		$init($Level);
		logp($Level::FINER, sourceClass, sourceMethod, msg);
		return;
	}
	$init($Level);
	if (!isLoggable($Level::FINER)) {
		return;
	}
	if ($nc(params)->length > 0) {
		$var($StringBuilder, b, $new($StringBuilder, msg));
		for (int32_t i = 0; i < params->length; ++i) {
			b->append(u' ')->append(u'{')->append(i)->append(u'}');
		}
		$assign(msg, b->toString());
	}
	logp($Level::FINER, sourceClass, sourceMethod, msg, params);
}

void Logger::exiting($String* sourceClass, $String* sourceMethod) {
	$init($Level);
	logp($Level::FINER, sourceClass, sourceMethod, "RETURN"_s);
}

void Logger::exiting($String* sourceClass, $String* sourceMethod, Object$* result) {
	$init($Level);
	logp($Level::FINER, sourceClass, sourceMethod, "RETURN {0}"_s, result);
}

void Logger::throwing($String* sourceClass, $String* sourceMethod, $Throwable* thrown) {
	$init($Level);
	if (!isLoggable($Level::FINER)) {
		return;
	}
	$var($LogRecord, lr, $new($LogRecord, $Level::FINER, "THROW"_s));
	lr->setSourceClassName(sourceClass);
	lr->setSourceMethodName(sourceMethod);
	lr->setThrown(thrown);
	doLog(lr);
}

void Logger::severe($String* msg) {
	$init($Level);
	log($Level::SEVERE, msg);
}

void Logger::warning($String* msg) {
	$init($Level);
	log($Level::WARNING, msg);
}

void Logger::info($String* msg) {
	$init($Level);
	log($Level::INFO, msg);
}

void Logger::config($String* msg) {
	$init($Level);
	log($Level::CONFIG, msg);
}

void Logger::fine($String* msg) {
	$init($Level);
	log($Level::FINE, msg);
}

void Logger::finer($String* msg) {
	$init($Level);
	log($Level::FINER, msg);
}

void Logger::finest($String* msg) {
	$init($Level);
	log($Level::FINEST, msg);
}

void Logger::severe($Supplier* msgSupplier) {
	$init($Level);
	log($Level::SEVERE, msgSupplier);
}

void Logger::warning($Supplier* msgSupplier) {
	$init($Level);
	log($Level::WARNING, msgSupplier);
}

void Logger::info($Supplier* msgSupplier) {
	$init($Level);
	log($Level::INFO, msgSupplier);
}

void Logger::config($Supplier* msgSupplier) {
	$init($Level);
	log($Level::CONFIG, msgSupplier);
}

void Logger::fine($Supplier* msgSupplier) {
	$init($Level);
	log($Level::FINE, msgSupplier);
}

void Logger::finer($Supplier* msgSupplier) {
	$init($Level);
	log($Level::FINER, msgSupplier);
}

void Logger::finest($Supplier* msgSupplier) {
	$init($Level);
	log($Level::FINEST, msgSupplier);
}

void Logger::setLevel($Level* newLevel) {
	checkPermission();
	$synchronized(Logger::treeLock) {
		$nc(this->config$)->setLevelObject(newLevel);
		updateEffectiveLevel();
	}
}

bool Logger::isLevelInitialized() {
	return $nc(this->config$)->levelObject != nullptr;
}

$Level* Logger::getLevel() {
	return $nc(this->config$)->levelObject;
}

bool Logger::isLoggable($Level* level) {
	int32_t levelValue = $nc(this->config$)->levelValue;
	if ($nc(level)->intValue() < levelValue || levelValue == Logger::offValue) {
		return false;
	}
	return true;
}

$String* Logger::getName() {
	return this->name;
}

void Logger::addHandler($Handler* handler) {
	$Objects::requireNonNull(handler);
	checkPermission();
	$nc(this->config$)->addHandler(handler);
}

void Logger::removeHandler($Handler* handler) {
	checkPermission();
	if (handler == nullptr) {
		return;
	}
	$nc(this->config$)->removeHandler(handler);
}

$HandlerArray* Logger::getHandlers() {
	return accessCheckedHandlers();
}

$HandlerArray* Logger::accessCheckedHandlers() {
	return $fcast($HandlerArray, $nc($nc(this->config$)->handlers)->toArray(Logger::emptyHandlers));
}

void Logger::setUseParentHandlers(bool useParentHandlers) {
	checkPermission();
	$nc(this->config$)->setUseParentHandlers(useParentHandlers);
}

bool Logger::getUseParentHandlers() {
	return $nc(this->config$)->useParentHandlers;
}

$ResourceBundle* Logger::catalog() {
	$var($WeakReference, ref, this->catalogRef);
	return ref == nullptr ? ($ResourceBundle*)nullptr : $cast($ResourceBundle, $nc(ref)->get());
}

$ResourceBundle* Logger::findResourceBundle($String* name, bool useCallersModule) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$beforeCallerSensitive();
		if (name == nullptr) {
			return nullptr;
		}
		$var($Locale, currentLocale, $Locale::getDefault());
		$var($Logger$LoggerBundle, lb, this->loggerBundle);
		$var($ResourceBundle, catalog, this->catalog());
		if ($nc(lb)->userBundle != nullptr && $nc(name)->equals(lb->resourceBundleName)) {
			return lb->userBundle;
		} else {
			bool var$1 = catalog != nullptr && $nc(currentLocale)->equals(this->catalogLocale);
			if (var$1 && name->equals(this->catalogName)) {
				return catalog;
			}
		}
		$var($ClassLoader, cl, $($Thread::currentThread())->getContextClassLoader());
		if (cl == nullptr) {
			$assign(cl, $ClassLoader::getSystemClassLoader());
		}
		$var($Module, callerModule, getCallerModule());
		if (!useCallersModule || callerModule == nullptr || !$nc(callerModule)->isNamed()) {
			try {
				$var($Module, mod, $nc(cl)->getUnnamedModule());
				$init($Logger$RbAccess);
				$assign(catalog, $nc($Logger$RbAccess::RB_ACCESS)->getBundle(name, currentLocale, mod));
				$set(this, catalogRef, $new($WeakReference, catalog));
				$set(this, catalogName, name);
				$set(this, catalogLocale, currentLocale);
				return catalog;
			} catch ($MissingResourceException& ex) {
				if (useCallersModule && callerModule != nullptr) {
					try {
						$var($PrivilegedAction, getModuleClassLoader, static_cast<$PrivilegedAction*>($new(Logger$$Lambda$lambda$findResourceBundle$0, callerModule)));
						$var($ClassLoader, moduleCL, $cast($ClassLoader, $AccessController::doPrivileged(getModuleClassLoader)));
						if (moduleCL == cl || moduleCL == nullptr) {
							return nullptr;
						}
						$assign(catalog, $ResourceBundle::getBundle(name, currentLocale, moduleCL));
						$set(this, catalogRef, $new($WeakReference, catalog));
						$set(this, catalogName, name);
						$set(this, catalogLocale, currentLocale);
						return catalog;
					} catch ($MissingResourceException& x) {
						return nullptr;
					}
				} else {
					return nullptr;
				}
			}
		} else {
			try {
				$init($Logger$RbAccess);
				$assign(catalog, $nc($Logger$RbAccess::RB_ACCESS)->getBundle(name, currentLocale, callerModule));
				$set(this, catalogRef, $new($WeakReference, catalog));
				$set(this, catalogName, name);
				$set(this, catalogLocale, currentLocale);
				return catalog;
			} catch ($MissingResourceException& ex) {
				return nullptr;
			}
		}
	}
	$shouldNotReachHere();
}

void Logger::setupResourceInfo($String* name, $Class* caller) {
	$var($Module, module, caller == nullptr ? ($Module*)nullptr : $nc(caller)->getModule());
	setupResourceInfo(name, module);
}

void Logger::setupResourceInfo($String* name, $Module* callerModule) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($Logger$LoggerBundle, lb, this->loggerBundle);
		if ($nc(lb)->resourceBundleName != nullptr) {
			if ($nc(lb->resourceBundleName)->equals(name)) {
				return;
			}
			$throwNew($IllegalArgumentException, $$str({lb->resourceBundleName, " != "_s, name}));
		}
		if (name == nullptr) {
			return;
		}
		setCallerModuleRef(callerModule);
		if (this->isSystemLogger && (callerModule != nullptr && !$DefaultLoggerFinder::isSystem(callerModule))) {
			checkPermission();
		}
		if ($nc(name)->equals(Logger::SYSTEM_LOGGER_RB_NAME)) {
			$set(this, loggerBundle, Logger::SYSTEM_BUNDLE);
		} else {
			$var($ResourceBundle, bundle, findResourceBundle(name, true));
			if (bundle == nullptr) {
				$set(this, callerModuleRef, nullptr);
				$throwNew($MissingResourceException, $$str({"Can\'t find "_s, name, " bundle from "_s}), name, ""_s);
			}
			$set(this, loggerBundle, $Logger$LoggerBundle::get(name, nullptr));
		}
	}
}

void Logger::setResourceBundle($ResourceBundle* bundle) {
	$useLocalCurrentObjectStackCache();
	checkPermission();
	$var($String, baseName, $nc(bundle)->getBaseBundleName());
	if (baseName == nullptr || $nc(baseName)->isEmpty()) {
		$throwNew($IllegalArgumentException, "resource bundle must have a name"_s);
	}
	$synchronized(this) {
		$var($Logger$LoggerBundle, lb, this->loggerBundle);
		bool canReplaceResourceBundle = $nc(lb)->resourceBundleName == nullptr || $nc($nc(lb)->resourceBundleName)->equals(baseName);
		if (!canReplaceResourceBundle) {
			$throwNew($IllegalArgumentException, "can\'t replace resource bundle"_s);
		}
		$set(this, loggerBundle, $Logger$LoggerBundle::get(baseName, bundle));
	}
}

Logger* Logger::getParent() {
	return this->parent;
}

void Logger::setParent(Logger* parent) {
	if (parent == nullptr) {
		$throwNew($NullPointerException);
	}
	if (this->manager == nullptr) {
		$set(this, manager, $LogManager::getLogManager());
	}
	$nc(this->manager)->checkPermission();
	doSetParent(parent);
}

void Logger::doSetParent(Logger* newParent) {
	$useLocalCurrentObjectStackCache();
	$synchronized(Logger::treeLock) {
		$var($LogManager$LoggerWeakRef, ref, nullptr);
		if (this->parent != nullptr) {
			{
				$var($Iterator, iter, $nc($nc(this->parent)->kids)->iterator());
				for (; $nc(iter)->hasNext();) {
					$assign(ref, $cast($LogManager$LoggerWeakRef, iter->next()));
					if ($nc(ref)->refersTo(this)) {
						iter->remove();
						break;
					} else {
						$assign(ref, nullptr);
					}
				}
			}
		}
		$set(this, parent, newParent);
		if ($nc(this->parent)->kids == nullptr) {
			$set($nc(this->parent), kids, $new($ArrayList, 2));
		}
		if (ref == nullptr) {
			$assign(ref, $new($LogManager$LoggerWeakRef, static_cast<$LogManager*>($nc(this->manager)), this));
		}
		$nc(ref)->setParentRef($$new($WeakReference, this->parent));
		$nc($nc(this->parent)->kids)->add(ref);
		updateEffectiveLevel();
	}
}

void Logger::removeChildLogger($LogManager$LoggerWeakRef* child) {
	$useLocalCurrentObjectStackCache();
	$synchronized(Logger::treeLock) {
		{
			$var($Iterator, iter, $nc(this->kids)->iterator());
			for (; $nc(iter)->hasNext();) {
				$var($LogManager$LoggerWeakRef, ref, $cast($LogManager$LoggerWeakRef, iter->next()));
				if (ref == child) {
					iter->remove();
					return;
				}
			}
		}
	}
}

void Logger::updateEffectiveLevel() {
	$useLocalCurrentObjectStackCache();
	int32_t newLevelValue = 0;
	$var($Logger$ConfigurationData, cfg, this->config$);
	$var($Level, levelObject, $nc(cfg)->levelObject);
	if (levelObject != nullptr) {
		newLevelValue = levelObject->intValue();
	} else if (this->parent != nullptr) {
		newLevelValue = $nc($nc(this->parent)->config$)->levelValue;
	} else {
		$init($Level);
		newLevelValue = $nc($Level::INFO)->intValue();
	}
	if (cfg->levelValue == newLevelValue) {
		return;
	}
	cfg->setLevelValue(newLevelValue);
	if (this->kids != nullptr) {
		{
			$var($Iterator, i$, $nc(this->kids)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($LogManager$LoggerWeakRef, ref, $cast($LogManager$LoggerWeakRef, i$->next()));
				{
					$var(Logger, kid, $cast(Logger, $nc(ref)->get()));
					if (kid != nullptr) {
						kid->updateEffectiveLevel();
					}
				}
			}
		}
	}
}

$Logger$LoggerBundle* Logger::getEffectiveLoggerBundle() {
	$useLocalCurrentObjectStackCache();
	$var($Logger$LoggerBundle, lb, this->loggerBundle);
	if ($nc(lb)->isSystemBundle()) {
		return Logger::SYSTEM_BUNDLE;
	}
	$var($ResourceBundle, b, getResourceBundle());
	if (b != nullptr && b == $nc(lb)->userBundle) {
		return lb;
	} else if (b != nullptr) {
		$var($String, rbName, getResourceBundleName());
		return $Logger$LoggerBundle::get(rbName, b);
	}
	$var(Logger, target, this->parent);
	while (target != nullptr) {
		$var($Logger$LoggerBundle, trb, target->loggerBundle);
		if ($nc(trb)->isSystemBundle()) {
			return Logger::SYSTEM_BUNDLE;
		}
		if ($nc(trb)->userBundle != nullptr) {
			return trb;
		}
		$var($String, rbName, this->isSystemLogger ? (target->isSystemLogger ? $nc(trb)->resourceBundleName : ($String*)nullptr) : target->getResourceBundleName());
		if (rbName != nullptr) {
			return $Logger$LoggerBundle::get(rbName, $(findResourceBundle(rbName, true)));
		}
		$assign(target, this->isSystemLogger ? $cast(Logger, target->parent) : target->getParent());
	}
	return Logger::NO_RESOURCE_BUNDLE;
}

$ClassLoader* Logger::lambda$findResourceBundle$0($Module* callerModule) {
	$init(Logger);
	return $nc(callerModule)->getClassLoader();
}

void clinit$Logger($Class* class$) {
	$assignStatic(Logger::SYSTEM_LOGGER_RB_NAME, "sun.util.logging.resources.logging"_s);
	$assignStatic(Logger::GLOBAL_LOGGER_NAME, "global"_s);
	$assignStatic(Logger::emptyHandlers, $new($HandlerArray, 0));
	$init($Level);
	Logger::offValue = $nc($Level::OFF)->intValue();
	$assignStatic(Logger::SYSTEM_BUNDLE, $new($Logger$LoggerBundle, Logger::SYSTEM_LOGGER_RB_NAME, nullptr));
	$assignStatic(Logger::NO_RESOURCE_BUNDLE, $new($Logger$LoggerBundle, nullptr, nullptr));
	$assignStatic(Logger::treeLock, $new($Object));
	$assignStatic(Logger::global, $new(Logger, Logger::GLOBAL_LOGGER_NAME));
}

Logger::Logger() {
}

$Class* Logger::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Logger$$Lambda$lambda$findResourceBundle$0::classInfo$.name)) {
			return Logger$$Lambda$lambda$findResourceBundle$0::load$(name, initialize);
		}
	}
	$loadClass(Logger, name, initialize, &_Logger_ClassInfo_, clinit$Logger, allocate$Logger);
	return class$;
}

$Class* Logger::class$ = nullptr;

		} // logging
	} // util
} // java