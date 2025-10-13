#ifndef _java_util_logging_Logging_h_
#define _java_util_logging_Logging_h_
//$ class java.util.logging.Logging
//$ extends java.util.logging.LoggingMXBean

#include <java/util/logging/LoggingMXBean.h>

#pragma push_macro("EMPTY_STRING")
#undef EMPTY_STRING
#pragma push_macro("INSTANCE")
#undef INSTANCE

namespace java {
	namespace util {
		class List;
	}
}
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

class Logging : public ::java::util::logging::LoggingMXBean {
	$class(Logging, 0, ::java::util::logging::LoggingMXBean)
public:
	Logging();
	void init$();
	static ::java::util::logging::Logging* getInstance();
	virtual $String* getLoggerLevel($String* loggerName) override;
	virtual ::java::util::List* getLoggerNames() override;
	virtual $String* getParentLoggerName($String* loggerName) override;
	virtual void setLoggerLevel($String* loggerName, $String* levelName) override;
	static ::java::util::logging::LogManager* logManager;
	static $String* EMPTY_STRING;
	static ::java::util::logging::Logging* INSTANCE;
};

		} // logging
	} // util
} // java

#pragma pop_macro("EMPTY_STRING")
#pragma pop_macro("INSTANCE")

#endif // _java_util_logging_Logging_h_