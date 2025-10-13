#ifndef _java_util_logging_LogManager$ModType_h_
#define _java_util_logging_LogManager$ModType_h_
//$ class java.util.logging.LogManager$ModType
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("ADDED")
#undef ADDED
#pragma push_macro("CHANGED")
#undef CHANGED
#pragma push_macro("REMOVED")
#undef REMOVED
#pragma push_macro("SAME")
#undef SAME

namespace java {
	namespace util {
		namespace logging {

class $import LogManager$ModType : public ::java::lang::Enum {
	$class(LogManager$ModType, 0, ::java::lang::Enum)
public:
	LogManager$ModType();
	static $Array<::java::util::logging::LogManager$ModType>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::java::util::logging::LogManager$ModType* of($String* previous, $String* next);
	static ::java::util::logging::LogManager$ModType* valueOf($String* name);
	static $Array<::java::util::logging::LogManager$ModType>* values();
	static ::java::util::logging::LogManager$ModType* SAME;
	static ::java::util::logging::LogManager$ModType* ADDED;
	static ::java::util::logging::LogManager$ModType* CHANGED;
	static ::java::util::logging::LogManager$ModType* REMOVED;
	static $Array<::java::util::logging::LogManager$ModType>* $VALUES;
};

		} // logging
	} // util
} // java

#pragma pop_macro("ADDED")
#pragma pop_macro("CHANGED")
#pragma pop_macro("REMOVED")
#pragma pop_macro("SAME")

#endif // _java_util_logging_LogManager$ModType_h_