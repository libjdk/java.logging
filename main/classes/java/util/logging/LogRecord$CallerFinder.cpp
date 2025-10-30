#include <java/util/logging/LogRecord$CallerFinder.h>

#include <java/io/Serializable.h>
#include <java/lang/StackWalker$Option.h>
#include <java/lang/StackWalker$StackFrame.h>
#include <java/lang/StackWalker.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Optional.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/logging/LogRecord.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/logger/SurrogateLogger.h>
#include <jcpp.h>

#undef RETAIN_CLASS_REFERENCE
#undef WALKER

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $StackWalker = ::java::lang::StackWalker;
using $StackWalker$Option = ::java::lang::StackWalker$Option;
using $StackWalker$StackFrame = ::java::lang::StackWalker$StackFrame;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Optional = ::java::util::Optional;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $LogRecord = ::java::util::logging::LogRecord;
using $Stream = ::java::util::stream::Stream;
using $SurrogateLogger = ::jdk::internal::logger::SurrogateLogger;

namespace java {
	namespace util {
		namespace logging {

class LogRecord$CallerFinder$$Lambda$lambda$get$1 : public $Function {
	$class(LogRecord$CallerFinder$$Lambda$lambda$get$1, $NO_CLASS_INIT, $Function)
public:
	void init$(LogRecord$CallerFinder* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* apply(Object$* s) override {
		 return $of($nc(inst$)->lambda$get$1($cast($Stream, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LogRecord$CallerFinder$$Lambda$lambda$get$1>());
	}
	LogRecord$CallerFinder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LogRecord$CallerFinder$$Lambda$lambda$get$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(LogRecord$CallerFinder$$Lambda$lambda$get$1, inst$)},
	{}
};
$MethodInfo LogRecord$CallerFinder$$Lambda$lambda$get$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/logging/LogRecord$CallerFinder;)V", nullptr, $PUBLIC, $method(static_cast<void(LogRecord$CallerFinder$$Lambda$lambda$get$1::*)(LogRecord$CallerFinder*)>(&LogRecord$CallerFinder$$Lambda$lambda$get$1::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo LogRecord$CallerFinder$$Lambda$lambda$get$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.LogRecord$CallerFinder$$Lambda$lambda$get$1",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* LogRecord$CallerFinder$$Lambda$lambda$get$1::load$($String* name, bool initialize) {
	$loadClass(LogRecord$CallerFinder$$Lambda$lambda$get$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LogRecord$CallerFinder$$Lambda$lambda$get$1::class$ = nullptr;

class LogRecord$CallerFinder$$Lambda$lambda$static$0$1 : public $PrivilegedAction {
	$class(LogRecord$CallerFinder$$Lambda$lambda$static$0$1, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$() {
	}
	virtual $Object* run() override {
		 return $of(LogRecord$CallerFinder::lambda$static$0());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LogRecord$CallerFinder$$Lambda$lambda$static$0$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo LogRecord$CallerFinder$$Lambda$lambda$static$0$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(LogRecord$CallerFinder$$Lambda$lambda$static$0$1::*)()>(&LogRecord$CallerFinder$$Lambda$lambda$static$0$1::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo LogRecord$CallerFinder$$Lambda$lambda$static$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.LogRecord$CallerFinder$$Lambda$lambda$static$0$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	methodInfos
};
$Class* LogRecord$CallerFinder$$Lambda$lambda$static$0$1::load$($String* name, bool initialize) {
	$loadClass(LogRecord$CallerFinder$$Lambda$lambda$static$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LogRecord$CallerFinder$$Lambda$lambda$static$0$1::class$ = nullptr;

$FieldInfo _LogRecord$CallerFinder_FieldInfo_[] = {
	{"WALKER", "Ljava/lang/StackWalker;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LogRecord$CallerFinder, WALKER)},
	{"lookingForLogger", "Z", nullptr, $PRIVATE, $field(LogRecord$CallerFinder, lookingForLogger)},
	{}
};

$MethodInfo _LogRecord$CallerFinder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(LogRecord$CallerFinder::*)()>(&LogRecord$CallerFinder::init$))},
	{"get", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/lang/StackWalker$StackFrame;>;", 0, $method(static_cast<$Optional*(LogRecord$CallerFinder::*)()>(&LogRecord$CallerFinder::get))},
	{"isLoggerImplFrame", "(Ljava/lang/String;)Z", nullptr, $PRIVATE, $method(static_cast<bool(LogRecord$CallerFinder::*)($String*)>(&LogRecord$CallerFinder::isLoggerImplFrame))},
	{"lambda$get$1", "(Ljava/util/stream/Stream;)Ljava/util/Optional;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$Optional*(LogRecord$CallerFinder::*)($Stream*)>(&LogRecord$CallerFinder::lambda$get$1))},
	{"lambda$static$0", "()Ljava/lang/StackWalker;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$StackWalker*(*)()>(&LogRecord$CallerFinder::lambda$static$0))},
	{"test", "(Ljava/lang/StackWalker$StackFrame;)Z", nullptr, $PUBLIC, $method(static_cast<bool(LogRecord$CallerFinder::*)($StackWalker$StackFrame*)>(&LogRecord$CallerFinder::test))},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{}
};

$InnerClassInfo _LogRecord$CallerFinder_InnerClassesInfo_[] = {
	{"java.util.logging.LogRecord$CallerFinder", "java.util.logging.LogRecord", "CallerFinder", $STATIC | $FINAL},
	{"java.lang.StackWalker$StackFrame", "java.lang.StackWalker", "StackFrame", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _LogRecord$CallerFinder_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.logging.LogRecord$CallerFinder",
	"java.lang.Object",
	"java.util.function.Predicate",
	_LogRecord$CallerFinder_FieldInfo_,
	_LogRecord$CallerFinder_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/function/Predicate<Ljava/lang/StackWalker$StackFrame;>;",
	nullptr,
	_LogRecord$CallerFinder_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogRecord"
};

$Object* allocate$LogRecord$CallerFinder($Class* clazz) {
	return $of($alloc(LogRecord$CallerFinder));
}

$StackWalker* LogRecord$CallerFinder::WALKER = nullptr;

void LogRecord$CallerFinder::init$() {
	this->lookingForLogger = true;
}

$Optional* LogRecord$CallerFinder::get() {
	$beforeCallerSensitive();
	return $cast($Optional, $nc(LogRecord$CallerFinder::WALKER)->walk(static_cast<$Function*>($$new(LogRecord$CallerFinder$$Lambda$lambda$get$1, this))));
}

bool LogRecord$CallerFinder::test($StackWalker$StackFrame* t) {
	$var($String, cname, $nc(t)->getClassName());
	if (this->lookingForLogger) {
		this->lookingForLogger = !isLoggerImplFrame(cname);
		return false;
	}
	return !$SurrogateLogger::isFilteredFrame(t);
}

bool LogRecord$CallerFinder::isLoggerImplFrame($String* cname) {
	bool var$0 = $nc(cname)->equals("java.util.logging.Logger"_s);
	return (var$0 || $nc(cname)->startsWith("sun.util.logging.PlatformLogger"_s));
}

bool LogRecord$CallerFinder::test(Object$* t) {
	return this->test($cast($StackWalker$StackFrame, t));
}

$Optional* LogRecord$CallerFinder::lambda$get$1($Stream* s) {
	return $nc($($nc(s)->filter(this)))->findFirst();
}

$StackWalker* LogRecord$CallerFinder::lambda$static$0() {
	$init(LogRecord$CallerFinder);
	$init($StackWalker$Option);
	return $StackWalker::getInstance($StackWalker$Option::RETAIN_CLASS_REFERENCE);
}

void clinit$LogRecord$CallerFinder($Class* class$) {
	$beforeCallerSensitive();
	{
		$var($PrivilegedAction, action, static_cast<$PrivilegedAction*>($new(LogRecord$CallerFinder$$Lambda$lambda$static$0$1)));
		$assignStatic(LogRecord$CallerFinder::WALKER, $cast($StackWalker, $AccessController::doPrivileged(action)));
	}
}

LogRecord$CallerFinder::LogRecord$CallerFinder() {
}

$Class* LogRecord$CallerFinder::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LogRecord$CallerFinder$$Lambda$lambda$get$1::classInfo$.name)) {
			return LogRecord$CallerFinder$$Lambda$lambda$get$1::load$(name, initialize);
		}
		if (name->equals(LogRecord$CallerFinder$$Lambda$lambda$static$0$1::classInfo$.name)) {
			return LogRecord$CallerFinder$$Lambda$lambda$static$0$1::load$(name, initialize);
		}
	}
	$loadClass(LogRecord$CallerFinder, name, initialize, &_LogRecord$CallerFinder_ClassInfo_, clinit$LogRecord$CallerFinder, allocate$LogRecord$CallerFinder);
	return class$;
}

$Class* LogRecord$CallerFinder::class$ = nullptr;

		} // logging
	} // util
} // java