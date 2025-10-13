#ifndef _java_util_logging_Level_h_
#define _java_util_logging_Level_h_
//$ class java.util.logging.Level
//$ extends java.io.Serializable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>

#pragma push_macro("ALL")
#undef ALL
#pragma push_macro("CONFIG")
#undef CONFIG
#pragma push_macro("FINE")
#undef FINE
#pragma push_macro("FINER")
#undef FINER
#pragma push_macro("FINEST")
#undef FINEST
#pragma push_macro("INFO")
#undef INFO
#pragma push_macro("OFF")
#undef OFF
#pragma push_macro("SEVERE")
#undef SEVERE
#pragma push_macro("WARNING")
#undef WARNING

namespace java {
	namespace util {
		class Locale;
	}
}

namespace java {
	namespace util {
		namespace logging {

class $import Level : public ::java::io::Serializable {
	$class(Level, 0, ::java::io::Serializable)
public:
	Level();
	void init$($String* name, int32_t value);
	void init$($String* name, int32_t value, $String* resourceBundleName);
	void init$($String* name, int32_t value, $String* resourceBundleName, bool visible);
	$String* computeLocalizedLevelName(::java::util::Locale* newLocale);
	virtual bool equals(Object$* ox) override;
	static ::java::util::logging::Level* findLevel($String* name);
	$String* getCachedLocalizedLevelName();
	$String* getLevelName();
	$String* getLocalizedLevelName();
	virtual $String* getLocalizedName();
	virtual $String* getName();
	virtual $String* getResourceBundleName();
	virtual int32_t hashCode() override;
	int32_t intValue();
	static ::java::util::logging::Level* parse($String* name);
	$Object* readResolve();
	virtual $String* toString() override;
	static $String* defaultBundle;
	$String* name = nullptr;
	int32_t value = 0;
	$String* resourceBundleName = nullptr;
	$String* localizedLevelName = nullptr;
	::java::util::Locale* cachedLocale = nullptr;
	static ::java::util::logging::Level* OFF;
	static ::java::util::logging::Level* SEVERE;
	static ::java::util::logging::Level* WARNING;
	static ::java::util::logging::Level* INFO;
	static ::java::util::logging::Level* CONFIG;
	static ::java::util::logging::Level* FINE;
	static ::java::util::logging::Level* FINER;
	static ::java::util::logging::Level* FINEST;
	static ::java::util::logging::Level* ALL;
	static $Array<::java::util::logging::Level>* standardLevels;
	static const int64_t serialVersionUID = (int64_t)0x8E88711351733692;
};

		} // logging
	} // util
} // java

#pragma pop_macro("ALL")
#pragma pop_macro("CONFIG")
#pragma pop_macro("FINE")
#pragma pop_macro("FINER")
#pragma pop_macro("FINEST")
#pragma pop_macro("INFO")
#pragma pop_macro("OFF")
#pragma pop_macro("SEVERE")
#pragma pop_macro("WARNING")

#endif // _java_util_logging_Level_h_