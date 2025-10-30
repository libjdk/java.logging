#include <java/util/logging/LogManager$ModType.h>

#include <java/lang/Enum.h>
#include <java/util/Objects.h>
#include <java/util/logging/LogManager.h>
#include <jcpp.h>

#undef ADDED
#undef CHANGED
#undef REMOVED
#undef SAME

using $LogManager$ModTypeArray = $Array<::java::util::logging::LogManager$ModType>;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Objects = ::java::util::Objects;
using $LogManager = ::java::util::logging::LogManager;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LogManager$ModType_FieldInfo_[] = {
	{"SAME", "Ljava/util/logging/LogManager$ModType;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(LogManager$ModType, SAME)},
	{"ADDED", "Ljava/util/logging/LogManager$ModType;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(LogManager$ModType, ADDED)},
	{"CHANGED", "Ljava/util/logging/LogManager$ModType;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(LogManager$ModType, CHANGED)},
	{"REMOVED", "Ljava/util/logging/LogManager$ModType;", nullptr, $PUBLIC | $STATIC | $FINAL | $ENUM, $staticField(LogManager$ModType, REMOVED)},
	{"$VALUES", "[Ljava/util/logging/LogManager$ModType;", nullptr, $PRIVATE | $STATIC | $FINAL | $SYNTHETIC, $staticField(LogManager$ModType, $VALUES)},
	{}
};

$MethodInfo _LogManager$ModType_MethodInfo_[] = {
	{"$values", "()[Ljava/util/logging/LogManager$ModType;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$LogManager$ModTypeArray*(*)()>(&LogManager$ModType::$values))},
	{"<init>", "(Ljava/lang/String;I)V", "()V", $PRIVATE, $method(static_cast<void(LogManager$ModType::*)($String*,int32_t)>(&LogManager$ModType::init$))},
	{"of", "(Ljava/lang/String;Ljava/lang/String;)Ljava/util/logging/LogManager$ModType;", nullptr, $STATIC, $method(static_cast<LogManager$ModType*(*)($String*,$String*)>(&LogManager$ModType::of))},
	{"valueOf", "(Ljava/lang/String;)Ljava/util/logging/LogManager$ModType;", nullptr, $PUBLIC | $STATIC, $method(static_cast<LogManager$ModType*(*)($String*)>(&LogManager$ModType::valueOf))},
	{"values", "()[Ljava/util/logging/LogManager$ModType;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$LogManager$ModTypeArray*(*)()>(&LogManager$ModType::values))},
	{}
};

$InnerClassInfo _LogManager$ModType_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$ModType", "java.util.logging.LogManager", "ModType", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _LogManager$ModType_ClassInfo_ = {
	$FINAL | $ACC_SUPER | $ENUM,
	"java.util.logging.LogManager$ModType",
	"java.lang.Enum",
	nullptr,
	_LogManager$ModType_FieldInfo_,
	_LogManager$ModType_MethodInfo_,
	"Ljava/lang/Enum<Ljava/util/logging/LogManager$ModType;>;",
	nullptr,
	_LogManager$ModType_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$ModType($Class* clazz) {
	return $of($alloc(LogManager$ModType));
}

LogManager$ModType* LogManager$ModType::SAME = nullptr;
LogManager$ModType* LogManager$ModType::ADDED = nullptr;
LogManager$ModType* LogManager$ModType::CHANGED = nullptr;
LogManager$ModType* LogManager$ModType::REMOVED = nullptr;
$LogManager$ModTypeArray* LogManager$ModType::$VALUES = nullptr;

$LogManager$ModTypeArray* LogManager$ModType::$values() {
	$init(LogManager$ModType);
	return $new($LogManager$ModTypeArray, {
		LogManager$ModType::SAME,
		LogManager$ModType::ADDED,
		LogManager$ModType::CHANGED,
		LogManager$ModType::REMOVED
	});
}

$LogManager$ModTypeArray* LogManager$ModType::values() {
	$init(LogManager$ModType);
	return $cast($LogManager$ModTypeArray, LogManager$ModType::$VALUES->clone());
}

LogManager$ModType* LogManager$ModType::valueOf($String* name) {
	$init(LogManager$ModType);
	return $cast(LogManager$ModType, $Enum::valueOf(LogManager$ModType::class$, name));
}

void LogManager$ModType::init$($String* $enum$name, int32_t $enum$ordinal) {
	$Enum::init$($enum$name, $enum$ordinal);
}

LogManager$ModType* LogManager$ModType::of($String* previous, $String* next) {
	$init(LogManager$ModType);
	$useLocalCurrentObjectStackCache();
	if (previous == nullptr && next != nullptr) {
		return LogManager$ModType::ADDED;
	}
	if (next == nullptr && previous != nullptr) {
		return LogManager$ModType::REMOVED;
	}
	$var($Object, var$0, $of($LogManager::trim(previous)));
	if (!$Objects::equals(var$0, $($LogManager::trim(next)))) {
		return LogManager$ModType::CHANGED;
	}
	return LogManager$ModType::SAME;
}

void clinit$LogManager$ModType($Class* class$) {
	$assignStatic(LogManager$ModType::SAME, $new(LogManager$ModType, "SAME"_s, 0));
	$assignStatic(LogManager$ModType::ADDED, $new(LogManager$ModType, "ADDED"_s, 1));
	$assignStatic(LogManager$ModType::CHANGED, $new(LogManager$ModType, "CHANGED"_s, 2));
	$assignStatic(LogManager$ModType::REMOVED, $new(LogManager$ModType, "REMOVED"_s, 3));
	$assignStatic(LogManager$ModType::$VALUES, LogManager$ModType::$values());
}

LogManager$ModType::LogManager$ModType() {
}

$Class* LogManager$ModType::load$($String* name, bool initialize) {
	$loadClass(LogManager$ModType, name, initialize, &_LogManager$ModType_ClassInfo_, clinit$LogManager$ModType, allocate$LogManager$ModType);
	return class$;
}

$Class* LogManager$ModType::class$ = nullptr;

		} // logging
	} // util
} // java