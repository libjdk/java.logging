#ifndef _java_util_logging_Handler_h_
#define _java_util_logging_Handler_h_
//$ class java.util.logging.Handler
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		class Exception;
	}
}
namespace java {
	namespace util {
		namespace logging {
			class ErrorManager;
			class Filter;
			class Formatter;
			class Level;
			class LogManager;
			class LogRecord;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $export Handler : public ::java::lang::Object {
	$class(Handler, 0, ::java::lang::Object)
public:
	Handler();
	void init$();
	void init$(::java::util::logging::Level* defaultLevel, ::java::util::logging::Formatter* defaultFormatter, ::java::util::logging::Formatter* specifiedFormatter);
	virtual void checkPermission();
	virtual void close() {}
	virtual void flush() {}
	virtual $String* getEncoding();
	virtual ::java::util::logging::ErrorManager* getErrorManager();
	virtual ::java::util::logging::Filter* getFilter();
	virtual ::java::util::logging::Formatter* getFormatter();
	virtual ::java::util::logging::Level* getLevel();
	virtual bool isLoggable(::java::util::logging::LogRecord* record);
	virtual void publish(::java::util::logging::LogRecord* record) {}
	virtual void reportError($String* msg, ::java::lang::Exception* ex, int32_t code);
	virtual void setEncoding($String* encoding);
	virtual void setErrorManager(::java::util::logging::ErrorManager* em);
	virtual void setFilter(::java::util::logging::Filter* newFilter);
	virtual void setFormatter(::java::util::logging::Formatter* newFormatter);
	virtual void setLevel(::java::util::logging::Level* newLevel);
	static int32_t offValue;
	::java::util::logging::LogManager* manager = nullptr;
	$volatile(::java::util::logging::Filter*) filter = nullptr;
	$volatile(::java::util::logging::Formatter*) formatter = nullptr;
	$volatile(::java::util::logging::Level*) logLevel = nullptr;
	$volatile(::java::util::logging::ErrorManager*) errorManager = nullptr;
	$volatile($String*) encoding = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_Handler_h_