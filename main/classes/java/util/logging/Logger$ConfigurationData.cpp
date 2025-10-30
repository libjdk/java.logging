#include <java/util/logging/Logger$ConfigurationData.h>

#include <java/lang/InternalError.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/concurrent/CopyOnWriteArrayList.h>
#include <java/util/logging/Filter.h>
#include <java/util/logging/Handler.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/Logger.h>
#include <jcpp.h>

#undef INFO

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $CopyOnWriteArrayList = ::java::util::concurrent::CopyOnWriteArrayList;
using $Filter = ::java::util::logging::Filter;
using $Handler = ::java::util::logging::Handler;
using $Level = ::java::util::logging::Level;
using $Logger = ::java::util::logging::Logger;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _Logger$ConfigurationData_FieldInfo_[] = {
	{"delegate", "Ljava/util/logging/Logger$ConfigurationData;", nullptr, $PRIVATE | $VOLATILE, $field(Logger$ConfigurationData, delegate)},
	{"useParentHandlers", "Z", nullptr, $VOLATILE, $field(Logger$ConfigurationData, useParentHandlers)},
	{"filter", "Ljava/util/logging/Filter;", nullptr, $VOLATILE, $field(Logger$ConfigurationData, filter)},
	{"levelObject", "Ljava/util/logging/Level;", nullptr, $VOLATILE, $field(Logger$ConfigurationData, levelObject)},
	{"levelValue", "I", nullptr, $VOLATILE, $field(Logger$ConfigurationData, levelValue)},
	{"handlers", "Ljava/util/concurrent/CopyOnWriteArrayList;", "Ljava/util/concurrent/CopyOnWriteArrayList<Ljava/util/logging/Handler;>;", $FINAL, $field(Logger$ConfigurationData, handlers)},
	{}
};

$MethodInfo _Logger$ConfigurationData_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(Logger$ConfigurationData::*)()>(&Logger$ConfigurationData::init$))},
	{"addHandler", "(Ljava/util/logging/Handler;)V", nullptr, 0, $method(static_cast<void(Logger$ConfigurationData::*)($Handler*)>(&Logger$ConfigurationData::addHandler))},
	{"merge", "(Ljava/util/logging/Logger;)Ljava/util/logging/Logger$ConfigurationData;", nullptr, 0, $method(static_cast<Logger$ConfigurationData*(Logger$ConfigurationData::*)($Logger*)>(&Logger$ConfigurationData::merge))},
	{"removeHandler", "(Ljava/util/logging/Handler;)V", nullptr, 0, $method(static_cast<void(Logger$ConfigurationData::*)($Handler*)>(&Logger$ConfigurationData::removeHandler))},
	{"setFilter", "(Ljava/util/logging/Filter;)V", nullptr, 0, $method(static_cast<void(Logger$ConfigurationData::*)($Filter*)>(&Logger$ConfigurationData::setFilter))},
	{"setLevelObject", "(Ljava/util/logging/Level;)V", nullptr, 0, $method(static_cast<void(Logger$ConfigurationData::*)($Level*)>(&Logger$ConfigurationData::setLevelObject))},
	{"setLevelValue", "(I)V", nullptr, 0, $method(static_cast<void(Logger$ConfigurationData::*)(int32_t)>(&Logger$ConfigurationData::setLevelValue))},
	{"setUseParentHandlers", "(Z)V", nullptr, 0, $method(static_cast<void(Logger$ConfigurationData::*)(bool)>(&Logger$ConfigurationData::setUseParentHandlers))},
	{}
};

