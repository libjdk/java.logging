#include <java/util/logging/LogManager$CloseOnReset.h>

#include <java/util/Objects.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/Logger.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Objects = ::java::util::Objects;
using $LogManager = ::java::util::logging::LogManager;
using $Logger = ::java::util::logging::Logger;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LogManager$CloseOnReset_FieldInfo_[] = {
	{"logger", "Ljava/util/logging/Logger;", nullptr, $PRIVATE | $FINAL, $field(LogManager$CloseOnReset, logger)},
	{}
};

$MethodInfo _LogManager$CloseOnReset_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/Logger;)V", nullptr, $PRIVATE, $method(static_cast<void(LogManager$CloseOnReset::*)($Logger*)>(&LogManager$CloseOnReset::init$))},
	{"create", "(Ljava/util/logging/Logger;)Ljava/util/logging/LogManager$CloseOnReset;", nullptr, $PUBLIC | $STATIC, $method(static_cast<LogManager$CloseOnReset*(*)($Logger*)>(&LogManager$CloseOnReset::create))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"get", "()Ljava/util/logging/Logger;", nullptr, $PUBLIC, $method(static_cast<$Logger*(LogManager$CloseOnReset::*)()>(&LogManager$CloseOnReset::get))},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _LogManager$CloseOnReset_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$CloseOnReset", "java.util.logging.LogManager", "CloseOnReset", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _LogManager$CloseOnReset_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.logging.LogManager$CloseOnReset",
	"java.lang.Object",
	nullptr,
	_LogManager$CloseOnReset_FieldInfo_,
	_LogManager$CloseOnReset_MethodInfo_,
	nullptr,
	nullptr,
	_LogManager$CloseOnReset_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$CloseOnReset($Class* clazz) {
	return $of($alloc(LogManager$CloseOnReset));
}

void LogManager$CloseOnReset::init$($Logger* ref) {
	$set(this, logger, $cast($Logger, $Objects::requireNonNull(ref)));
}

bool LogManager$CloseOnReset::equals(Object$* other) {
	return ($instanceOf(LogManager$CloseOnReset, other)) && $nc(($cast(LogManager$CloseOnReset, other)))->logger == this->logger;
}

int32_t LogManager$CloseOnReset::hashCode() {
	return $System::identityHashCode(this->logger);
}

$Logger* LogManager$CloseOnReset::get() {
	return this->logger;
}

LogManager$CloseOnReset* LogManager$CloseOnReset::create($Logger* logger) {
	return $new(LogManager$CloseOnReset, logger);
}

LogManager$CloseOnReset::LogManager$CloseOnReset() {
}

$Class* LogManager$CloseOnReset::load$($String* name, bool initialize) {
	$loadClass(LogManager$CloseOnReset, name, initialize, &_LogManager$CloseOnReset_ClassInfo_, allocate$LogManager$CloseOnReset);
	return class$;
}

$Class* LogManager$CloseOnReset::class$ = nullptr;

		} // logging
	} // util
} // java