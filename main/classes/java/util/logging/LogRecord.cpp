#include <java/util/logging/LogRecord.h>

#include <java/io/IOException.h>
#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream$PutField.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/ObjectStreamField.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/Math.h>
#include <java/lang/NegativeArraySizeException.h>
#include <java/lang/StackWalker$StackFrame.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/time/Instant.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/MissingResourceException.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/ResourceBundle.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <java/util/function/Consumer.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/LogRecord$CallerFinder.h>
#include <jcpp.h>

#undef MAX_VALUE
#undef TYPE

using $ObjectStreamFieldArray = $Array<::java::io::ObjectStreamField>;
using $IOException = ::java::io::IOException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectOutputStream$PutField = ::java::io::ObjectOutputStream$PutField;
using $ObjectStreamField = ::java::io::ObjectStreamField;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $NegativeArraySizeException = ::java::lang::NegativeArraySizeException;
using $NullPointerException = ::java::lang::NullPointerException;
using $StackWalker$StackFrame = ::java::lang::StackWalker$StackFrame;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Instant = ::java::time::Instant;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $MissingResourceException = ::java::util::MissingResourceException;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $ResourceBundle = ::java::util::ResourceBundle;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $Consumer = ::java::util::function::Consumer;
using $Level = ::java::util::logging::Level;
using $LogRecord$CallerFinder = ::java::util::logging::LogRecord$CallerFinder;

