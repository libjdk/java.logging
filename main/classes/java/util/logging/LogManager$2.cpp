#include <java/util/logging/LogManager$2.h>

#include <java/lang/AssertionError.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/LogManager$RootLogger.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/Logger.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Level = ::java::util::logging::Level;
using $LogManager = ::java::util::logging::LogManager;
using $LogManager$RootLogger = ::java::util::logging::LogManager$RootLogger;
using $Logger = ::java::util::logging::Logger;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LogManager$2_FieldInfo_[] = {
	{"this$0", "Ljava/util/logging/LogManager;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$2, this$0)},
	{"val$owner", "Ljava/util/logging/LogManager;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$2, val$owner)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(LogManager$2, $assertionsDisabled)},
	{}
};

$MethodInfo _LogManager$2_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/LogManager;Ljava/util/logging/LogManager;)V", "()V", 0, $method(static_cast<void(LogManager$2::*)($LogManager*,$LogManager*)>(&LogManager$2::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _LogManager$2_EnclosingMethodInfo_ = {
	"java.util.logging.LogManager",
	"ensureLogManagerInitialized",
	"()V"
};

$InnerClassInfo _LogManager$2_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$2", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LogManager$2_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.logging.LogManager$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_LogManager$2_FieldInfo_,
	_LogManager$2_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Object;>;",
	&_LogManager$2_EnclosingMethodInfo_,
	_LogManager$2_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$2($Class* clazz) {
	return $of($alloc(LogManager$2));
}

bool LogManager$2::$assertionsDisabled = false;

void LogManager$2::init$($LogManager* this$0, $LogManager* val$owner) {
	$set(this, this$0, this$0);
	$set(this, val$owner, val$owner);
}

$Object* LogManager$2::run() {
	$useLocalCurrentObjectStackCache();
	if (!LogManager$2::$assertionsDisabled && !(this->this$0->rootLogger == nullptr)) {
		$throwNew($AssertionError);
	}
	if (!LogManager$2::$assertionsDisabled && !(this->this$0->initializedCalled && !this->this$0->initializationDone)) {
		$throwNew($AssertionError);
	}
	$var($Logger, root, $set($nc(this->val$owner), rootLogger, $new($LogManager$RootLogger, static_cast<$LogManager*>($nc(this->val$owner)))));
	$nc(this->val$owner)->readPrimordialConfiguration();
	$nc(this->val$owner)->addLogger(root);
	if (!$nc(root)->isLevelInitialized()) {
		root->setLevel($LogManager::defaultLevel);
	}
	$var($Logger, global, $Logger::global);
	$nc(this->val$owner)->addLogger(global);
	return $of(nullptr);
}

void clinit$LogManager$2($Class* class$) {
	$load($LogManager);
	LogManager$2::$assertionsDisabled = !$LogManager::class$->desiredAssertionStatus();
}

LogManager$2::LogManager$2() {
}

$Class* LogManager$2::load$($String* name, bool initialize) {
	$loadClass(LogManager$2, name, initialize, &_LogManager$2_ClassInfo_, clinit$LogManager$2, allocate$LogManager$2);
	return class$;
}

$Class* LogManager$2::class$ = nullptr;

		} // logging
	} // util
} // java