#ifndef _java_util_logging_LogManager$2_h_
#define _java_util_logging_LogManager$2_h_
//$ class java.util.logging.LogManager$2
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace util {
		namespace logging {
			class LogManager;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class LogManager$2 : public ::java::security::PrivilegedAction {
	$class(LogManager$2, 0, ::java::security::PrivilegedAction)
public:
	LogManager$2();
	void init$(::java::util::logging::LogManager* this$0, ::java::util::logging::LogManager* val$owner);
	virtual $Object* run() override;
	::java::util::logging::LogManager* this$0 = nullptr;
	::java::util::logging::LogManager* val$owner = nullptr;
	static bool $assertionsDisabled;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LogManager$2_h_