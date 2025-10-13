#ifndef _java_util_logging_LogManager$SystemLoggerContext_h_
#define _java_util_logging_LogManager$SystemLoggerContext_h_
//$ class java.util.logging.LogManager$SystemLoggerContext
//$ extends java.util.logging.LogManager$LoggerContext

#include <java/util/logging/LogManager$LoggerContext.h>

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

namespace java {
	namespace util {
		namespace logging {

class $export LogManager$SystemLoggerContext : public ::java::util::logging::LogManager$LoggerContext {
	$class(LogManager$SystemLoggerContext, $NO_CLASS_INIT, ::java::util::logging::LogManager$LoggerContext)
public:
	LogManager$SystemLoggerContext();
	void init$(::java::util::logging::LogManager* this$0);
	virtual ::java::util::logging::Logger* demandLogger($String* name, $String* resourceBundleName, ::java::lang::Module* module) override;
	::java::util::logging::LogManager* this$0 = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LogManager$SystemLoggerContext_h_