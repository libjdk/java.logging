#include <java/util/logging/LogManager$LogNode.h>

#include <java/lang/ref/Reference.h>
#include <java/util/Collection.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/logging/LogManager$LoggerContext.h>
#include <java/util/logging/LogManager$LoggerWeakRef.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/Logger.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Reference = ::java::lang::ref::Reference;
using $Collection = ::java::util::Collection;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LogManager = ::java::util::logging::LogManager;
using $LogManager$LoggerContext = ::java::util::logging::LogManager$LoggerContext;
using $LogManager$LoggerWeakRef = ::java::util::logging::LogManager$LoggerWeakRef;
using $Logger = ::java::util::logging::Logger;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _LogManager$LogNode_FieldInfo_[] = {
	{"children", "Ljava/util/HashMap;", "Ljava/util/HashMap<Ljava/lang/String;Ljava/util/logging/LogManager$LogNode;>;", 0, $field(LogManager$LogNode, children)},
	{"loggerRef", "Ljava/util/logging/LogManager$LoggerWeakRef;", nullptr, 0, $field(LogManager$LogNode, loggerRef)},
	{"parent", "Ljava/util/logging/LogManager$LogNode;", nullptr, 0, $field(LogManager$LogNode, parent)},
	{"context", "Ljava/util/logging/LogManager$LoggerContext;", nullptr, $FINAL, $field(LogManager$LogNode, context)},
	{}
};

$MethodInfo _LogManager$LogNode_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/LogManager$LogNode;Ljava/util/logging/LogManager$LoggerContext;)V", nullptr, 0, $method(static_cast<void(LogManager$LogNode::*)(LogManager$LogNode*,$LogManager$LoggerContext*)>(&LogManager$LogNode::init$))},
	{"walkAndSetParent", "(Ljava/util/logging/Logger;)V", nullptr, 0},
	{}
};

$InnerClassInfo _LogManager$LogNode_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$LogNode", "java.util.logging.LogManager", "LogNode", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _LogManager$LogNode_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.logging.LogManager$LogNode",
	"java.lang.Object",
	nullptr,
	_LogManager$LogNode_FieldInfo_,
	_LogManager$LogNode_MethodInfo_,
	nullptr,
	nullptr,
	_LogManager$LogNode_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$LogNode($Class* clazz) {
	return $of($alloc(LogManager$LogNode));
}

void LogManager$LogNode::init$(LogManager$LogNode* parent, $LogManager$LoggerContext* context) {
	$set(this, parent, parent);
	$set(this, context, context);
}

void LogManager$LogNode::walkAndSetParent($Logger* parent) {
	$useLocalCurrentObjectStackCache();
	if (this->children == nullptr) {
		return;
	}
	{
		$var($Iterator, i$, $nc($($nc(this->children)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var(LogManager$LogNode, node, $cast(LogManager$LogNode, i$->next()));
			{
				$var($LogManager$LoggerWeakRef, ref, $nc(node)->loggerRef);
				$var($Logger, logger, (ref == nullptr) ? ($Logger*)nullptr : $cast($Logger, $nc(ref)->get()));
				if (logger == nullptr) {
					node->walkAndSetParent(parent);
				} else {
					$LogManager::doSetParent(logger, parent);
				}
			}
		}
	}
}

LogManager$LogNode::LogManager$LogNode() {
}

$Class* LogManager$LogNode::load$($String* name, bool initialize) {
	$loadClass(LogManager$LogNode, name, initialize, &_LogManager$LogNode_ClassInfo_, allocate$LogManager$LogNode);
	return class$;
}

$Class* LogManager$LogNode::class$ = nullptr;

		} // logging
	} // util
} // java