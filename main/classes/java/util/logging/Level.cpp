#include <java/util/logging/Level.h>

#include <java/io/Serializable.h>
#include <java/lang/Module.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Locale.h>
#include <java/util/Optional.h>
#include <java/util/ResourceBundle.h>
#include <java/util/function/Function.h>
#include <java/util/logging/Level$KnownLevel.h>
#include <java/util/logging/Level$RbAccess.h>
#include <jdk/internal/access/JavaUtilResourceBundleAccess.h>
#include <jcpp.h>

#undef ALL
#undef CONFIG
#undef FINE
#undef FINER
#undef FINEST
#undef INFO
#undef MAX_VALUE
#undef MIN_VALUE
#undef OFF
#undef RB_ACCESS
#undef ROOT
#undef SEVERE
#undef WARNING

using $LevelArray = $Array<::java::util::logging::Level>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $NullPointerException = ::java::lang::NullPointerException;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Locale = ::java::util::Locale;
using $Optional = ::java::util::Optional;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Function = ::java::util::function::Function;
using $Level$KnownLevel = ::java::util::logging::Level$KnownLevel;
using $Level$RbAccess = ::java::util::logging::Level$RbAccess;
using $JavaUtilResourceBundleAccess = ::jdk::internal::access::JavaUtilResourceBundleAccess;

