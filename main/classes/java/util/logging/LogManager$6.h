#ifndef _java_util_logging_LogManager$6_h_
#define _java_util_logging_LogManager$6_h_
//$ class java.util.logging.LogManager$6
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace util {
		namespace logging {
			class Logger;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class LogManager$6 : public ::java::security::PrivilegedAction {
	$class(LogManager$6, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	LogManager$6();
	void init$(::java::util::logging::Logger* val$logger, ::java::util::logging::Logger* val$parent);
	virtual $Object* run() override;
	::java::util::logging::Logger* val$parent = nullptr;
	::java::util::logging::Logger* val$logger = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LogManager$6_h_