#ifndef _java_util_logging_Logger$SystemLoggerHelper$1_h_
#define _java_util_logging_Logger$SystemLoggerHelper$1_h_
//$ class java.util.logging.Logger$SystemLoggerHelper$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace util {
		namespace logging {

class Logger$SystemLoggerHelper$1 : public ::java::security::PrivilegedAction {
	$class(Logger$SystemLoggerHelper$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	Logger$SystemLoggerHelper$1();
	void init$($String* val$key);
	virtual $Object* run() override;
	$String* val$key = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_Logger$SystemLoggerHelper$1_h_