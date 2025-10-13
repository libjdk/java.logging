#ifndef _java_util_logging_LogManager$4_h_
#define _java_util_logging_LogManager$4_h_
//$ class java.util.logging.LogManager$4
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

class LogManager$4 : public ::java::security::PrivilegedAction {
	$class(LogManager$4, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	LogManager$4();
	void init$(::java::util::logging::LogManager* this$0, ::java::util::logging::Logger* val$logger, $String* val$name, $String* val$handlersPropertyName);
	virtual $Object* run() override;
	::java::util::logging::LogManager* this$0 = nullptr;
	$String* val$handlersPropertyName = nullptr;
	$String* val$name = nullptr;
	::java::util::logging::Logger* val$logger = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LogManager$4_h_