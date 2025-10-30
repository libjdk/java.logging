#include <java/util/logging/LogManager$SystemLoggerContext.h>

#include <java/lang/Module.h>
#include <java/util/logging/LogManager$LoggerContext.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/Logger.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $LogManager = ::java::util::logging::LogManager;
using $LogManager$LoggerContext = ::java::util::logging::LogManager$LoggerContext;
using $Logger = ::java::util::logging::Logger;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LogManager$SystemLoggerContext_FieldInfo_[] = {
	{"this$0", "Ljava/util/logging/LogManager;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$SystemLoggerContext, this$0)},
	{}
};

$MethodInfo _LogManager$SystemLoggerContext_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/LogManager;)V", nullptr, 0, $method(static_cast<void(LogManager$SystemLoggerContext::*)($LogManager*)>(&LogManager$SystemLoggerContext::init$))},
	{"demandLogger", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Module;)Ljava/util/logging/Logger;", nullptr, 0},
	{}
};

$InnerClassInfo _LogManager$SystemLoggerContext_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$SystemLoggerContext", "java.util.logging.LogManager", "SystemLoggerContext", $FINAL},
	{"java.util.logging.LogManager$LoggerContext", "java.util.logging.LogManager", "LoggerContext", 0},
	{}
};

$ClassInfo _LogManager$SystemLoggerContext_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.logging.LogManager$SystemLoggerContext",
	"java.util.logging.LogManager$LoggerContext",
	nullptr,
	_LogManager$SystemLoggerContext_FieldInfo_,
	_LogManager$SystemLoggerContext_MethodInfo_,
	nullptr,
	nullptr,
	_LogManager$SystemLoggerContext_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$SystemLoggerContext($Class* clazz) {
	return $of($alloc(LogManager$SystemLoggerContext));
}

void LogManager$SystemLoggerContext::init$($LogManager* this$0) {
	$set(this, this$0, this$0);
	$LogManager$LoggerContext::init$(this$0);
}

$Logger* LogManager$SystemLoggerContext::demandLogger($String* name, $String* resourceBundleName, $Module* module) {
	$useLocalCurrentObjectStackCache();
	$var($Logger, result, findLogger(name));
	if (result == nullptr) {
		$var($Logger, newLogger, $new($Logger, name, resourceBundleName, module, $(getOwner()), true));
		do {
			if (addLocalLogger(newLogger)) {
				$assign(result, newLogger);
			} else {
				$assign(result, findLogger(name));
			}
		} while (result == nullptr);
	}
	return result;
}

LogManager$SystemLoggerContext::LogManager$SystemLoggerContext() {
}

$Class* LogManager$SystemLoggerContext::load$($String* name, bool initialize) {
	$loadClass(LogManager$SystemLoggerContext, name, initialize, &_LogManager$SystemLoggerContext_ClassInfo_, allocate$LogManager$SystemLoggerContext);
	return class$;
}

$Class* LogManager$SystemLoggerContext::class$ = nullptr;

		} // logging
	} // util
} // java