#include <java/util/logging/FileHandler$InitializationErrorManager.h>

#include <java/util/logging/ErrorManager.h>
#include <java/util/logging/FileHandler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ErrorManager = ::java::util::logging::ErrorManager;
using $FileHandler = ::java::util::logging::FileHandler;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _FileHandler$InitializationErrorManager_FieldInfo_[] = {
	{"lastException", "Ljava/lang/Exception;", nullptr, 0, $field(FileHandler$InitializationErrorManager, lastException)},
	{}
};

$MethodInfo _FileHandler$InitializationErrorManager_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(FileHandler$InitializationErrorManager::*)()>(&FileHandler$InitializationErrorManager::init$))},
	{"error", "(Ljava/lang/String;Ljava/lang/Exception;I)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _FileHandler$InitializationErrorManager_InnerClassesInfo_[] = {
	{"java.util.logging.FileHandler$InitializationErrorManager", "java.util.logging.FileHandler", "InitializationErrorManager", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _FileHandler$InitializationErrorManager_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.logging.FileHandler$InitializationErrorManager",
	"java.util.logging.ErrorManager",
	nullptr,
	_FileHandler$InitializationErrorManager_FieldInfo_,
	_FileHandler$InitializationErrorManager_MethodInfo_,
	nullptr,
	nullptr,
	_FileHandler$InitializationErrorManager_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.FileHandler"
};

$Object* allocate$FileHandler$InitializationErrorManager($Class* clazz) {
	return $of($alloc(FileHandler$InitializationErrorManager));
}

void FileHandler$InitializationErrorManager::init$() {
	$ErrorManager::init$();
}

void FileHandler$InitializationErrorManager::error($String* msg, $Exception* ex, int32_t code) {
	$set(this, lastException, ex);
}

FileHandler$InitializationErrorManager::FileHandler$InitializationErrorManager() {
}

$Class* FileHandler$InitializationErrorManager::load$($String* name, bool initialize) {
	$loadClass(FileHandler$InitializationErrorManager, name, initialize, &_FileHandler$InitializationErrorManager_ClassInfo_, allocate$FileHandler$InitializationErrorManager);
	return class$;
}

$Class* FileHandler$InitializationErrorManager::class$ = nullptr;

		} // logging
	} // util
} // java