namespace java {
	namespace util {
		namespace logging {

class LogRecord$$Lambda$lambda$inferCaller$0 : public $Consumer {
	$class(LogRecord$$Lambda$lambda$inferCaller$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$(LogRecord* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* f) override {
		$nc(inst$)->lambda$inferCaller$0($cast($StackWalker$StackFrame, f));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<LogRecord$$Lambda$lambda$inferCaller$0>());
	}
	LogRecord* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo LogRecord$$Lambda$lambda$inferCaller$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(LogRecord$$Lambda$lambda$inferCaller$0, inst$)},
	{}
};
$MethodInfo LogRecord$$Lambda$lambda$inferCaller$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/logging/LogRecord;)V", nullptr, $PUBLIC, $method(static_cast<void(LogRecord$$Lambda$lambda$inferCaller$0::*)(LogRecord*)>(&LogRecord$$Lambda$lambda$inferCaller$0::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo LogRecord$$Lambda$lambda$inferCaller$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.LogRecord$$Lambda$lambda$inferCaller$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* LogRecord$$Lambda$lambda$inferCaller$0::load$($String* name, bool initialize) {
	$loadClass(LogRecord$$Lambda$lambda$inferCaller$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* LogRecord$$Lambda$lambda$inferCaller$0::class$ = nullptr;

$NamedAttribute LogRecord_Attribute_var$0[] = {
	{"since", 's', "16"},
	{}
};

$CompoundAttribute _LogRecord_MethodAnnotations_getThreadID13[] = {
	{"Ljava/lang/Deprecated;", LogRecord_Attribute_var$0},
	{}
};

$CompoundAttribute _LogRecord_MethodAnnotations_setMillis23[] = {
	{"Ljava/lang/Deprecated;", nullptr},
	{}
};

$NamedAttribute LogRecord_Attribute_var$1[] = {
	{"since", 's', "16"},
	{}
};

$CompoundAttribute _LogRecord_MethodAnnotations_setThreadID30[] = {
	{"Ljava/lang/Deprecated;", LogRecord_Attribute_var$1},
	{}
};

$FieldInfo _LogRecord_FieldInfo_[] = {
	{"globalSequenceNumber", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LogRecord, globalSequenceNumber)},
	{"level", "Ljava/util/logging/Level;", nullptr, $PRIVATE, $field(LogRecord, level)},
	{"sequenceNumber", "J", nullptr, $PRIVATE, $field(LogRecord, sequenceNumber)},
	{"sourceClassName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(LogRecord, sourceClassName)},
	{"sourceMethodName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(LogRecord, sourceMethodName)},
	{"message", "Ljava/lang/String;", nullptr, $PRIVATE, $field(LogRecord, message)},
	{"threadID", "I", nullptr, $PRIVATE, $field(LogRecord, threadID)},
	{"longThreadID", "J", nullptr, $PRIVATE, $field(LogRecord, longThreadID)},
	{"thrown", "Ljava/lang/Throwable;", nullptr, $PRIVATE, $field(LogRecord, thrown)},
	{"loggerName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(LogRecord, loggerName)},
	{"resourceBundleName", "Ljava/lang/String;", nullptr, $PRIVATE, $field(LogRecord, resourceBundleName)},
	{"instant", "Ljava/time/Instant;", nullptr, $PRIVATE, $field(LogRecord, instant)},
	{"serialPersistentFields", "[Ljava/io/ObjectStreamField;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(LogRecord, serialPersistentFields)},
	{"needToInferCaller", "Z", nullptr, $PRIVATE | $TRANSIENT, $field(LogRecord, needToInferCaller)},
	{"parameters", "[Ljava/lang/Object;", nullptr, $PRIVATE | $TRANSIENT, $field(LogRecord, parameters)},
	{"resourceBundle", "Ljava/util/ResourceBundle;", nullptr, $PRIVATE | $TRANSIENT, $field(LogRecord, resourceBundle)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(LogRecord, serialVersionUID)},
	{}
};

$MethodInfo _LogRecord_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/Level;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(LogRecord::*)($Level*,$String*)>(&LogRecord::init$))},
	{"getInstant", "()Ljava/time/Instant;", nullptr, $PUBLIC},
	{"getLevel", "()Ljava/util/logging/Level;", nullptr, $PUBLIC},
	{"getLoggerName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getLongThreadID", "()J", nullptr, $PUBLIC},
	{"getMessage", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getMillis", "()J", nullptr, $PUBLIC},
	{"getParameters", "()[Ljava/lang/Object;", nullptr, $PUBLIC},
	{"getResourceBundle", "()Ljava/util/ResourceBundle;", nullptr, $PUBLIC},
	{"getResourceBundleName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getSequenceNumber", "()J", nullptr, $PUBLIC},
	{"getSourceClassName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getSourceMethodName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getThreadID", "()I", nullptr, $PUBLIC | $DEPRECATED, nullptr, nullptr, nullptr, _LogRecord_MethodAnnotations_getThreadID13},
	{"getThrown", "()Ljava/lang/Throwable;", nullptr, $PUBLIC},
	{"inferCaller", "()V", nullptr, $PRIVATE, $method(static_cast<void(LogRecord::*)()>(&LogRecord::inferCaller))},
	{"lambda$inferCaller$0", "(Ljava/lang/StackWalker$StackFrame;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(LogRecord::*)($StackWalker$StackFrame*)>(&LogRecord::lambda$inferCaller$0))},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(LogRecord::*)($ObjectInputStream*)>(&LogRecord::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"setInstant", "(Ljava/time/Instant;)V", nullptr, $PUBLIC},
	{"setLevel", "(Ljava/util/logging/Level;)V", nullptr, $PUBLIC},
	{"setLoggerName", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"setLongThreadID", "(J)Ljava/util/logging/LogRecord;", nullptr, $PUBLIC},
	{"setMessage", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"setMillis", "(J)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, nullptr, nullptr, _LogRecord_MethodAnnotations_setMillis23},
	{"setParameters", "([Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"setResourceBundle", "(Ljava/util/ResourceBundle;)V", nullptr, $PUBLIC},
	{"setResourceBundleName", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"setSequenceNumber", "(J)V", nullptr, $PUBLIC},
	{"setSourceClassName", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"setSourceMethodName", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"setThreadID", "(I)V", nullptr, $PUBLIC | $DEPRECATED, nullptr, nullptr, nullptr, _LogRecord_MethodAnnotations_setThreadID30},
	{"setThrown", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"shortThreadID", "(J)I", nullptr, $PRIVATE, $method(static_cast<int32_t(LogRecord::*)(int64_t)>(&LogRecord::shortThreadID))},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(LogRecord::*)($ObjectOutputStream*)>(&LogRecord::writeObject)), "java.io.IOException"},
	{}
};

$InnerClassInfo _LogRecord_InnerClassesInfo_[] = {
	{"java.util.logging.LogRecord$CallerFinder", "java.util.logging.LogRecord", "CallerFinder", $STATIC | $FINAL},
	{}
};

$ClassInfo _LogRecord_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.logging.LogRecord",
	"java.lang.Object",
	"java.io.Serializable",
	_LogRecord_FieldInfo_,
	_LogRecord_MethodInfo_,
	nullptr,
	nullptr,
	_LogRecord_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.logging.LogRecord$CallerFinder"
};

$Object* allocate$LogRecord($Class* clazz) {
	return $of($alloc(LogRecord));
}

$AtomicLong* LogRecord::globalSequenceNumber = nullptr;
$ObjectStreamFieldArray* LogRecord::serialPersistentFields = nullptr;

int32_t LogRecord::shortThreadID(int64_t id) {
	if (id >= 0 && id <= $Integer::MAX_VALUE) {
		return (int32_t)id;
	}
	int32_t hash = $Long::hashCode(id);
	return hash < 0 ? hash : (-1 - hash);
}

void LogRecord::init$($Level* level, $String* msg) {
	$set(this, level, $cast($Level, $Objects::requireNonNull(level)));
	$set(this, message, msg);
	this->sequenceNumber = $nc(LogRecord::globalSequenceNumber)->getAndIncrement();
	int64_t id = $($Thread::currentThread())->getId();
	this->threadID = shortThreadID(id);
	this->longThreadID = id;
	$set(this, instant, $Instant::now());
	this->needToInferCaller = true;
}

$String* LogRecord::getLoggerName() {
	return this->loggerName;
}

void LogRecord::setLoggerName($String* name) {
	$set(this, loggerName, name);
}

$ResourceBundle* LogRecord::getResourceBundle() {
	return this->resourceBundle;
}

void LogRecord::setResourceBundle($ResourceBundle* bundle) {
	$set(this, resourceBundle, bundle);
}

$String* LogRecord::getResourceBundleName() {
	return this->resourceBundleName;
}

void LogRecord::setResourceBundleName($String* name) {
	$set(this, resourceBundleName, name);
}

$Level* LogRecord::getLevel() {
	return this->level;
}

void LogRecord::setLevel($Level* level) {
	if (level == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, level, level);
}

int64_t LogRecord::getSequenceNumber() {
	return this->sequenceNumber;
}

void LogRecord::setSequenceNumber(int64_t seq) {
	this->sequenceNumber = seq;
}

$String* LogRecord::getSourceClassName() {
	if (this->needToInferCaller) {
		inferCaller();
	}
	return this->sourceClassName;
}

void LogRecord::setSourceClassName($String* sourceClassName) {
	$set(this, sourceClassName, sourceClassName);
	this->needToInferCaller = false;
}

$String* LogRecord::getSourceMethodName() {
	if (this->needToInferCaller) {
		inferCaller();
	}
	return this->sourceMethodName;
}

void LogRecord::setSourceMethodName($String* sourceMethodName) {
	$set(this, sourceMethodName, sourceMethodName);
	this->needToInferCaller = false;
}

$String* LogRecord::getMessage() {
	return this->message;
}

void LogRecord::setMessage($String* message) {
	$set(this, message, message);
}

$ObjectArray* LogRecord::getParameters() {
	return this->parameters;
}

void LogRecord::setParameters($ObjectArray* parameters) {
	$set(this, parameters, parameters);
}

int32_t LogRecord::getThreadID() {
	return this->threadID;
}

void LogRecord::setThreadID(int32_t threadID) {
	this->threadID = threadID;
	this->longThreadID = threadID;
}

int64_t LogRecord::getLongThreadID() {
	return this->longThreadID;
}

LogRecord* LogRecord::setLongThreadID(int64_t longThreadID) {
	this->threadID = shortThreadID(longThreadID);
	this->longThreadID = longThreadID;
	return this;
}

int64_t LogRecord::getMillis() {
	return $nc(this->instant)->toEpochMilli();
}

void LogRecord::setMillis(int64_t millis) {
	$set(this, instant, $Instant::ofEpochMilli(millis));
}

$Instant* LogRecord::getInstant() {
	return this->instant;
}

void LogRecord::setInstant($Instant* instant) {
	$nc(instant)->toEpochMilli();
	$set(this, instant, instant);
}

$Throwable* LogRecord::getThrown() {
	return this->thrown;
}

void LogRecord::setThrown($Throwable* thrown) {
	$set(this, thrown, thrown);
}

void LogRecord::writeObject($ObjectOutputStream* out) {
	$useLocalCurrentObjectStackCache();
	$var($ObjectOutputStream$PutField, pf, $nc(out)->putFields());
	$nc(pf)->put("level"_s, $of(this->level));
	pf->put("sequenceNumber"_s, this->sequenceNumber);
	pf->put("sourceClassName"_s, $of(this->sourceClassName));
	pf->put("sourceMethodName"_s, $of(this->sourceMethodName));
	pf->put("message"_s, $of(this->message));
	pf->put("threadID"_s, this->threadID);
	pf->put("longThreadID"_s, this->longThreadID);
	pf->put("millis"_s, $nc(this->instant)->toEpochMilli());
	pf->put("nanoAdjustment"_s, $nc(this->instant)->getNano() % 0x000F4240);
	pf->put("thrown"_s, $of(this->thrown));
	pf->put("loggerName"_s, $of(this->loggerName));
	pf->put("resourceBundleName"_s, $of(this->resourceBundleName));
	out->writeFields();
	out->writeByte(1);
	out->writeByte(0);
	if (this->parameters == nullptr) {
		out->writeInt(-1);
		return;
	}
	out->writeInt($nc(this->parameters)->length);
	{
		$var($ObjectArray, arr$, this->parameters);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Object0, parameter, arr$->get(i$));
			{
				out->writeObject($($Objects::toString(parameter, nullptr)));
			}
		}
	}
}

void LogRecord::readObject($ObjectInputStream* in) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ObjectInputStream$GetField, gf, $nc(in)->readFields());
	$set(this, level, $cast($Level, $nc(gf)->get("level"_s, ($Object*)nullptr)));
	this->sequenceNumber = gf->get("sequenceNumber"_s, (int64_t)0);
	$set(this, sourceClassName, $cast($String, gf->get("sourceClassName"_s, ($Object*)nullptr)));
	$set(this, sourceMethodName, $cast($String, gf->get("sourceMethodName"_s, ($Object*)nullptr)));
	$set(this, message, $cast($String, gf->get("message"_s, ($Object*)nullptr)));
	int32_t threadID = gf->get("threadID"_s, 0);
	int64_t longThreadID = gf->get("longThreadID"_s, (int64_t)threadID);
	if (threadID != longThreadID) {
		threadID = shortThreadID(longThreadID);
	}
	this->threadID = threadID;
	this->longThreadID = longThreadID;
	int64_t millis = gf->get("millis"_s, (int64_t)0);
	int32_t nanoOfMilli = gf->get("nanoAdjustment"_s, 0);
	$set(this, instant, $Instant::ofEpochSecond($div(millis, (int64_t)1000), ($mod(millis, (int64_t)1000)) * (int64_t)1000000 + nanoOfMilli));
	$set(this, thrown, $cast($Throwable, gf->get("thrown"_s, ($Object*)nullptr)));
	$set(this, loggerName, $cast($String, gf->get("loggerName"_s, ($Object*)nullptr)));
	$set(this, resourceBundleName, $cast($String, gf->get("resourceBundleName"_s, ($Object*)nullptr)));
	int8_t major = in->readByte();
	int8_t minor = in->readByte();
	if (major != 1) {
		$throwNew($IOException, $$str({"LogRecord: bad version: "_s, $$str(major), "."_s, $$str(minor)}));
	}
	int32_t len = in->readInt();
	if (len < -1) {
		$throwNew($NegativeArraySizeException);
	} else if (len == -1) {
		$set(this, parameters, nullptr);
	} else if (len < 255) {
		$set(this, parameters, $new($ObjectArray, len));
		for (int32_t i = 0; i < $nc(this->parameters)->length; ++i) {
			$nc(this->parameters)->set(i, $(in->readObject()));
		}
	} else {
		$var($List, params, $new($ArrayList, $Math::min(len, 1024)));
		for (int32_t i = 0; i < len; ++i) {
			params->add($(in->readObject()));
		}
		$set(this, parameters, params->toArray($$new($ObjectArray, params->size())));
	}
	if (this->resourceBundleName != nullptr) {
		try {
			$var($String, var$0, this->resourceBundleName);
			$var($Locale, var$1, $Locale::getDefault());
			$var($ResourceBundle, bundle, $ResourceBundle::getBundle(var$0, var$1, $($ClassLoader::getSystemClassLoader())));
			$set(this, resourceBundle, bundle);
		} catch ($MissingResourceException& ex) {
			$set(this, resourceBundle, nullptr);
		}
	}
	this->needToInferCaller = false;
}

