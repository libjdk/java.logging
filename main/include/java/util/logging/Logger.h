#ifndef _java_util_logging_Logger_h_
#define _java_util_logging_Logger_h_
//$ class java.util.logging.Logger
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("GLOBAL_LOGGER_NAME")
#undef GLOBAL_LOGGER_NAME
#pragma push_macro("NO_RESOURCE_BUNDLE")
#undef NO_RESOURCE_BUNDLE
#pragma push_macro("SYSTEM_BUNDLE")
#undef SYSTEM_BUNDLE
#pragma push_macro("SYSTEM_LOGGER_RB_NAME")
#undef SYSTEM_LOGGER_RB_NAME

namespace java {
	namespace lang {
		class ClassLoader;
		class Module;
		class Throwable;
	}
}
namespace java {
	namespace lang {
		namespace ref {
			class WeakReference;
		}
	}
}
namespace java {
	namespace util {
		class ArrayList;
		class Locale;
		class ResourceBundle;
	}
}
namespace java {
	namespace util {
		namespace function {
			class Supplier;
		}
	}
}
namespace java {
	namespace util {
		namespace logging {
			class Filter;
			class Handler;
			class Level;
			class LogManager;
			class LogManager$LoggerWeakRef;
			class LogRecord;
			class Logger$ConfigurationData;
			class Logger$LoggerBundle;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $import Logger : public ::java::lang::Object {
	$class(Logger, 0, ::java::lang::Object)
public:
	Logger();
	void init$($String* name, $String* resourceBundleName);
	void init$($String* name, $String* resourceBundleName, ::java::lang::Module* caller, ::java::util::logging::LogManager* manager, bool isSystemLogger);
	void init$($String* name);
	virtual $Array<::java::util::logging::Handler>* accessCheckedHandlers();
	virtual void addHandler(::java::util::logging::Handler* handler);
	::java::util::ResourceBundle* catalog();
	void checkPermission();
	virtual void config($String* msg);
	virtual void config(::java::util::function::Supplier* msgSupplier);
	static ::java::util::logging::Logger* demandLogger($String* name, $String* resourceBundleName, $Class* caller);
	void doLog(::java::util::logging::LogRecord* lr);
	void doLog(::java::util::logging::LogRecord* lr, $String* rbname);
	void doLog(::java::util::logging::LogRecord* lr, ::java::util::ResourceBundle* rb);
	void doSetParent(::java::util::logging::Logger* newParent);
	virtual void entering($String* sourceClass, $String* sourceMethod);
	virtual void entering($String* sourceClass, $String* sourceMethod, Object$* param1);
	virtual void entering($String* sourceClass, $String* sourceMethod, $ObjectArray* params);
	virtual void exiting($String* sourceClass, $String* sourceMethod);
	virtual void exiting($String* sourceClass, $String* sourceMethod, Object$* result);
	::java::util::ResourceBundle* findResourceBundle($String* name, bool useCallersModule);
	virtual void fine($String* msg);
	virtual void fine(::java::util::function::Supplier* msgSupplier);
	virtual void finer($String* msg);
	virtual void finer(::java::util::function::Supplier* msgSupplier);
	virtual void finest($String* msg);
	virtual void finest(::java::util::function::Supplier* msgSupplier);
	static ::java::util::logging::Logger* getAnonymousLogger();
	static ::java::util::logging::Logger* getAnonymousLogger($String* resourceBundleName);
	::java::lang::Module* getCallerModule();
	::java::util::logging::Logger$LoggerBundle* getEffectiveLoggerBundle();
	virtual ::java::util::logging::Filter* getFilter();
	static ::java::util::logging::Logger* getGlobal();
	virtual $Array<::java::util::logging::Handler>* getHandlers();
	virtual ::java::util::logging::Level* getLevel();
	static ::java::util::logging::Logger* getLogger($String* name);
	static ::java::util::logging::Logger* getLogger($String* name, $Class* callerClass);
	static ::java::util::logging::Logger* getLogger($String* name, $String* resourceBundleName);
	static ::java::util::logging::Logger* getLogger($String* name, $String* resourceBundleName, $Class* callerClass);
	virtual $String* getName();
	virtual ::java::util::logging::Logger* getParent();
	static ::java::util::logging::Logger* getPlatformLogger($String* name);
	virtual ::java::util::ResourceBundle* getResourceBundle();
	virtual $String* getResourceBundleName();
	virtual bool getUseParentHandlers();
	virtual void info($String* msg);
	virtual void info(::java::util::function::Supplier* msgSupplier);
	bool isLevelInitialized();
	virtual bool isLoggable(::java::util::logging::Level* level);
	static ::java::lang::ClassLoader* lambda$findResourceBundle$0(::java::lang::Module* callerModule);
	virtual void log(::java::util::logging::LogRecord* record);
	virtual void log(::java::util::logging::Level* level, $String* msg);
	virtual void log(::java::util::logging::Level* level, ::java::util::function::Supplier* msgSupplier);
	virtual void log(::java::util::logging::Level* level, $String* msg, Object$* param1);
	virtual void log(::java::util::logging::Level* level, $String* msg, $ObjectArray* params);
	virtual void log(::java::util::logging::Level* level, $String* msg, $Throwable* thrown);
	virtual void log(::java::util::logging::Level* level, $Throwable* thrown, ::java::util::function::Supplier* msgSupplier);
	virtual void logp(::java::util::logging::Level* level, $String* sourceClass, $String* sourceMethod, $String* msg);
	virtual void logp(::java::util::logging::Level* level, $String* sourceClass, $String* sourceMethod, ::java::util::function::Supplier* msgSupplier);
	virtual void logp(::java::util::logging::Level* level, $String* sourceClass, $String* sourceMethod, $String* msg, Object$* param1);
	virtual void logp(::java::util::logging::Level* level, $String* sourceClass, $String* sourceMethod, $String* msg, $ObjectArray* params);
	virtual void logp(::java::util::logging::Level* level, $String* sourceClass, $String* sourceMethod, $String* msg, $Throwable* thrown);
	virtual void logp(::java::util::logging::Level* level, $String* sourceClass, $String* sourceMethod, $Throwable* thrown, ::java::util::function::Supplier* msgSupplier);
	virtual void logrb(::java::util::logging::Level* level, $String* sourceClass, $String* sourceMethod, $String* bundleName, $String* msg);
	virtual void logrb(::java::util::logging::Level* level, $String* sourceClass, $String* sourceMethod, $String* bundleName, $String* msg, Object$* param1);
	virtual void logrb(::java::util::logging::Level* level, $String* sourceClass, $String* sourceMethod, $String* bundleName, $String* msg, $ObjectArray* params);
	virtual void logrb(::java::util::logging::Level* level, $String* sourceClass, $String* sourceMethod, ::java::util::ResourceBundle* bundle, $String* msg, $ObjectArray* params);
	virtual void logrb(::java::util::logging::Level* level, ::java::util::ResourceBundle* bundle, $String* msg, $ObjectArray* params);
	virtual void logrb(::java::util::logging::Level* level, $String* sourceClass, $String* sourceMethod, $String* bundleName, $String* msg, $Throwable* thrown);
	virtual void logrb(::java::util::logging::Level* level, $String* sourceClass, $String* sourceMethod, ::java::util::ResourceBundle* bundle, $String* msg, $Throwable* thrown);
	virtual void logrb(::java::util::logging::Level* level, ::java::util::ResourceBundle* bundle, $String* msg, $Throwable* thrown);
	void mergeWithSystemLogger(::java::util::logging::Logger* system);
	void removeChildLogger(::java::util::logging::LogManager$LoggerWeakRef* child);
	virtual void removeHandler(::java::util::logging::Handler* handler);
	void setCallerModuleRef(::java::lang::Module* callerModule);
	virtual void setFilter(::java::util::logging::Filter* newFilter);
	virtual void setLevel(::java::util::logging::Level* newLevel);
	virtual void setLogManager(::java::util::logging::LogManager* manager);
	virtual void setParent(::java::util::logging::Logger* parent);
	virtual void setResourceBundle(::java::util::ResourceBundle* bundle);
	virtual void setUseParentHandlers(bool useParentHandlers);
	void setupResourceInfo($String* name, $Class* caller);
	void setupResourceInfo($String* name, ::java::lang::Module* callerModule);
	virtual void severe($String* msg);
	virtual void severe(::java::util::function::Supplier* msgSupplier);
	virtual void throwing($String* sourceClass, $String* sourceMethod, $Throwable* thrown);
	void updateEffectiveLevel();
	virtual void warning($String* msg);
	virtual void warning(::java::util::function::Supplier* msgSupplier);
	static $Array<::java::util::logging::Handler>* emptyHandlers;
	static int32_t offValue;
	static $String* SYSTEM_LOGGER_RB_NAME;
	static ::java::util::logging::Logger$LoggerBundle* SYSTEM_BUNDLE;
	static ::java::util::logging::Logger$LoggerBundle* NO_RESOURCE_BUNDLE;
	$volatile(::java::util::logging::Logger$ConfigurationData*) config$ = nullptr;
	$volatile(::java::util::logging::LogManager*) manager = nullptr;
	$String* name = nullptr;
	$volatile(::java::util::logging::Logger$LoggerBundle*) loggerBundle = nullptr;
	bool anonymous = false;
	::java::lang::ref::WeakReference* catalogRef = nullptr;
	$String* catalogName = nullptr;
	::java::util::Locale* catalogLocale = nullptr;
	static $Object* treeLock;
	$volatile(::java::util::logging::Logger*) parent = nullptr;
	::java::util::ArrayList* kids = nullptr;
	::java::lang::ref::WeakReference* callerModuleRef = nullptr;
	bool isSystemLogger = false;
	static $String* GLOBAL_LOGGER_NAME;
	static ::java::util::logging::Logger* global;
};

		} // logging
	} // util
} // java

#pragma pop_macro("GLOBAL_LOGGER_NAME")
#pragma pop_macro("NO_RESOURCE_BUNDLE")
#pragma pop_macro("SYSTEM_BUNDLE")
#pragma pop_macro("SYSTEM_LOGGER_RB_NAME")

#endif // _java_util_logging_Logger_h_