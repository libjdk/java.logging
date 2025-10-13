#ifndef _java_util_logging_Logger$SystemLoggerHelper_h_
#define _java_util_logging_Logger$SystemLoggerHelper_h_
//$ class java.util.logging.Logger$SystemLoggerHelper
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace util {
		namespace logging {

class Logger$SystemLoggerHelper : public ::java::lang::Object {
	$class(Logger$SystemLoggerHelper, 0, ::java::lang::Object)
public:
	Logger$SystemLoggerHelper();
	void init$();
	static bool getBooleanProperty($String* key);
	static bool disableCallerCheck;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_Logger$SystemLoggerHelper_h_