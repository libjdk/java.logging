#include <java/util/logging/LogManager.h>

#include <java/io/BufferedInputStream.h>
#include <java/io/FileInputStream.h>
#include <java/io/FilterInputStream.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Module.h>
#include <java/lang/Runnable.h>
#include <java/lang/Runtime.h>
#include <java/lang/RuntimePermission.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/ThreadDeath.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/Paths.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/BasicPermission.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/IdentityHashMap.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Properties.h>
#include <java/util/Set.h>
#include <java/util/TreeMap.h>
#include <java/util/TreeSet.h>
#include <java/util/WeakHashMap.h>
#include <java/util/concurrent/CopyOnWriteArrayList.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/function/Supplier.h>
#include <java/util/logging/Filter.h>
#include <java/util/logging/Formatter.h>
#include <java/util/logging/Handler.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/LogManager$1.h>
#include <java/util/logging/LogManager$2.h>
#include <java/util/logging/LogManager$3.h>
#include <java/util/logging/LogManager$4.h>
#include <java/util/logging/LogManager$5.h>
#include <java/util/logging/LogManager$6.h>
#include <java/util/logging/LogManager$7.h>
#include <java/util/logging/LogManager$Cleaner.h>
#include <java/util/logging/LogManager$CloseOnReset.h>
#include <java/util/logging/LogManager$ConfigProperty.h>
#include <java/util/logging/LogManager$LoggerContext.h>
#include <java/util/logging/LogManager$LoggerWeakRef.h>
#include <java/util/logging/LogManager$LoggingProviderAccess.h>
#include <java/util/logging/LogManager$ModType.h>
#include <java/util/logging/LogManager$SystemLoggerContext.h>
#include <java/util/logging/LogManager$VisitedLoggers.h>
#include <java/util/logging/Logger.h>
#include <java/util/logging/Logging.h>
#include <java/util/logging/LoggingMXBean.h>
#include <java/util/logging/LoggingPermission.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/access/JavaAWTAccess.h>
#include <jdk/internal/access/SharedSecrets.h>
#include <jdk/internal/logger/BootstrapLogger.h>
#include <jcpp.h>

#undef INFO
#undef INSTANCE
#undef LOGGING_MXBEAN_NAME
#undef MAX_ITERATIONS
#undef REMOVED
#undef SAME
#undef STATE_INITIALIZED
#undef STATE_INITIALIZING
#undef STATE_READING_CONFIG
#undef STATE_SHUTDOWN
#undef STATE_UNINITIALIZED

using $RunnableArray = $Array<::java::lang::Runnable>;
using $PermissionArray = $Array<::java::security::Permission>;
using $HandlerArray = $Array<::java::util::logging::Handler>;
using $BufferedInputStream = ::java::io::BufferedInputStream;
using $FileInputStream = ::java::io::FileInputStream;
using $FilterInputStream = ::java::io::FilterInputStream;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $Enum = ::java::lang::Enum;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NullPointerException = ::java::lang::NullPointerException;
using $Runnable = ::java::lang::Runnable;
using $Runtime = ::java::lang::Runtime;
using $RuntimeException = ::java::lang::RuntimeException;
using $RuntimePermission = ::java::lang::RuntimePermission;
using $SecurityManager = ::java::lang::SecurityManager;
using $ThreadDeath = ::java::lang::ThreadDeath;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Reference = ::java::lang::ref::Reference;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $Path = ::java::nio::file::Path;
using $Paths = ::java::nio::file::Paths;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $BasicPermission = ::java::security::BasicPermission;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $AbstractList = ::java::util::AbstractList;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $IdentityHashMap = ::java::util::IdentityHashMap;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Properties = ::java::util::Properties;
using $Set = ::java::util::Set;
using $TreeMap = ::java::util::TreeMap;
using $TreeSet = ::java::util::TreeSet;
using $WeakHashMap = ::java::util::WeakHashMap;
using $CopyOnWriteArrayList = ::java::util::concurrent::CopyOnWriteArrayList;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $BiFunction = ::java::util::function::BiFunction;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Supplier = ::java::util::function::Supplier;
using $Filter = ::java::util::logging::Filter;
using $Formatter = ::java::util::logging::Formatter;
using $Handler = ::java::util::logging::Handler;
using $Level = ::java::util::logging::Level;
using $LogManager$1 = ::java::util::logging::LogManager$1;
using $LogManager$2 = ::java::util::logging::LogManager$2;
using $LogManager$3 = ::java::util::logging::LogManager$3;
using $LogManager$4 = ::java::util::logging::LogManager$4;
using $LogManager$5 = ::java::util::logging::LogManager$5;
using $LogManager$6 = ::java::util::logging::LogManager$6;
using $LogManager$7 = ::java::util::logging::LogManager$7;
using $LogManager$Cleaner = ::java::util::logging::LogManager$Cleaner;
using $LogManager$CloseOnReset = ::java::util::logging::LogManager$CloseOnReset;
using $LogManager$ConfigProperty = ::java::util::logging::LogManager$ConfigProperty;
using $LogManager$LoggerContext = ::java::util::logging::LogManager$LoggerContext;
using $LogManager$LoggerWeakRef = ::java::util::logging::LogManager$LoggerWeakRef;
using $LogManager$LoggingProviderAccess = ::java::util::logging::LogManager$LoggingProviderAccess;
using $LogManager$ModType = ::java::util::logging::LogManager$ModType;
using $LogManager$SystemLoggerContext = ::java::util::logging::LogManager$SystemLoggerContext;
using $LogManager$VisitedLoggers = ::java::util::logging::LogManager$VisitedLoggers;
using $Logger = ::java::util::logging::Logger;
using $Logging = ::java::util::logging::Logging;
using $LoggingMXBean = ::java::util::logging::LoggingMXBean;
using $LoggingPermission = ::java::util::logging::LoggingPermission;
using $Collector = ::java::util::stream::Collector;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $JavaAWTAccess = ::jdk::internal::access::JavaAWTAccess;
using $SharedSecrets = ::jdk::internal::access::SharedSecrets;
using $BootstrapLogger = ::jdk::internal::logger::BootstrapLogger;

