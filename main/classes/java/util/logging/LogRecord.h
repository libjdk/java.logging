#ifndef _java_util_logging_LogRecord_h_
#define _java_util_logging_LogRecord_h_
//$ class java.util.logging.LogRecord
//$ extends java.io.Serializable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>

namespace java {
	namespace io {
		class ObjectInputStream;
		class ObjectOutputStream;
		class ObjectStreamField;
	}
}
namespace java {
	namespace lang {
		class StackWalker$StackFrame;
		class Throwable;
	}
}
namespace java {
	namespace time {
		class Instant;
	}
}
namespace java {
	namespace util {
		class ResourceBundle;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicLong;
			}
		}
	}
}
namespace java {
	namespace util {
		namespace logging {
			class Level;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $export LogRecord : public ::java::io::Serializable {
	$class(LogRecord, 0, ::java::io::Serializable)
public:
	LogRecord();
	void init$(::java::util::logging::Level* level, $String* msg);
	virtual ::java::time::Instant* getInstant();
	virtual ::java::util::logging::Level* getLevel();
	virtual $String* getLoggerName();
	virtual int64_t getLongThreadID();
	virtual $String* getMessage();
	virtual int64_t getMillis();
	virtual $ObjectArray* getParameters();
	virtual ::java::util::ResourceBundle* getResourceBundle();
	virtual $String* getResourceBundleName();
	virtual int64_t getSequenceNumber();
	virtual $String* getSourceClassName();
	virtual $String* getSourceMethodName();
	virtual int32_t getThreadID();
	virtual $Throwable* getThrown();
	void inferCaller();
	void lambda$inferCaller$0(::java::lang::StackWalker$StackFrame* f);
	void readObject(::java::io::ObjectInputStream* in);
	virtual void setInstant(::java::time::Instant* instant);
	virtual void setLevel(::java::util::logging::Level* level);
	virtual void setLoggerName($String* name);
	virtual ::java::util::logging::LogRecord* setLongThreadID(int64_t longThreadID);
	virtual void setMessage($String* message);
	virtual void setMillis(int64_t millis);
	virtual void setParameters($ObjectArray* parameters);
	virtual void setResourceBundle(::java::util::ResourceBundle* bundle);
	virtual void setResourceBundleName($String* name);
	virtual void setSequenceNumber(int64_t seq);
	virtual void setSourceClassName($String* sourceClassName);
	virtual void setSourceMethodName($String* sourceMethodName);
	virtual void setThreadID(int32_t threadID);
	virtual void setThrown($Throwable* thrown);
	int32_t shortThreadID(int64_t id);
	void writeObject(::java::io::ObjectOutputStream* out);
	static ::java::util::concurrent::atomic::AtomicLong* globalSequenceNumber;
	::java::util::logging::Level* level = nullptr;
	int64_t sequenceNumber = 0;
	$String* sourceClassName = nullptr;
	$String* sourceMethodName = nullptr;
	$String* message = nullptr;
	int32_t threadID = 0;
	int64_t longThreadID = 0;
	$Throwable* thrown = nullptr;
	$String* loggerName = nullptr;
	$String* resourceBundleName = nullptr;
	::java::time::Instant* instant = nullptr;
	static $Array<::java::io::ObjectStreamField>* serialPersistentFields;
	bool needToInferCaller = false;
	$ObjectArray* parameters = nullptr;
	::java::util::ResourceBundle* resourceBundle = nullptr;
	static const int64_t serialVersionUID = (int64_t)0x4A8D593DF3695196;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_LogRecord_h_