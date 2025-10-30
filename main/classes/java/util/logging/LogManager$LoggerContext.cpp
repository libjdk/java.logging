#include <java/util/logging/LogManager$LoggerContext.h>

#include <java/lang/AssertionError.h>
#include <java/lang/Module.h>
#include <java/lang/ref/Reference.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Enumeration.h>
#include <java/util/HashMap.h>
#include <java/util/Set.h>
#include <java/util/concurrent/ConcurrentHashMap$KeySetView.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/function/Predicate.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/LogManager$LogNode.h>
#include <java/util/logging/LogManager$LoggerContext$1.h>
#include <java/util/logging/LogManager$LoggerWeakRef.h>
#include <java/util/logging/LogManager$VisitedLoggers.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/Logger.h>
#include <jcpp.h>

#undef GLOBAL_LOGGER_NAME
#undef NEVER

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NullPointerException = ::java::lang::NullPointerException;
using $Reference = ::java::lang::ref::Reference;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Enumeration = ::java::util::Enumeration;
using $HashMap = ::java::util::HashMap;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentHashMap$KeySetView = ::java::util::concurrent::ConcurrentHashMap$KeySetView;
using $Predicate = ::java::util::function::Predicate;
using $Level = ::java::util::logging::Level;
using $LogManager = ::java::util::logging::LogManager;
using $LogManager$LogNode = ::java::util::logging::LogManager$LogNode;
using $LogManager$LoggerContext$1 = ::java::util::logging::LogManager$LoggerContext$1;
using $LogManager$LoggerWeakRef = ::java::util::logging::LogManager$LoggerWeakRef;
using $LogManager$VisitedLoggers = ::java::util::logging::LogManager$VisitedLoggers;
using $Logger = ::java::util::logging::Logger;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LogManager$LoggerContext_FieldInfo_[] = {
	{"this$0", "Ljava/util/logging/LogManager;", nullptr, $FINAL | $SYNTHETIC, $field(LogManager$LoggerContext, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(LogManager$LoggerContext, $assertionsDisabled)},
	{"namedLoggers", "Ljava/util/concurrent/ConcurrentHashMap;", "Ljava/util/concurrent/ConcurrentHashMap<Ljava/lang/String;Ljava/util/logging/LogManager$LoggerWeakRef;>;", $PRIVATE | $FINAL, $field(LogManager$LoggerContext, namedLoggers)},
	{"root", "Ljava/util/logging/LogManager$LogNode;", nullptr, $PRIVATE | $FINAL, $field(LogManager$LoggerContext, root)},
	{}
};

$MethodInfo _LogManager$LoggerContext_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/LogManager;)V", nullptr, $PRIVATE, $method(static_cast<void(LogManager$LoggerContext::*)($LogManager*)>(&LogManager$LoggerContext::init$))},
	{"addLocalLogger", "(Ljava/util/logging/Logger;)Z", nullptr, 0},
	{"addLocalLogger", "(Ljava/util/logging/Logger;Z)Z", nullptr, $SYNCHRONIZED},
	{"demandLogger", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/Module;)Ljava/util/logging/Logger;", nullptr, 0},
	{"ensureAllDefaultLoggers", "(Ljava/util/logging/Logger;)V", nullptr, $PRIVATE, $method(static_cast<void(LogManager$LoggerContext::*)($Logger*)>(&LogManager$LoggerContext::ensureAllDefaultLoggers))},
	{"ensureDefaultLogger", "(Ljava/util/logging/Logger;)V", nullptr, $PRIVATE, $method(static_cast<void(LogManager$LoggerContext::*)($Logger*)>(&LogManager$LoggerContext::ensureDefaultLogger))},
	{"ensureInitialized", "()V", nullptr, $PRIVATE, $method(static_cast<void(LogManager$LoggerContext::*)()>(&LogManager$LoggerContext::ensureInitialized))},
	{"findLogger", "(Ljava/lang/String;)Ljava/util/logging/Logger;", nullptr, 0},
	{"getGlobalLogger", "()Ljava/util/logging/Logger;", nullptr, $FINAL, $method(static_cast<$Logger*(LogManager$LoggerContext::*)()>(&LogManager$LoggerContext::getGlobalLogger))},
	{"getLoggerNames", "()Ljava/util/Enumeration;", "()Ljava/util/Enumeration<Ljava/lang/String;>;", $SYNCHRONIZED},
	{"getNode", "(Ljava/lang/String;)Ljava/util/logging/LogManager$LogNode;", nullptr, 0},
	{"getOwner", "()Ljava/util/logging/LogManager;", nullptr, $FINAL, $method(static_cast<$LogManager*(LogManager$LoggerContext::*)()>(&LogManager$LoggerContext::getOwner))},
	{"getRootLogger", "()Ljava/util/logging/Logger;", nullptr, $FINAL, $method(static_cast<$Logger*(LogManager$LoggerContext::*)()>(&LogManager$LoggerContext::getRootLogger))},
	{"processParentHandlers", "(Ljava/util/logging/Logger;Ljava/lang/String;Ljava/util/function/Predicate;)V", "(Ljava/util/logging/Logger;Ljava/lang/String;Ljava/util/function/Predicate<Ljava/util/logging/Logger;>;)V", $PRIVATE, $method(static_cast<void(LogManager$LoggerContext::*)($Logger*,$String*,$Predicate*)>(&LogManager$LoggerContext::processParentHandlers))},
	{"removeLoggerRef", "(Ljava/lang/String;Ljava/util/logging/LogManager$LoggerWeakRef;)V", nullptr, 0},
	{"requiresDefaultLoggers", "()Z", nullptr, $FINAL, $method(static_cast<bool(LogManager$LoggerContext::*)()>(&LogManager$LoggerContext::requiresDefaultLoggers))},
	{}
};

