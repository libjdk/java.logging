#ifndef _java_util_logging_MemoryHandler_h_
#define _java_util_logging_MemoryHandler_h_
//$ class java.util.logging.MemoryHandler
//$ extends java.util.logging.Handler

#include <java/lang/Array.h>
#include <java/util/logging/Handler.h>

#pragma push_macro("DEFAULT_SIZE")
#undef DEFAULT_SIZE

namespace java {
	namespace util {
		namespace logging {
			class Level;
			class LogRecord;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $export MemoryHandler : public ::java::util::logging::Handler {
	$class(MemoryHandler, $NO_CLASS_INIT, ::java::util::logging::Handler)
public:
	MemoryHandler();
	void init$();
	void init$(::java::util::logging::Handler* target, int32_t size, ::java::util::logging::Level* pushLevel);
	virtual void close() override;
	virtual void flush() override;
	virtual ::java::util::logging::Level* getPushLevel();
	void init();
	virtual bool isLoggable(::java::util::logging::LogRecord* record) override;
	virtual void publish(::java::util::logging::LogRecord* record) override;
	virtual void push();
	virtual void setPushLevel(::java::util::logging::Level* newLevel);
	static const int32_t DEFAULT_SIZE = 1000;
	$volatile(::java::util::logging::Level*) pushLevel = nullptr;
	int32_t size = 0;
	::java::util::logging::Handler* target = nullptr;
	$Array<::java::util::logging::LogRecord>* buffer = nullptr;
	int32_t start = 0;
	int32_t count = 0;
};

		} // logging
	} // util
} // java

#pragma pop_macro("DEFAULT_SIZE")

#endif // _java_util_logging_MemoryHandler_h_