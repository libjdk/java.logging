#ifndef _java_util_logging_LogManager$5_h_
#define _java_util_logging_LogManager$5_h_
//$ class java.util.logging.LogManager$5
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace util {
		namespace logging {
			class Level;
			class Logger;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class LogManager$5 : public ::java::security::PrivilegedAction {
	$class(LogManager$5, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	LogManager$5();
	void init$(::java::util::logging::Logger* val$logger, ::java::util::logging::Level* val$level);
	virtual $Object* run() override;
	::java::util::logging::Level* val$level = nullptr;
	::java::util::logging::Logger* val$logger = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LogManager$5_h_