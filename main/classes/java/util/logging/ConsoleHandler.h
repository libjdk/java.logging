#ifndef _java_util_logging_ConsoleHandler_h_
#define _java_util_logging_ConsoleHandler_h_
//$ class java.util.logging.ConsoleHandler
//$ extends java.util.logging.StreamHandler

#include <java/util/logging/StreamHandler.h>

namespace java {
	namespace util {
		namespace logging {
			class LogRecord;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $export ConsoleHandler : public ::java::util::logging::StreamHandler {
	$class(ConsoleHandler, $NO_CLASS_INIT, ::java::util::logging::StreamHandler)
public:
	ConsoleHandler();
	void init$();
	virtual void close() override;
	virtual void publish(::java::util::logging::LogRecord* record) override;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_ConsoleHandler_h_