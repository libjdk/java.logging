#include <java/util/logging/FileHandler$1.h>

#include <java/util/logging/FileHandler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $FileHandler = ::java::util::logging::FileHandler;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _FileHandler$1_FieldInfo_[] = {
	{"this$0", "Ljava/util/logging/FileHandler;", nullptr, $FINAL | $SYNTHETIC, $field(FileHandler$1, this$0)},
	{}
};

$MethodInfo _FileHandler$1_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/FileHandler;)V", nullptr, 0, $method(static_cast<void(FileHandler$1::*)($FileHandler*)>(&FileHandler$1::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _FileHandler$1_EnclosingMethodInfo_ = {
	"java.util.logging.FileHandler",
	"publish",
	"(Ljava/util/logging/LogRecord;)V"
};

$InnerClassInfo _FileHandler$1_InnerClassesInfo_[] = {
	{"java.util.logging.FileHandler$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _FileHandler$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.logging.FileHandler$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_FileHandler$1_FieldInfo_,
	_FileHandler$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Object;>;",
	&_FileHandler$1_EnclosingMethodInfo_,
	_FileHandler$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.FileHandler"
};

$Object* allocate$FileHandler$1($Class* clazz) {
	return $of($alloc(FileHandler$1));
}

void FileHandler$1::init$($FileHandler* this$0) {
	$set(this, this$0, this$0);
}

$Object* FileHandler$1::run() {
	this->this$0->rotate();
	return $of(nullptr);
}

FileHandler$1::FileHandler$1() {
}

$Class* FileHandler$1::load$($String* name, bool initialize) {
	$loadClass(FileHandler$1, name, initialize, &_FileHandler$1_ClassInfo_, allocate$FileHandler$1);
	return class$;
}

$Class* FileHandler$1::class$ = nullptr;

		} // logging
	} // util
} // java