#ifndef _java_util_logging_LogManager$VisitedLoggers_h_
#define _java_util_logging_LogManager$VisitedLoggers_h_
//$ class java.util.logging.LogManager$VisitedLoggers
//$ extends java.util.function.Predicate

#include <java/util/function/Predicate.h>

#pragma push_macro("NEVER")
#undef NEVER

namespace java {
	namespace util {
		class IdentityHashMap;
	}
}
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

class $import LogManager$VisitedLoggers : public ::java::util::function::Predicate {
	$class(LogManager$VisitedLoggers, 0, ::java::util::function::Predicate)
public:
	LogManager$VisitedLoggers();
	void init$(::java::util::IdentityHashMap* visited);
	void init$();
	void clear();
	bool test(::java::util::logging::Logger* logger);
	virtual bool test(Object$* logger) override;
	::java::util::IdentityHashMap* visited = nullptr;
	static ::java::util::logging::LogManager$VisitedLoggers* NEVER;
};

		} // logging
	} // util
} // java

#pragma pop_macro("NEVER")

#endif // _java_util_logging_LogManager$VisitedLoggers_h_