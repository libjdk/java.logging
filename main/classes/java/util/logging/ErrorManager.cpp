#include <java/util/logging/ErrorManager.h>

#include <jcpp.h>

#undef CLOSE_FAILURE
#undef FLUSH_FAILURE
#undef FORMAT_FAILURE
#undef GENERIC_FAILURE
#undef OPEN_FAILURE
#undef WRITE_FAILURE

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _ErrorManager_FieldInfo_[] = {
	{"reported", "Z", nullptr, $PRIVATE, $field(ErrorManager, reported)},
	{"GENERIC_FAILURE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorManager, GENERIC_FAILURE)},
	{"WRITE_FAILURE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorManager, WRITE_FAILURE)},
	{"FLUSH_FAILURE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorManager, FLUSH_FAILURE)},
	{"CLOSE_FAILURE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorManager, CLOSE_FAILURE)},
	{"OPEN_FAILURE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorManager, OPEN_FAILURE)},
	{"FORMAT_FAILURE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(ErrorManager, FORMAT_FAILURE)},
	{}
};

$MethodInfo _ErrorManager_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ErrorManager::*)()>(&ErrorManager::init$))},
	{"error", "(Ljava/lang/String;Ljava/lang/Exception;I)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{}
};

$ClassInfo _ErrorManager_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.logging.ErrorManager",
	"java.lang.Object",
	nullptr,
	_ErrorManager_FieldInfo_,
	_ErrorManager_MethodInfo_
};

$Object* allocate$ErrorManager($Class* clazz) {
	return $of($alloc(ErrorManager));
}

void ErrorManager::init$() {
	this->reported = false;
}

void ErrorManager::error($String* msg, $Exception* ex, int32_t code) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		if (this->reported) {
			return;
		}
		this->reported = true;
		$var($String, text, $str({"java.util.logging.ErrorManager: "_s, $$str(code)}));
		if (msg != nullptr) {
			$assign(text, $str({text, ": "_s, msg}));
		}
		$nc($System::err)->println(text);
		if (ex != nullptr) {
			ex->printStackTrace();
		}
	}
}

ErrorManager::ErrorManager() {
}

$Class* ErrorManager::load$($String* name, bool initialize) {
	$loadClass(ErrorManager, name, initialize, &_ErrorManager_ClassInfo_, allocate$ErrorManager);
	return class$;
}

$Class* ErrorManager::class$ = nullptr;

		} // logging
	} // util
} // java