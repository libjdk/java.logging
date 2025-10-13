#ifndef _java_util_logging_LogManager$1_h_
#define _java_util_logging_LogManager$1_h_
//$ class java.util.logging.LogManager$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace util {
		namespace logging {

class LogManager$1 : public ::java::security::PrivilegedAction {
	$class(LogManager$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	LogManager$1();
	void init$();
	virtual $Object* run() override;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LogManager$1_h_