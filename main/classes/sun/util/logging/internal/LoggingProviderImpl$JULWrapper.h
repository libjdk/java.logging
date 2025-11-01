#ifndef _sun_util_logging_internal_LoggingProviderImpl$JULWrapper_h_
#define _sun_util_logging_internal_LoggingProviderImpl$JULWrapper_h_
//$ class sun.util.logging.internal.LoggingProviderImpl$JULWrapper
//$ extends sun.util.logging.PlatformLogger$ConfigurableBridge$LoggerConfiguration
//$ implements java.lang.System$Logger,sun.util.logging.PlatformLogger$Bridge,sun.util.logging.PlatformLogger$ConfigurableBridge

#include <java/lang/Array.h>
#include <java/lang/System$Logger.h>
#include <sun/util/logging/PlatformLogger$Bridge.h>
#include <sun/util/logging/PlatformLogger$ConfigurableBridge$LoggerConfiguration.h>
#include <sun/util/logging/PlatformLogger$ConfigurableBridge.h>

namespace java {
	namespace lang {
		class System$Logger$Level;
		class Throwable;
	}
}
namespace java {
	namespace util {
		class ResourceBundle;
	}
}
namespace java {
	namespace util {
		namespace function {
			class Supplier;
		}
	}
}
namespace java {
	namespace util {
		namespace logging {
			class Level;
			class Logger;
		}
	}
}
namespace sun {
	namespace util {
		namespace logging {
			class PlatformLogger$Level;
		}
	}
}

namespace sun {
	namespace util {
		namespace logging {
			namespace internal {

class LoggingProviderImpl$JULWrapper : public ::sun::util::logging::PlatformLogger$ConfigurableBridge$LoggerConfiguration, public ::java::lang::System$Logger, public ::sun::util::logging::PlatformLogger$Bridge, public ::sun::util::logging::PlatformLogger$ConfigurableBridge {
	$class(LoggingProviderImpl$JULWrapper, 0, ::sun::util::logging::PlatformLogger$ConfigurableBridge$LoggerConfiguration, ::java::lang::System$Logger, ::sun::util::logging::PlatformLogger$Bridge, ::sun::util::logging::PlatformLogger$ConfigurableBridge)
public:
	LoggingProviderImpl$JULWrapper();
	virtual $Object* clone() override;
	virtual void finalize() override;
	void init$(::java::util::logging::Logger* logger);
	virtual bool equals(Object$* obj) override;
	virtual ::sun::util::logging::PlatformLogger$ConfigurableBridge$LoggerConfiguration* getLoggerConfiguration() override;
	virtual $String* getName() override;
	virtual ::sun::util::logging::PlatformLogger$Level* getPlatformLevel() override;
	virtual int32_t hashCode() override;
	virtual bool isEnabled() override;
	virtual bool isLoggable(::sun::util::logging::PlatformLogger$Level* level) override;
	virtual bool isLoggable(::java::lang::System$Logger$Level* level) override;
	static $String* lambda$log$0(Object$* obj);
	virtual void log(::sun::util::logging::PlatformLogger$Level* level, $String* msg, $Throwable* throwable) override;
	virtual void log(::sun::util::logging::PlatformLogger$Level* level, $String* format, $ObjectArray* params) override;
	virtual void log(::sun::util::logging::PlatformLogger$Level* level, $String* msg) override;
	virtual void log(::sun::util::logging::PlatformLogger$Level* level, ::java::util::function::Supplier* msgSuppier) override;
	virtual void log(::sun::util::logging::PlatformLogger$Level* level, $Throwable* thrown, ::java::util::function::Supplier* msgSuppier) override;
	virtual void log(::java::lang::System$Logger$Level* level, $String* msg) override;
	virtual void log(::java::lang::System$Logger$Level* level, ::java::util::function::Supplier* msgSupplier) override;
	virtual void log(::java::lang::System$Logger$Level* level, Object$* obj) override;
	virtual void log(::java::lang::System$Logger$Level* level, $String* msg, $Throwable* thrown) override;
	virtual void log(::java::lang::System$Logger$Level* level, ::java::util::function::Supplier* msgSupplier, $Throwable* thrown) override;
	virtual void log(::java::lang::System$Logger$Level* level, $String* format, $ObjectArray* params) override;
	virtual void log(::java::lang::System$Logger$Level* level, ::java::util::ResourceBundle* bundle, $String* key, $Throwable* thrown) override;
	virtual void log(::java::lang::System$Logger$Level* level, ::java::util::ResourceBundle* bundle, $String* format, $ObjectArray* params) override;
	virtual void logp(::sun::util::logging::PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $String* msg) override;
	virtual void logp(::sun::util::logging::PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, ::java::util::function::Supplier* msgSupplier) override;
	virtual void logp(::sun::util::logging::PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $String* msg, $ObjectArray* params) override;
	virtual void logp(::sun::util::logging::PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $String* msg, $Throwable* thrown) override;
	virtual void logp(::sun::util::logging::PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, $Throwable* thrown, ::java::util::function::Supplier* msgSupplier) override;
	virtual void logrb(::sun::util::logging::PlatformLogger$Level* level, ::java::util::ResourceBundle* bundle, $String* key, $Throwable* throwable) override;
	virtual void logrb(::sun::util::logging::PlatformLogger$Level* level, ::java::util::ResourceBundle* bundle, $String* key, $ObjectArray* params) override;
	virtual void logrb(::sun::util::logging::PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, ::java::util::ResourceBundle* bundle, $String* key, $ObjectArray* params) override;
	virtual void logrb(::sun::util::logging::PlatformLogger$Level* level, $String* sourceClass, $String* sourceMethod, ::java::util::ResourceBundle* bundle, $String* key, $Throwable* thrown) override;
	static ::sun::util::logging::internal::LoggingProviderImpl$JULWrapper* of(::java::util::logging::Logger* logger);
	virtual void setPlatformLevel(::sun::util::logging::PlatformLogger$Level* level) override;
	static ::java::util::logging::Level* toJUL(::java::lang::System$Logger$Level* level);
	static ::java::util::logging::Level* toJUL(::sun::util::logging::PlatformLogger$Level* level);
	virtual $String* toString() override;
	static bool $assertionsDisabled;
	static $Array<::java::util::logging::Level>* spi2JulLevelMapping;
	static $Array<::java::util::logging::Level>* platform2JulLevelMapping;
	::java::util::logging::Logger* julLogger = nullptr;
};

			} // internal
		} // logging
	} // util
} // sun

#endif // _sun_util_logging_internal_LoggingProviderImpl$JULWrapper_h_