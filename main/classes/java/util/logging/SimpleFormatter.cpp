#include <java/util/logging/SimpleFormatter.h>

#include <java/io/PrintWriter.h>
#include <java/io/Serializable.h>
#include <java/io/StringWriter.h>
#include <java/io/Writer.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/time/Instant.h>
#include <java/time/ZoneId.h>
#include <java/time/ZonedDateTime.h>
#include <java/util/function/Function.h>
#include <java/util/logging/Formatter.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/LogRecord.h>
#include <jdk/internal/logger/SurrogateLogger.h>
#include <jcpp.h>

using $PrintWriter = ::java::io::PrintWriter;
using $Serializable = ::java::io::Serializable;
using $StringWriter = ::java::io::StringWriter;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Instant = ::java::time::Instant;
using $ZoneId = ::java::time::ZoneId;
using $ZonedDateTime = ::java::time::ZonedDateTime;
using $Function = ::java::util::function::Function;
using $Formatter = ::java::util::logging::Formatter;
using $Level = ::java::util::logging::Level;
using $LogManager = ::java::util::logging::LogManager;
using $LogRecord = ::java::util::logging::LogRecord;
using $SurrogateLogger = ::jdk::internal::logger::SurrogateLogger;

namespace java {
	namespace util {
		namespace logging {

class SimpleFormatter$$Lambda$getLoggingProperty : public $Function {
	$class(SimpleFormatter$$Lambda$getLoggingProperty, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* name) override {
		 return $of(SimpleFormatter::getLoggingProperty($cast($String, name)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SimpleFormatter$$Lambda$getLoggingProperty>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SimpleFormatter$$Lambda$getLoggingProperty::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SimpleFormatter$$Lambda$getLoggingProperty::*)()>(&SimpleFormatter$$Lambda$getLoggingProperty::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SimpleFormatter$$Lambda$getLoggingProperty::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.SimpleFormatter$$Lambda$getLoggingProperty",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* SimpleFormatter$$Lambda$getLoggingProperty::load$($String* name, bool initialize) {
	$loadClass(SimpleFormatter$$Lambda$getLoggingProperty, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SimpleFormatter$$Lambda$getLoggingProperty::class$ = nullptr;

$FieldInfo _SimpleFormatter_FieldInfo_[] = {
	{"format", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(SimpleFormatter, format$)},
	{}
};

$MethodInfo _SimpleFormatter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SimpleFormatter::*)()>(&SimpleFormatter::init$))},
	{"format", "(Ljava/util/logging/LogRecord;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"getLoggingProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $method(static_cast<$String*(*)($String*)>(&SimpleFormatter::getLoggingProperty))},
	{}
};

$ClassInfo _SimpleFormatter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.logging.SimpleFormatter",
	"java.util.logging.Formatter",
	nullptr,
	_SimpleFormatter_FieldInfo_,
	_SimpleFormatter_MethodInfo_
};

$Object* allocate$SimpleFormatter($Class* clazz) {
	return $of($alloc(SimpleFormatter));
}

$String* SimpleFormatter::getLoggingProperty($String* name) {
	$init(SimpleFormatter);
	return $nc($($LogManager::getLogManager()))->getProperty(name);
}

void SimpleFormatter::init$() {
	$Formatter::init$();
	$set(this, format$, $SurrogateLogger::getSimpleFormat(static_cast<$Function*>($$new(SimpleFormatter$$Lambda$getLoggingProperty))));
}

$String* SimpleFormatter::format($LogRecord* record) {
	$useLocalCurrentObjectStackCache();
	$var($Instant, var$0, $nc(record)->getInstant());
	$var($ZonedDateTime, zdt, $ZonedDateTime::ofInstant(var$0, $($ZoneId::systemDefault())));
	$var($String, source, nullptr);
	if ($nc(record)->getSourceClassName() != nullptr) {
		$assign(source, record->getSourceClassName());
		if (record->getSourceMethodName() != nullptr) {
			$plusAssign(source, $$str({" "_s, $(record->getSourceMethodName())}));
		}
	} else {
		$assign(source, record->getLoggerName());
	}
	$var($String, message, formatMessage(record));
	$var($String, throwable, ""_s);
	if ($nc(record)->getThrown() != nullptr) {
		$var($StringWriter, sw, $new($StringWriter));
		$var($PrintWriter, pw, $new($PrintWriter, static_cast<$Writer*>(sw)));
		pw->println();
		$nc($(record->getThrown()))->printStackTrace(pw);
		pw->close();
		$assign(throwable, sw->toString());
	}
	return $String::format(this->format$, $$new($ObjectArray, {
		$of(zdt),
		$of(source),
		$($of($nc(record)->getLoggerName())),
		$($of($nc($(record->getLevel()))->getLocalizedLevelName())),
		$of(message),
		$of(throwable)
	}));
}

SimpleFormatter::SimpleFormatter() {
}

$Class* SimpleFormatter::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SimpleFormatter$$Lambda$getLoggingProperty::classInfo$.name)) {
			return SimpleFormatter$$Lambda$getLoggingProperty::load$(name, initialize);
		}
	}
	$loadClass(SimpleFormatter, name, initialize, &_SimpleFormatter_ClassInfo_, allocate$SimpleFormatter);
	return class$;
}

$Class* SimpleFormatter::class$ = nullptr;

		} // logging
	} // util
} // java