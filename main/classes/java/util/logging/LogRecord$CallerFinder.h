#ifndef _java_util_logging_LogRecord$CallerFinder_h_
#define _java_util_logging_LogRecord$CallerFinder_h_
//$ class java.util.logging.LogRecord$CallerFinder
//$ extends java.util.function.Predicate

#include <java/util/function/Predicate.h>

#pragma push_macro("WALKER")
#undef WALKER

namespace java {
	namespace lang {
		class StackWalker;
		class StackWalker$StackFrame;
	}
}
namespace java {
	namespace util {
		class Optional;
	}
}
namespace java {
	namespace util {
		namespace stream {
			class Stream;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $export LogRecord$CallerFinder : public ::java::util::function::Predicate {
	$class(LogRecord$CallerFinder, 0, ::java::util::function::Predicate)
public:
	LogRecord$CallerFinder();
	void init$();
	::java::util::Optional* get();
	bool isLoggerImplFrame($String* cname);
	::java::util::Optional* lambda$get$1(::java::util::stream::Stream* s);
	static ::java::lang::StackWalker* lambda$static$0();
	bool test(::java::lang::StackWalker$StackFrame* t);
	virtual bool test(Object$* t) override;
	static ::java::lang::StackWalker* WALKER;
	bool lookingForLogger = false;
};

		} // logging
	} // util
} // java

#pragma pop_macro("WALKER")

#endif // _java_util_logging_LogRecord$CallerFinder_h_