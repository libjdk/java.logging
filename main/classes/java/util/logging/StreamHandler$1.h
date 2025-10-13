#ifndef _java_util_logging_StreamHandler$1_h_
#define _java_util_logging_StreamHandler$1_h_
//$ class java.util.logging.StreamHandler$1
//$ extends java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>

namespace java {
	namespace io {
		class OutputStream;
	}
}
namespace java {
	namespace util {
		namespace logging {
			class StreamHandler;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class StreamHandler$1 : public ::java::security::PrivilegedAction {
	$class(StreamHandler$1, $NO_CLASS_INIT, ::java::security::PrivilegedAction)
public:
	StreamHandler$1();
	void init$(::java::util::logging::StreamHandler* this$0, ::java::io::OutputStream* val$out);
	virtual $Object* run() override;
	::java::util::logging::StreamHandler* this$0 = nullptr;
	::java::io::OutputStream* val$out = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_StreamHandler$1_h_