namespace java {
	namespace util {
		namespace logging {

class Level$$Lambda$mirrored : public $Function {
	$class(Level$$Lambda$mirrored, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($Level$KnownLevel, inst$)->mirrored());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Level$$Lambda$mirrored>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Level$$Lambda$mirrored::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Level$$Lambda$mirrored::*)()>(&Level$$Lambda$mirrored::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Level$$Lambda$mirrored::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.Level$$Lambda$mirrored",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Level$$Lambda$mirrored::load$($String* name, bool initialize) {
	$loadClass(Level$$Lambda$mirrored, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Level$$Lambda$mirrored::class$ = nullptr;

class Level$$Lambda$referent$1 : public $Function {
	$class(Level$$Lambda$referent$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($Level$KnownLevel, inst$)->referent());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Level$$Lambda$referent$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Level$$Lambda$referent$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Level$$Lambda$referent$1::*)()>(&Level$$Lambda$referent$1::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Level$$Lambda$referent$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.util.logging.Level$$Lambda$referent$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Level$$Lambda$referent$1::load$($String* name, bool initialize) {
	$loadClass(Level$$Lambda$referent$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Level$$Lambda$referent$1::class$ = nullptr;

$FieldInfo _Level_FieldInfo_[] = {
	{"defaultBundle", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Level, defaultBundle)},
	{"name", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Level, name)},
	{"value", "I", nullptr, $PRIVATE | $FINAL, $field(Level, value)},
	{"resourceBundleName", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Level, resourceBundleName)},
	{"localizedLevelName", "Ljava/lang/String;", nullptr, $PRIVATE | $TRANSIENT, $field(Level, localizedLevelName)},
	{"cachedLocale", "Ljava/util/Locale;", nullptr, $PRIVATE | $TRANSIENT, $field(Level, cachedLocale)},
	{"OFF", "Ljava/util/logging/Level;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Level, OFF)},
	{"SEVERE", "Ljava/util/logging/Level;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Level, SEVERE)},
	{"WARNING", "Ljava/util/logging/Level;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Level, WARNING)},
	{"INFO", "Ljava/util/logging/Level;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Level, INFO)},
	{"CONFIG", "Ljava/util/logging/Level;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Level, CONFIG)},
	{"FINE", "Ljava/util/logging/Level;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Level, FINE)},
	{"FINER", "Ljava/util/logging/Level;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Level, FINER)},
	{"FINEST", "Ljava/util/logging/Level;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Level, FINEST)},
	{"ALL", "Ljava/util/logging/Level;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Level, ALL)},
	{"standardLevels", "[Ljava/util/logging/Level;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Level, standardLevels)},
	{"serialVersionUID", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Level, serialVersionUID)},
	{}
};

$MethodInfo _Level_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PROTECTED, $method(static_cast<void(Level::*)($String*,int32_t)>(&Level::init$))},
	{"<init>", "(Ljava/lang/String;ILjava/lang/String;)V", nullptr, $PROTECTED, $method(static_cast<void(Level::*)($String*,int32_t,$String*)>(&Level::init$))},
	{"<init>", "(Ljava/lang/String;ILjava/lang/String;Z)V", nullptr, $PRIVATE, $method(static_cast<void(Level::*)($String*,int32_t,$String*,bool)>(&Level::init$))},
	{"computeLocalizedLevelName", "(Ljava/util/Locale;)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(Level::*)($Locale*)>(&Level::computeLocalizedLevelName))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"findLevel", "(Ljava/lang/String;)Ljava/util/logging/Level;", nullptr, $STATIC, $method(static_cast<Level*(*)($String*)>(&Level::findLevel))},
	{"getCachedLocalizedLevelName", "()Ljava/lang/String;", nullptr, $FINAL, $method(static_cast<$String*(Level::*)()>(&Level::getCachedLocalizedLevelName))},
	{"getLevelName", "()Ljava/lang/String;", nullptr, $FINAL, $method(static_cast<$String*(Level::*)()>(&Level::getLevelName))},
	{"getLocalizedLevelName", "()Ljava/lang/String;", nullptr, $FINAL | $SYNCHRONIZED, $method(static_cast<$String*(Level::*)()>(&Level::getLocalizedLevelName))},
	{"getLocalizedName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getResourceBundleName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"intValue", "()I", nullptr, $PUBLIC | $FINAL, $method(static_cast<int32_t(Level::*)()>(&Level::intValue))},
	{"parse", "(Ljava/lang/String;)Ljava/util/logging/Level;", nullptr, $PUBLIC | $STATIC | $SYNCHRONIZED, $method(static_cast<Level*(*)($String*)>(&Level::parse)), "java.lang.IllegalArgumentException"},
	{"readResolve", "()Ljava/lang/Object;", nullptr, $PRIVATE, $method(static_cast<$Object*(Level::*)()>(&Level::readResolve))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{}
};

$InnerClassInfo _Level_InnerClassesInfo_[] = {
	{"java.util.logging.Level$KnownLevel", "java.util.logging.Level", "KnownLevel", $STATIC | $FINAL},
	{"java.util.logging.Level$RbAccess", "java.util.logging.Level", "RbAccess", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _Level_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.logging.Level",
	"java.lang.Object",
	"java.io.Serializable",
	_Level_FieldInfo_,
	_Level_MethodInfo_,
	nullptr,
	nullptr,
	_Level_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.util.logging.Level$KnownLevel,java.util.logging.Level$RbAccess"
};

$Object* allocate$Level($Class* clazz) {
	return $of($alloc(Level));
}

$String* Level::defaultBundle = nullptr;
Level* Level::OFF = nullptr;
Level* Level::SEVERE = nullptr;
Level* Level::WARNING = nullptr;
Level* Level::INFO = nullptr;
Level* Level::CONFIG = nullptr;
Level* Level::FINE = nullptr;
Level* Level::FINER = nullptr;
Level* Level::FINEST = nullptr;
Level* Level::ALL = nullptr;
$LevelArray* Level::standardLevels = nullptr;

void Level::init$($String* name, int32_t value) {
	Level::init$(name, value, nullptr);
}

void Level::init$($String* name, int32_t value, $String* resourceBundleName) {
	Level::init$(name, value, resourceBundleName, true);
}

void Level::init$($String* name, int32_t value, $String* resourceBundleName, bool visible) {
	if (name == nullptr) {
		$throwNew($NullPointerException);
	}
	$set(this, name, name);
	this->value = value;
	$set(this, resourceBundleName, resourceBundleName);
	$set(this, localizedLevelName, resourceBundleName == nullptr ? name : ($String*)nullptr);
	$set(this, cachedLocale, nullptr);
	if (visible) {
		$Level$KnownLevel::add(this);
	}
}

$String* Level::getResourceBundleName() {
	return this->resourceBundleName;
}

$String* Level::getName() {
	return this->name;
}

$String* Level::getLocalizedName() {
	return getLocalizedLevelName();
}

$String* Level::getLevelName() {
	return this->name;
}

$String* Level::computeLocalizedLevelName($Locale* newLocale) {
	$useLocalCurrentObjectStackCache();
	$var($Module, module, $of(this)->getClass()->getModule());
	$init($Level$RbAccess);
	$var($ResourceBundle, rb, $nc($Level$RbAccess::RB_ACCESS)->getBundle(this->resourceBundleName, newLocale, module));
	$var($String, localizedName, $nc(rb)->getString(this->name));
	bool isDefaultBundle = $nc(Level::defaultBundle)->equals(this->resourceBundleName);
	if (!isDefaultBundle) {
		return localizedName;
	}
	$var($Locale, rbLocale, rb->getLocale());
	$init($Locale);
	bool var$0 = $nc($Locale::ROOT)->equals(rbLocale);
	$var($Locale, locale, var$0 || $nc(this->name)->equals($($nc(localizedName)->toUpperCase($Locale::ROOT))) ? $Locale::ROOT : rbLocale);
	return $nc($Locale::ROOT)->equals(locale) ? this->name : $nc(localizedName)->toUpperCase(locale);
}

$String* Level::getCachedLocalizedLevelName() {
	if (this->localizedLevelName != nullptr) {
		if (this->cachedLocale != nullptr) {
			if ($nc(this->cachedLocale)->equals($($Locale::getDefault()))) {
				return this->localizedLevelName;
			}
		}
	}
	if (this->resourceBundleName == nullptr) {
		return this->name;
	}
	return nullptr;
}

$String* Level::getLocalizedLevelName() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($String, cachedLocalizedName, getCachedLocalizedLevelName());
		if (cachedLocalizedName != nullptr) {
			return cachedLocalizedName;
		}
		$var($Locale, newLocale, $Locale::getDefault());
		try {
			$set(this, localizedLevelName, computeLocalizedLevelName(newLocale));
		} catch ($Exception& ex) {
			$set(this, localizedLevelName, this->name);
		}
		$set(this, cachedLocale, newLocale);
		return this->localizedLevelName;
	}
}

Level* Level::findLevel($String* name) {
	$init(Level);
	$useLocalCurrentObjectStackCache();
	if (name == nullptr) {
		$throwNew($NullPointerException);
	}
	$var($Optional, level, nullptr);
	$assign(level, $Level$KnownLevel::findByName(name, static_cast<$Function*>($$new(Level$$Lambda$mirrored))));
	if ($nc(level)->isPresent()) {
		return $cast(Level, level->get());
	}
	try {
		int32_t x = $Integer::parseInt(name);
		$assign(level, $Level$KnownLevel::findByValue(x, static_cast<$Function*>($$new(Level$$Lambda$mirrored))));
		if ($nc(level)->isPresent()) {
			return $cast(Level, level->get());
		}
		$var(Level, levelObject, $new(Level, name, x));
		return $cast(Level, $nc($($Level$KnownLevel::findByValue(x, static_cast<$Function*>($$new(Level$$Lambda$mirrored)))))->get());
	} catch ($NumberFormatException& ex) {
	}
	$assign(level, $Level$KnownLevel::findByLocalizedLevelName(name, static_cast<$Function*>($$new(Level$$Lambda$mirrored))));
	if ($nc(level)->isPresent()) {
		return $cast(Level, level->get());
	}
	return nullptr;
}

$String* Level::toString() {
	return this->name;
}

int32_t Level::intValue() {
	return this->value;
}

$Object* Level::readResolve() {
	$var($Optional, level, $Level$KnownLevel::matches(this));
	if ($nc(level)->isPresent()) {
		return $of(level->get());
	}
	return $of($new(Level, this->name, this->value, this->resourceBundleName));
}

Level* Level::parse($String* name) {
	$load(Level);
	$synchronized(class$) {
		$init(Level);
		$useLocalCurrentObjectStackCache();
		$nc(name)->length();
		$var($Optional, level, nullptr);
		$assign(level, $Level$KnownLevel::findByName(name, static_cast<$Function*>($$new(Level$$Lambda$referent$1))));
		if ($nc(level)->isPresent()) {
			return $cast(Level, level->get());
		}
		try {
			int32_t x = $Integer::parseInt(name);
			$assign(level, $Level$KnownLevel::findByValue(x, static_cast<$Function*>($$new(Level$$Lambda$referent$1))));
			if ($nc(level)->isPresent()) {
				return $cast(Level, level->get());
			}
			$var(Level, levelObject, $new(Level, name, x));
			return $cast(Level, $nc($($Level$KnownLevel::findByValue(x, static_cast<$Function*>($$new(Level$$Lambda$referent$1)))))->get());
		} catch ($NumberFormatException& ex) {
		}
		$assign(level, $Level$KnownLevel::findByLocalizedLevelName(name, static_cast<$Function*>($$new(Level$$Lambda$referent$1))));
		if ($nc(level)->isPresent()) {
			return $cast(Level, level->get());
		}
		$throwNew($IllegalArgumentException, $$str({"Bad level \""_s, name, "\""_s}));
	}
}

bool Level::equals(Object$* ox) {
	try {
		$var(Level, lx, $cast(Level, ox));
		return ($nc(lx)->value == this->value);
	} catch ($Exception& ex) {
		return false;
	}
	$shouldNotReachHere();
}

int32_t Level::hashCode() {
	return this->value;
}

void clinit$Level($Class* class$) {
	$assignStatic(Level::defaultBundle, "sun.util.logging.resources.logging"_s);
	$assignStatic(Level::OFF, $new(Level, "OFF"_s, $Integer::MAX_VALUE, Level::defaultBundle));
	$assignStatic(Level::SEVERE, $new(Level, "SEVERE"_s, 1000, Level::defaultBundle));
	$assignStatic(Level::WARNING, $new(Level, "WARNING"_s, 900, Level::defaultBundle));
	$assignStatic(Level::INFO, $new(Level, "INFO"_s, 800, Level::defaultBundle));
	$assignStatic(Level::CONFIG, $new(Level, "CONFIG"_s, 700, Level::defaultBundle));
	$assignStatic(Level::FINE, $new(Level, "FINE"_s, 500, Level::defaultBundle));
	$assignStatic(Level::FINER, $new(Level, "FINER"_s, 400, Level::defaultBundle));
	$assignStatic(Level::FINEST, $new(Level, "FINEST"_s, 300, Level::defaultBundle));
	$assignStatic(Level::ALL, $new(Level, "ALL"_s, $Integer::MIN_VALUE, Level::defaultBundle));
	$assignStatic(Level::standardLevels, $new($LevelArray, {
		Level::OFF,
		Level::SEVERE,
		Level::WARNING,
		Level::INFO,
		Level::CONFIG,
		Level::FINE,
		Level::FINER,
		Level::FINEST,
		Level::ALL
	}));
}

Level::Level() {
}

$Class* Level::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Level$$Lambda$mirrored::classInfo$.name)) {
			return Level$$Lambda$mirrored::load$(name, initialize);
		}
		if (name->equals(Level$$Lambda$referent$1::classInfo$.name)) {
			return Level$$Lambda$referent$1::load$(name, initialize);
		}
	}
	$loadClass(Level, name, initialize, &_Level_ClassInfo_, clinit$Level, allocate$Level);
	return class$;
}

$Class* Level::class$ = nullptr;

		} // logging
	} // util
} // java