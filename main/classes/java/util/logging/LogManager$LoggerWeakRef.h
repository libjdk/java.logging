#ifndef _java_util_logging_LogManager$LoggerWeakRef_h_
#define _java_util_logging_LogManager$LoggerWeakRef_h_
//$ class java.util.logging.LogManager$LoggerWeakRef
//$ extends java.lang.ref.WeakReference

#include <java/lang/ref/WeakReference.h>

namespace java {
	namespace util {
		namespace logging {
			class LogManager;
			class LogManager$LogNode;
			class Logger;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $export LogManager$LoggerWeakRef : public ::java::lang::ref::WeakReference {
	$class(LogManager$LoggerWeakRef, $NO_CLASS_INIT, ::java::lang::ref::WeakReference)
public:
	LogManager$LoggerWeakRef();
	void init$(::java::util::logging::LogManager* this$0, ::java::util::logging::Logger* logger);
	void dispose();
	void setNode(::java::util::logging::LogManager$LogNode* node);
	void setParentRef(::java::lang::ref::WeakReference* parentRef);
	::java::util::logging::LogManager* this$0 = nullptr;
	$String* name = nullptr;
	::java::util::logging::LogManager$LogNode* node = nullptr;
	::java::lang::ref::WeakReference* parentRef = nullptr;
	bool disposed = false;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LogManager$LoggerWeakRef_h_