namespace java {
	namespace util {
		namespace logging {

class LogManager$$Lambda$TreeSet : public $Supplier {
	$class(LogManager$$Lambda$TreeSet, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($new($TreeSet));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LogManager$$Lambda$TreeSet>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LogManager$$Lambda$TreeSet::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(LogManager$$Lambda$TreeSet::*)()>(&LogManager$$Lambda$TreeSet::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo LogManager$$Lambda$TreeSet::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.LogManager$$Lambda$TreeSet",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* LogManager$$Lambda$TreeSet::load$($String* name, bool initialize) {
	$loadClass(LogManager$$Lambda$TreeSet, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LogManager$$Lambda$TreeSet::class$ = nullptr;

class LogManager$$Lambda$lambda$updateConfiguration$0$1 : public $Consumer {
	$class(LogManager$$Lambda$lambda$updateConfiguration$0$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$($Properties* previous, $Properties* next, $Function* mapper) {
		$set(this, previous, previous);
		$set(this, next, next);
		$set(this, mapper, mapper);
	}
	virtual void accept(Object$* k) override {
		LogManager::lambda$updateConfiguration$0(previous, next, mapper, $cast($String, k));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LogManager$$Lambda$lambda$updateConfiguration$0$1>());
	}
	$Properties* previous = nullptr;
	$Properties* next = nullptr;
	$Function* mapper = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LogManager$$Lambda$lambda$updateConfiguration$0$1::fieldInfos[4] = {
	{"previous", "Ljava/util/Properties;", nullptr, $PUBLIC, $field(LogManager$$Lambda$lambda$updateConfiguration$0$1, previous)},
	{"next", "Ljava/util/Properties;", nullptr, $PUBLIC, $field(LogManager$$Lambda$lambda$updateConfiguration$0$1, next)},
	{"mapper", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(LogManager$$Lambda$lambda$updateConfiguration$0$1, mapper)},
	{}
};
$MethodInfo LogManager$$Lambda$lambda$updateConfiguration$0$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/Properties;Ljava/util/Properties;Ljava/util/function/Function;)V", nullptr, $PUBLIC, $method(static_cast<void(LogManager$$Lambda$lambda$updateConfiguration$0$1::*)($Properties*,$Properties*,$Function*)>(&LogManager$$Lambda$lambda$updateConfiguration$0$1::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo LogManager$$Lambda$lambda$updateConfiguration$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.LogManager$$Lambda$lambda$updateConfiguration$0$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* LogManager$$Lambda$lambda$updateConfiguration$0$1::load$($String* name, bool initialize) {
	$loadClass(LogManager$$Lambda$lambda$updateConfiguration$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LogManager$$Lambda$lambda$updateConfiguration$0$1::class$ = nullptr;

class LogManager$$Lambda$matches$2 : public $Predicate {
	$class(LogManager$$Lambda$matches$2, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* property) override {
		 return $LogManager$ConfigProperty::matches($cast($String, property));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LogManager$$Lambda$matches$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LogManager$$Lambda$matches$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(LogManager$$Lambda$matches$2::*)()>(&LogManager$$Lambda$matches$2::init$))},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo LogManager$$Lambda$matches$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.LogManager$$Lambda$matches$2",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* LogManager$$Lambda$matches$2::load$($String* name, bool initialize) {
	$loadClass(LogManager$$Lambda$matches$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LogManager$$Lambda$matches$2::class$ = nullptr;

class LogManager$$Lambda$lambda$updateConfiguration$1$3 : public $Predicate {
	$class(LogManager$$Lambda$lambda$updateConfiguration$1$3, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Properties* previous, $Properties* next) {
		$set(this, previous, previous);
		$set(this, next, next);
	}
	virtual bool test(Object$* k) override {
		 return LogManager::lambda$updateConfiguration$1(previous, next, $cast($String, k));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LogManager$$Lambda$lambda$updateConfiguration$1$3>());
	}
	$Properties* previous = nullptr;
	$Properties* next = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LogManager$$Lambda$lambda$updateConfiguration$1$3::fieldInfos[3] = {
	{"previous", "Ljava/util/Properties;", nullptr, $PUBLIC, $field(LogManager$$Lambda$lambda$updateConfiguration$1$3, previous)},
	{"next", "Ljava/util/Properties;", nullptr, $PUBLIC, $field(LogManager$$Lambda$lambda$updateConfiguration$1$3, next)},
	{}
};
$MethodInfo LogManager$$Lambda$lambda$updateConfiguration$1$3::methodInfos[3] = {
	{"<init>", "(Ljava/util/Properties;Ljava/util/Properties;)V", nullptr, $PUBLIC, $method(static_cast<void(LogManager$$Lambda$lambda$updateConfiguration$1$3::*)($Properties*,$Properties*)>(&LogManager$$Lambda$lambda$updateConfiguration$1$3::init$))},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo LogManager$$Lambda$lambda$updateConfiguration$1$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.LogManager$$Lambda$lambda$updateConfiguration$1$3",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* LogManager$$Lambda$lambda$updateConfiguration$1$3::load$($String* name, bool initialize) {
	$loadClass(LogManager$$Lambda$lambda$updateConfiguration$1$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LogManager$$Lambda$lambda$updateConfiguration$1$3::class$ = nullptr;

class LogManager$$Lambda$getLoggerName$4 : public $Function {
	$class(LogManager$$Lambda$getLoggerName$4, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* property) override {
		 return $of($LogManager$ConfigProperty::getLoggerName($cast($String, property)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LogManager$$Lambda$getLoggerName$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LogManager$$Lambda$getLoggerName$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(LogManager$$Lambda$getLoggerName$4::*)()>(&LogManager$$Lambda$getLoggerName$4::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo LogManager$$Lambda$getLoggerName$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.LogManager$$Lambda$getLoggerName$4",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* LogManager$$Lambda$getLoggerName$4::load$($String* name, bool initialize) {
	$loadClass(LogManager$$Lambda$getLoggerName$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LogManager$$Lambda$getLoggerName$4::class$ = nullptr;

class LogManager$$Lambda$TreeMap$5 : public $Supplier {
	$class(LogManager$$Lambda$TreeMap$5, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($new($TreeMap));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LogManager$$Lambda$TreeMap$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LogManager$$Lambda$TreeMap$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(LogManager$$Lambda$TreeMap$5::*)()>(&LogManager$$Lambda$TreeMap$5::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo LogManager$$Lambda$TreeMap$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.LogManager$$Lambda$TreeMap$5",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* LogManager$$Lambda$TreeMap$5::load$($String* name, bool initialize) {
	$loadClass(LogManager$$Lambda$TreeMap$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LogManager$$Lambda$TreeMap$5::class$ = nullptr;

class LogManager$$Lambda$lambda$updateConfiguration$2$6 : public $Predicate {
	$class(LogManager$$Lambda$lambda$updateConfiguration$2$6, $NO_CLASS_INIT, $Predicate)
public:
	void init$($Logger* l) {
		$set(this, l, l);
	}
	virtual bool test(Object$* c) override {
		 return LogManager::lambda$updateConfiguration$2(l, $cast($LogManager$CloseOnReset, c));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LogManager$$Lambda$lambda$updateConfiguration$2$6>());
	}
	$Logger* l = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LogManager$$Lambda$lambda$updateConfiguration$2$6::fieldInfos[2] = {
	{"l", "Ljava/util/logging/Logger;", nullptr, $PUBLIC, $field(LogManager$$Lambda$lambda$updateConfiguration$2$6, l)},
	{}
};
$MethodInfo LogManager$$Lambda$lambda$updateConfiguration$2$6::methodInfos[3] = {
	{"<init>", "(Ljava/util/logging/Logger;)V", nullptr, $PUBLIC, $method(static_cast<void(LogManager$$Lambda$lambda$updateConfiguration$2$6::*)($Logger*)>(&LogManager$$Lambda$lambda$updateConfiguration$2$6::init$))},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo LogManager$$Lambda$lambda$updateConfiguration$2$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.LogManager$$Lambda$lambda$updateConfiguration$2$6",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* LogManager$$Lambda$lambda$updateConfiguration$2$6::load$($String* name, bool initialize) {
	$loadClass(LogManager$$Lambda$lambda$updateConfiguration$2$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LogManager$$Lambda$lambda$updateConfiguration$2$6::class$ = nullptr;

class LogManager$$Lambda$lambda$addConfigurationListener$3$7 : public $PrivilegedAction {
	$class(LogManager$$Lambda$lambda$addConfigurationListener$3$7, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($Runnable* r) {
		$set(this, r, r);
	}
	virtual $Object* run() override {
		 return $of(LogManager::lambda$addConfigurationListener$3(r));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LogManager$$Lambda$lambda$addConfigurationListener$3$7>());
	}
	$Runnable* r = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LogManager$$Lambda$lambda$addConfigurationListener$3$7::fieldInfos[2] = {
	{"r", "Ljava/lang/Runnable;", nullptr, $PUBLIC, $field(LogManager$$Lambda$lambda$addConfigurationListener$3$7, r)},
	{}
};
$MethodInfo LogManager$$Lambda$lambda$addConfigurationListener$3$7::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Runnable;)V", nullptr, $PUBLIC, $method(static_cast<void(LogManager$$Lambda$lambda$addConfigurationListener$3$7::*)($Runnable*)>(&LogManager$$Lambda$lambda$addConfigurationListener$3$7::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo LogManager$$Lambda$lambda$addConfigurationListener$3$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.LogManager$$Lambda$lambda$addConfigurationListener$3$7",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* LogManager$$Lambda$lambda$addConfigurationListener$3$7::load$($String* name, bool initialize) {
	$loadClass(LogManager$$Lambda$lambda$addConfigurationListener$3$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LogManager$$Lambda$lambda$addConfigurationListener$3$7::class$ = nullptr;

class LogManager$$Lambda$lambda$addConfigurationListener$4$8 : public $Runnable {
	$class(LogManager$$Lambda$lambda$addConfigurationListener$4$8, $NO_CLASS_INIT, $Runnable)
public:
	void init$($PrivilegedAction* pa, $AccessControlContext* acc) {
		$set(this, pa, pa);
		$set(this, acc, acc);
	}
	virtual void run() override {
		LogManager::lambda$addConfigurationListener$4(pa, acc);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LogManager$$Lambda$lambda$addConfigurationListener$4$8>());
	}
	$PrivilegedAction* pa = nullptr;
	$AccessControlContext* acc = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LogManager$$Lambda$lambda$addConfigurationListener$4$8::fieldInfos[3] = {
	{"pa", "Ljava/security/PrivilegedAction;", nullptr, $PUBLIC, $field(LogManager$$Lambda$lambda$addConfigurationListener$4$8, pa)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $PUBLIC, $field(LogManager$$Lambda$lambda$addConfigurationListener$4$8, acc)},
	{}
};
$MethodInfo LogManager$$Lambda$lambda$addConfigurationListener$4$8::methodInfos[3] = {
	{"<init>", "(Ljava/security/PrivilegedAction;Ljava/security/AccessControlContext;)V", nullptr, $PUBLIC, $method(static_cast<void(LogManager$$Lambda$lambda$addConfigurationListener$4$8::*)($PrivilegedAction*,$AccessControlContext*)>(&LogManager$$Lambda$lambda$addConfigurationListener$4$8::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo LogManager$$Lambda$lambda$addConfigurationListener$4$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.LogManager$$Lambda$lambda$addConfigurationListener$4$8",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* LogManager$$Lambda$lambda$addConfigurationListener$4$8::load$($String* name, bool initialize) {
	$loadClass(LogManager$$Lambda$lambda$addConfigurationListener$4$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LogManager$$Lambda$lambda$addConfigurationListener$4$8::class$ = nullptr;

$NamedAttribute LogManager_Attribute_var$0[] = {
	{"since", 's', "17"},
	{"forRemoval", 'Z', "true"},
	{}
};

$CompoundAttribute _LogManager_MethodAnnotations_checkAccess4[] = {
	{"Ljava/lang/Deprecated;", LogManager_Attribute_var$0},
	{}
};

$NamedAttribute LogManager_Attribute_var$1[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _LogManager_MethodAnnotations_getLoggingMXBean28[] = {
	{"Ljava/lang/Deprecated;", LogManager_Attribute_var$1},
	{}
};

$FieldInfo _LogManager_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(LogManager, $assertionsDisabled)},
	{"props", "Ljava/util/Properties;", nullptr, $PRIVATE | $VOLATILE, $field(LogManager, props)},
	{"defaultLevel", "Ljava/util/logging/Level;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LogManager, defaultLevel)},
	{"systemContext", "Ljava/util/logging/LogManager$LoggerContext;", nullptr, $PRIVATE | $FINAL, $field(LogManager, systemContext)},
	{"userContext", "Ljava/util/logging/LogManager$LoggerContext;", nullptr, $PRIVATE | $FINAL, $field(LogManager, userContext)},
	{"rootLogger", "Ljava/util/logging/Logger;", nullptr, $PRIVATE | $VOLATILE, $field(LogManager, rootLogger)},
	{"readPrimordialConfiguration", "Z", nullptr, $PRIVATE | $VOLATILE, $field(LogManager, readPrimordialConfiguration$)},
	{"STATE_INITIALIZED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LogManager, STATE_INITIALIZED)},
	{"STATE_INITIALIZING", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LogManager, STATE_INITIALIZING)},
	{"STATE_READING_CONFIG", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LogManager, STATE_READING_CONFIG)},
	{"STATE_UNINITIALIZED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LogManager, STATE_UNINITIALIZED)},
	{"STATE_SHUTDOWN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LogManager, STATE_SHUTDOWN)},
	{"globalHandlersState", "I", nullptr, $PRIVATE | $VOLATILE, $field(LogManager, globalHandlersState)},
	{"configurationLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(LogManager, configurationLock)},
	{"closeOnResetLoggers", "Ljava/util/concurrent/CopyOnWriteArrayList;", "Ljava/util/concurrent/CopyOnWriteArrayList<Ljava/util/logging/LogManager$CloseOnReset;>;", $PRIVATE | $FINAL, $field(LogManager, closeOnResetLoggers)},
	{"listeners", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Object;Ljava/lang/Runnable;>;", $PRIVATE | $FINAL, $field(LogManager, listeners)},
	{"manager", "Ljava/util/logging/LogManager;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LogManager, manager)},
	{"initializedCalled", "Z", nullptr, $PRIVATE, $field(LogManager, initializedCalled)},
	{"initializationDone", "Z", nullptr, $PRIVATE | $VOLATILE, $field(LogManager, initializationDone)},
	{"contextsMap", "Ljava/util/WeakHashMap;", "Ljava/util/WeakHashMap<Ljava/lang/Object;Ljava/util/logging/LogManager$LoggerContext;>;", $PRIVATE, $field(LogManager, contextsMap)},
	{"loggerRefQueue", "Ljava/lang/ref/ReferenceQueue;", "Ljava/lang/ref/ReferenceQueue<Ljava/util/logging/Logger;>;", $PRIVATE | $FINAL, $field(LogManager, loggerRefQueue)},
	{"MAX_ITERATIONS", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LogManager, MAX_ITERATIONS)},
	{"controlPermission", "Ljava/security/Permission;", nullptr, $STATIC | $FINAL, $staticField(LogManager, controlPermission)},
	{"LOGGING_MXBEAN_NAME", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(LogManager, LOGGING_MXBEAN_NAME)},
	{}
};

$MethodInfo _LogManager_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(static_cast<void(LogManager::*)()>(&LogManager::init$))},
	{"<init>", "(Ljava/lang/Void;)V", nullptr, $PRIVATE, $method(static_cast<void(LogManager::*)($Void*)>(&LogManager::init$))},
	{"addConfigurationListener", "(Ljava/lang/Runnable;)Ljava/util/logging/LogManager;", nullptr, $PUBLIC},
	{"addLogger", "(Ljava/util/logging/Logger;)Z", nullptr, $PUBLIC},
	{"checkAccess", "()V", nullptr, $PUBLIC | $DEPRECATED, nullptr, "java.lang.SecurityException", nullptr, _LogManager_MethodAnnotations_checkAccess4},
	{"checkPermission", "()V", nullptr, 0},
	{"checkSubclassPermissions", "()Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$Void*(*)()>(&LogManager::checkSubclassPermissions))},
	{"closeHandlers", "(Ljava/util/logging/Logger;)V", nullptr, $PRIVATE, $method(static_cast<void(LogManager::*)($Logger*)>(&LogManager::closeHandlers))},
	{"contexts", "()Ljava/util/List;", "()Ljava/util/List<Ljava/util/logging/LogManager$LoggerContext;>;", $PRIVATE, $method(static_cast<$List*(LogManager::*)()>(&LogManager::contexts))},
	{"createLoggerHandlers", "(Ljava/lang/String;Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;Ljava/lang/String;)Ljava/util/List<Ljava/util/logging/Handler;>;", $PRIVATE, $method(static_cast<$List*(LogManager::*)($String*,$String*)>(&LogManager::createLoggerHandlers))},
	{"demandLogger", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class;)Ljava/util/logging/Logger;", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class<*>;)Ljava/util/logging/Logger;", 0},
	{"demandLogger", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Module;)Ljava/util/logging/Logger;", nullptr, 0},
	{"demandSystemLogger", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class;)Ljava/util/logging/Logger;", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Class<*>;)Ljava/util/logging/Logger;", 0},
	{"demandSystemLogger", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Module;)Ljava/util/logging/Logger;", nullptr, 0},
	{"doSetLevel", "(Ljava/util/logging/Logger;Ljava/util/logging/Level;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($Logger*,$Level*)>(&LogManager::doSetLevel))},
	{"doSetParent", "(Ljava/util/logging/Logger;Ljava/util/logging/Logger;)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)($Logger*,$Logger*)>(&LogManager::doSetParent))},
	{"drainLoggerRefQueueBounded", "()V", nullptr, $FINAL, $method(static_cast<void(LogManager::*)()>(&LogManager::drainLoggerRefQueueBounded))},
	{"ensureLogManagerInitialized", "()V", nullptr, $FINAL, $method(static_cast<void(LogManager::*)()>(&LogManager::ensureLogManagerInitialized))},
	{"forceLoadHandlers", "(Ljava/util/logging/Logger;)Z", nullptr, $PRIVATE, $method(static_cast<bool(LogManager::*)($Logger*)>(&LogManager::forceLoadHandlers))},
	{"getBooleanProperty", "(Ljava/lang/String;Z)Z", nullptr, 0},
	{"getConfigurationFileName", "()Ljava/lang/String;", nullptr, 0, nullptr, "java.io.IOException"},
	{"getFilterProperty", "(Ljava/lang/String;Ljava/util/logging/Filter;)Ljava/util/logging/Filter;", nullptr, 0},
	{"getFormatterProperty", "(Ljava/lang/String;Ljava/util/logging/Formatter;)Ljava/util/logging/Formatter;", nullptr, 0},
	{"getIntProperty", "(Ljava/lang/String;I)I", nullptr, 0},
	{"getLevelProperty", "(Ljava/lang/String;Ljava/util/logging/Level;)Ljava/util/logging/Level;", nullptr, 0},
	{"getLogManager", "()Ljava/util/logging/LogManager;", nullptr, $PUBLIC | $STATIC, $method(static_cast<LogManager*(*)()>(&LogManager::getLogManager))},
	{"getLogger", "(Ljava/lang/String;)Ljava/util/logging/Logger;", nullptr, $PUBLIC},
	{"getLoggerNames", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $PUBLIC},
	{"getLoggingMXBean", "()Ljava/util/logging/LoggingMXBean;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED | $DEPRECATED, $method(static_cast<$LoggingMXBean*(*)()>(&LogManager::getLoggingMXBean)), nullptr, nullptr, _LogManager_MethodAnnotations_getLoggingMXBean28},
	{"getLongProperty", "(Ljava/lang/String;J)J", nullptr, 0},
	{"getProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"getStringProperty", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, 0},
	{"getSystemContext", "()Ljava/util/logging/LogManager$LoggerContext;", nullptr, $FINAL, $method(static_cast<$LogManager$LoggerContext*(LogManager::*)()>(&LogManager::getSystemContext))},
	{"getUserContext", "()Ljava/util/logging/LogManager$LoggerContext;", nullptr, $PRIVATE, $method(static_cast<$LogManager$LoggerContext*(LogManager::*)()>(&LogManager::getUserContext))},
	{"initStatic", "()V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)()>(&LogManager::initStatic))},
	{"initializeGlobalHandlers", "()V", nullptr, $PRIVATE, $method(static_cast<void(LogManager::*)()>(&LogManager::initializeGlobalHandlers))},
	{"invokeConfigurationListeners", "()V", nullptr, $PRIVATE, $method(static_cast<void(LogManager::*)()>(&LogManager::invokeConfigurationListeners))},
	{"lambda$addConfigurationListener$3", "(Ljava/lang/Runnable;)Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Void*(*)($Runnable*)>(&LogManager::lambda$addConfigurationListener$3))},
	{"lambda$addConfigurationListener$4", "(Ljava/security/PrivilegedAction;Ljava/security/AccessControlContext;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($PrivilegedAction*,$AccessControlContext*)>(&LogManager::lambda$addConfigurationListener$4))},
	{"lambda$updateConfiguration$0", "(Ljava/util/Properties;Ljava/util/Properties;Ljava/util/function/Function;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($Properties*,$Properties*,$Function*,$String*)>(&LogManager::lambda$updateConfiguration$0))},
	{"lambda$updateConfiguration$1", "(Ljava/util/Properties;Ljava/util/Properties;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($Properties*,$Properties*,$String*)>(&LogManager::lambda$updateConfiguration$1))},
	{"lambda$updateConfiguration$2", "(Ljava/util/logging/Logger;Ljava/util/logging/LogManager$CloseOnReset;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($Logger*,$LogManager$CloseOnReset*)>(&LogManager::lambda$updateConfiguration$2))},
	{"loadLoggerHandlers", "(Ljava/util/logging/Logger;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(LogManager::*)($Logger*,$String*,$String*)>(&LogManager::loadLoggerHandlers))},
	{"parseClassNames", "(Ljava/lang/String;)[Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$StringArray*(LogManager::*)($String*)>(&LogManager::parseClassNames))},
	{"readConfiguration", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException,java.lang.SecurityException"},
	{"readConfiguration", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.io.IOException,java.lang.SecurityException"},
	{"readPrimordialConfiguration", "()V", nullptr, $PRIVATE, $method(static_cast<void(LogManager::*)()>(&LogManager::readPrimordialConfiguration))},
	{"removeConfigurationListener", "(Ljava/lang/Runnable;)V", nullptr, $PUBLIC},
	{"reset", "()V", nullptr, $PUBLIC, nullptr, "java.lang.SecurityException"},
	{"resetLogger", "(Ljava/util/logging/Logger;)V", nullptr, $PRIVATE, $method(static_cast<void(LogManager::*)($Logger*)>(&LogManager::resetLogger))},
	{"resetLoggerContext", "(Ljava/util/logging/LogManager$LoggerContext;)V", nullptr, $PRIVATE, $method(static_cast<void(LogManager::*)($LogManager$LoggerContext*)>(&LogManager::resetLoggerContext))},
	{"setLevelsOnExistingLoggers", "()V", nullptr, $PRIVATE, $method(static_cast<void(LogManager::*)()>(&LogManager::setLevelsOnExistingLoggers))},
	{"setLoggerHandlers", "(Ljava/util/logging/Logger;Ljava/lang/String;Ljava/lang/String;Ljava/util/List;)V", "(Ljava/util/logging/Logger;Ljava/lang/String;Ljava/lang/String;Ljava/util/List<Ljava/util/logging/Handler;>;)V", $PRIVATE, $method(static_cast<void(LogManager::*)($Logger*,$String*,$String*,$List*)>(&LogManager::setLoggerHandlers))},
	{"trim", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $method(static_cast<$String*(*)($String*)>(&LogManager::trim))},
	{"updateConfiguration", "(Ljava/util/function/Function;)V", "(Ljava/util/function/Function<Ljava/lang/String;Ljava/util/function/BiFunction<Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;>;>;)V", $PUBLIC, nullptr, "java.io.IOException"},
	{"updateConfiguration", "(Ljava/io/InputStream;Ljava/util/function/Function;)V", "(Ljava/io/InputStream;Ljava/util/function/Function<Ljava/lang/String;Ljava/util/function/BiFunction<Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;>;>;)V", $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _LogManager_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$7", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"java.util.logging.LogManager$LoggingProviderAccess", "java.util.logging.LogManager", "LoggingProviderAccess", $PRIVATE | $STATIC | $FINAL},
	{"java.util.logging.LogManager$RootLogger", "java.util.logging.LogManager", "RootLogger", $PRIVATE | $FINAL},
	{"java.util.logging.LogManager$LogNode", "java.util.logging.LogManager", "LogNode", $PRIVATE | $STATIC},
	{"java.util.logging.LogManager$ModType", "java.util.logging.LogManager", "ModType", $STATIC | $FINAL | $ENUM},
	{"java.util.logging.LogManager$VisitedLoggers", "java.util.logging.LogManager", "VisitedLoggers", $STATIC | $FINAL},
	{"java.util.logging.LogManager$ConfigProperty", "java.util.logging.LogManager", "ConfigProperty", $STATIC | $FINAL | $ENUM},
	{"java.util.logging.LogManager$LoggerWeakRef", "java.util.logging.LogManager", "LoggerWeakRef", $FINAL},
	{"java.util.logging.LogManager$SystemLoggerContext", "java.util.logging.LogManager", "SystemLoggerContext", $FINAL},
	{"java.util.logging.LogManager$LoggerContext", "java.util.logging.LogManager", "LoggerContext", 0},
	{"java.util.logging.LogManager$Cleaner", "java.util.logging.LogManager", "Cleaner", $PRIVATE},
	{"java.util.logging.LogManager$CloseOnReset", "java.util.logging.LogManager", "CloseOnReset", $PRIVATE | $STATIC | $FINAL},
	{"java.util.logging.LogManager$6", nullptr, nullptr, 0},
	{"java.util.logging.LogManager$5", nullptr, nullptr, 0},
	{"java.util.logging.LogManager$4", nullptr, nullptr, 0},
	{"java.util.logging.LogManager$3", nullptr, nullptr, 0},
	{"java.util.logging.LogManager$2", nullptr, nullptr, 0},
	{"java.util.logging.LogManager$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LogManager_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.logging.LogManager",
	"java.lang.Object",
	nullptr,
	_LogManager_FieldInfo_,
	_LogManager_MethodInfo_,
	nullptr,
	nullptr,
	_LogManager_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.logging.LogManager$7,java.util.logging.LogManager$LoggingProviderAccess,java.util.logging.LogManager$RootLogger,java.util.logging.LogManager$LogNode,java.util.logging.LogManager$ModType,java.util.logging.LogManager$VisitedLoggers,java.util.logging.LogManager$ConfigProperty,java.util.logging.LogManager$LoggerWeakRef,java.util.logging.LogManager$SystemLoggerContext,java.util.logging.LogManager$LoggerContext,java.util.logging.LogManager$LoggerContext$1,java.util.logging.LogManager$Cleaner,java.util.logging.LogManager$CloseOnReset,java.util.logging.LogManager$6,java.util.logging.LogManager$5,java.util.logging.LogManager$4,java.util.logging.LogManager$3,java.util.logging.LogManager$2,java.util.logging.LogManager$1"
};

$Object* allocate$LogManager($Class* clazz) {
	return $of($alloc(LogManager));
}

bool LogManager::$assertionsDisabled = false;
$Level* LogManager::defaultLevel = nullptr;
LogManager* LogManager::manager = nullptr;
$Permission* LogManager::controlPermission = nullptr;
$String* LogManager::LOGGING_MXBEAN_NAME = nullptr;

void LogManager::init$() {
	LogManager::init$($(checkSubclassPermissions()));
}

void LogManager::init$($Void* checked) {
	$useLocalCurrentObjectStackCache();
	$set(this, props, $new($Properties));
	$set(this, systemContext, $new($LogManager$SystemLoggerContext, this));
	$set(this, userContext, $new($LogManager$LoggerContext, this));
	$set(this, configurationLock, $new($ReentrantLock));
	$set(this, closeOnResetLoggers, $new($CopyOnWriteArrayList));
	$set(this, listeners, $Collections::synchronizedMap($$new($IdentityHashMap)));
	this->initializedCalled = false;
	this->initializationDone = false;
	$set(this, contextsMap, nullptr);
	$set(this, loggerRefQueue, $new($ReferenceQueue));
	try {
		$nc($($Runtime::getRuntime()))->addShutdownHook($$new($LogManager$Cleaner, this));
	} catch ($IllegalStateException& e) {
	}
}

$Void* LogManager::checkSubclassPermissions() {
	$init(LogManager);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission($$new($RuntimePermission, "shutdownHooks"_s));
		sm->checkPermission($$new($RuntimePermission, "setContextClassLoader"_s));
	}
	return nullptr;
}

void LogManager::ensureLogManagerInitialized() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var(LogManager, owner, this);
	if (this->initializationDone || owner != LogManager::manager) {
		return;
	}
	$nc(this->configurationLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			bool isRecursiveInitialization = (this->initializedCalled == true);
			if (!LogManager::$assertionsDisabled && !(this->initializedCalled || !this->initializationDone)) {
				$throwNew($AssertionError, $of("Initialization can\'t be done if initialized has not been called!"_s));
			}
			if (isRecursiveInitialization || this->initializationDone) {
				return$1 = true;
				goto $finally;
			}
			this->initializedCalled = true;
			{
				$var($Throwable, var$2, nullptr);
				try {
					$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($LogManager$2, this, owner)));
				} catch ($Throwable& var$3) {
					$assign(var$2, var$3);
				} /*finally*/ {
					this->initializationDone = true;
				}
				if (var$2 != nullptr) {
					$throw(var$2);
				}
			}
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			$nc(this->configurationLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

LogManager* LogManager::getLogManager() {
	$init(LogManager);
	if (LogManager::manager != nullptr) {
		$nc(LogManager::manager)->ensureLogManagerInitialized();
	}
	return LogManager::manager;
}

void LogManager::readPrimordialConfiguration() {
	if (!this->readPrimordialConfiguration$) {
		if ($System::out == nullptr) {
			return;
		}
		this->readPrimordialConfiguration$ = true;
		try {
			readConfiguration();
			$BootstrapLogger::redirectTemporaryLoggers();
		} catch ($Exception& ex) {
			if (!LogManager::$assertionsDisabled) {
				$throwNew($AssertionError, $of($$str({"Exception raised while reading logging configuration: "_s, ex})));
			}
		}
	}
}

$LogManager$LoggerContext* LogManager::getUserContext() {
	$useLocalCurrentObjectStackCache();
	$var($LogManager$LoggerContext, context, nullptr);
	$var($SecurityManager, sm, $System::getSecurityManager());
	$var($JavaAWTAccess, javaAwtAccess, $SharedSecrets::getJavaAWTAccess());
	if (sm != nullptr && javaAwtAccess != nullptr) {
		$var($Object, ecx, javaAwtAccess->getAppletContext());
		if (ecx != nullptr) {
			$synchronized(javaAwtAccess) {
				if (this->contextsMap == nullptr) {
					$set(this, contextsMap, $new($WeakHashMap));
				}
				$assign(context, $cast($LogManager$LoggerContext, $nc(this->contextsMap)->get(ecx)));
				if (context == nullptr) {
					$assign(context, $new($LogManager$LoggerContext, this));
					$nc(this->contextsMap)->put(ecx, context);
				}
			}
		}
	}
	return context != nullptr ? context : this->userContext;
}

$LogManager$LoggerContext* LogManager::getSystemContext() {
	return this->systemContext;
}

$List* LogManager::contexts() {
	$useLocalCurrentObjectStackCache();
	$var($List, cxs, $new($ArrayList));
	cxs->add($(getSystemContext()));
	cxs->add($(getUserContext()));
	return cxs;
}

$Logger* LogManager::demandLogger($String* name, $String* resourceBundleName, $Class* caller) {
	$var($Module, module, caller == nullptr ? ($Module*)nullptr : $nc(caller)->getModule());
	return demandLogger(name, resourceBundleName, module);
}

$Logger* LogManager::demandLogger($String* name, $String* resourceBundleName, $Module* module) {
	$useLocalCurrentObjectStackCache();
	$var($Logger, result, getLogger(name));
	if (result == nullptr) {
		$var($Logger, newLogger, $new($Logger, name, resourceBundleName, module, this, false));
		do {
			if (addLogger(newLogger)) {
				return newLogger;
			}
			$assign(result, getLogger(name));
		} while (result == nullptr);
	}
	return result;
}

$Logger* LogManager::demandSystemLogger($String* name, $String* resourceBundleName, $Class* caller) {
	$var($Module, module, caller == nullptr ? ($Module*)nullptr : $nc(caller)->getModule());
	return demandSystemLogger(name, resourceBundleName, module);
}

$Logger* LogManager::demandSystemLogger($String* name, $String* resourceBundleName, $Module* module) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($Logger, sysLogger, $nc($(getSystemContext()))->demandLogger(name, resourceBundleName, module));
	$var($Logger, logger, nullptr);
	do {
		if (addLogger(sysLogger)) {
			$assign(logger, sysLogger);
		} else {
			$assign(logger, getLogger(name));
		}
	} while (logger == nullptr);
	if (logger != sysLogger) {
		$var($Logger, l, logger);
		$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($LogManager$3, this, l, sysLogger)));
	}
	return sysLogger;
}

void LogManager::loadLoggerHandlers($Logger* logger, $String* name, $String* handlersPropertyName) {
	$beforeCallerSensitive();
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($LogManager$4, this, logger, name, handlersPropertyName)));
}

void LogManager::setLoggerHandlers($Logger* logger, $String* name, $String* handlersPropertyName, $List* handlers) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = !$nc(handlers)->isEmpty();
	bool ensureCloseOnReset = var$0 && getBooleanProperty($$str({handlersPropertyName, ".ensureCloseOnReset"_s}), true);
	int32_t count = 0;
	{
		$var($Iterator, i$, handlers->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Handler, hdl, $cast($Handler, i$->next()));
			{
				$nc(logger)->addHandler(hdl);
				if (++count == 1 && ensureCloseOnReset) {
					$nc(this->closeOnResetLoggers)->addIfAbsent($($LogManager$CloseOnReset::create(logger)));
				}
			}
		}
	}
}

$List* LogManager::createLoggerHandlers($String* name, $String* handlersPropertyName) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($StringArray, names, parseClassNames(handlersPropertyName));
	$var($List, handlers, $new($ArrayList, $nc(names)->length));
	{
		$var($StringArray, arr$, names);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, type, arr$->get(i$));
			{
				try {
					$var($Object, o, $nc($nc($($ClassLoader::getSystemClassLoader()))->loadClass(type))->newInstance());
					$var($Handler, hdl, $cast($Handler, o));
					$var($String, levs, getProperty($$str({type, ".level"_s})));
					if (levs != nullptr) {
						$var($Level, l, $Level::findLevel(levs));
						if (l != nullptr) {
							$nc(hdl)->setLevel(l);
						} else {
							$nc($System::err)->println($$str({"Can\'t set level for "_s, type}));
						}
					}
					handlers->add(hdl);
				} catch ($Exception& ex) {
					$nc($System::err)->println($$str({"Can\'t load log handler \""_s, type, "\""_s}));
					$nc($System::err)->println($$str({""_s, ex}));
					ex->printStackTrace();
				}
			}
		}
	}
	return handlers;
}

void LogManager::drainLoggerRefQueueBounded() {
	$useLocalCurrentObjectStackCache();
	for (int32_t i = 0; i < LogManager::MAX_ITERATIONS; ++i) {
		if (this->loggerRefQueue == nullptr) {
			break;
		}
		$var($LogManager$LoggerWeakRef, ref, $cast($LogManager$LoggerWeakRef, $nc(this->loggerRefQueue)->poll()));
		if (ref == nullptr) {
			break;
		}
		$nc(ref)->dispose();
	}
}

bool LogManager::addLogger($Logger* logger) {
	$useLocalCurrentObjectStackCache();
	$var($String, name, $nc(logger)->getName());
	if (name == nullptr) {
		$throwNew($NullPointerException);
	}
	drainLoggerRefQueueBounded();
	$var($LogManager$LoggerContext, cx, getUserContext());
	bool var$0 = $nc(cx)->addLocalLogger(logger);
	if (var$0 || forceLoadHandlers(logger)) {
		loadLoggerHandlers(logger, name, $$str({name, ".handlers"_s}));
		return true;
	} else {
		return false;
	}
}

bool LogManager::forceLoadHandlers($Logger* logger) {
	$init($Logger);
	return (logger == this->rootLogger || logger == $Logger::global) && !this->initializationDone && this->initializedCalled && $nc(this->configurationLock)->isHeldByCurrentThread();
}

void LogManager::doSetLevel($Logger* logger, $Level* level) {
	$init(LogManager);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm == nullptr) {
		$nc(logger)->setLevel(level);
		return;
	}
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($LogManager$5, logger, level)));
}

void LogManager::doSetParent($Logger* logger, $Logger* parent) {
	$init(LogManager);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm == nullptr) {
		$nc(logger)->setParent(parent);
		return;
	}
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($LogManager$6, logger, parent)));
}

$Logger* LogManager::getLogger($String* name) {
	return $nc($(getUserContext()))->findLogger(name);
}

$Enumeration* LogManager::getLoggerNames() {
	return $nc($(getUserContext()))->getLoggerNames();
}

void LogManager::readConfiguration() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	checkPermission();
	$var($String, cname, $System::getProperty("java.util.logging.config.class"_s));
	if (cname != nullptr) {
		try {
			try {
				$Class* clz = $nc($($ClassLoader::getSystemClassLoader()))->loadClass(cname);
				$var($Object, witness, $nc(clz)->newInstance());
				return;
			} catch ($ClassNotFoundException& ex) {
				$Class* clz = $nc($($($Thread::currentThread())->getContextClassLoader()))->loadClass(cname);
				$var($Object, witness, $nc(clz)->newInstance());
				return;
			}
		} catch ($Exception& ex) {
			$nc($System::err)->println($$str({"Logging configuration class \""_s, cname, "\" failed"_s}));
			$nc($System::err)->println($$str({""_s, ex}));
		}
	}
	$var($String, fname, getConfigurationFileName());
	{
		$var($InputStream, in, $new($FileInputStream, fname));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($BufferedInputStream, bin, $new($BufferedInputStream, in));
					readConfiguration(bin);
				} catch ($Throwable& t$) {
					try {
						in->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				in->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

$String* LogManager::getConfigurationFileName() {
	$useLocalCurrentObjectStackCache();
	$var($String, fname, $System::getProperty("java.util.logging.config.file"_s));
	if (fname == nullptr) {
		$assign(fname, $System::getProperty("java.home"_s));
		if (fname == nullptr) {
			$throwNew($Error, "Can\'t find java.home ??"_s);
		}
		$assign(fname, $nc($($nc($($nc($($Paths::get(fname, $$new($StringArray, {
			"conf"_s,
			"logging.properties"_s
		}))))->toAbsolutePath()))->normalize()))->toString());
	}
	return fname;
}

void LogManager::reset() {
	$useLocalCurrentObjectStackCache();
	checkPermission();
	$var($List, persistent, nullptr);
	$nc(this->configurationLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$set(this, props, $new($Properties));
			$assign(persistent, $new($ArrayList, static_cast<$Collection*>(this->closeOnResetLoggers)));
			$nc(this->closeOnResetLoggers)->clear();
			if (this->globalHandlersState != LogManager::STATE_SHUTDOWN && this->globalHandlersState != LogManager::STATE_READING_CONFIG) {
				this->globalHandlersState = LogManager::STATE_INITIALIZED;
			}
			{
				$var($Iterator, i$, $nc($(contexts()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($LogManager$LoggerContext, cx, $cast($LogManager$LoggerContext, i$->next()));
					{
						resetLoggerContext(cx);
					}
				}
			}
			persistent->clear();
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->configurationLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void LogManager::resetLoggerContext($LogManager$LoggerContext* cx) {
	$useLocalCurrentObjectStackCache();
	$var($Enumeration, enum_, $nc(cx)->getLoggerNames());
	while ($nc(enum_)->hasMoreElements()) {
		$var($String, name, $cast($String, enum_->nextElement()));
		$var($Logger, logger, cx->findLogger(name));
		if (logger != nullptr) {
			resetLogger(logger);
		}
	}
}

void LogManager::closeHandlers($Logger* logger) {
	$useLocalCurrentObjectStackCache();
	$var($HandlerArray, targets, $nc(logger)->getHandlers());
	{
		$var($HandlerArray, arr$, targets);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Handler, h, arr$->get(i$));
			{
				logger->removeHandler(h);
				try {
					$nc(h)->close();
				} catch ($Exception& ex) {
				} catch ($Error& e) {
					if (this->globalHandlersState != LogManager::STATE_SHUTDOWN) {
						$throw(e);
					}
				}
			}
		}
	}
}

void LogManager::resetLogger($Logger* logger) {
	closeHandlers(logger);
	$var($String, name, $nc(logger)->getName());
	if (name != nullptr && name->isEmpty()) {
		logger->setLevel(LogManager::defaultLevel);
	} else {
		logger->setLevel(nullptr);
	}
}

$StringArray* LogManager::parseClassNames($String* propertyName) {
	$useLocalCurrentObjectStackCache();
	$var($String, hands, getProperty(propertyName));
	if (hands == nullptr) {
		return $new($StringArray, 0);
	}
	$assign(hands, $nc(hands)->trim());
	int32_t ix = 0;
	$var($List, result, $new($ArrayList));
	while (ix < hands->length()) {
		int32_t end = ix;
		while (end < hands->length()) {
			if ($Character::isWhitespace(hands->charAt(end))) {
				break;
			}
			if (hands->charAt(end) == u',') {
				break;
			}
			++end;
		}
		$var($String, word, hands->substring(ix, end));
		ix = end + 1;
		$assign(word, word->trim());
		if (word->length() == 0) {
			continue;
		}
		result->add(word);
	}
	return $fcast($StringArray, result->toArray($$new($StringArray, result->size())));
}

void LogManager::readConfiguration($InputStream* ins) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	checkPermission();
	$nc(this->configurationLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			if (this->globalHandlersState == LogManager::STATE_SHUTDOWN) {
				return$1 = true;
				goto $finally;
			}
			this->globalHandlersState = LogManager::STATE_READING_CONFIG;
			try {
				reset();
				try {
					$nc(this->props)->load(ins);
				} catch ($IllegalArgumentException& x) {
					$throwNew($IOException, $(x->getMessage()), x);
				}
				$var($StringArray, names, parseClassNames("config"_s));
				{
					$var($StringArray, arr$, names);
					int32_t len$ = $nc(arr$)->length;
					int32_t i$ = 0;
					for (; i$ < len$; ++i$) {
						$var($String, word, arr$->get(i$));
						{
							try {
								$Class* clz = $nc($($ClassLoader::getSystemClassLoader()))->loadClass(word);
								$var($Object, witness, $nc(clz)->newInstance());
							} catch ($Exception& ex) {
								$nc($System::err)->println($$str({"Can\'t load config class \""_s, word, "\""_s}));
								$nc($System::err)->println($$str({""_s, ex}));
							}
						}
					}
				}
				setLevelsOnExistingLoggers();
				this->globalHandlersState = LogManager::STATE_UNINITIALIZED;
			} catch ($Throwable& t) {
				this->globalHandlersState = LogManager::STATE_INITIALIZED;
				$throw(t);
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			$nc(this->configurationLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
	invokeConfigurationListeners();
}

$String* LogManager::trim($String* value) {
	$init(LogManager);
	return value == nullptr ? ($String*)nullptr : $nc(value)->trim();
}

void LogManager::updateConfiguration($Function* mapper) {
	$useLocalCurrentObjectStackCache();
	checkPermission();
	ensureLogManagerInitialized();
	drainLoggerRefQueueBounded();
	$var($String, fname, getConfigurationFileName());
	{
		$var($InputStream, in, $new($FileInputStream, fname));
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$var($BufferedInputStream, bin, $new($BufferedInputStream, in));
					updateConfiguration(bin, mapper);
				} catch ($Throwable& t$) {
					try {
						in->close();
					} catch ($Throwable& x2) {
						t$->addSuppressed(x2);
					}
					$throw(t$);
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				in->close();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void LogManager::updateConfiguration($InputStream* ins, $Function* mapper) {
	$useLocalCurrentObjectStackCache();
	checkPermission();
	ensureLogManagerInitialized();
	drainLoggerRefQueueBounded();
	$var($Properties, previous, nullptr);
	$var($Set, updatePropertyNames, nullptr);
	$var($List, cxs, $Collections::emptyList());
	$var($LogManager$VisitedLoggers, visited, $new($LogManager$VisitedLoggers));
	$var($Properties, next, $new($Properties));
	try {
		next->load(ins);
	} catch ($IllegalArgumentException& x) {
		$throwNew($IOException, $(x->getMessage()), x);
	}
	if (this->globalHandlersState == LogManager::STATE_SHUTDOWN) {
		return;
	}
	$nc(this->configurationLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			if (this->globalHandlersState == LogManager::STATE_SHUTDOWN) {
				return$1 = true;
				goto $finally;
			}
			$assign(previous, this->props);
			$var($Stream, var$2, $nc($($nc(previous)->stringPropertyNames()))->stream());
			$assign(updatePropertyNames, $cast($Set, $nc($($Stream::concat(var$2, $($nc($(next->stringPropertyNames()))->stream()))))->collect($($Collectors::toCollection(static_cast<$Supplier*>($$new(LogManager$$Lambda$TreeSet)))))));
			if (mapper != nullptr) {
				$nc($($nc(updatePropertyNames)->stream()))->forEachOrdered(static_cast<$Consumer*>($$new(LogManager$$Lambda$lambda$updateConfiguration$0$1, previous, next, mapper)));
			}
			$set(this, props, next);
			$var($Stream, allKeys, $nc($($nc($($nc(updatePropertyNames)->stream()))->filter(static_cast<$Predicate*>($$new(LogManager$$Lambda$matches$2)))))->filter(static_cast<$Predicate*>($$new(LogManager$$Lambda$lambda$updateConfiguration$1$3, previous, next))));
			$var($Function, var$3, static_cast<$Function*>($new(LogManager$$Lambda$getLoggerName$4)));
			$var($Supplier, var$4, static_cast<$Supplier*>($new(LogManager$$Lambda$TreeMap$5)));
			$var($Map, loggerConfigs, $cast($Map, $nc(allKeys)->collect($($Collectors::groupingBy(var$3, var$4, $($Collectors::toCollection(static_cast<$Supplier*>($$new(LogManager$$Lambda$TreeSet)))))))));
			if (!$nc(loggerConfigs)->isEmpty()) {
				$assign(cxs, contexts());
			}
			$var($List, loggers, $nc(cxs)->isEmpty() ? $Collections::emptyList() : static_cast<$List*>($new($ArrayList, $nc(cxs)->size())));
			{
				$var($Iterator, i$, $nc($($nc(loggerConfigs)->entrySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
					{
						$var($String, name, $cast($String, $nc(e)->getKey()));
						$var($Set, properties, $cast($Set, e->getValue()));
						$nc(loggers)->clear();
						{
							$var($Iterator, i$, $nc(cxs)->iterator());
							for (; $nc(i$)->hasNext();) {
								$var($LogManager$LoggerContext, cx, $cast($LogManager$LoggerContext, i$->next()));
								{
									$var($Logger, l, $nc(cx)->findLogger(name));
									if (l != nullptr && !visited->test(l)) {
										loggers->add(l);
									}
								}
							}
						}
						if (loggers->isEmpty()) {
							continue;
						}
						{
							$var($Iterator, i$, $nc(properties)->iterator());
							for (; $nc(i$)->hasNext();) {
								$var($String, pk, $cast($String, i$->next()));
								{
									$LogManager$ConfigProperty* cp = $cast($LogManager$ConfigProperty, $nc($($LogManager$ConfigProperty::find(pk)))->get());
									$var($String, p, $nc(previous)->getProperty(pk, nullptr));
									$var($String, n, next->getProperty(pk, nullptr));
									$LogManager$ModType* mod = $LogManager$ModType::of(p, n);
									if (mod == $LogManager$ModType::SAME) {
										continue;
									}
									$init($LogManager$7);
									{
										$var($Level, level, nullptr)
										$var($List, hdls, nullptr)
										switch ($nc($LogManager$7::$SwitchMap$java$util$logging$LogManager$ConfigProperty)->get($nc((cp))->ordinal())) {
										case 1:
											{
												if (mod == $LogManager$ModType::REMOVED) {
													continue;
												}
												$assign(level, $Level::findLevel($(trim(n))));
												if (level != nullptr) {
													if ($nc(name)->isEmpty()) {
														$nc(this->rootLogger)->setLevel(level);
													}
													{
														$var($Iterator, i$, loggers->iterator());
														for (; $nc(i$)->hasNext();) {
															$var($Logger, l, $cast($Logger, i$->next()));
															{
																if (!$nc(name)->isEmpty() || l != this->rootLogger) {
																	$nc(l)->setLevel(level);
																}
															}
														}
													}
												}
												break;
											}
										case 2:
											{
												if (!$nc(name)->isEmpty()) {
													bool useParent = getBooleanProperty(pk, true);
													if (n != nullptr || p != nullptr) {
														{
															$var($Iterator, i$, loggers->iterator());
															for (; $nc(i$)->hasNext();) {
																$var($Logger, l, $cast($Logger, i$->next()));
																{
																	$nc(l)->setUseParentHandlers(useParent);
																}
															}
														}
													}
												}
												break;
											}
										case 3:
											{
												$assign(hdls, nullptr);
												if ($nc(name)->isEmpty()) {
													this->globalHandlersState = LogManager::STATE_READING_CONFIG;
													try {
														closeHandlers(this->rootLogger);
														this->globalHandlersState = LogManager::STATE_UNINITIALIZED;
													} catch ($Throwable& t) {
														this->globalHandlersState = LogManager::STATE_INITIALIZED;
														$throw(t);
													}
												}
												{
													$var($Iterator, i$, loggers->iterator());
													for (; $nc(i$)->hasNext();) {
														$var($Logger, l, $cast($Logger, i$->next()));
														{
															if (l == this->rootLogger) {
																continue;
															}
															closeHandlers(l);
															if (mod == $LogManager$ModType::REMOVED) {
																$nc(this->closeOnResetLoggers)->removeIf(static_cast<$Predicate*>($$new(LogManager$$Lambda$lambda$updateConfiguration$2$6, l)));
																continue;
															}
															if (hdls == nullptr) {
																$assign(hdls, $nc(name)->isEmpty() ? $Arrays::asList($($nc(this->rootLogger)->getHandlers())) : createLoggerHandlers(name, pk));
															}
															setLoggerHandlers(l, name, pk, hdls);
														}
													}
												}
												break;
											}
										default:
											{
												break;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		} catch ($Throwable& var$5) {
			$assign(var$0, var$5);
		} $finally: {
			$nc(this->configurationLock)->unlock();
			visited->clear();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
	drainLoggerRefQueueBounded();
	{
		$var($Iterator, i$, $nc(cxs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($LogManager$LoggerContext, cx, $cast($LogManager$LoggerContext, i$->next()));
			{
				{
					$var($Enumeration, names, $nc(cx)->getLoggerNames());
					for (; $nc(names)->hasMoreElements();) {
						$var($String, name, $cast($String, names->nextElement()));
						if ($nc(name)->isEmpty()) {
							continue;
						}
						$var($Logger, l, cx->findLogger(name));
						if (l != nullptr && !visited->test(l)) {
							cx->processParentHandlers(l, name, visited);
						}
					}
				}
			}
		}
	}
	invokeConfigurationListeners();
}

$String* LogManager::getProperty($String* name) {
	return $nc(this->props)->getProperty(name);
}

$String* LogManager::getStringProperty($String* name, $String* defaultValue) {
	$var($String, val, getProperty(name));
	if (val == nullptr) {
		return defaultValue;
	}
	return $nc(val)->trim();
}

int32_t LogManager::getIntProperty($String* name, int32_t defaultValue) {
	$useLocalCurrentObjectStackCache();
	$var($String, val, getProperty(name));
	if (val == nullptr) {
		return defaultValue;
	}
	try {
		return $Integer::parseInt($($nc(val)->trim()));
	} catch ($Exception& ex) {
		return defaultValue;
	}
	$shouldNotReachHere();
}

int64_t LogManager::getLongProperty($String* name, int64_t defaultValue) {
	$useLocalCurrentObjectStackCache();
	$var($String, val, getProperty(name));
	if (val == nullptr) {
		return defaultValue;
	}
	try {
		return $Long::parseLong($($nc(val)->trim()));
	} catch ($Exception& ex) {
		return defaultValue;
	}
	$shouldNotReachHere();
}

bool LogManager::getBooleanProperty($String* name, bool defaultValue) {
	$var($String, val, getProperty(name));
	if (val == nullptr) {
		return defaultValue;
	}
	$assign(val, $nc(val)->toLowerCase());
	bool var$0 = val->equals("true"_s);
	if (var$0 || val->equals("1"_s)) {
		return true;
	} else {
		bool var$2 = val->equals("false"_s);
		if (var$2 || val->equals("0"_s)) {
			return false;
		}
	}
	return defaultValue;
}

$Level* LogManager::getLevelProperty($String* name, $Level* defaultValue) {
	$useLocalCurrentObjectStackCache();
	$var($String, val, getProperty(name));
	if (val == nullptr) {
		return defaultValue;
	}
	$var($Level, l, $Level::findLevel($($nc(val)->trim())));
	return l != nullptr ? l : defaultValue;
}

$Filter* LogManager::getFilterProperty($String* name, $Filter* defaultValue) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, val, getProperty(name));
	try {
		if (val != nullptr) {
			$var($Object, o, $nc($nc($($ClassLoader::getSystemClassLoader()))->loadClass(val))->newInstance());
			return $cast($Filter, o);
		}
	} catch ($Exception& ex) {
	}
	return defaultValue;
}

$Formatter* LogManager::getFormatterProperty($String* name, $Formatter* defaultValue) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, val, getProperty(name));
	try {
		if (val != nullptr) {
			$var($Object, o, $nc($nc($($ClassLoader::getSystemClassLoader()))->loadClass(val))->newInstance());
			return $cast($Formatter, o);
		}
	} catch ($Exception& ex) {
	}
	return defaultValue;
}

void LogManager::initializeGlobalHandlers() {
	$useLocalCurrentObjectStackCache();
	int32_t state = this->globalHandlersState;
	if (state == LogManager::STATE_INITIALIZED || state == LogManager::STATE_SHUTDOWN) {
		return;
	}
	$nc(this->configurationLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			if (this->globalHandlersState != LogManager::STATE_UNINITIALIZED) {
				return$1 = true;
				goto $finally;
			}
			this->globalHandlersState = LogManager::STATE_INITIALIZING;
			{
				$var($Throwable, var$2, nullptr);
				try {
					loadLoggerHandlers(this->rootLogger, nullptr, "handlers"_s);
				} catch ($Throwable& var$3) {
					$assign(var$2, var$3);
				} /*finally*/ {
					this->globalHandlersState = LogManager::STATE_INITIALIZED;
				}
				if (var$2 != nullptr) {
					$throw(var$2);
				}
			}
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			$nc(this->configurationLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

void LogManager::checkPermission() {
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		sm->checkPermission(LogManager::controlPermission);
	}
}

void LogManager::checkAccess() {
	checkPermission();
}

void LogManager::setLevelsOnExistingLoggers() {
	$useLocalCurrentObjectStackCache();
	$var($Enumeration, enum_, $nc(this->props)->propertyNames());
	while ($nc(enum_)->hasMoreElements()) {
		$var($String, key, $cast($String, enum_->nextElement()));
		if (!$nc(key)->endsWith(".level"_s)) {
			continue;
		}
		int32_t ix = $nc(key)->length() - 6;
		$var($String, name, key->substring(0, ix));
		$var($Level, level, getLevelProperty(key, nullptr));
		if (level == nullptr) {
			$nc($System::err)->println($$str({"Bad level value for property: "_s, key}));
			continue;
		}
		{
			$var($Iterator, i$, $nc($(contexts()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($LogManager$LoggerContext, cx, $cast($LogManager$LoggerContext, i$->next()));
				{
					$var($Logger, l, $nc(cx)->findLogger(name));
					if (l == nullptr) {
						continue;
					}
					$nc(l)->setLevel(level);
				}
			}
		}
	}
}

$LoggingMXBean* LogManager::getLoggingMXBean() {
	$load(LogManager);
	$synchronized(class$) {
		$init(LogManager);
		return $Logging::getInstance();
	}
}

LogManager* LogManager::addConfigurationListener($Runnable* listener) {
	$useLocalCurrentObjectStackCache();
	$var($Runnable, r, $cast($Runnable, $Objects::requireNonNull(listener)));
	checkPermission();
	$var($SecurityManager, sm, $System::getSecurityManager());
	$var($AccessControlContext, acc, sm == nullptr ? ($AccessControlContext*)nullptr : $AccessController::getContext());
	$var($PrivilegedAction, pa, acc == nullptr ? ($PrivilegedAction*)nullptr : static_cast<$PrivilegedAction*>($new(LogManager$$Lambda$lambda$addConfigurationListener$3$7, r)));
	$var($Runnable, pr, acc == nullptr ? r : static_cast<$Runnable*>($new(LogManager$$Lambda$lambda$addConfigurationListener$4$8, pa, acc)));
	$nc(this->listeners)->putIfAbsent(r, pr);
	return this;
}

void LogManager::removeConfigurationListener($Runnable* listener) {
	$var($Runnable, key, $cast($Runnable, $Objects::requireNonNull(listener)));
	checkPermission();
	$nc(this->listeners)->remove(key);
}

void LogManager::invokeConfigurationListeners() {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, t, nullptr);
	{
		$var($RunnableArray, arr$, $fcast($RunnableArray, $nc($($nc(this->listeners)->values()))->toArray($$new($RunnableArray, 0))));
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Runnable, c, arr$->get(i$));
			{
				try {
					$nc(c)->run();
				} catch ($ThreadDeath& death) {
					$throw(death);
				} catch ($Error& x) {
					if (t == nullptr) {
						$assign(t, x);
					} else {
						$nc(t)->addSuppressed(x);
					}
				} catch ($RuntimeException& x) {
					if (t == nullptr) {
						$assign(t, x);
					} else {
						$nc(t)->addSuppressed(x);
					}
				}
			}
		}
	}
	if ($instanceOf($Error, t)) {
		$throw($cast($Error, t));
	}
	if ($instanceOf($RuntimeException, t)) {
		$throw($cast($RuntimeException, t));
	}
}

void LogManager::initStatic() {
	$init(LogManager);
	$beforeCallerSensitive();
	$init($LogManager$LoggingProviderAccess);
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($LogManager$LoggingProviderAccess::INSTANCE), ($AccessControlContext*)nullptr, $$new($PermissionArray, {LogManager::controlPermission}));
}

void LogManager::lambda$addConfigurationListener$4($PrivilegedAction* pa, $AccessControlContext* acc) {
	$init(LogManager);
	$beforeCallerSensitive();
	$AccessController::doPrivileged(pa, acc);
}

$Void* LogManager::lambda$addConfigurationListener$3($Runnable* r) {
	$init(LogManager);
	$nc(r)->run();
	return nullptr;
}

bool LogManager::lambda$updateConfiguration$2($Logger* l, $LogManager$CloseOnReset* c) {
	$init(LogManager);
	return $nc(c)->logger == l;
}

bool LogManager::lambda$updateConfiguration$1($Properties* previous, $Properties* next, $String* k) {
	$init(LogManager);
	return $LogManager$ConfigProperty::needsUpdating(k, previous, next);
}

void LogManager::lambda$updateConfiguration$0($Properties* previous, $Properties* next, $Function* mapper, $String* k) {
	$init(LogManager);
	$LogManager$ConfigProperty::merge(k, previous, next, $cast($BiFunction, $Objects::requireNonNull($cast($BiFunction, $($nc(mapper)->apply(k))))));
}

void clinit$LogManager($Class* class$) {
	$assignStatic(LogManager::LOGGING_MXBEAN_NAME, "java.util.logging:type=Logging"_s);
	$beforeCallerSensitive();
	LogManager::$assertionsDisabled = !LogManager::class$->desiredAssertionStatus();
	$init($Level);
	$assignStatic(LogManager::defaultLevel, $Level::INFO);
	$assignStatic(LogManager::manager, $cast(LogManager, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($LogManager$1)))));
	$assignStatic(LogManager::controlPermission, $new($LoggingPermission, "control"_s, nullptr));
	{
		LogManager::initStatic();
	}
}

LogManager::LogManager() {
}

$Class* LogManager::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LogManager$$Lambda$TreeSet::classInfo$.name)) {
			return LogManager$$Lambda$TreeSet::load$(name, initialize);
		}
		if (name->equals(LogManager$$Lambda$lambda$updateConfiguration$0$1::classInfo$.name)) {
			return LogManager$$Lambda$lambda$updateConfiguration$0$1::load$(name, initialize);
		}
		if (name->equals(LogManager$$Lambda$matches$2::classInfo$.name)) {
			return LogManager$$Lambda$matches$2::load$(name, initialize);
		}
		if (name->equals(LogManager$$Lambda$lambda$updateConfiguration$1$3::classInfo$.name)) {
			return LogManager$$Lambda$lambda$updateConfiguration$1$3::load$(name, initialize);
		}
		if (name->equals(LogManager$$Lambda$getLoggerName$4::classInfo$.name)) {
			return LogManager$$Lambda$getLoggerName$4::load$(name, initialize);
		}
		if (name->equals(LogManager$$Lambda$TreeMap$5::classInfo$.name)) {
			return LogManager$$Lambda$TreeMap$5::load$(name, initialize);
		}
		if (name->equals(LogManager$$Lambda$lambda$updateConfiguration$2$6::classInfo$.name)) {
			return LogManager$$Lambda$lambda$updateConfiguration$2$6::load$(name, initialize);
		}
		if (name->equals(LogManager$$Lambda$lambda$addConfigurationListener$3$7::classInfo$.name)) {
			return LogManager$$Lambda$lambda$addConfigurationListener$3$7::load$(name, initialize);
		}
		if (name->equals(LogManager$$Lambda$lambda$addConfigurationListener$4$8::classInfo$.name)) {
			return LogManager$$Lambda$lambda$addConfigurationListener$4$8::load$(name, initialize);
		}
	}
	$loadClass(LogManager, name, initialize, &_LogManager_ClassInfo_, clinit$LogManager, allocate$LogManager);
	return class$;
}

$Class* LogManager::class$ = nullptr;

		} // logging
	} // util
} // java