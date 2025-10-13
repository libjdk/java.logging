#ifndef _sun_util_logging_internal_LoggingProviderImpl$LogManagerAccess_h_
#define _sun_util_logging_internal_LoggingProviderImpl$LogManagerAccess_h_
//$ interface sun.util.logging.internal.LoggingProviderImpl$LogManagerAccess
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		class Module;
	}
}
namespace java {
	namespace util {
		namespace logging {
			class LogManager;
			class Logger;
		}
	}
}

namespace sun {
	namespace util {
		namespace logging {
			namespace internal {

class LoggingProviderImpl$LogManagerAccess : public ::java::lang::Object {
	$interface(LoggingProviderImpl$LogManagerAccess, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::java::util::logging::Logger* demandLoggerFor(::java::util::logging::LogManager* manager, $String* name, ::java::lang::Module* module) {return nullptr;}
};

			} // internal
		} // logging
	} // util
} // sun

#endif // _sun_util_logging_internal_LoggingProviderImpl$LogManagerAccess_h_