#include <java/util/logging/LogManager$ConfigProperty.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Enum.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Collection.h>
#include <java/util/EnumSet.h>
#include <java/util/Iterator.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/Properties.h>
#include <java/util/Set.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/Predicate.h>
#include <java/util/logging/LogManager.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

#undef ALL
#undef HANDLERS
#undef LEVEL
#undef USEPARENT

using $LogManager$ConfigPropertyArray = $Array<::java::util::logging::LogManager$ConfigProperty>;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Collection = ::java::util::Collection;
using $EnumSet = ::java::util::EnumSet;
using $Iterator = ::java::util::Iterator;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Properties = ::java::util::Properties;
using $Set = ::java::util::Set;
using $BiFunction = ::java::util::function::BiFunction;
using $Predicate = ::java::util::function::Predicate;
using $LogManager = ::java::util::logging::LogManager;
using $Stream = ::java::util::stream::Stream;

namespace java {
	namespace util {
		namespace logging {

class LogManager$ConfigProperty$$Lambda$lambda$find$0 : public $Predicate {
	$class(LogManager$ConfigProperty$$Lambda$lambda$find$0, $NO_CLASS_INIT, $Predicate)
public:
	void init$($String* property) {
		$set(this, property, property);
	}
	virtual bool test(Object$* p) override {
		 return LogManager$ConfigProperty::lambda$find$0(property, $cast(LogManager$ConfigProperty, p));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LogManager$ConfigProperty$$Lambda$lambda$find$0>());
	}
	$String* property = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LogManager$ConfigProperty$$Lambda$lambda$find$0::fieldInfos[2] = {
	{"property", "Ljava/lang/String;", nullptr, $PUBLIC, $field(LogManager$ConfigProperty$$Lambda$lambda$find$0, property)},
	{}
};
$MethodInfo LogManager$ConfigProperty$$Lambda$lambda$find$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(LogManager$ConfigProperty$$Lambda$lambda$find$0::*)($String*)>(&LogManager$ConfigProperty$$Lambda$lambda$find$0::init$))},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo LogManager$ConfigProperty$$Lambda$lambda$find$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.LogManager$ConfigProperty$$Lambda$lambda$find$0",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* LogManager$ConfigProperty$$Lambda$lambda$find$0::load$($String* name, bool initialize) {
	$loadClass(LogManager$ConfigProperty$$Lambda$lambda$find$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LogManager$ConfigProperty$$Lambda$lambda$find$0::class$ = nullptr;

$FieldInfo _LogManager$ConfigProperty_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(LogManager$ConfigProperty, $assertionsDisabled)},
	{"LEVEL", "Ljava/util/logging/LogManager$ConfigProperty;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(LogManager$ConfigProperty, LEVEL)},
	{"HANDLERS", "Ljava/util/logging/LogManager$ConfigProperty;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(LogManager$ConfigProperty, HANDLERS)},
	{"USEPARENT", "Ljava/util/logging/LogManager$ConfigProperty;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(LogManager$ConfigProperty, USEPARENT)},
	{"$VALUES", "[Ljava/util/logging/LogManager$ConfigProperty;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(LogManager$ConfigProperty, $VALUES)},
	{"suffix", "Ljava/lang/String;", nullptr, $FINAL, $field(LogManager$ConfigProperty, suffix)},
	{"length", "I", nullptr, $FINAL, $field(LogManager$ConfigProperty, length)},
	{"ALL", "Ljava/util/EnumSet;", "Ljava/util/EnumSet<Ljava/util/logging/LogManager$ConfigProperty;>;", $PRIVATE | $STATIC | $FINAL, $staticField(LogManager$ConfigProperty, ALL)},
	{}
};

$MethodInfo _LogManager$ConfigProperty_MethodInfo_[] = {
	{"$values", "()[Ljava/util/logging/LogManager$ConfigProperty;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$LogManager$ConfigPropertyArray*(*)()>(&LogManager$ConfigProperty::$values))},
	{"<init>", "(Ljava/lang/String;ILjava/lang/String;)V", "(Ljava/lang/String;)V", $PRIVATE, $method(static_cast<void(LogManager$ConfigProperty::*)($String*,int32_t,$String*)>(&LogManager$ConfigProperty::init$))},
	{"find", "(Ljava/lang/String;)Ljava/util/Optional;", "(Ljava/lang/String;)Ljava/util/Optional<Ljava/util/logging/LogManager$ConfigProperty;>;", $STATIC, $method(static_cast<$Optional*(*)($String*)>(&LogManager$ConfigProperty::find))},
	{"getLoggerName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $STATIC, $method(static_cast<$String*(*)($String*)>(&LogManager$ConfigProperty::getLoggerName))},
	{"handleKey", "(Ljava/lang/String;)Z", nullptr, $PUBLIC, $method(static_cast<bool(LogManager$ConfigProperty::*)($String*)>(&LogManager$ConfigProperty::handleKey))},
	{"key", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, 0, $method(static_cast<$String*(LogManager$ConfigProperty::*)($String*)>(&LogManager$ConfigProperty::key))},
	{"lambda$find$0", "(Ljava/lang/String;Ljava/util/logging/LogManager$ConfigProperty;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($String*,LogManager$ConfigProperty*)>(&LogManager$ConfigProperty::lambda$find$0))},
	{"loggerName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, 0, $method(static_cast<$String*(LogManager$ConfigProperty::*)($String*)>(&LogManager$ConfigProperty::loggerName))},
	{"matches", "(Ljava/lang/String;)Z", nullptr, $STATIC, $method(static_cast<bool(*)($String*)>(&LogManager$ConfigProperty::matches))},
	{"merge", "(Ljava/lang/String;Ljava/util/Properties;Ljava/util/Properties;Ljava/util/function/BiFunction;)V", "(Ljava/lang/String;Ljava/util/Properties;Ljava/util/Properties;Ljava/util/function/BiFunction<Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;>;)V", $STATIC, $method(static_cast<void(*)($String*,$Properties*,$Properties*,$BiFunction*)>(&LogManager$ConfigProperty::merge))},
	{"needsUpdating", "(Ljava/lang/String;Ljava/util/Properties;Ljava/util/Properties;)Z", nullptr, $STATIC, $method(static_cast<bool(*)($String*,$Properties*,$Properties*)>(&LogManager$ConfigProperty::needsUpdating))},
	{"valueOf", "(Ljava/lang/String;)Ljava/util/logging/LogManager$ConfigProperty;", nullptr, $PUBLIC | $STATIC, $method(static_cast<LogManager$ConfigProperty*(*)($String*)>(&LogManager$ConfigProperty::valueOf))},
	{"values", "()[Ljava/util/logging/LogManager$ConfigProperty;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$LogManager$ConfigPropertyArray*(*)()>(&LogManager$ConfigProperty::values))},
	{}
};

$InnerClassInfo _LogManager$ConfigProperty_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$ConfigProperty", "java.util.logging.LogManager", "ConfigProperty", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _LogManager$ConfigProperty_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"java.util.logging.LogManager$ConfigProperty",
	"java.lang.Enum",
	nullptr,
	_LogManager$ConfigProperty_FieldInfo_,
	_LogManager$ConfigProperty_MethodInfo_,
	"Ljava/lang/Enum<Ljava/util/logging/LogManager$ConfigProperty;>;",
	nullptr,
	_LogManager$ConfigProperty_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$ConfigProperty($Class* clazz) {
	return $of($alloc(LogManager$ConfigProperty));
}

bool LogManager$ConfigProperty::$assertionsDisabled = false;
LogManager$ConfigProperty* LogManager$ConfigProperty::LEVEL = nullptr;
LogManager$ConfigProperty* LogManager$ConfigProperty::HANDLERS = nullptr;
LogManager$ConfigProperty* LogManager$ConfigProperty::USEPARENT = nullptr;
$LogManager$ConfigPropertyArray* LogManager$ConfigProperty::$VALUES = nullptr;
$EnumSet* LogManager$ConfigProperty::ALL = nullptr;

$LogManager$ConfigPropertyArray* LogManager$ConfigProperty::$values() {
	$init(LogManager$ConfigProperty);
	return $new($LogManager$ConfigPropertyArray, {
		LogManager$ConfigProperty::LEVEL,
		LogManager$ConfigProperty::HANDLERS,
		LogManager$ConfigProperty::USEPARENT
	});
}

$LogManager$ConfigPropertyArray* LogManager$ConfigProperty::values() {
	$init(LogManager$ConfigProperty);
	return $cast($LogManager$ConfigPropertyArray, LogManager$ConfigProperty::$VALUES->clone());
}

LogManager$ConfigProperty* LogManager$ConfigProperty::valueOf($String* name) {
	$init(LogManager$ConfigProperty);
	return $cast(LogManager$ConfigProperty, $Enum::valueOf(LogManager$ConfigProperty::class$, name));
}

void LogManager$ConfigProperty::init$($String* $enum$name, int32_t $enum$ordinal, $String* suffix) {
	$Enum::init$($enum$name, $enum$ordinal);
	$set(this, suffix, $cast($String, $Objects::requireNonNull(suffix)));
	this->length = suffix->length();
}

bool LogManager$ConfigProperty::handleKey($String* key) {
	if (this == LogManager$ConfigProperty::HANDLERS && $($nc(this->suffix)->substring(1))->equals(key)) {
		return true;
	}
	if (this == LogManager$ConfigProperty::HANDLERS && $nc(this->suffix)->equals(key)) {
		return false;
	}
	return $nc(key)->endsWith(this->suffix);
}

$String* LogManager$ConfigProperty::key($String* loggerName) {
	if (this == LogManager$ConfigProperty::HANDLERS && (loggerName == nullptr || $nc(loggerName)->isEmpty())) {
		return $nc(this->suffix)->substring(1);
	}
	return $str({loggerName, this->suffix});
}

$String* LogManager$ConfigProperty::loggerName($String* key) {
	$useLocalCurrentObjectStackCache();
	bool var$0 = !LogManager$ConfigProperty::$assertionsDisabled;
	if (var$0) {
		bool var$1 = $nc(key)->equals($($nc(this->suffix)->substring(1))) && this == LogManager$ConfigProperty::HANDLERS;
		var$0 = !(var$1 || $nc(key)->endsWith(this->suffix));
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	if (this == LogManager$ConfigProperty::HANDLERS && $($nc(this->suffix)->substring(1))->equals(key)) {
		return ""_s;
	}
	return $nc(key)->substring(0, key->length() - this->length);
}

$String* LogManager$ConfigProperty::getLoggerName($String* property) {
	$init(LogManager$ConfigProperty);
	{
		$var($Iterator, i$, $nc(LogManager$ConfigProperty::ALL)->iterator());
		for (; $nc(i$)->hasNext();) {
			LogManager$ConfigProperty* p = $cast(LogManager$ConfigProperty, i$->next());
			{
				if ($nc(p)->handleKey(property)) {
					return p->loggerName(property);
				}
			}
		}
	}
	return nullptr;
}

$Optional* LogManager$ConfigProperty::find($String* property) {
	$init(LogManager$ConfigProperty);
	$useLocalCurrentObjectStackCache();
	return $nc($($nc($($nc(LogManager$ConfigProperty::ALL)->stream()))->filter(static_cast<$Predicate*>($$new(LogManager$ConfigProperty$$Lambda$lambda$find$0, property)))))->findFirst();
}

bool LogManager$ConfigProperty::matches($String* property) {
	$init(LogManager$ConfigProperty);
	return $nc($(find(property)))->isPresent();
}

bool LogManager$ConfigProperty::needsUpdating($String* k, $Properties* previous, $Properties* next) {
	$init(LogManager$ConfigProperty);
	$useLocalCurrentObjectStackCache();
	$var($String, p, $LogManager::trim($($nc(previous)->getProperty(k, nullptr))));
	$var($String, n, $LogManager::trim($($nc(next)->getProperty(k, nullptr))));
	return !$Objects::equals(p, n);
}

void LogManager$ConfigProperty::merge($String* k, $Properties* previous, $Properties* next, $BiFunction* mappingFunction) {
	$init(LogManager$ConfigProperty);
	$useLocalCurrentObjectStackCache();
	$var($String, p, $LogManager::trim($($nc(previous)->getProperty(k, nullptr))));
	$var($String, n, $LogManager::trim($($nc(next)->getProperty(k, nullptr))));
	$var($String, mapped, $LogManager::trim($cast($String, $($nc(mappingFunction)->apply(p, n)))));
	if (!$Objects::equals(n, mapped)) {
		if (mapped == nullptr) {
			$nc(next)->remove(k);
		} else {
			$nc(next)->setProperty(k, mapped);
		}
	}
}

bool LogManager$ConfigProperty::lambda$find$0($String* property, LogManager$ConfigProperty* p) {
	$init(LogManager$ConfigProperty);
	return $nc(p)->handleKey(property);
}

void clinit$LogManager$ConfigProperty($Class* class$) {
	$load($LogManager);
	LogManager$ConfigProperty::$assertionsDisabled = !$LogManager::class$->desiredAssertionStatus();
	$assignStatic(LogManager$ConfigProperty::LEVEL, $new(LogManager$ConfigProperty, "LEVEL"_s, 0, ".level"_s));
	$assignStatic(LogManager$ConfigProperty::HANDLERS, $new(LogManager$ConfigProperty, "HANDLERS"_s, 1, ".handlers"_s));
	$assignStatic(LogManager$ConfigProperty::USEPARENT, $new(LogManager$ConfigProperty, "USEPARENT"_s, 2, ".useParentHandlers"_s));
	$assignStatic(LogManager$ConfigProperty::$VALUES, LogManager$ConfigProperty::$values());
	$assignStatic(LogManager$ConfigProperty::ALL, $EnumSet::allOf(LogManager$ConfigProperty::class$));
}

LogManager$ConfigProperty::LogManager$ConfigProperty() {
}

$Class* LogManager$ConfigProperty::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LogManager$ConfigProperty$$Lambda$lambda$find$0::classInfo$.name)) {
			return LogManager$ConfigProperty$$Lambda$lambda$find$0::load$(name, initialize);
		}
	}
	$loadClass(LogManager$ConfigProperty, name, initialize, &_LogManager$ConfigProperty_ClassInfo_, clinit$LogManager$ConfigProperty, allocate$LogManager$ConfigProperty);
	return class$;
}

$Class* LogManager$ConfigProperty::class$ = nullptr;

		} // logging
	} // util
} // java