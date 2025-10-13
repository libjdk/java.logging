#ifndef _java_util_logging_FileHandler$InitializationErrorManager_h_
#define _java_util_logging_FileHandler$InitializationErrorManager_h_
//$ class java.util.logging.FileHandler$InitializationErrorManager
//$ extends java.util.logging.ErrorManager

#include <java/util/logging/ErrorManager.h>

namespace java {
	namespace lang {
		class Exception;
	}
}

namespace java {
	namespace util {
		namespace logging {

class FileHandler$InitializationErrorManager : public ::java::util::logging::ErrorManager {
	$class(FileHandler$InitializationErrorManager, $NO_CLASS_INIT, ::java::util::logging::ErrorManager)
public:
	FileHandler$InitializationErrorManager();
	void init$();
	virtual void error($String* msg, ::java::lang::Exception* ex, int32_t code) override;
	::java::lang::Exception* lastException = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_FileHandler$InitializationErrorManager_h_