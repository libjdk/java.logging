#ifndef _java_util_logging_FileHandler$MeteredStream_h_
#define _java_util_logging_FileHandler$MeteredStream_h_
//$ class java.util.logging.FileHandler$MeteredStream
//$ extends java.io.OutputStream

#include <java/io/OutputStream.h>
#include <java/lang/Array.h>

namespace java {
	namespace util {
		namespace logging {

class FileHandler$MeteredStream : public ::java::io::OutputStream {
	$class(FileHandler$MeteredStream, $NO_CLASS_INIT, ::java::io::OutputStream)
public:
	FileHandler$MeteredStream();
	void init$(::java::io::OutputStream* out, int64_t written);
	virtual void close() override;
	virtual void flush() override;
	virtual void write(int32_t b) override;
	virtual void write($bytes* buff) override;
	virtual void write($bytes* buff, int32_t off, int32_t len) override;
	::java::io::OutputStream* out = nullptr;
	int64_t written = 0;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_FileHandler$MeteredStream_h_