#ifndef _java_util_logging_LogManager$Cleaner_h_
#define _java_util_logging_LogManager$Cleaner_h_
//$ class java.util.logging.LogManager$Cleaner
//$ extends java.lang.Thread

#include <java/lang/Thread.h>

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

class LogManager$Cleaner : public ::java::lang::Thread {
	$class(LogManager$Cleaner, $NO_CLASS_INIT, ::java::lang::Thread)
public:
	LogManager$Cleaner();
	void init$(::java::util::logging::LogManager* this$0);
	virtual void run() override;
	::java::util::logging::LogManager* this$0 = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LogManager$Cleaner_h_