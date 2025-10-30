#include <java/util/logging/Filter.h>

#include <java/util/logging/LogRecord.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $MethodInfo = ::java::lang::MethodInfo;
using $LogRecord = ::java::util::logging::LogRecord;

namespace java {
	namespace util {
		namespace logging {

$CompoundAttribute _Filter_Annotations_[] = {
	{"Ljava/lang/FunctionalInterface;", nullptr},
	{}
};

$MethodInfo _Filter_MethodInfo_[] = {
	{"isLoggable", "(Ljava/util/logging/LogRecord;)Z", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$ClassInfo _Filter_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"java.util.logging.Filter",
	nullptr,
	nullptr,
	nullptr,
	_Filter_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_Filter_Annotations_
};

$Object* allocate$Filter($Class* clazz) {
	return $of($alloc(Filter));
}

$Class* Filter::load$($String* name, bool initialize) {
	$loadClass(Filter, name, initialize, &_Filter_ClassInfo_, allocate$Filter);
	return class$;
}

$Class* Filter::class$ = nullptr;

		} // logging
	} // util
} // java