#ifndef _java_util_logging_LogManager$3_h_
#define _java_util_logging_LogManager$3_h_
//$ class java.util.logging.LogManager$3
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace util {
		namespace logging {
			class LogManager;
			class Logger;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class LogManager$3 : public ::java::security::PrivilegedAction {
	$class(LogManager$3, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	LogManager$3();
	void init$(::java::util::logging::LogManager* this$0, ::java::util::logging::Logger* val$l, ::java::util::logging::Logger* val$sysLogger);
	virtual $Object* run() override;
	::java::util::logging::LogManager* this$0 = nullptr;
	::java::util::logging::Logger* val$sysLogger = nullptr;
	::java::util::logging::Logger* val$l = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LogManager$3_h_