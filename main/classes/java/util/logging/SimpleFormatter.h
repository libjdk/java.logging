#ifndef _java_util_logging_SimpleFormatter_h_
#define _java_util_logging_SimpleFormatter_h_
//$ class java.util.logging.SimpleFormatter
//$ extends java.util.logging.Formatter

#include <java/util/logging/Formatter.h>

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

class $export SimpleFormatter : public ::java::util::logging::Formatter {
	$class(SimpleFormatter, $NO_CLASS_INIT, ::java::util::logging::Formatter)
public:
	SimpleFormatter();
	void init$();
	virtual $String* format(::java::util::logging::LogRecord* record) override;
	static $String* getLoggingProperty($String* name);
	$String* format$ = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_SimpleFormatter_h_