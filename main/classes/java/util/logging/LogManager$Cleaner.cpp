#include <java/util/logging/LogManager$Cleaner.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/Runnable.h>
#include <java/lang/ThreadGroup.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <java/util/logging/LogManager.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $ThreadGroup = ::java::lang::ThreadGroup;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $LogManager = ::java::util::logging::LogManager;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LogManager$Cleaner_FieldInfo_[] = {
	{"this$0", "Ljava/util/logging/LogManager;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$Cleaner, this$0)},
	{}
};

$MethodInfo _LogManager$Cleaner_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/LogManager;)V", nullptr, $PRIVATE, $method(static_cast<void(LogManager$Cleaner::*)($LogManager*)>(&LogManager$Cleaner::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _LogManager$Cleaner_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$Cleaner", "java.util.logging.LogManager", "Cleaner", $PRIVATE},
	{}
};

$ClassInfo _LogManager$Cleaner_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.logging.LogManager$Cleaner",
	"java.lang.Thread",
	nullptr,
	_LogManager$Cleaner_FieldInfo_,
	_LogManager$Cleaner_MethodInfo_,
	nullptr,
	nullptr,
	_LogManager$Cleaner_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$Cleaner($Class* clazz) {
	return $of($alloc(LogManager$Cleaner));
}

void LogManager$Cleaner::init$($LogManager* this$0) {
	$set(this, this$0, this$0);
	$Thread::init$(nullptr, nullptr, "Logging-Cleaner"_s, 0, false);
	this->setContextClassLoader(nullptr);
}

void LogManager$Cleaner::run() {
	$init($LogManager);
	$var($LogManager, mgr, $LogManager::manager);
	$nc(this->this$0->configurationLock)->lock();
	this->this$0->globalHandlersState = 4;
	$nc(this->this$0->configurationLock)->unlock();
	this->this$0->reset();
}

LogManager$Cleaner::LogManager$Cleaner() {
}

$Class* LogManager$Cleaner::load$($String* name, bool initialize) {
	$loadClass(LogManager$Cleaner, name, initialize, &_LogManager$Cleaner_ClassInfo_, allocate$LogManager$Cleaner);
	return class$;
}

$Class* LogManager$Cleaner::class$ = nullptr;

		} // logging
	} // util
} // java