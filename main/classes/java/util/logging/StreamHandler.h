#ifndef _java_util_logging_StreamHandler_h_
#define _java_util_logging_StreamHandler_h_
//$ class java.util.logging.StreamHandler
//$ extends java.util.logging.Handler

#include <java/util/logging/Handler.h>

namespace java {
	namespace io {
		class OutputStream;
		class Writer;
	}
}
namespace java {
	namespace util {
		namespace logging {
			class Formatter;
			class Level;
			class LogRecord;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $export StreamHandler : public ::java::util::logging::Handler {
	$class(StreamHandler, $NO_CLASS_INIT, ::java::util::logging::Handler)
public:
	StreamHandler();
	void init$();
	void init$(::java::io::OutputStream* out, ::java::util::logging::Formatter* formatter);
	void init$(::java::util::logging::Level* defaultLevel, ::java::util::logging::Formatter* defaultFormatter, ::java::util::logging::Formatter* specifiedFormatter);
	virtual void close() override;
	virtual void flush() override;
	void flushAndClose();
	virtual bool isLoggable(::java::util::logging::LogRecord* record) override;
	virtual void publish(::java::util::logging::LogRecord* record) override;
	virtual void setEncoding($String* encoding) override;
	virtual void setOutputStream(::java::io::OutputStream* out);
	void setOutputStreamPrivileged(::java::io::OutputStream* out);
	::java::io::OutputStream* output = nullptr;
	bool doneHeader = false;
	$volatile(::java::io::Writer*) writer = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_StreamHandler_h_