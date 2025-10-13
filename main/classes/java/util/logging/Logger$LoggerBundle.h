#ifndef _java_util_logging_Logger$LoggerBundle_h_
#define _java_util_logging_Logger$LoggerBundle_h_
//$ class java.util.logging.Logger$LoggerBundle
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace util {
		class ResourceBundle;
	}
}

namespace java {
	namespace util {
		namespace logging {

class Logger$LoggerBundle : public ::java::lang::Object {
	$class(Logger$LoggerBundle, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Logger$LoggerBundle();
	void init$($String* resourceBundleName, ::java::util::ResourceBundle* bundle);
	static ::java::util::logging::Logger$LoggerBundle* get($String* name, ::java::util::ResourceBundle* bundle);
	bool isSystemBundle();
	$String* resourceBundleName = nullptr;
	::java::util::ResourceBundle* userBundle = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_Logger$LoggerBundle_h_