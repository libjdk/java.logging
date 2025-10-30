#include <java/util/logging/LogManager$RootLogger.h>

#include <java/lang/Module.h>
#include <java/util/logging/Handler.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/LogRecord.h>
#include <java/util/logging/Logger.h>
#include <jcpp.h>

using $HandlerArray = $Array<::java::util::logging::Handler>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $Handler = ::java::util::logging::Handler;
using $LogManager = ::java::util::logging::LogManager;
using $LogRecord = ::java::util::logging::LogRecord;
using $Logger = ::java::util::logging::Logger;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LogManager$RootLogger_FieldInfo_[] = {
	{"this$0", "Ljava/util/logging/LogManager;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$RootLogger, this$0)},
	{}
};

$MethodInfo _LogManager$RootLogger_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/LogManager;)V", nullptr, $PRIVATE, $method(static_cast<void(LogManager$RootLogger::*)($LogManager*)>(&LogManager$RootLogger::init$))},
	{"accessCheckedHandlers", "()[Ljava/util/logging/Handler;", nullptr, 0},
	{"addHandler", "(Ljava/util/logging/Handler;)V", nullptr, $PUBLIC},
	{"log", "(Ljava/util/logging/LogRecord;)V", nullptr, $PUBLIC},
	{"removeHandler", "(Ljava/util/logging/Handler;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _LogManager$RootLogger_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$RootLogger", "java.util.logging.LogManager", "RootLogger", $PRIVATE | $FINAL},
	{}
};

$ClassInfo _LogManager$RootLogger_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.logging.LogManager$RootLogger",
	"java.util.logging.Logger",
	nullptr,
	_LogManager$RootLogger_FieldInfo_,
	_LogManager$RootLogger_MethodInfo_,
	nullptr,
	nullptr,
	_LogManager$RootLogger_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$RootLogger($Class* clazz) {
	return $of($alloc(LogManager$RootLogger));
}

void LogManager$RootLogger::init$($LogManager* this$0) {
	$set(this, this$0, this$0);
	$Logger::init$(""_s, nullptr, nullptr, this$0, true);
}

void LogManager$RootLogger::log($LogRecord* record) {
	this->this$0->initializeGlobalHandlers();
	$Logger::log(record);
}

void LogManager$RootLogger::addHandler($Handler* h) {
	this->this$0->initializeGlobalHandlers();
	$Logger::addHandler(h);
}

void LogManager$RootLogger::removeHandler($Handler* h) {
	this->this$0->initializeGlobalHandlers();
	$Logger::removeHandler(h);
}

$HandlerArray* LogManager$RootLogger::accessCheckedHandlers() {
	this->this$0->initializeGlobalHandlers();
	return $Logger::accessCheckedHandlers();
}

LogManager$RootLogger::LogManager$RootLogger() {
}

$Class* LogManager$RootLogger::load$($String* name, bool initialize) {
	$loadClass(LogManager$RootLogger, name, initialize, &_LogManager$RootLogger_ClassInfo_, allocate$LogManager$RootLogger);
	return class$;
}

$Class* LogManager$RootLogger::class$ = nullptr;

		} // logging
	} // util
} // java