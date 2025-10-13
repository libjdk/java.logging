#ifndef _java_util_logging_Level$RbAccess_h_
#define _java_util_logging_Level$RbAccess_h_
//$ class java.util.logging.Level$RbAccess
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("RB_ACCESS")
#undef RB_ACCESS

namespace jdk {
	namespace internal {
		namespace access {
			class JavaUtilResourceBundleAccess;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class Level$RbAccess : public ::java::lang::Object {
	$class(Level$RbAccess, 0, ::java::lang::Object)
public:
	Level$RbAccess();
	void init$();
	static ::jdk::internal::access::JavaUtilResourceBundleAccess* RB_ACCESS;
};

		} // logging
	} // util
} // java

#pragma pop_macro("RB_ACCESS")

#endif // _java_util_logging_Level$RbAccess_h_