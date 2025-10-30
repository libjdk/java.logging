#include <java/util/logging/LogManager$LoggerWeakRef.h>

#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/lang/ref/WeakReference.h>
#include <java/util/logging/LogManager$LogNode.h>
#include <java/util/logging/LogManager$LoggerContext.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/Logger.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Reference = ::java::lang::ref::Reference;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $WeakReference = ::java::lang::ref::WeakReference;
using $LogManager = ::java::util::logging::LogManager;
using $LogManager$LogNode = ::java::util::logging::LogManager$LogNode;
using $LogManager$LoggerContext = ::java::util::logging::LogManager$LoggerContext;
using $Logger = ::java::util::logging::Logger;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LogManager$LoggerWeakRef_FieldInfo_[] = {
	{"this$0", "Ljava/util/logging/LogManager;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$LoggerWeakRef, this$0)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE, $field(LogManager$LoggerWeakRef, name)},
	{"node", "Ljava/util/logging/LogManager$LogNode;", nullptr, $PRIVATE, $field(LogManager$LoggerWeakRef, node)},
	{"parentRef", "Ljava/lang/ref/WeakReference;", "Ljava/lang/ref/WeakReference<Ljava/util/logging/Logger;>;", $PRIVATE, $field(LogManager$LoggerWeakRef, parentRef)},
	{"disposed", "Z", nullptr, $PRIVATE, $field(LogManager$LoggerWeakRef, disposed)},
	{}
};

$MethodInfo _LogManager$LoggerWeakRef_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/LogManager;Ljava/util/logging/Logger;)V", nullptr, 0, $method(static_cast<void(LogManager$LoggerWeakRef::*)($LogManager*,$Logger*)>(&LogManager$LoggerWeakRef::init$))},
	{"dispose", "()V", nullptr, 0, $method(static_cast<void(LogManager$LoggerWeakRef::*)()>(&LogManager$LoggerWeakRef::dispose))},
	{"setNode", "(Ljava/util/logging/LogManager$LogNode;)V", nullptr, 0, $method(static_cast<void(LogManager$LoggerWeakRef::*)($LogManager$LogNode*)>(&LogManager$LoggerWeakRef::setNode))},
	{"setParentRef", "(Ljava/lang/ref/WeakReference;)V", "(Ljava/lang/ref/WeakReference<Ljava/util/logging/Logger;>;)V", 0, $method(static_cast<void(LogManager$LoggerWeakRef::*)($WeakReference*)>(&LogManager$LoggerWeakRef::setParentRef))},
	{}
};

$InnerClassInfo _LogManager$LoggerWeakRef_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$LoggerWeakRef", "java.util.logging.LogManager", "LoggerWeakRef", $FINAL},
	{}
};

$ClassInfo _LogManager$LoggerWeakRef_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.logging.LogManager$LoggerWeakRef",
	"java.lang.ref.WeakReference",
	nullptr,
	_LogManager$LoggerWeakRef_FieldInfo_,
	_LogManager$LoggerWeakRef_MethodInfo_,
	"Ljava/lang/ref/WeakReference<Ljava/util/logging/Logger;>;",
	nullptr,
	_LogManager$LoggerWeakRef_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$LoggerWeakRef($Class* clazz) {
	return $of($alloc(LogManager$LoggerWeakRef));
}

void LogManager$LoggerWeakRef::init$($LogManager* this$0, $Logger* logger) {
	$set(this, this$0, this$0);
	$WeakReference::init$(logger, this$0->loggerRefQueue);
	this->disposed = false;
	$set(this, name, $nc(logger)->getName());
}

void LogManager$LoggerWeakRef::dispose() {
	$useLocalCurrentObjectStackCache();
	$synchronized(this) {
		if (this->disposed) {
			return;
		}
		this->disposed = true;
	}
	$var($LogManager$LogNode, n, this->node);
	if (n != nullptr) {
		$synchronized(n->context) {
			$nc(n->context)->removeLoggerRef(this->name, this);
			$set(this, name, nullptr);
			if (n->loggerRef == this) {
				$set(n, loggerRef, nullptr);
			}
			$set(this, node, nullptr);
		}
	}
	if (this->parentRef != nullptr) {
		$var($Logger, parent, $cast($Logger, $nc(this->parentRef)->get()));
		if (parent != nullptr) {
			parent->removeChildLogger(this);
		}
		$set(this, parentRef, nullptr);
	}
}

void LogManager$LoggerWeakRef::setNode($LogManager$LogNode* node) {
	$set(this, node, node);
}

void LogManager$LoggerWeakRef::setParentRef($WeakReference* parentRef) {
	$set(this, parentRef, parentRef);
}

LogManager$LoggerWeakRef::LogManager$LoggerWeakRef() {
}

$Class* LogManager$LoggerWeakRef::load$($String* name, bool initialize) {
	$loadClass(LogManager$LoggerWeakRef, name, initialize, &_LogManager$LoggerWeakRef_ClassInfo_, allocate$LogManager$LoggerWeakRef);
	return class$;
}

$Class* LogManager$LoggerWeakRef::class$ = nullptr;

		} // logging
	} // util
} // java