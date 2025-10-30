#include <sun/util/logging/internal/LoggingProviderImpl$JULWrapper.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/System$Logger$Level.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Objects.h>
#include <java/util/ResourceBundle.h>
#include <java/util/function/Supplier.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/Logger.h>
#include <sun/util/logging/PlatformLogger$ConfigurableBridge$LoggerConfiguration.h>
#include <sun/util/logging/PlatformLogger$Level.h>
#include <sun/util/logging/internal/LoggingProviderImpl.h>
#include <jcpp.h>

#undef ALL
#undef CONFIG
#undef FINE
#undef FINER
#undef FINEST
#undef INFO
#undef OFF
#undef SEVERE
#undef WARNING

using $LevelArray = $Array<::java::util::logging::Level>;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $System$Logger = ::java::lang::System$Logger;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Objects = ::java::util::Objects;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Supplier = ::java::util::function::Supplier;
using $Level = ::java::util::logging::Level;
using $Logger = ::java::util::logging::Logger;
using $PlatformLogger$Bridge = ::sun::util::logging::PlatformLogger$Bridge;
using $PlatformLogger$ConfigurableBridge = ::sun::util::logging::PlatformLogger$ConfigurableBridge;
using $PlatformLogger$ConfigurableBridge$LoggerConfiguration = ::sun::util::logging::PlatformLogger$ConfigurableBridge$LoggerConfiguration;
using $PlatformLogger$Level = ::sun::util::logging::PlatformLogger$Level;
using $LoggingProviderImpl = ::sun::util::logging::internal::LoggingProviderImpl;