$InnerClassInfo _LogManager$LoggerContext_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$LoggerContext", "java.util.logging.LogManager", "LoggerContext", 0},
	{"java.util.logging.LogManager$LoggerContext$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LogManager$LoggerContext_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.logging.LogManager$LoggerContext",
	"java.lang.Object",
	nullptr,
	_LogManager$LoggerContext_FieldInfo_,
	_LogManager$LoggerContext_MethodInfo_,
	nullptr,
	nullptr,
	_LogManager$LoggerContext_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$LoggerContext($Class* clazz) {
	return $of($alloc(LogManager$LoggerContext));
}

bool LogManager$LoggerContext::$assertionsDisabled = false;

void LogManager$LoggerContext::init$($LogManager* this$0) {
	$set(this, this$0, this$0);
	$set(this, namedLoggers, $new($ConcurrentHashMap));
	$set(this, root, $new($LogManager$LogNode, nullptr, this));
}

bool LogManager$LoggerContext::requiresDefaultLoggers() {
	$init($LogManager);
	bool requiresDefaultLoggers = (getOwner() == $LogManager::manager);
	if (requiresDefaultLoggers) {
		$nc($(getOwner()))->ensureLogManagerInitialized();
	}
	return requiresDefaultLoggers;
}

$LogManager* LogManager$LoggerContext::getOwner() {
	return this->this$0;
}

$Logger* LogManager$LoggerContext::getRootLogger() {
	return $nc($(getOwner()))->rootLogger;
}

$Logger* LogManager$LoggerContext::getGlobalLogger() {
	$init($Logger);
	$var($Logger, global, $Logger::global);
	return global;
}

$Logger* LogManager$LoggerContext::demandLogger($String* name, $String* resourceBundleName, $Module* module) {
	$var($LogManager, owner, getOwner());
	return $nc(owner)->demandLogger(name, resourceBundleName, module);
}

void LogManager$LoggerContext::ensureInitialized() {
	$useLocalCurrentObjectStackCache();
	if (requiresDefaultLoggers()) {
		ensureDefaultLogger($(getRootLogger()));
		ensureDefaultLogger($(getGlobalLogger()));
	}
}

$Logger* LogManager$LoggerContext::findLogger($String* name) {
	$useLocalCurrentObjectStackCache();
	$var($LogManager$LoggerWeakRef, ref, $cast($LogManager$LoggerWeakRef, $nc(this->namedLoggers)->get(name)));
	$var($Logger, logger, ref == nullptr ? ($Logger*)nullptr : $cast($Logger, $nc(ref)->get()));
	bool var$0 = logger != nullptr;
	if (!var$0) {
		bool var$1 = ref == nullptr && !$nc(name)->isEmpty();
		$init($Logger);
		var$0 = (var$1 && !name->equals($Logger::GLOBAL_LOGGER_NAME));
	}
	if (var$0) {
		return logger;
	}
	$synchronized(this) {
		ensureInitialized();
		$assign(ref, $cast($LogManager$LoggerWeakRef, $nc(this->namedLoggers)->get(name)));
		if (ref == nullptr) {
			return nullptr;
		}
		$assign(logger, $cast($Logger, $nc(ref)->get()));
		if (logger == nullptr) {
			ref->dispose();
		}
		return logger;
	}
}

void LogManager$LoggerContext::ensureAllDefaultLoggers($Logger* logger) {
	$useLocalCurrentObjectStackCache();
	if (requiresDefaultLoggers()) {
		$var($String, name, $nc(logger)->getName());
		if (!$nc(name)->isEmpty()) {
			ensureDefaultLogger($(getRootLogger()));
			if (!$nc($Logger::GLOBAL_LOGGER_NAME)->equals(name)) {
				ensureDefaultLogger($(getGlobalLogger()));
			}
		}
	}
}

void LogManager$LoggerContext::ensureDefaultLogger($Logger* logger) {
	bool var$0 = !requiresDefaultLoggers() || logger == nullptr;
	if (var$0 || logger != getGlobalLogger() && logger != this->this$0->rootLogger) {
		if (!LogManager$LoggerContext::$assertionsDisabled && !(logger == nullptr)) {
			$throwNew($AssertionError);
		}
		return;
	}
	if (!$nc(this->namedLoggers)->containsKey($($nc(logger)->getName()))) {
		addLocalLogger(logger, false);
	}
}

bool LogManager$LoggerContext::addLocalLogger($Logger* logger) {
	return addLocalLogger(logger, requiresDefaultLoggers());
}

bool LogManager$LoggerContext::addLocalLogger($Logger* logger, bool addDefaultLoggersIfNeeded) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (addDefaultLoggersIfNeeded) {
			ensureAllDefaultLoggers(logger);
		}
		$var($String, name, $nc(logger)->getName());
		if (name == nullptr) {
			$throwNew($NullPointerException);
		}
		$var($LogManager$LoggerWeakRef, ref, $cast($LogManager$LoggerWeakRef, $nc(this->namedLoggers)->get(name)));
		if (ref != nullptr) {
			if (ref->refersTo(nullptr)) {
				ref->dispose();
			} else {
				return false;
			}
		}
		$var($LogManager, owner, getOwner());
		logger->setLogManager(owner);
		$assign(ref, $new($LogManager$LoggerWeakRef, static_cast<$LogManager*>($nc(owner)), logger));
		$var($Level, level, $nc(owner)->getLevelProperty($$str({name, ".level"_s}), nullptr));
		if (level != nullptr && !logger->isLevelInitialized()) {
			$LogManager::doSetLevel(logger, level);
		}
		$init($LogManager$VisitedLoggers);
		processParentHandlers(logger, name, $LogManager$VisitedLoggers::NEVER);
		$var($LogManager$LogNode, node, getNode(name));
		$set($nc(node), loggerRef, ref);
		$var($Logger, parent, nullptr);
		$var($LogManager$LogNode, nodep, node->parent);
		while (nodep != nullptr) {
			$var($LogManager$LoggerWeakRef, nodeRef, nodep->loggerRef);
			if (nodeRef != nullptr) {
				$assign(parent, $cast($Logger, nodeRef->get()));
				if (parent != nullptr) {
					break;
				}
			}
			$assign(nodep, nodep->parent);
		}
		if (parent != nullptr) {
			$LogManager::doSetParent(logger, parent);
		}
		node->walkAndSetParent(logger);
		ref->setNode(node);
		$nc(this->namedLoggers)->put(name, ref);
		return true;
	}
}