void LogRecord::inferCaller() {
	$useLocalCurrentObjectStackCache();
	this->needToInferCaller = false;
	$var($Optional, frame, $$new($LogRecord$CallerFinder)->get());
	$nc(frame)->ifPresent(static_cast<$Consumer*>($$new(LogRecord$$Lambda$lambda$inferCaller$0, this)));
}

void LogRecord::lambda$inferCaller$0($StackWalker$StackFrame* f) {
	$useLocalCurrentObjectStackCache();
	setSourceClassName($($nc(f)->getClassName()));
	setSourceMethodName($($nc(f)->getMethodName()));
}

void clinit$LogRecord($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(LogRecord::globalSequenceNumber, $new($AtomicLong));
	$load($Level);
	$init($Long);
	$init($Integer);
	$assignStatic(LogRecord::serialPersistentFields, $new($ObjectStreamFieldArray, {
		$$new($ObjectStreamField, "level"_s, $Level::class$),
		$$new($ObjectStreamField, "sequenceNumber"_s, $Long::TYPE),
		$$new($ObjectStreamField, "sourceClassName"_s, $String::class$),
		$$new($ObjectStreamField, "sourceMethodName"_s, $String::class$),
		$$new($ObjectStreamField, "message"_s, $String::class$),
		$$new($ObjectStreamField, "threadID"_s, $Integer::TYPE),
		$$new($ObjectStreamField, "longThreadID"_s, $Long::TYPE),
		$$new($ObjectStreamField, "millis"_s, $Long::TYPE),
		$$new($ObjectStreamField, "nanoAdjustment"_s, $Integer::TYPE),
		$$new($ObjectStreamField, "thrown"_s, $Throwable::class$),
		$$new($ObjectStreamField, "loggerName"_s, $String::class$),
		$$new($ObjectStreamField, "resourceBundleName"_s, $String::class$)
	}));
}

LogRecord::LogRecord() {
}

$Class* LogRecord::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(LogRecord$$Lambda$lambda$inferCaller$0::classInfo$.name)) {
			return LogRecord$$Lambda$lambda$inferCaller$0::load$(name, initialize);
		}
	}
	$loadClass(LogRecord, name, initialize, &_LogRecord_ClassInfo_, clinit$LogRecord, allocate$LogRecord);
	return class$;
}

$Class* LogRecord::class$ = nullptr;

		} // logging
	} // util
} // java