#include <java/util/logging/LogManager$4.h>

#include <java/util/List.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/Logger.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $List = ::java::util::List;
using $LogManager = ::java::util::logging::LogManager;
using $Logger = ::java::util::logging::Logger;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LogManager$4_FieldInfo_[] = {
	{"this$0", "Ljava/util/logging/LogManager;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$4, this$0)},
	{"val$handlersPropertyName", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$4, val$handlersPropertyName)},
	{"val$name", "Ljava/lang/String;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$4, val$name)},
	{"val$logger", "Ljava/util/logging/Logger;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$4, val$logger)},
	{}
};

$MethodInfo _LogManager$4_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/LogManager;Ljava/util/logging/Logger;Ljava/lang/String;Ljava/lang/String;)V", "()V", 0, $method(static_cast<void(LogManager$4::*)($LogManager*,$Logger*,$String*,$String*)>(&LogManager$4::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _LogManager$4_EnclosingMethodInfo_ = {
	"java.util.logging.LogManager",
	"loadLoggerHandlers",
	"(Ljava/util/logging/Logger;Ljava/lang/String;Ljava/lang/String;)V"
};

$InnerClassInfo _LogManager$4_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$4", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LogManager$4_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.logging.LogManager$4",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_LogManager$4_FieldInfo_,
	_LogManager$4_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_LogManager$4_EnclosingMethodInfo_,
	_LogManager$4_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$4($Class* clazz) {
	return $of($alloc(LogManager$4));
}

void LogManager$4::init$($LogManager* this$0, $Logger* val$logger, $String* val$name, $String* val$handlersPropertyName) {
	$set(this, this$0, this$0);
	$set(this, val$logger, val$logger);
	$set(this, val$name, val$name);
	$set(this, val$handlersPropertyName, val$handlersPropertyName);
}

$Object* LogManager$4::run() {
	this->this$0->setLoggerHandlers(this->val$logger, this->val$name, this->val$handlersPropertyName, $(this->this$0->createLoggerHandlers(this->val$name, this->val$handlersPropertyName)));
	return $of(nullptr);
}

LogManager$4::LogManager$4() {
}

$Class* LogManager$4::load$($String* name, bool initialize) {
	$loadClass(LogManager$4, name, initialize, &_LogManager$4_ClassInfo_, allocate$LogManager$4);
	return class$;
}

$Class* LogManager$4::class$ = nullptr;

		} // logging
	} // util
} // java