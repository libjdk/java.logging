#ifndef _java_util_logging_LogManager$LoggerContext_h_
#define _java_util_logging_LogManager$LoggerContext_h_
//$ class java.util.logging.LogManager$LoggerContext
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		class Module;
	}
}
namespace java {
	namespace util {
		class Enumeration;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class ConcurrentHashMap;
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Predicate;
		}
	}
}
namespace java {
	namespace util {
		namespace logging {
			class LogManager;
			class LogManager$LogNode;
			class LogManager$LoggerWeakRef;
			class Logger;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $import LogManager$LoggerContext : public ::java::lang::Object {
	$class(LogManager$LoggerContext, 0, ::java::lang::Object)
public:
	LogManager$LoggerContext();
	void init$(::java::util::logging::LogManager* this$0);
	virtual bool addLocalLogger(::java::util::logging::Logger* logger);
	virtual bool addLocalLogger(::java::util::logging::Logger* logger, bool addDefaultLoggersIfNeeded);
	virtual ::java::util::logging::Logger* demandLogger($String* name, $String* resourceBundleName, ::java::lang::Module* module);
	void ensureAllDefaultLoggers(::java::util::logging::Logger* logger);
	void ensureDefaultLogger(::java::util::logging::Logger* logger);
	void ensureInitialized();
	virtual ::java::util::logging::Logger* findLogger($String* name);
	::java::util::logging::Logger* getGlobalLogger();
	virtual ::java::util::Enumeration* getLoggerNames();
	virtual ::java::util::logging::LogManager$LogNode* getNode($String* name);
	::java::util::logging::LogManager* getOwner();
	::java::util::logging::Logger* getRootLogger();
	void processParentHandlers(::java::util::logging::Logger* logger, $String* name, ::java::util::function::Predicate* visited);
	virtual void removeLoggerRef($String* name, ::java::util::logging::LogManager$LoggerWeakRef* ref);
	bool requiresDefaultLoggers();
	::java::util::logging::LogManager* this$0 = nullptr;
	static bool $assertionsDisabled;
	::java::util::concurrent::ConcurrentHashMap* namedLoggers = nullptr;
	::java::util::logging::LogManager$LogNode* root = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LogManager$LoggerContext_h_