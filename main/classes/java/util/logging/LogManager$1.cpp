#include <java/util/logging/LogManager$1.h>

#include <java/lang/ClassLoader.h>
#include <java/lang/ClassNotFoundException.h>
#include <java/util/logging/LogManager.h>
#include <jcpp.h>

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $ClassNotFoundException = ::java::lang::ClassNotFoundException;
using $EnclosingMethodInfo = ::java::lang::EnclosingMethodInfo;
using $Exception = ::java::lang::Exception;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $LogManager = ::java::util::logging::LogManager;

namespace java {
	namespace util {
		namespace logging {

$MethodInfo _LogManager$1_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(LogManager$1::*)()>(&LogManager$1::init$))},
	{"run", "()Ljava/util/logging/LogManager;", nullptr, $PUBLIC},
	{}
};

$EnclosingMethodInfo _LogManager$1_EnclosingMethodInfo_ = {
	"java.util.logging.LogManager",
	nullptr,
	nullptr
};

$InnerClassInfo _LogManager$1_InnerClassesInfo_[] = {
	{"java.util.logging.LogManager$1", nullptr, nullptr, 0},
	{}
};

$ClassInfo _LogManager$1_ClassInfo_ = {
	$ACC_SUPER,
	"java.util.logging.LogManager$1",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	nullptr,
	_LogManager$1_MethodInfo_,
	"Ljava/lang/Object;Ljava/security/PrivilegedAction<Ljava/util/logging/LogManager;>;",
	&_LogManager$1_EnclosingMethodInfo_,
	_LogManager$1_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.util.logging.LogManager"
};

$Object* allocate$LogManager$1($Class* clazz) {
	return $of($alloc(LogManager$1));
}

void LogManager$1::init$() {
}

$Object* LogManager$1::run() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($LogManager, mgr, nullptr);
	$var($String, cname, nullptr);
	try {
		$assign(cname, $System::getProperty("java.util.logging.manager"_s));
		if (cname != nullptr) {
			try {
				$var($Object, tmp, $nc($nc($($ClassLoader::getSystemClassLoader()))->loadClass(cname))->newInstance());
				$assign(mgr, $cast($LogManager, tmp));
			} catch ($ClassNotFoundException& ex) {
				$var($Object, tmp, $nc($nc($($($Thread::currentThread())->getContextClassLoader()))->loadClass(cname))->newInstance());
				$assign(mgr, $cast($LogManager, tmp));
			}
		}
	} catch ($Exception& ex) {
		$nc($System::err)->println($$str({"Could not load Logmanager \""_s, cname, "\""_s}));
		ex->printStackTrace();
	}
	if (mgr == nullptr) {
		$assign(mgr, $new($LogManager));
	}
	return $of(mgr);
}

LogManager$1::LogManager$1() {
}

$Class* LogManager$1::load$($String* name, bool initialize) {
	$loadClass(LogManager$1, name, initialize, &_LogManager$1_ClassInfo_, allocate$LogManager$1);
	return class$;
}

$Class* LogManager$1::class$ = nullptr;

		} // logging
	} // util
} // java