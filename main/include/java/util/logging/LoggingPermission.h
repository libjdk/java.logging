#ifndef _java_util_logging_LoggingPermission_h_
#define _java_util_logging_LoggingPermission_h_
//$ class java.util.logging.LoggingPermission
//$ extends java.security.BasicPermission

#include <java/security/BasicPermission.h>

namespace java {
	namespace util {
		namespace logging {

class $import LoggingPermission : public ::java::security::BasicPermission {
	$class(LoggingPermission, $NO_CLASS_INIT, ::java::security::BasicPermission)
public:
	LoggingPermission();
	void init$($String* name, $String* actions);
	static const int64_t serialVersionUID = (int64_t)0x00E1D36E9045739E;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LoggingPermission_h_