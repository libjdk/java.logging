#ifndef _java_util_logging_Logger$ConfigurationData_h_
#define _java_util_logging_Logger$ConfigurationData_h_
//$ class java.util.logging.Logger$ConfigurationData
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace util {
		namespace concurrent {
			class CopyOnWriteArrayList;
		}
	}
}
namespace java {
	namespace util {
		namespace logging {
			class Filter;
			class Handler;
			class Level;
			class Logger;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class Logger$ConfigurationData : public ::java::lang::Object {
	$class(Logger$ConfigurationData, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Logger$ConfigurationData();
	void init$();
	void addHandler(::java::util::logging::Handler* h);
	::java::util::logging::Logger$ConfigurationData* merge(::java::util::logging::Logger* systemPeer);
	void removeHandler(::java::util::logging::Handler* h);
	void setFilter(::java::util::logging::Filter* f);
	void setLevelObject(::java::util::logging::Level* l);
	void setLevelValue(int32_t v);
	void setUseParentHandlers(bool flag);
	$volatile(::java::util::logging::Logger$ConfigurationData*) delegate = nullptr;
	$volatile(bool) useParentHandlers = false;
	$volatile(::java::util::logging::Filter*) filter = nullptr;
	$volatile(::java::util::logging::Level*) levelObject = nullptr;
	$volatile(int32_t) levelValue = 0;
	::java::util::concurrent::CopyOnWriteArrayList* handlers = nullptr;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_Logger$ConfigurationData_h_