#include <java/util/logging/Logging.h>

#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Enumeration.h>
#include <java/util/List.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/Logger.h>
#include <jcpp.h>

#undef EMPTY_STRING
#undef INSTANCE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Enumeration = ::java::util::Enumeration;
using $List = ::java::util::List;
using $Level = ::java::util::logging::Level;
using $LogManager = ::java::util::logging::LogManager;
using $Logger = ::java::util::logging::Logger;
using $LoggingMXBean = ::java::util::logging::LoggingMXBean;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _Logging_FieldInfo_[] = {
	{"logManager", "Ljava/util/logging/LogManager;", nullptr, $PRIVATE | $STATIC, $staticField(Logging, logManager)},
	{"EMPTY_STRING", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC, $staticField(Logging, EMPTY_STRING)},
	{"INSTANCE", "Ljava/util/logging/Logging;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Logging, INSTANCE)},
	{}
};

$MethodInfo _Logging_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Logging::*)()>(&Logging::init$))},
	{"getInstance", "()Ljava/util/logging/Logging;", nullptr, $STATIC, $method(static_cast<Logging*(*)()>(&Logging::getInstance))},
	{"getLoggerLevel", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"getLoggerNames", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/String;>;", $PUBLIC},
	{"getParentLoggerName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"setLoggerLevel", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{}
};

$ClassInfo _Logging_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.logging.Logging",
	"java.lang.Object",
	"java.util.logging.LoggingMXBean",
	_Logging_FieldInfo_,
	_Logging_MethodInfo_
};

$Object* allocate$Logging($Class* clazz) {
	return $of($alloc(Logging));
}

$LogManager* Logging::logManager = nullptr;
$String* Logging::EMPTY_STRING = nullptr;
Logging* Logging::INSTANCE = nullptr;

void Logging::init$() {
}

$List* Logging::getLoggerNames() {
	$useLocalCurrentObjectStackCache();
	$var($Enumeration, loggers, $nc(Logging::logManager)->getLoggerNames());
	$var($ArrayList, array, $new($ArrayList));
	for (; $nc(loggers)->hasMoreElements();) {
		array->add($cast($String, $(loggers->nextElement())));
	}
	return array;
}

$String* Logging::getLoggerLevel($String* loggerName) {
	$useLocalCurrentObjectStackCache();
	$var($Logger, l, $nc(Logging::logManager)->getLogger(loggerName));
	if (l == nullptr) {
		return nullptr;
	}
	$var($Level, level, $nc(l)->getLevel());
	if (level == nullptr) {
		return Logging::EMPTY_STRING;
	} else {
		return $nc(level)->getLevelName();
	}
}

void Logging::setLoggerLevel($String* loggerName, $String* levelName) {
	$useLocalCurrentObjectStackCache();
	if (loggerName == nullptr) {
		$throwNew($NullPointerException, "loggerName is null"_s);
	}
	$var($Logger, logger, $nc(Logging::logManager)->getLogger(loggerName));
	if (logger == nullptr) {
		$throwNew($IllegalArgumentException, $$str({"Logger "_s, loggerName, " does not exist"_s}));
	}
	$var($Level, level, nullptr);
	if (levelName != nullptr) {
		$assign(level, $Level::findLevel(levelName));
		if (level == nullptr) {
			$throwNew($IllegalArgumentException, $$str({"Unknown level \""_s, levelName, "\""_s}));
		}
	}
	$nc(logger)->setLevel(level);
}

$String* Logging::getParentLoggerName($String* loggerName) {
	$useLocalCurrentObjectStackCache();
	$var($Logger, l, $nc(Logging::logManager)->getLogger(loggerName));
	if (l == nullptr) {
		return nullptr;
	}
	$var($Logger, p, $nc(l)->getParent());
	if (p == nullptr) {
		return Logging::EMPTY_STRING;
	} else {
		return $nc(p)->getName();
	}
}

Logging* Logging::getInstance() {
	$init(Logging);
	return Logging::INSTANCE;
}

void clinit$Logging($Class* class$) {
	$assignStatic(Logging::logManager, $LogManager::getLogManager());
	$assignStatic(Logging::EMPTY_STRING, ""_s);
	$assignStatic(Logging::INSTANCE, $new(Logging));
}

Logging::Logging() {
}

$Class* Logging::load$($String* name, bool initialize) {
	$loadClass(Logging, name, initialize, &_Logging_ClassInfo_, clinit$Logging, allocate$Logging);
	return class$;
}

$Class* Logging::class$ = nullptr;

		} // logging
	} // util
} // java