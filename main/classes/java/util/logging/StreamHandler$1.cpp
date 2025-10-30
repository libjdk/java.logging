#include <java/util/logging/StreamHandler$1.h>

#include <java/io/OutputStream.h>
#include <java/util/logging/StreamHandler.h>
#include <jcpp.h>

using $OutputStream = ::java::io::OutputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $StreamHandler = ::java::util::logging::StreamHandler;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _StreamHandler$1_FieldInfo_[] = {
	{"this$0", "Ljava/util/logging/StreamHandler;", nullptr, $FINAL | $SYNTHETIC, $field(StreamHandler$1, this$0)},
	{"val$out", "Ljava/io/OutputStream;", nullptr, $FINAL | $SYNTHETIC, $field(StreamHandler$1, val$out)},
	{}
};

$MethodInfo _StreamHandler$1_MethodInfo_[] = {
	{"<init>", "(Ljava/util/logging/StreamHandler;Ljava/io/OutputStream;)V", "()V", 0, $method(static_cast<void(StreamHandler$1::*)($StreamHandler*,$OutputStream*)>(&StreamHandler$1::init$))},
	{"run", "()Ljava/lang/Void;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _StreamHandler$1_EnclosingMethodInfo_ = {
	"java.util.logging.StreamHandler",
	"setOutputStreamPrivileged",
	"(Ljava/io/OutputStream;)V"
};

$InnerClassInfo _StreamHandler$1_InnerClassesInfo_[] = {
	{"java.util.logging.StreamHandler$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _StreamHandler$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.logging.StreamHandler$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	_StreamHandler$1_FieldInfo_,
	_StreamHandler$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/lang/Void;>;",
	&_StreamHandler$1_EnclosingMethodInfo_,
	_StreamHandler$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.StreamHandler"
};

$Object* allocate$StreamHandler$1($Class* clazz) {
	return $of($alloc(StreamHandler$1));
}

void StreamHandler$1::init$($StreamHandler* this$0, $OutputStream* val$out) {
	$set(this, this$0, this$0);
	$set(this, val$out, val$out);
}

$Object* StreamHandler$1::run() {
	this->this$0->setOutputStream(this->val$out);
	return $of(nullptr);
}

StreamHandler$1::StreamHandler$1() {
}

$Class* StreamHandler$1::load$($String* name, bool initialize) {
	$loadClass(StreamHandler$1, name, initialize, &_StreamHandler$1_ClassInfo_, allocate$StreamHandler$1);
	return class$;
}

$Class* StreamHandler$1::class$ = nullptr;

		} // logging
	} // util
} // java