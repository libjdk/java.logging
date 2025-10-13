#ifndef _java_util_logging_ErrorManager_h_
#define _java_util_logging_ErrorManager_h_
//$ class java.util.logging.ErrorManager
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("CLOSE_FAILURE")
#undef CLOSE_FAILURE
#pragma push_macro("FLUSH_FAILURE")
#undef FLUSH_FAILURE
#pragma push_macro("FORMAT_FAILURE")
#undef FORMAT_FAILURE
#pragma push_macro("GENERIC_FAILURE")
#undef GENERIC_FAILURE
#pragma push_macro("OPEN_FAILURE")
#undef OPEN_FAILURE
#pragma push_macro("WRITE_FAILURE")
#undef WRITE_FAILURE

namespace java {
	namespace lang {
		class Exception;
	}
}

namespace java {
	namespace util {
		namespace logging {

class $import ErrorManager : public ::java::lang::Object {
	$class(ErrorManager, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ErrorManager();
	void init$();
	virtual void error($String* msg, ::java::lang::Exception* ex, int32_t code);
	bool reported = false;
	static const int32_t GENERIC_FAILURE = 0;
	static const int32_t WRITE_FAILURE = 1;
	static const int32_t FLUSH_FAILURE = 2;
	static const int32_t CLOSE_FAILURE = 3;
	static const int32_t OPEN_FAILURE = 4;
	static const int32_t FORMAT_FAILURE = 5;
};

		} // logging
	} // util
} // java

#pragma pop_macro("CLOSE_FAILURE")
#pragma pop_macro("FLUSH_FAILURE")
#pragma pop_macro("FORMAT_FAILURE")
#pragma pop_macro("GENERIC_FAILURE")
#pragma pop_macro("OPEN_FAILURE")
#pragma pop_macro("WRITE_FAILURE")

#endif // _java_util_logging_ErrorManager_h_