#ifndef _java_util_logging_LogManager$CloseOnReset_h_
#define _java_util_logging_LogManager$CloseOnReset_h_
//$ class java.util.logging.LogManager$CloseOnReset
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

class LogManager$CloseOnReset : public ::java::lang::Object {
	$class(LogManager$CloseOnReset, $NO_CLASS_INIT, ::java::lang::Object)
public:
	LogManager$CloseOnReset();
	void init$(::java::util::logging::Logger* ref);
	static ::java::util::logging::LogManager$CloseOnReset* create(::java::util::logging::Logger* logger);
	virtual bool equals(Object$* other) override;
	::java::util::logging::Logger* get();
	virtual int32_t hashCode() override;
	::java::util::logging::Logger* logger = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LogManager$CloseOnReset_h_