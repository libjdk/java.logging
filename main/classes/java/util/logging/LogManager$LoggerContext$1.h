#ifndef _java_util_logging_LogManager$LoggerContext$1_h_
#define _java_util_logging_LogManager$LoggerContext$1_h_
//$ class java.util.logging.LogManager$LoggerContext$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace util {
		namespace logging {
			class LogManager;
			class LogManager$LoggerContext;
			class Logger;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class LogManager$LoggerContext$1 : public ::java::security::PrivilegedAction {
	$class(LogManager$LoggerContext$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	LogManager$LoggerContext$1();
	void init$(::java::util::logging::LogManager$LoggerContext* this$1, ::java::util::logging::Logger* val$logger, ::java::util::logging::LogManager* val$owner, $String* val$name);
	virtual $Object* run() override;
	::java::util::logging::LogManager$LoggerContext* this$1 = nullptr;
	$String* val$name = nullptr;
	::java::util::logging::LogManager* val$owner = nullptr;
	::java::util::logging::Logger* val$logger = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LogManager$LoggerContext$1_h_