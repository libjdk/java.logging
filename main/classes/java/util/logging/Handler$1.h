#ifndef _java_util_logging_Handler$1_h_
#define _java_util_logging_Handler$1_h_
//$ class java.util.logging.Handler$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace util {
		namespace logging {
			class Filter;
			class Formatter;
			class Handler;
			class Level;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class Handler$1 : public ::java::security::PrivilegedAction {
	$class(Handler$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	Handler$1();
	void init$(::java::util::logging::Handler* this$0, ::java::util::logging::Level* val$level, ::java::util::logging::Filter* val$filter, ::java::util::logging::Formatter* val$formatter, $String* val$encoding);
	virtual $Object* run() override;
	::java::util::logging::Handler* this$0 = nullptr;
	$String* val$encoding = nullptr;
	::java::util::logging::Formatter* val$formatter = nullptr;
	::java::util::logging::Filter* val$filter = nullptr;
	::java::util::logging::Level* val$level = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_Handler$1_h_