void LogManager$LoggerContext::removeLoggerRef($String* name, $LogManager$LoggerWeakRef* ref) {
	$nc(this->namedLoggers)->remove(name, ref);
}

$Enumeration* LogManager$LoggerContext::getLoggerNames() {
	$synchronized(this) {
		ensureInitialized();
		return $Collections::enumeration($($nc(this->namedLoggers)->keySet()));
	}
}

void LogManager$LoggerContext::processParentHandlers($Logger* logger, $String* name, $Predicate* visited) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($LogManager, owner, getOwner());
	$AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new($LogManager$LoggerContext$1, this, logger, owner, name)));
	int32_t ix = 1;
	for (;;) {
		int32_t ix2 = $nc(name)->indexOf((int32_t)u'.', ix);
		if (ix2 < 0) {
			break;
		}
		$var($String, pname, name->substring(0, ix2));
		bool var$0 = $nc(owner)->getProperty($$str({pname, ".level"_s})) != nullptr;
		if (var$0 || $nc(owner)->getProperty($$str({pname, ".handlers"_s})) != nullptr) {
			if ($nc(visited)->test($(demandLogger(pname, nullptr, nullptr)))) {
				break;
			}
		}
		ix = ix2 + 1;
	}
}

$LogManager$LogNode* LogManager$LoggerContext::getNode($String* name$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, name, name$renamed);
	if (name == nullptr || $nc(name)->isEmpty()) {
		return this->root;
	}
	$var($LogManager$LogNode, node, this->root);
	while ($nc(name)->length() > 0) {
		int32_t ix = name->indexOf((int32_t)u'.');
		$var($String, head, nullptr);
		if (ix > 0) {
			$assign(head, name->substring(0, ix));
			$assign(name, name->substring(ix + 1));
		} else {
			$assign(head, name);
			$assign(name, ""_s);
		}
		if ($nc(node)->children == nullptr) {
			$set(node, children, $new($HashMap));
		}
		$var($LogManager$LogNode, child, $cast($LogManager$LogNode, $nc($nc(node)->children)->get(head)));
		if (child == nullptr) {
			$assign(child, $new($LogManager$LogNode, node, this));
			$nc(node->children)->put(head, child);
		}
		$assign(node, child);
	}
	return node;
}

void clinit$LogManager$LoggerContext($Class* class$) {
	$load($LogManager);
	LogManager$LoggerContext::$assertionsDisabled = !$LogManager::class$->desiredAssertionStatus();
}

LogManager$LoggerContext::LogManager$LoggerContext() {
}

$Class* LogManager$LoggerContext::load$($String* name, bool initialize) {
	$loadClass(LogManager$LoggerContext, name, initialize, &_LogManager$LoggerContext_ClassInfo_, clinit$LogManager$LoggerContext, allocate$LogManager$LoggerContext);
	return class$;
}

$Class* LogManager$LoggerContext::class$ = nullptr;

		} // logging
	} // util
} // java