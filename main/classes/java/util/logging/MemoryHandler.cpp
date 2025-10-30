#include <java/util/logging/MemoryHandler.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/lang/IllegalAccessException.h>
#include <java/lang/InstantiationException.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/util/logging/Formatter.h>
#include <java/util/logging/Handler.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/LogRecord.h>
#include <java/util/logging/SimpleFormatter.h>
#include <jcpp.h>

#undef ALL
#undef DEFAULT_SIZE
#undef OFF
#undef SEVERE

using $LogRecordArray = $Array<::java::util::logging::LogRecord>;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalAccessException = ::java::lang::IllegalAccessException;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InstantiationException = ::java::lang::InstantiationException;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Formatter = ::java::util::logging::Formatter;
using $Handler = ::java::util::logging::Handler;
using $Level = ::java::util::logging::Level;
using $LogManager = ::java::util::logging::LogManager;
using $LogRecord = ::java::util::logging::LogRecord;
using $SimpleFormatter = ::java::util::logging::SimpleFormatter;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _MemoryHandler_FieldInfo_[] = {
	{"DEFAULT_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(MemoryHandler, DEFAULT_SIZE)},
	{"pushLevel", "Ljava/util/logging/Level;", nullptr, $PRIVATE | $VOLATILE, $field(MemoryHandler, pushLevel)},
	{"size", "I", nullptr, $PRIVATE, $field(MemoryHandler, size)},
	{"target", "Ljava/util/logging/Handler;", nullptr, $PRIVATE, $field(MemoryHandler, target)},
	{"buffer", "[Ljava/util/logging/LogRecord;", nullptr, $PRIVATE, $field(MemoryHandler, buffer)},
	{"start", "I", nullptr, 0, $field(MemoryHandler, start)},
	{"count", "I", nullptr, 0, $field(MemoryHandler, count)},
	{}
};

$MethodInfo _MemoryHandler_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(MemoryHandler::*)()>(&MemoryHandler::init$))},
	{"<init>", "(Ljava/util/logging/Handler;ILjava/util/logging/Level;)V", nullptr, $PUBLIC, $method(static_cast<void(MemoryHandler::*)($Handler*,int32_t,$Level*)>(&MemoryHandler::init$))},
	{"close", "()V", nullptr, $PUBLIC, nullptr, "java.lang.SecurityException"},
	{"flush", "()V", nullptr, $PUBLIC},
	{"getPushLevel", "()Ljava/util/logging/Level;", nullptr, $PUBLIC},
	{"init", "()V", nullptr, $PRIVATE, $method(static_cast<void(MemoryHandler::*)()>(&MemoryHandler::init))},
	{"isLoggable", "(Ljava/util/logging/LogRecord;)Z", nullptr, $PUBLIC},
	{"publish", "(Ljava/util/logging/LogRecord;)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"push", "()V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"setPushLevel", "(Ljava/util/logging/Level;)V", nullptr, $PUBLIC | $SYNCHRONIZED, nullptr, "java.lang.SecurityException"},
	{}
};

$ClassInfo _MemoryHandler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.logging.MemoryHandler",
	"java.util.logging.Handler",
	nullptr,
	_MemoryHandler_FieldInfo_,
	_MemoryHandler_MethodInfo_
};

$Object* allocate$MemoryHandler($Class* clazz) {
	return $of($alloc(MemoryHandler));
}

void MemoryHandler::init$() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$init($Level);
	$Handler::init$($Level::ALL, $$new($SimpleFormatter), nullptr);
	$var($LogManager, manager, $LogManager::getLogManager());
	$var($String, cname, $of(this)->getClass()->getName());
	$set(this, pushLevel, $nc(manager)->getLevelProperty($$str({cname, ".push"_s}), $Level::SEVERE));
	this->size = manager->getIntProperty($$str({cname, ".size"_s}), MemoryHandler::DEFAULT_SIZE);
	if (this->size <= 0) {
		this->size = MemoryHandler::DEFAULT_SIZE;
	}
	$var($String, targetName, manager->getProperty($$str({cname, ".target"_s})));
	if (targetName == nullptr) {
		$throwNew($RuntimeException, $$str({"The handler "_s, cname, " does not specify a target"_s}));
	}
	$Class* clz = nullptr;
	try {
		clz = $nc($($ClassLoader::getSystemClassLoader()))->loadClass(targetName);
		$var($Object, o, $nc(clz)->newInstance());
		$set(this, target, $cast($Handler, o));
	} catch ($ClassNotFoundException& e) {
		$throwNew($RuntimeException, $$str({"MemoryHandler can\'t load handler target \""_s, targetName, "\""_s}), e);
	} catch ($InstantiationException& e) {
		$throwNew($RuntimeException, $$str({"MemoryHandler can\'t load handler target \""_s, targetName, "\""_s}), e);
	} catch ($IllegalAccessException& e) {
		$throwNew($RuntimeException, $$str({"MemoryHandler can\'t load handler target \""_s, targetName, "\""_s}), e);
	}
	init();
}

void MemoryHandler::init() {
	$set(this, buffer, $new($LogRecordArray, this->size));
	this->start = 0;
	this->count = 0;
}

void MemoryHandler::init$($Handler* target, int32_t size, $Level* pushLevel) {
	$init($Level);
	$Handler::init$($Level::ALL, $$new($SimpleFormatter), nullptr);
	if (target == nullptr || pushLevel == nullptr) {
		$throwNew($NullPointerException);
	}
	if (size <= 0) {
		$throwNew($IllegalArgumentException);
	}
	$set(this, target, target);
	$set(this, pushLevel, pushLevel);
	this->size = size;
	init();
}

void MemoryHandler::publish($LogRecord* record) {
	$synchronized(this) {
		if (!isLoggable(record)) {
			return;
		}
		int32_t ix = $mod((this->start + this->count), $nc(this->buffer)->length);
		$nc(this->buffer)->set(ix, record);
		if (this->count < $nc(this->buffer)->length) {
			++this->count;
		} else {
			++this->start;
			$modAssign(this->start, $nc(this->buffer)->length);
		}
		int32_t var$0 = $nc($($nc(record)->getLevel()))->intValue();
		if (var$0 >= $nc(this->pushLevel)->intValue()) {
			push();
		}
	}
}

void MemoryHandler::push() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		for (int32_t i = 0; i < this->count; ++i) {
			int32_t ix = $mod((this->start + i), $nc(this->buffer)->length);
			$var($LogRecord, record, $nc(this->buffer)->get(ix));
			$nc(this->target)->publish(record);
		}
		this->start = 0;
		this->count = 0;
	}
}

void MemoryHandler::flush() {
	$nc(this->target)->flush();
}

void MemoryHandler::close() {
	$nc(this->target)->close();
	$init($Level);
	setLevel($Level::OFF);
}

void MemoryHandler::setPushLevel($Level* newLevel) {
	$synchronized(this) {
		if (newLevel == nullptr) {
			$throwNew($NullPointerException);
		}
		checkPermission();
		$set(this, pushLevel, newLevel);
	}
}

$Level* MemoryHandler::getPushLevel() {
	return this->pushLevel;
}

bool MemoryHandler::isLoggable($LogRecord* record) {
	return $Handler::isLoggable(record);
}

MemoryHandler::MemoryHandler() {
}

$Class* MemoryHandler::load$($String* name, bool initialize) {
	$loadClass(MemoryHandler, name, initialize, &_MemoryHandler_ClassInfo_, allocate$MemoryHandler);
	return class$;
}

$Class* MemoryHandler::class$ = nullptr;

		} // logging
	} // util
} // java