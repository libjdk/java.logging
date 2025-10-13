#ifndef _java_util_logging_Filter_h_
#define _java_util_logging_Filter_h_
//$ interface java.util.logging.Filter
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

class $export Filter : public ::java::lang::Object {
	$interface(Filter, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual bool isLoggable(::java::util::logging::LogRecord* record) {return false;}
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_Filter_h_