namespace sun {
	namespace util {
		namespace logging {
			namespace internal {

class LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0 : public $Supplier {
	$class(LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Object$* obj) {
		$set(this, obj, obj);
	}
	virtual $Object* get() override {
		 return $of(LoggingProviderImpl$JULWrapper::lambda$log$0(obj));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0>());
	}
	$Object* obj = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0::fieldInfos[2] = {
	{"obj", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0, obj)},
	{}
};
$MethodInfo LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(static_cast<void(LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0::*)(Object$*)>(&LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"sun.util.logging.internal.LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0::load$($String* name, bool initialize) {
	$loadClass(LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0::class$ = nullptr;

$FieldInfo _LoggingProviderImpl$JULWrapper_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(LoggingProviderImpl$JULWrapper, $assertionsDisabled)},
	{"spi2JulLevelMapping", "[Ljava/util/logging/Level;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LoggingProviderImpl$JULWrapper, spi2JulLevelMapping)},
	{"platform2JulLevelMapping", "[Ljava/util/logging/Level;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LoggingProviderImpl$JULWrapper, platform2JulLevelMapping)},
	{"julLogger", "Ljava/util/logging/Logger;", nullptr, $PRIVATE | $FINAL, $field(LoggingProviderImpl$JULWrapper, julLogger)},
	{}
};

$MethodInfo _LoggingProviderImpl$JULWrapper_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/util/logging/Logger;)V", nullptr, $PRIVATE, $method(static_cast<void(LoggingProviderImpl$JULWrapper::*)($Logger*)>(&LoggingProviderImpl$JULWrapper::init$))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getLoggerConfiguration", "()Lsun/util/logging/PlatformLogger$ConfigurableBridge$LoggerConfiguration;", nullptr, $PUBLIC},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getPlatformLevel", "()Lsun/util/logging/PlatformLogger$Level;", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"isEnabled", "()Z", nullptr, $PUBLIC},
	{"isLoggable", "(Lsun/util/logging/PlatformLogger$Level;)Z", nullptr, $PUBLIC},
	{"isLoggable", "(Ljava/lang/System$Logger$Level;)Z", nullptr, $PUBLIC},
	{"lambda$log$0", "(Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)(Object$*)>(&LoggingProviderImpl$JULWrapper::lambda$log$0))},
	{"log", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"log", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT},
	{"log", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"log", "(Lsun/util/logging/PlatformLogger$Level;Ljava/util/function/Supplier;)V", "(Lsun/util/logging/PlatformLogger$Level;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"log", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/Throwable;Ljava/util/function/Supplier;)V", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/Throwable;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/util/function/Supplier;)V", "(Ljava/lang/System$Logger$Level;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/util/function/Supplier;Ljava/lang/Throwable;)V", "(Ljava/lang/System$Logger$Level;Ljava/util/function/Supplier<Ljava/lang/String;>;Ljava/lang/Throwable;)V", $PUBLIC},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/util/ResourceBundle;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/util/ResourceBundle;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT},
	{"logp", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"logp", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/function/Supplier;)V", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"logp", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT},
	{"logp", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"logp", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;Ljava/util/function/Supplier;)V", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/lang/Throwable;Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC},
	{"logrb", "(Lsun/util/logging/PlatformLogger$Level;Ljava/util/ResourceBundle;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"logrb", "(Lsun/util/logging/PlatformLogger$Level;Ljava/util/ResourceBundle;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT},
	{"logrb", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/ResourceBundle;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT},
	{"logrb", "(Lsun/util/logging/PlatformLogger$Level;Ljava/lang/String;Ljava/lang/String;Ljava/util/ResourceBundle;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"of", "(Ljava/util/logging/Logger;)Lsun/util/logging/internal/LoggingProviderImpl$JULWrapper;", nullptr, $STATIC, $method(static_cast<LoggingProviderImpl$JULWrapper*(*)($Logger*)>(&LoggingProviderImpl$JULWrapper::of))},
	{"setPlatformLevel", "(Lsun/util/logging/PlatformLogger$Level;)V", nullptr, $PUBLIC},
	{"toJUL", "(Ljava/lang/System$Logger$Level;)Ljava/util/logging/Level;", nullptr, $STATIC, $method(static_cast<$Level*(*)($System$Logger$Level*)>(&LoggingProviderImpl$JULWrapper::toJUL))},
	{"toJUL", "(Lsun/util/logging/PlatformLogger$Level;)Ljava/util/logging/Level;", nullptr, $STATIC, $method(static_cast<$Level*(*)($PlatformLogger$Level*)>(&LoggingProviderImpl$JULWrapper::toJUL))},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _LoggingProviderImpl$JULWrapper_InnerClassesInfo_[] = {
	{"sun.util.logging.internal.LoggingProviderImpl$JULWrapper", "sun.util.logging.internal.LoggingProviderImpl", "JULWrapper", $STATIC | $FINAL},
	{"sun.util.logging.PlatformLogger$ConfigurableBridge", "sun.util.logging.PlatformLogger", "ConfigurableBridge", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.util.logging.PlatformLogger$ConfigurableBridge$LoggerConfiguration", "sun.util.logging.PlatformLogger$ConfigurableBridge", "LoggerConfiguration", $PUBLIC | $STATIC | $ABSTRACT},
	{"java.lang.System$Logger", "java.lang.System", "Logger", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"sun.util.logging.PlatformLogger$Bridge", "sun.util.logging.PlatformLogger", "Bridge", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _LoggingProviderImpl$JULWrapper_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"sun.util.logging.internal.LoggingProviderImpl$JULWrapper",
	"sun.util.logging.PlatformLogger$ConfigurableBridge$LoggerConfiguration",
	"java.lang.System$Logger,sun.util.logging.PlatformLogger$Bridge,sun.util.logging.PlatformLogger$ConfigurableBridge",
	_LoggingProviderImpl$JULWrapper_FieldInfo_,
	_LoggingProviderImpl$JULWrapper_MethodInfo_,
	nullptr,
	nullptr,
	_LoggingProviderImpl$JULWrapper_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.util.logging.internal.LoggingProviderImpl"
};

$Object* allocate$LoggingProviderImpl$JULWrapper($Class* clazz) {
	return $of($alloc(LoggingProviderImpl$JULWrapper));
}

$Object* LoggingProviderImpl$JULWrapper::clone() {
	 return this->$PlatformLogger$ConfigurableBridge$LoggerConfiguration::clone();
}

$String* LoggingProviderImpl$JULWrapper::toString() {
	 return this->$PlatformLogger$ConfigurableBridge$LoggerConfiguration::toString();
}

void LoggingProviderImpl$JULWrapper::finalize() {
	this->$PlatformLogger$ConfigurableBridge$LoggerConfiguration::finalize();
}

bool LoggingProviderImpl$JULWrapper::$assertionsDisabled = false;
$LevelArray* LoggingProviderImpl$JULWrapper::spi2JulLevelMapping = nullptr;
$LevelArray* LoggingProviderImpl$JULWrapper::platform2JulLevelMapping = nullptr;

void LoggingProviderImpl$JULWrapper::init$($Logger* logger) {
	$PlatformLogger$ConfigurableBridge$LoggerConfiguration::init$();
	$set(this, julLogger, logger);
}

$String* LoggingProviderImpl$JULWrapper::getName() {
	return $nc(this->julLogger)->getName();
}

void LoggingProviderImpl$JULWrapper::log($PlatformLogger$Level* level, $String* msg, $Throwable* throwable) {
	$nc(this->julLogger)->log($(toJUL(level)), msg, throwable);
}

void LoggingProviderImpl$JULWrapper::log($PlatformLogger$Level* level, $String* format, $ObjectArray* params) {
	$nc(this->julLogger)->log($(toJUL(level)), format, params);
}

void LoggingProviderImpl$JULWrapper::log($PlatformLogger$Level* level, $String* msg) {
	$nc(this->julLogger)->log($(toJUL(level)), msg);
}

void LoggingProviderImpl$JULWrapper::log($PlatformLogger$Level* level, $Supplier* msgSuppier) {
	$nc(this->julLogger)->log($(toJUL(level)), msgSuppier);
}

void LoggingProviderImpl$JULWrapper::log($PlatformLogger$Level* level, $Throwable* thrown, $Supplier* msgSuppier) {
	$nc(this->julLogger)->log($(toJUL(level)), thrown, msgSuppier);
}

void LoggingProviderImpl$JULWrapper::logrb($PlatformLogger$Level* level, $ResourceBundle* bundle, $String* key, $Throwable* throwable) {
	$nc(this->julLogger)->logrb($(toJUL(level)), bundle, key, throwable);
}

void LoggingProviderImpl$JULWrapper::logrb($PlatformLogger$Level* level, $ResourceBundle* bundle, $String* key, $ObjectArray* params) {
	$nc(this->julLogger)->logrb($(toJUL(level)), bundle, key, params);
}

void LoggingProviderImpl$JULWrapper::logp($PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $String* msg) {
	$nc(this->julLogger)->logp($(toJUL(level)), sourceClass, sourceMethod, msg);
}

void LoggingProviderImpl$JULWrapper::logp($PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $Supplier* msgSupplier) {
	$nc(this->julLogger)->logp($(toJUL(level)), sourceClass, sourceMethod, msgSupplier);
}

void LoggingProviderImpl$JULWrapper::logp($PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $String* msg, $ObjectArray* params) {
	$nc(this->julLogger)->logp($(toJUL(level)), sourceClass, sourceMethod, msg, params);
}

void LoggingProviderImpl$JULWrapper::logp($PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $String* msg, $Throwable* thrown) {
	$nc(this->julLogger)->logp($(toJUL(level)), sourceClass, sourceMethod, msg, thrown);
}

void LoggingProviderImpl$JULWrapper::logp($PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $Throwable* thrown, $Supplier* msgSupplier) {
	$nc(this->julLogger)->logp($(toJUL(level)), sourceClass, sourceMethod, thrown, msgSupplier);
}

void LoggingProviderImpl$JULWrapper::logrb($PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $ResourceBundle* bundle, $String* key, $ObjectArray* params) {
	$nc(this->julLogger)->logrb($(toJUL(level)), sourceClass, sourceMethod, bundle, key, params);
}

void LoggingProviderImpl$JULWrapper::logrb($PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $ResourceBundle* bundle, $String* key, $Throwable* thrown) {
	$nc(this->julLogger)->logrb($(toJUL(level)), sourceClass, sourceMethod, bundle, key, thrown);
}

bool LoggingProviderImpl$JULWrapper::isLoggable($PlatformLogger$Level* level) {
	return $nc(this->julLogger)->isLoggable($(toJUL(level)));
}

bool LoggingProviderImpl$JULWrapper::isLoggable($System$Logger$Level* level) {
	return $nc(this->julLogger)->isLoggable($(toJUL(level)));
}

void LoggingProviderImpl$JULWrapper::log($System$Logger$Level* level, $String* msg) {
	$nc(this->julLogger)->log($(toJUL(level)), msg);
}

void LoggingProviderImpl$JULWrapper::log($System$Logger$Level* level, $Supplier* msgSupplier) {
	$Objects::requireNonNull(msgSupplier);
	$nc(this->julLogger)->log($(toJUL(level)), msgSupplier);
}

void LoggingProviderImpl$JULWrapper::log($System$Logger$Level* level, Object$* obj) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(obj);
	$var($Level, var$0, toJUL(level));
	$nc(this->julLogger)->log(var$0, static_cast<$Supplier*>($$new(LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0, obj)));
}

void LoggingProviderImpl$JULWrapper::log($System$Logger$Level* level, $String* msg, $Throwable* thrown) {
	$nc(this->julLogger)->log($(toJUL(level)), msg, thrown);
}

void LoggingProviderImpl$JULWrapper::log($System$Logger$Level* level, $Supplier* msgSupplier, $Throwable* thrown) {
	$Objects::requireNonNull(msgSupplier);
	$nc(this->julLogger)->log($(toJUL(level)), thrown, msgSupplier);
}

void LoggingProviderImpl$JULWrapper::log($System$Logger$Level* level, $String* format, $ObjectArray* params) {
	$nc(this->julLogger)->log($(toJUL(level)), format, params);
}

void LoggingProviderImpl$JULWrapper::log($System$Logger$Level* level, $ResourceBundle* bundle, $String* key, $Throwable* thrown) {
	$nc(this->julLogger)->logrb($(toJUL(level)), bundle, key, thrown);
}

void LoggingProviderImpl$JULWrapper::log($System$Logger$Level* level, $ResourceBundle* bundle, $String* format, $ObjectArray* params) {
	$nc(this->julLogger)->logrb($(toJUL(level)), bundle, format, params);
}

$Level* LoggingProviderImpl$JULWrapper::toJUL($System$Logger$Level* level) {
	$init(LoggingProviderImpl$JULWrapper);
	if (level == nullptr) {
		return nullptr;
	}
	if (!LoggingProviderImpl$JULWrapper::$assertionsDisabled && !($nc(level)->ordinal() < $nc(LoggingProviderImpl$JULWrapper::spi2JulLevelMapping)->length)) {
		$throwNew($AssertionError);
	}
	return $nc(LoggingProviderImpl$JULWrapper::spi2JulLevelMapping)->get($nc(level)->ordinal());
}

bool LoggingProviderImpl$JULWrapper::isEnabled() {
	$init($Level);
	return $nc(this->julLogger)->getLevel() != $Level::OFF;
}

$PlatformLogger$Level* LoggingProviderImpl$JULWrapper::getPlatformLevel() {
	$useLocalCurrentObjectStackCache();
	$var($Level, javaLevel, $nc(this->julLogger)->getLevel());
	if (javaLevel == nullptr) {
		return nullptr;
	}
	try {
		return $PlatformLogger$Level::valueOf($($nc(javaLevel)->getName()));
	} catch ($IllegalArgumentException& e) {
		return $PlatformLogger$Level::valueOf($nc(javaLevel)->intValue());
	}
	$shouldNotReachHere();
}

void LoggingProviderImpl$JULWrapper::setPlatformLevel($PlatformLogger$Level* level) {
	$nc(this->julLogger)->setLevel($(toJUL(level)));
}

$PlatformLogger$ConfigurableBridge$LoggerConfiguration* LoggingProviderImpl$JULWrapper::getLoggerConfiguration() {
	return this;
}

$Level* LoggingProviderImpl$JULWrapper::toJUL($PlatformLogger$Level* level) {
	$init(LoggingProviderImpl$JULWrapper);
	if (level == nullptr) {
		return nullptr;
	}
	if (!LoggingProviderImpl$JULWrapper::$assertionsDisabled && !($nc(level)->ordinal() < $nc(LoggingProviderImpl$JULWrapper::platform2JulLevelMapping)->length)) {
		$throwNew($AssertionError);
	}
	return $nc(LoggingProviderImpl$JULWrapper::platform2JulLevelMapping)->get($nc(level)->ordinal());
}

bool LoggingProviderImpl$JULWrapper::equals(Object$* obj) {
	bool var$0 = ($instanceOf(LoggingProviderImpl$JULWrapper, obj));
	if (var$0) {
		var$0 = $nc($of(obj))->getClass() == $of(this)->getClass();
	}
	return var$0 && $nc(($cast(LoggingProviderImpl$JULWrapper, obj)))->julLogger == this->julLogger;
}

int32_t LoggingProviderImpl$JULWrapper::hashCode() {
	return $nc($of(this->julLogger))->hashCode();
}

LoggingProviderImpl$JULWrapper* LoggingProviderImpl$JULWrapper::of($Logger* logger) {
	$init(LoggingProviderImpl$JULWrapper);
	return $new(LoggingProviderImpl$JULWrapper, logger);
}

$String* LoggingProviderImpl$JULWrapper::lambda$log$0(Object$* obj) {
	$init(LoggingProviderImpl$JULWrapper);
	return $nc($of(obj))->toString();
}

void clinit$LoggingProviderImpl$JULWrapper($Class* class$) {
	$load($LoggingProviderImpl);
	LoggingProviderImpl$JULWrapper::$assertionsDisabled = !$LoggingProviderImpl::class$->desiredAssertionStatus();
	$init($Level);
	$assignStatic(LoggingProviderImpl$JULWrapper::spi2JulLevelMapping, $new($LevelArray, {
		$Level::ALL,
		$Level::FINER,
		$Level::FINE,
		$Level::INFO,
		$Level::WARNING,
		$Level::SEVERE,
		$Level::OFF
	}));
	$assignStatic(LoggingProviderImpl$JULWrapper::platform2JulLevelMapping, $new($LevelArray, {
		$Level::ALL,
		$Level::FINEST,
		$Level::FINER,
		$Level::FINE,
		$Level::CONFIG,
		$Level::INFO,
		$Level::WARNING,
		$Level::SEVERE,
		$Level::OFF
	}));
}

LoggingProviderImpl$JULWrapper::LoggingProviderImpl$JULWrapper() {
}

$Class* LoggingProviderImpl$JULWrapper::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0::classInfo$.name)) {
			return LoggingProviderImpl$JULWrapper$$Lambda$lambda$log$0::load$(name, initialize);
		}
	}
	$loadClass(LoggingProviderImpl$JULWrapper, name, initialize, &_LoggingProviderImpl$JULWrapper_ClassInfo_, clinit$LoggingProviderImpl$JULWrapper, allocate$LoggingProviderImpl$JULWrapper);
	return class$;
}

$Class* LoggingProviderImpl$JULWrapper::class$ = nullptr;

			} // internal
		} // logging
	} // util
} // sun