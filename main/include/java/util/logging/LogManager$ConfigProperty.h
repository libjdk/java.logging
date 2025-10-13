#ifndef _java_util_logging_LogManager$ConfigProperty_h_
#define _java_util_logging_LogManager$ConfigProperty_h_
//$ class java.util.logging.LogManager$ConfigProperty
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("ALL")
#undef ALL
#pragma push_macro("HANDLERS")
#undef HANDLERS
#pragma push_macro("LEVEL")
#undef LEVEL
#pragma push_macro("USEPARENT")
#undef USEPARENT

namespace java {
	namespace util {
		class EnumSet;
		class Optional;
		class Properties;
	}
}
namespace java {
	namespace util {
		namespace function {
			class BiFunction;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $import LogManager$ConfigProperty : public ::java::lang::Enum {
	$class(LogManager$ConfigProperty, 0, ::java::lang::Enum)
public:
	LogManager$ConfigProperty();
	static $Array<::java::util::logging::LogManager$ConfigProperty>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal, $String* suffix);
	static ::java::util::Optional* find($String* property);
	static $String* getLoggerName($String* property);
	virtual bool handleKey($String* key);
	virtual $String* key($String* loggerName);
	static bool lambda$find$0($String* property, ::java::util::logging::LogManager$ConfigProperty* p);
	virtual $String* loggerName($String* key);
	static bool matches($String* property);
	static void merge($String* k, ::java::util::Properties* previous, ::java::util::Properties* next, ::java::util::function::BiFunction* mappingFunction);
	static bool needsUpdating($String* k, ::java::util::Properties* previous, ::java::util::Properties* next);
	static ::java::util::logging::LogManager$ConfigProperty* valueOf($String* name);
	static $Array<::java::util::logging::LogManager$ConfigProperty>* values();
	static bool $assertionsDisabled;
	static ::java::util::logging::LogManager$ConfigProperty* LEVEL;
	static ::java::util::logging::LogManager$ConfigProperty* HANDLERS;
	static ::java::util::logging::LogManager$ConfigProperty* USEPARENT;
	static $Array<::java::util::logging::LogManager$ConfigProperty>* $VALUES;
	$String* suffix = nullptr;
	int32_t length = 0;
	static ::java::util::EnumSet* ALL;
};

		} // logging
	} // util
} // java

#pragma pop_macro("ALL")
#pragma pop_macro("HANDLERS")
#pragma pop_macro("LEVEL")
#pragma pop_macro("USEPARENT")

#endif // _java_util_logging_LogManager$ConfigProperty_h_