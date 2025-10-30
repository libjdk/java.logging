#include <java/util/logging/LogManager$7.h>

#include <java/lang/NoSuchFieldError.h>
#include <java/util/logging/LogManager$ConfigProperty.h>
#include <java/util/logging/LogManager.h>
#include <jcpp.h>

#undef HANDLERS
#undef LEVEL
#undef USEPARENT

using $LogManager$ConfigPropertyArray = $Array<::java::util::logging::LogManager$ConfigProperty>;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $NoSuchFieldError = ::java::lang::NoSuchFieldError;
using $LogManager = ::java::util::logging::LogManager;
using $LogManager$ConfigProperty = ::java::util::logging::LogManager$ConfigProperty;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LogManager$7_FieldInfo_[] = {
	{"$SwitchMap$java$util$logging$LogManager$ConfigProperty", "[I", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(LogManager$7, $SwitchMap$java$util$logging$LogManager$ConfigProperty)},
	{}
};

$EnclosingMethodInfo _LogManager$7_EnclosingMethodInfo_ = {
	"java.util.logging.LogManager",
	nullptr,
	nullptr
};

$InnerClassInfo _LogManager$7_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$7", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{}
};

$ClassInfo _LogManager$7_ClassInfo_ = {
	$ACC_SUPER | $SYNTHETIC,
	"java.util.logging.LogManager$7",
	"java.lang.Object",
	nullptr,
	_LogManager$7_FieldInfo_,
	nullptr,
	nullptr,
	&_LogManager$7_EnclosingMethodInfo_,
	_LogManager$7_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$7($Class* clazz) {
	return $of($alloc(LogManager$7));
}

$ints* LogManager$7::$SwitchMap$java$util$logging$LogManager$ConfigProperty = nullptr;

void clinit$LogManager$7($Class* class$) {
	$assignStatic(LogManager$7::$SwitchMap$java$util$logging$LogManager$ConfigProperty, $new($ints, $($LogManager$ConfigProperty::values())->length));
	{
		try {
			$nc(LogManager$7::$SwitchMap$java$util$logging$LogManager$ConfigProperty)->set($LogManager$ConfigProperty::LEVEL->ordinal(), 1);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(LogManager$7::$SwitchMap$java$util$logging$LogManager$ConfigProperty)->set($LogManager$ConfigProperty::USEPARENT->ordinal(), 2);
		} catch ($NoSuchFieldError& ex) {
		}
		try {
			$nc(LogManager$7::$SwitchMap$java$util$logging$LogManager$ConfigProperty)->set($LogManager$ConfigProperty::HANDLERS->ordinal(), 3);
		} catch ($NoSuchFieldError& ex) {
		}
	}
}

LogManager$7::LogManager$7() {
}

$Class* LogManager$7::load$($String* name, bool initialize) {
	$loadClass(LogManager$7, name, initialize, &_LogManager$7_ClassInfo_, clinit$LogManager$7, allocate$LogManager$7);
	return class$;
}

$Class* LogManager$7::class$ = nullptr;

		} // logging
	} // util
} // java