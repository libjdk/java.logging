#include <java/util/logging/LogManager$VisitedLoggers.h>

#include <java/util/IdentityHashMap.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/Logger.h>
#include <jcpp.h>

#undef NEVER
#undef TRUE

using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $IdentityHashMap = ::java::util::IdentityHashMap;
using $Predicate = ::java::util::function::Predicate;
using $LogManager = ::java::util::logging::LogManager;
using $Logger = ::java::util::logging::Logger;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LogManager$VisitedLoggers_FieldInfo_[] = {
	{"visited", "Ljava/util/IdentityHashMap;", "Ljava/util/IdentityHashMap<Ljava/util/logging/Logger;Ljava/lang/Boolean;>;", $FINAL, $field(LogManager$VisitedLoggers, visited)},
	{"NEVER", "Ljava/util/logging/LogManager$VisitedLoggers;", nullptr, $STATIC | $FINAL, $staticField(LogManager$VisitedLoggers, NEVER)},
	{}
};

$MethodInfo _LogManager$VisitedLoggers_MethodInfo_[] = {
	{"<init>", "(Ljava/util/IdentityHashMap;)V", "(Ljava/util/IdentityHashMap<Ljava/util/logging/Logger;Ljava/lang/Boolean;>;)V", $PRIVATE, $method(static_cast<void(LogManager$VisitedLoggers::*)($IdentityHashMap*)>(&LogManager$VisitedLoggers::init$))},
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(LogManager$VisitedLoggers::*)()>(&LogManager$VisitedLoggers::init$))},
	{"clear", "()V", nullptr, $PUBLIC, $method(static_cast<void(LogManager$VisitedLoggers::*)()>(&LogManager$VisitedLoggers::clear))},
	{"test", "(Ljava/util/logging/Logger;)Z", nullptr, $PUBLIC, $method(static_cast<bool(LogManager$VisitedLoggers::*)($Logger*)>(&LogManager$VisitedLoggers::test))},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{}
};

$InnerClassInfo _LogManager$VisitedLoggers_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$VisitedLoggers", "java.util.logging.LogManager", "VisitedLoggers", $STATIC | $FINAL},
	{}
};

$ClassInfo _LogManager$VisitedLoggers_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.logging.LogManager$VisitedLoggers",
	"java.lang.Object",
	"java.util.function.Predicate",
	_LogManager$VisitedLoggers_FieldInfo_,
	_LogManager$VisitedLoggers_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/function/Predicate<Ljava/util/logging/Logger;>;",
	nullptr,
	_LogManager$VisitedLoggers_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$VisitedLoggers($Class* clazz) {
	return $of($alloc(LogManager$VisitedLoggers));
}

LogManager$VisitedLoggers* LogManager$VisitedLoggers::NEVER = nullptr;

void LogManager$VisitedLoggers::init$($IdentityHashMap* visited) {
	$set(this, visited, visited);
}

void LogManager$VisitedLoggers::init$() {
	LogManager$VisitedLoggers::init$($$new($IdentityHashMap));
}

bool LogManager$VisitedLoggers::test($Logger* logger) {
	$init($Boolean);
	return this->visited != nullptr && $nc(this->visited)->put(logger, $Boolean::TRUE) != nullptr;
}

void LogManager$VisitedLoggers::clear() {
	if (this->visited != nullptr) {
		$nc(this->visited)->clear();
	}
}

bool LogManager$VisitedLoggers::test(Object$* logger) {
	return this->test($cast($Logger, logger));
}

void clinit$LogManager$VisitedLoggers($Class* class$) {
	$assignStatic(LogManager$VisitedLoggers::NEVER, $new(LogManager$VisitedLoggers, nullptr));
}

LogManager$VisitedLoggers::LogManager$VisitedLoggers() {
}

$Class* LogManager$VisitedLoggers::load$($String* name, bool initialize) {
	$loadClass(LogManager$VisitedLoggers, name, initialize, &_LogManager$VisitedLoggers_ClassInfo_, clinit$LogManager$VisitedLoggers, allocate$LogManager$VisitedLoggers);
	return class$;
}

$Class* LogManager$VisitedLoggers::class$ = nullptr;

		} // logging
	} // util
} // java