#ifndef _java_util_logging_FileHandler_h_
#define _java_util_logging_FileHandler_h_
//$ class java.util.logging.FileHandler
//$ extends java.util.logging.StreamHandler

#include <java/lang/Array.h>
#include <java/util/logging/StreamHandler.h>

#pragma push_macro("MAX_LOCKS")
#undef MAX_LOCKS

namespace java {
	namespace io {
		class File;
	}
}
namespace java {
	namespace nio {
		namespace channels {
			class FileChannel;
		}
	}
}
namespace java {
	namespace nio {
		namespace file {
			class Path;
		}
	}
}
namespace java {
	namespace util {
		class Set;
	}
}
namespace java {
	namespace util {
		namespace logging {
			class FileHandler$MeteredStream;
			class LogRecord;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $export FileHandler : public ::java::util::logging::StreamHandler {
	$class(FileHandler, 0, ::java::util::logging::StreamHandler)
public:
	FileHandler();
	void init$();
	void init$($String* pattern);
	void init$($String* pattern, bool append);
	void init$($String* pattern, int32_t limit, int32_t count);
	void init$($String* pattern, int32_t limit, int32_t count, bool append);
	void init$($String* pattern, int64_t limit, int32_t count, bool append);
	virtual void close() override;
	void configure();
	::java::io::File* generate($String* pattern, int32_t generation, int32_t unique);
	static ::java::io::File* generate($String* pat, int32_t count, int32_t generation, int32_t unique);
	bool isParentWritable(::java::nio::file::Path* path);
	void open(::java::io::File* fname, bool append);
	void openFiles();
	virtual void publish(::java::util::logging::LogRecord* record) override;
	void rotate();
	static bool $assertionsDisabled;
	::java::util::logging::FileHandler$MeteredStream* meter = nullptr;
	bool append = false;
	int64_t limit = 0;
	int32_t count = 0;
	$String* pattern = nullptr;
	$String* lockFileName = nullptr;
	::java::nio::channels::FileChannel* lockFileChannel = nullptr;
	$Array<::java::io::File>* files = nullptr;
	static const int32_t MAX_LOCKS = 100;
	int32_t maxLocks = 0;
	static ::java::util::Set* locks;
};

		} // logging
	} // util
} // java

#pragma pop_macro("MAX_LOCKS")

#endif // _java_util_logging_FileHandler_h_