$InnerClassInfo _Logger$ConfigurationData_InnerClassesInfo_[] = {
	{"java.util.logging.Logger$ConfigurationData", "java.util.logging.Logger", "ConfigurationData", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _Logger$ConfigurationData_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.logging.Logger$ConfigurationData",
	"java.lang.Object",
	nullptr,
	_Logger$ConfigurationData_FieldInfo_,
	_Logger$ConfigurationData_MethodInfo_,
	nullptr,
	nullptr,
	_Logger$ConfigurationData_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.Logger"
};

$Object* allocate$Logger$ConfigurationData($Class* clazz) {
	return $of($alloc(Logger$ConfigurationData));
}

void Logger$ConfigurationData::init$() {
	$set(this, handlers, $new($CopyOnWriteArrayList));
	$set(this, delegate, this);
	this->useParentHandlers = true;
	$init($Level);
	this->levelValue = $nc($Level::INFO)->intValue();
}

void Logger$ConfigurationData::setUseParentHandlers(bool flag) {
	this->useParentHandlers = flag;
	if (this->delegate != this) {
		$var(Logger$ConfigurationData, system, this->delegate);
		$synchronized(system) {
			$nc(system)->useParentHandlers = this->useParentHandlers;
		}
	}
}

void Logger$ConfigurationData::setFilter($Filter* f) {
	$set(this, filter, f);
	if (this->delegate != this) {
		$var(Logger$ConfigurationData, system, this->delegate);
		$synchronized(system) {
			$set($nc(system), filter, this->filter);
		}
	}
}

void Logger$ConfigurationData::setLevelObject($Level* l) {
	$set(this, levelObject, l);
	if (this->delegate != this) {
		$var(Logger$ConfigurationData, system, this->delegate);
		$synchronized(system) {
			$set($nc(system), levelObject, this->levelObject);
		}
	}
}

void Logger$ConfigurationData::setLevelValue(int32_t v) {
	this->levelValue = v;
	if (this->delegate != this) {
		$var(Logger$ConfigurationData, system, this->delegate);
		$synchronized(system) {
			$nc(system)->levelValue = this->levelValue;
		}
	}
}

void Logger$ConfigurationData::addHandler($Handler* h) {
	if ($nc(this->handlers)->add(h)) {
		if (this->delegate != this) {
			$var(Logger$ConfigurationData, system, this->delegate);
			$synchronized(system) {
				$nc($nc(system)->handlers)->addIfAbsent(h);
			}
		}
	}
}

void Logger$ConfigurationData::removeHandler($Handler* h) {
	if ($nc(this->handlers)->remove($of(h))) {
		if (this->delegate != this) {
			$var(Logger$ConfigurationData, system, this->delegate);
			$synchronized(system) {
				$nc($nc(system)->handlers)->remove($of(h));
			}
		}
	}
}

Logger$ConfigurationData* Logger$ConfigurationData::merge($Logger* systemPeer) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(systemPeer)->isSystemLogger) {
		$throwNew($InternalError, "not a system logger"_s);
	}
	$var(Logger$ConfigurationData, system, $nc(systemPeer)->config$);
	if (system == this) {
		return system;
	}
	$synchronized(system) {
		if (this->delegate == system) {
			return system;
		}
		$set(this, delegate, system);
		$nc(system)->useParentHandlers = this->useParentHandlers;
		$set(system, filter, this->filter);
		$set(system, levelObject, this->levelObject);
		system->levelValue = this->levelValue;
		{
			$var($Iterator, i$, $nc(this->handlers)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Handler, h, $cast($Handler, i$->next()));
				{
					if (!$nc(system->handlers)->contains(h)) {
						systemPeer->addHandler(h);
					}
				}
			}
		}
		$nc(system->handlers)->retainAll(this->handlers);
		$nc(system->handlers)->addAllAbsent(this->handlers);
	}
	$init($Logger);
	$synchronized($Logger::treeLock) {
		systemPeer->updateEffectiveLevel();
	}
	return system;
}

Logger$ConfigurationData::Logger$ConfigurationData() {
}

$Class* Logger$ConfigurationData::load$($String* name, bool initialize) {
	$loadClass(Logger$ConfigurationData, name, initialize, &_Logger$ConfigurationData_ClassInfo_, allocate$Logger$ConfigurationData);
	return class$;
}

$Class* Logger$ConfigurationData::class$ = nullptr;

		} // logging
	} // util
} // java