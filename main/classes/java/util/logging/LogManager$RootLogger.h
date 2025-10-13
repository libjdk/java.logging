#ifndef _java_util_logging_LogManager$RootLogger_h_
#define _java_util_logging_LogManager$RootLogger_h_
//$ class java.util.logging.LogManager$RootLogger
//$ extends java.util.logging.Logger

#include <java/lang/Array.h>
#include <java/util/logging/Logger.h>

namespace java {
	namespace util {
		namespace logging {
			class Handler;
			class LogManager;
			class LogRecord;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class LogManager$RootLogger : public ::java::util::logging::Logger {
	$class(LogManager$RootLogger, $NO_CLASS_INIT, ::java::util::logging::Logger)
public:
	LogManager$RootLogger();
	void init$(::java::util::logging::LogManager* this$0);
	virtual $Array<::java::util::logging::Handler>* accessCheckedHandlers() override;
	virtual void addHandler(::java::util::logging::Handler* h) override;
	using ::java::util::logging::Logger::log;
	virtual void log(::java::util::logging::LogRecord* record) override;
	virtual void removeHandler(::java::util::logging::Handler* h) override;
	::java::util::logging::LogManager* this$0 = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LogManager$RootLogger_h_