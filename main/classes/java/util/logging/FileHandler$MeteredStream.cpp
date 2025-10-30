#include <java/util/logging/FileHandler$MeteredStream.h>

#include <java/io/OutputStream.h>
#include <java/util/logging/FileHandler.h>
#include <jcpp.h>

using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $FileHandler = ::java::util::logging::FileHandler;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _FileHandler$MeteredStream_FieldInfo_[] = {
	{"out", "Ljava/io/OutputStream;", nullptr, $FINAL, $field(FileHandler$MeteredStream, out)},
	{"written", "J", nullptr, 0, $field(FileHandler$MeteredStream, written)},
	{}
};

$MethodInfo _FileHandler$MeteredStream_MethodInfo_[] = {
	{"<init>", "(Ljava/io/OutputStream;J)V", nullptr, 0, $method(static_cast<void(FileHandler$MeteredStream::*)($OutputStream*,int64_t)>(&FileHandler$MeteredStream::init$))},
	{"close", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"flush", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"write", "(I)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"write", "([B)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"write", "([BII)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _FileHandler$MeteredStream_InnerClassesInfo_[] = {
	{"java.util.logging.FileHandler$MeteredStream", "java.util.logging.FileHandler", "MeteredStream", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _FileHandler$MeteredStream_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.logging.FileHandler$MeteredStream",
	"java.io.OutputStream",
	nullptr,
	_FileHandler$MeteredStream_FieldInfo_,
	_FileHandler$MeteredStream_MethodInfo_,
	nullptr,
	nullptr,
	_FileHandler$MeteredStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.FileHandler"
};

$Object* allocate$FileHandler$MeteredStream($Class* clazz) {
	return $of($alloc(FileHandler$MeteredStream));
}

void FileHandler$MeteredStream::init$($OutputStream* out, int64_t written) {
	$OutputStream::init$();
	$set(this, out, out);
	this->written = written;
}

void FileHandler$MeteredStream::write(int32_t b) {
	$nc(this->out)->write(b);
	++this->written;
}

void FileHandler$MeteredStream::write($bytes* buff) {
	$nc(this->out)->write(buff);
	this->written += $nc(buff)->length;
}

void FileHandler$MeteredStream::write($bytes* buff, int32_t off, int32_t len) {
	$nc(this->out)->write(buff, off, len);
	this->written += len;
}

void FileHandler$MeteredStream::flush() {
	$nc(this->out)->flush();
}

void FileHandler$MeteredStream::close() {
	$nc(this->out)->close();
}

FileHandler$MeteredStream::FileHandler$MeteredStream() {
}

$Class* FileHandler$MeteredStream::load$($String* name, bool initialize) {
	$loadClass(FileHandler$MeteredStream, name, initialize, &_FileHandler$MeteredStream_ClassInfo_, allocate$FileHandler$MeteredStream);
	return class$;
}

$Class* FileHandler$MeteredStream::class$ = nullptr;

		} // logging
	} // util
} // java