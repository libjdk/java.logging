#ifndef _java_util_logging_LoggingMXBean_h_
#define _java_util_logging_LoggingMXBean_h_
//$ interface java.util.logging.LoggingMXBean
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace util {
		class List;
	}
}

namespace java {
	namespace util {
		namespace logging {

class $export LoggingMXBean : public ::java::lang::Object {
	$interface(LoggingMXBean, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual $String* getLoggerLevel($String* loggerName) {return nullptr;}
	virtual ::java::util::List* getLoggerNames() {return nullptr;}
	virtual $String* getParentLoggerName($String* loggerName) {return nullptr;}
	virtual void setLoggerLevel($String* loggerName, $String* levelName) {}
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LoggingMXBean_h_