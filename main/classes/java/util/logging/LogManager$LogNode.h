#ifndef _java_util_logging_LogManager$LogNode_h_
#define _java_util_logging_LogManager$LogNode_h_
//$ class java.util.logging.LogManager$LogNode
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace util {
		class HashMap;
	}
}
namespace java {
	namespace util {
		namespace logging {
			class LogManager$LoggerContext;
			class LogManager$LoggerWeakRef;
			class Logger;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class LogManager$LogNode : public ::java::lang::Object {
	$class(LogManager$LogNode, $NO_CLASS_INIT, ::java::lang::Object)
public:
	LogManager$LogNode();
	void init$(::java::util::logging::LogManager$LogNode* parent, ::java::util::logging::LogManager$LoggerContext* context);
	virtual void walkAndSetParent(::java::util::logging::Logger* parent);
	::java::util::HashMap* children = nullptr;
	::java::util::logging::LogManager$LoggerWeakRef* loggerRef = nullptr;
	::java::util::logging::LogManager$LogNode* parent = nullptr;
	::java::util::logging::LogManager$LoggerContext* context = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LogManager$LogNode_h_