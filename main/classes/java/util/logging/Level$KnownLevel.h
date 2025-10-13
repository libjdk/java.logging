#ifndef _java_util_logging_Level$KnownLevel_h_
#define _java_util_logging_Level$KnownLevel_h_
//$ class java.util.logging.Level$KnownLevel
//$ extends java.lang.ref.WeakReference

#include <java/lang/ref/WeakReference.h>

#pragma push_macro("CUSTOM_LEVEL_CLV")
#undef CUSTOM_LEVEL_CLV
#pragma push_macro("QUEUE")
#undef QUEUE

namespace java {
	namespace lang {
		class ClassLoader;
		class Integer;
	}
}
namespace java {
	namespace lang {
		namespace ref {
			class ReferenceQueue;
		}
	}
}
namespace java {
	namespace util {
		class List;
		class Map;
		class Optional;
	}
}
namespace java {
	namespace util {
		namespace function {
			class Function;
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
namespace jdk {
	namespace internal {
		namespace loader {
			class ClassLoaderValue;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $export Level$KnownLevel : public ::java::lang::ref::WeakReference {
	$class(Level$KnownLevel, 0, ::java::lang::ref::WeakReference)
public:
	Level$KnownLevel();
	void init$(::java::util::logging::Level* l);
	static void add(::java::util::logging::Level* l);
	static ::java::util::Optional* findByLocalizedLevelName($String* name, ::java::util::function::Function* selector);
	static ::java::util::Optional* findByName($String* name, ::java::util::function::Function* selector);
	static ::java::util::Optional* findByValue(int32_t value, ::java::util::function::Function* selector);
	static ::java::util::List* lambda$add$3($String* k);
	static ::java::util::List* lambda$add$4(::java::lang::Integer* k);
	static bool lambda$findByLocalizedLevelName$5($String* name, ::java::util::logging::Level* l);
	static ::java::util::List* lambda$registerWithClassLoader$2(::java::lang::ClassLoader* c, ::jdk::internal::loader::ClassLoaderValue* v);
	void lambda$remove$0(::java::util::List* x);
	static ::java::util::Optional* matches(::java::util::logging::Level* l);
	::java::util::Optional* mirrored();
	static void purge();
	::java::util::Optional* referent();
	static void registerWithClassLoader(::java::util::logging::Level* customLevel);
	void remove();
	static ::java::util::Map* nameToLevels;
	static ::java::util::Map* intToLevels;
	static ::java::lang::ref::ReferenceQueue* QUEUE;
	static ::jdk::internal::loader::ClassLoaderValue* CUSTOM_LEVEL_CLV;
	::java::util::logging::Level* mirroredLevel = nullptr;
};

		} // logging
	} // util
} // java

#pragma pop_macro("CUSTOM_LEVEL_CLV")
#pragma pop_macro("QUEUE")

#endif // _java_util_logging_Level$KnownLevel_h_