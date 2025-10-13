#ifndef _java_util_logging_XMLFormatter_h_
#define _java_util_logging_XMLFormatter_h_
//$ class java.util.logging.XMLFormatter
//$ extends java.util.logging.Formatter

#include <java/util/logging/Formatter.h>

namespace java {
	namespace lang {
		class StringBuilder;
	}
}
namespace java {
	namespace util {
		namespace logging {
			class Handler;
			class LogManager;
			class LogRecord;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $export XMLFormatter : public ::java::util::logging::Formatter {
	$class(XMLFormatter, $NO_CLASS_INIT, ::java::util::logging::Formatter)
public:
	XMLFormatter();
	void init$();
	void a2(::java::lang::StringBuilder* sb, int32_t x);
	void appendISO8601(::java::lang::StringBuilder* sb, int64_t millis);
	void escape(::java::lang::StringBuilder* sb, $String* text);
	virtual $String* format(::java::util::logging::LogRecord* record) override;
	virtual $String* getHead(::java::util::logging::Handler* h) override;
	virtual $String* getTail(::java::util::logging::Handler* h) override;
	::java::util::logging::LogManager* manager = nullptr;
	bool useInstant = false;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_XMLFormatter_h_