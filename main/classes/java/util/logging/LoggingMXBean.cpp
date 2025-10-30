#include <java/util/logging/LoggingMXBean.h>

#include <java/util/List.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $MethodInfo = ::java::lang::MethodInfo;
using $NamedAttribute = ::java::lang::NamedAttribute;
using $List = ::java::util::List;

namespace java {
	namespace util {
		namespace logging {

$NamedAttribute LoggingMXBean_Attribute_var$0[] = {
	{"since", 's', "9"},
	{}
};

$CompoundAttribute _LoggingMXBean_Annotations_[] = {
	{"Ljava/lang/Deprecated;", LoggingMXBean_Attribute_var$0},
	{}
};

$MethodInfo _LoggingMXBean_MethodInfo_[] = {
	{"getLoggerLevel", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{"getLoggerNames", "()Ljava/util/List;", "()Ljava/util/List<Ljava/lang/String;>;", $PUBLIC | $ABSTRACT},
	{"getParentLoggerName", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{"setLoggerLevel", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _LoggingMXBean_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.util.logging.LoggingMXBean",
	nullptr,
	nullptr,
	nullptr,
	_LoggingMXBean_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_LoggingMXBean_Annotations_
};

$Object* allocate$LoggingMXBean($Class* clazz) {
	return $of($alloc(LoggingMXBean));
}

$Class* LoggingMXBean::load$($String* name, bool initialize) {
	$loadClass(LoggingMXBean, name, initialize, &_LoggingMXBean_ClassInfo_, allocate$LoggingMXBean);
	return class$;
}

$Class* LoggingMXBean::class$ = nullptr;

		} // logging
	} // util
} // java