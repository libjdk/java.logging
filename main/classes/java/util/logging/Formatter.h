#ifndef _java_util_logging_Formatter_h_
#define _java_util_logging_Formatter_h_
//$ class java.util.logging.Formatter
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace util {
		namespace logging {
			class Handler;
			class LogRecord;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $export Formatter : public ::java::lang::Object {
	$class(Formatter, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Formatter();
	void init$();
	virtual $String* format(::java::util::logging::LogRecord* record) {return nullptr;}
	virtual $String* formatMessage(::java::util::logging::LogRecord* record);
	virtual $String* getHead(::java::util::logging::Handler* h);
	virtual $String* getTail(::java::util::logging::Handler* h);
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_Formatter_h_