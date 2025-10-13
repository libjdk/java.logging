#ifndef _java_util_logging_FileHandler$1_h_
#define _java_util_logging_FileHandler$1_h_
//$ class java.util.logging.FileHandler$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace util {
		namespace logging {
			class FileHandler;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class FileHandler$1 : public ::java::security::PrivilegedAction {
	$class(FileHandler$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	FileHandler$1();
	void init$(::java::util::logging::FileHandler* this$0);
	virtual $Object* run() override;
	::java::util::logging::FileHandler* this$0 = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_FileHandler$1_h_