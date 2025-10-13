#ifndef _sun_util_logging_internal_LoggingProviderImpl_h_
#define _sun_util_logging_internal_LoggingProviderImpl_h_
//$ class sun.util.logging.internal.LoggingProviderImpl
//$ extends jdk.internal.logger.DefaultLoggerFinder

#include <jdk/internal/logger/DefaultLoggerFinder.h>

#pragma push_macro("LOGGERFINDER_PERMISSION")
#undef LOGGERFINDER_PERMISSION
#pragma push_macro("LOGGING_CONTROL_PERMISSION")
#undef LOGGING_CONTROL_PERMISSION

namespace java {
	namespace lang {
		class Module;
		class RuntimePermission;
		class System$Logger;
	}
}
namespace java {
	namespace util {
		namespace logging {
			class LogManager;
			class Logger;
			class LoggingPermission;
		}
	}
}
namespace sun {
	namespace util {
		namespace logging {
			namespace internal {
				class LoggingProviderImpl$LogManagerAccess;
			}
		}
	}
}

namespace sun {
	namespace util {
		namespace logging {
			namespace internal {

class LoggingProviderImpl : public ::jdk::internal::logger::DefaultLoggerFinder {
	$class(LoggingProviderImpl, 0, ::jdk::internal::logger::DefaultLoggerFinder)
public:
	LoggingProviderImpl();
	void init$();
	static ::java::util::logging::Logger* demandJULLoggerFor($String* name, ::java::lang::Module* module);
	virtual ::java::lang::System$Logger* demandLoggerFor($String* name, ::java::lang::Module* module) override;
	static ::sun::util::logging::internal::LoggingProviderImpl$LogManagerAccess* getLogManagerAccess();
	static ::java::util::logging::Logger* lambda$demandJULLoggerFor$0(::java::util::logging::LogManager* manager, $String* name, ::java::lang::Module* module);
	static void setLogManagerAccess(::sun::util::logging::internal::LoggingProviderImpl$LogManagerAccess* accesLoggers);
	static ::java::lang::RuntimePermission* LOGGERFINDER_PERMISSION;
	static ::java::util::logging::LoggingPermission* LOGGING_CONTROL_PERMISSION;
	static $volatile(::sun::util::logging::internal::LoggingProviderImpl$LogManagerAccess*) logManagerAccess;
};

			} // internal
		} // logging
	} // util
} // sun

#pragma pop_macro("LOGGERFINDER_PERMISSION")
#pragma pop_macro("LOGGING_CONTROL_PERMISSION")

#endif // _sun_util_logging_internal_LoggingProviderImpl_h_