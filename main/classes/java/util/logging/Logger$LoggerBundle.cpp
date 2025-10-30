#include <java/util/logging/Logger$LoggerBundle.h>

#include <java/util/ResourceBundle.h>
#include <java/util/logging/Logger.h>
#include <jcpp.h>

#undef NO_RESOURCE_BUNDLE
#undef SYSTEM_BUNDLE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Logger = ::java::util::logging::Logger;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _Logger$LoggerBundle_FieldInfo_[] = {
	{"resourceBundleName", "Ljava/lang/String;", nullptr, $FINAL, $field(Logger$LoggerBundle, resourceBundleName)},
	{"userBundle", "Ljava/util/ResourceBundle;", nullptr, $FINAL, $field(Logger$LoggerBundle, userBundle)},
	{}
};

$MethodInfo _Logger$LoggerBundle_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;Ljava/util/ResourceBundle;)V", nullptr, $PRIVATE, $method(static_cast<void(Logger$LoggerBundle::*)($String*,$ResourceBundle*)>(&Logger$LoggerBundle::init$))},
	{"get", "(Ljava/lang/String;Ljava/util/ResourceBundle;)Ljava/util/logging/Logger$LoggerBundle;", nullptr, $STATIC, $method(static_cast<Logger$LoggerBundle*(*)($String*,$ResourceBundle*)>(&Logger$LoggerBundle::get))},
	{"isSystemBundle", "()Z", nullptr, 0, $method(static_cast<bool(Logger$LoggerBundle::*)()>(&Logger$LoggerBundle::isSystemBundle))},
	{}
};

$InnerClassInfo _Logger$LoggerBundle_InnerClassesInfo_[] = {
	{"java.util.logging.Logger$LoggerBundle", "java.util.logging.Logger", "LoggerBundle", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _Logger$LoggerBundle_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"java.util.logging.Logger$LoggerBundle",
	"java.lang.Object",
	nullptr,
	_Logger$LoggerBundle_FieldInfo_,
	_Logger$LoggerBundle_MethodInfo_,
	nullptr,
	nullptr,
	_Logger$LoggerBundle_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.Logger"
};

$Object* allocate$Logger$LoggerBundle($Class* clazz) {
	return $of($alloc(Logger$LoggerBundle));
}

void Logger$LoggerBundle::init$($String* resourceBundleName, $ResourceBundle* bundle) {
	$set(this, resourceBundleName, resourceBundleName);
	$set(this, userBundle, bundle);
}

bool Logger$LoggerBundle::isSystemBundle() {
	return "sun.util.logging.resources.logging"_s->equals(this->resourceBundleName);
}

Logger$LoggerBundle* Logger$LoggerBundle::get($String* name, $ResourceBundle* bundle) {
	if (name == nullptr && bundle == nullptr) {
		$init($Logger);
		return $Logger::NO_RESOURCE_BUNDLE;
	} else if ("sun.util.logging.resources.logging"_s->equals(name) && bundle == nullptr) {
		$init($Logger);
		return $Logger::SYSTEM_BUNDLE;
	} else {
		return $new(Logger$LoggerBundle, name, bundle);
	}
}

Logger$LoggerBundle::Logger$LoggerBundle() {
}

$Class* Logger$LoggerBundle::load$($String* name, bool initialize) {
	$loadClass(Logger$LoggerBundle, name, initialize, &_Logger$LoggerBundle_ClassInfo_, allocate$Logger$LoggerBundle);
	return class$;
}

$Class* Logger$LoggerBundle::class$ = nullptr;

		} // logging
	} // util
} // java