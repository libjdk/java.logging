#ifndef _java_util_logging_LogManager_h_
#define _java_util_logging_LogManager_h_
//$ class java.util.logging.LogManager
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("LOGGING_MXBEAN_NAME")
#undef LOGGING_MXBEAN_NAME
#pragma push_macro("MAX_ITERATIONS")
#undef MAX_ITERATIONS
#pragma push_macro("STATE_INITIALIZED")
#undef STATE_INITIALIZED
#pragma push_macro("STATE_INITIALIZING")
#undef STATE_INITIALIZING
#pragma push_macro("STATE_READING_CONFIG")
#undef STATE_READING_CONFIG
#pragma push_macro("STATE_SHUTDOWN")
#undef STATE_SHUTDOWN
#pragma push_macro("STATE_UNINITIALIZED")
#undef STATE_UNINITIALIZED

namespace java {
	namespace io {
		class InputStream;
	}
}
namespace java {
	namespace lang {
		class Module;
		class Runnable;
		class Void;
	}
}
namespace java {
	namespace lang {
		namespace ref {
			class ReferenceQueue;
		}
	}
}
namespace java {
	namespace security {
		class AccessControlContext;
		class Permission;
		class PrivilegedAction;
	}
}
namespace java {
	namespace util {
		class Enumeration;
		class List;
		class Map;
		class Properties;
		class WeakHashMap;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CopyOnWriteArrayList;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace locks {
				class ReentrantLock;
			}
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Function;
		}
	}
}
namespace java {
	namespace util {
		namespace logging {
			class Filter;
			class Formatter;
			class Level;
			class LogManager$CloseOnReset;
			class LogManager$LoggerContext;
			class Logger;
			class LoggingMXBean;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $export LogManager : public ::java::lang::Object {
	$class(LogManager, 0, ::java::lang::Object)
public:
	LogManager();
	void init$();
	void init$(::java::lang::Void* checked);
	virtual ::java::util::logging::LogManager* addConfigurationListener(::java::lang::Runnable* listener);
	virtual bool addLogger(::java::util::logging::Logger* logger);
	virtual void checkAccess();
	virtual void checkPermission();
	static ::java::lang::Void* checkSubclassPermissions();
	void closeHandlers(::java::util::logging::Logger* logger);
	::java::util::List* contexts();
	::java::util::List* createLoggerHandlers($String* name, $String* handlersPropertyName);
	virtual ::java::util::logging::Logger* demandLogger($String* name, $String* resourceBundleName, $Class* caller);
	virtual ::java::util::logging::Logger* demandLogger($String* name, $String* resourceBundleName, ::java::lang::Module* module);
	virtual ::java::util::logging::Logger* demandSystemLogger($String* name, $String* resourceBundleName, $Class* caller);
	virtual ::java::util::logging::Logger* demandSystemLogger($String* name, $String* resourceBundleName, ::java::lang::Module* module);
	static void doSetLevel(::java::util::logging::Logger* logger, ::java::util::logging::Level* level);
	static void doSetParent(::java::util::logging::Logger* logger, ::java::util::logging::Logger* parent);
	void drainLoggerRefQueueBounded();
	void ensureLogManagerInitialized();
	bool forceLoadHandlers(::java::util::logging::Logger* logger);
	virtual bool getBooleanProperty($String* name, bool defaultValue);
	virtual $String* getConfigurationFileName();
	virtual ::java::util::logging::Filter* getFilterProperty($String* name, ::java::util::logging::Filter* defaultValue);
	virtual ::java::util::logging::Formatter* getFormatterProperty($String* name, ::java::util::logging::Formatter* defaultValue);
	virtual int32_t getIntProperty($String* name, int32_t defaultValue);
	virtual ::java::util::logging::Level* getLevelProperty($String* name, ::java::util::logging::Level* defaultValue);
	static ::java::util::logging::LogManager* getLogManager();
	virtual ::java::util::logging::Logger* getLogger($String* name);
	virtual ::java::util::Enumeration* getLoggerNames();
	static ::java::util::logging::LoggingMXBean* getLoggingMXBean();
	virtual int64_t getLongProperty($String* name, int64_t defaultValue);
	virtual $String* getProperty($String* name);
	virtual $String* getStringProperty($String* name, $String* defaultValue);
	::java::util::logging::LogManager$LoggerContext* getSystemContext();
	::java::util::logging::LogManager$LoggerContext* getUserContext();
	static void initStatic();
	void initializeGlobalHandlers();
	void invokeConfigurationListeners();
	static ::java::lang::Void* lambda$addConfigurationListener$3(::java::lang::Runnable* r);
	static void lambda$addConfigurationListener$4(::java::security::PrivilegedAction* pa, ::java::security::AccessControlContext* acc);
	static void lambda$updateConfiguration$0(::java::util::Properties* previous, ::java::util::Properties* next, ::java::util::function::Function* mapper, $String* k);
	static bool lambda$updateConfiguration$1(::java::util::Properties* previous, ::java::util::Properties* next, $String* k);
	static bool lambda$updateConfiguration$2(::java::util::logging::Logger* l, ::java::util::logging::LogManager$CloseOnReset* c);
	void loadLoggerHandlers(::java::util::logging::Logger* logger, $String* name, $String* handlersPropertyName);
	$StringArray* parseClassNames($String* propertyName);
	virtual void readConfiguration();
	virtual void readConfiguration(::java::io::InputStream* ins);
	void readPrimordialConfiguration();
	virtual void removeConfigurationListener(::java::lang::Runnable* listener);
	virtual void reset();
	void resetLogger(::java::util::logging::Logger* logger);
	void resetLoggerContext(::java::util::logging::LogManager$LoggerContext* cx);
	void setLevelsOnExistingLoggers();
	void setLoggerHandlers(::java::util::logging::Logger* logger, $String* name, $String* handlersPropertyName, ::java::util::List* handlers);
	static $String* trim($String* value);
	virtual void updateConfiguration(::java::util::function::Function* mapper);
	virtual void updateConfiguration(::java::io::InputStream* ins, ::java::util::function::Function* mapper);
	static bool $assertionsDisabled;
	$volatile(::java::util::Properties*) props = nullptr;
	static ::java::util::logging::Level* defaultLevel;
	::java::util::logging::LogManager$LoggerContext* systemContext = nullptr;
	::java::util::logging::LogManager$LoggerContext* userContext = nullptr;
	$volatile(::java::util::logging::Logger*) rootLogger = nullptr;
	$volatile(bool) readPrimordialConfiguration$ = false;
	static const int32_t STATE_INITIALIZED = 0;
	static const int32_t STATE_INITIALIZING = 1;
	static const int32_t STATE_READING_CONFIG = 2;
	static const int32_t STATE_UNINITIALIZED = 3;
	static const int32_t STATE_SHUTDOWN = 4;
	$volatile(int32_t) globalHandlersState = 0;
	::java::util::concurrent::locks::ReentrantLock* configurationLock = nullptr;
	::java::util::concurrent::CopyOnWriteArrayList* closeOnResetLoggers = nullptr;
	::java::util::Map* listeners = nullptr;
	static ::java::util::logging::LogManager* manager;
	bool initializedCalled = false;
	$volatile(bool) initializationDone = false;
	::java::util::WeakHashMap* contextsMap = nullptr;
	::java::lang::ref::ReferenceQueue* loggerRefQueue = nullptr;
	static const int32_t MAX_ITERATIONS = 400;
	static ::java::security::Permission* controlPermission;
	static $String* LOGGING_MXBEAN_NAME;
};

		} // logging
	} // util
} // java

#pragma pop_macro("LOGGING_MXBEAN_NAME")
#pragma pop_macro("MAX_ITERATIONS")
#pragma pop_macro("STATE_INITIALIZED")
#pragma pop_macro("STATE_INITIALIZING")
#pragma pop_macro("STATE_READING_CONFIG")
#pragma pop_macro("STATE_SHUTDOWN")
#pragma pop_macro("STATE_UNINITIALIZED")

#endif // _java_util_logging_LogManager_h_