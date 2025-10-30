#include <sun/util/logging/internal/LoggingProviderImpl$LogManagerAccess.h>

#include <java/lang/Module.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/Logger.h>
#include <sun/util/logging/internal/LoggingProviderImpl.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Module = ::java::lang::Module;
using $LogManager = ::java::util::logging::LogManager;
using $Logger = ::java::util::logging::Logger;
using $LoggingProviderImpl = ::sun::util::logging::internal::LoggingProviderImpl;

namespace sun {
	namespace util {
		namespace logging {
			namespace internal {

$MethodInfo _LoggingProviderImpl$LogManagerAccess_MethodInfo_[] = {
	{"demandLoggerFor", "(Ljava/util/logging/LogManager;Ljava/lang/String;Ljava/lang/Module;)Ljava/util/logging/Logger;", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _LoggingProviderImpl$LogManagerAccess_InnerClassesInfo_[] = {
	{"sun.util.logging.internal.LoggingProviderImpl$LogManagerAccess", "sun.util.logging.internal.LoggingProviderImpl", "LogManagerAccess", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _LoggingProviderImpl$LogManagerAccess_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"sun.util.logging.internal.LoggingProviderImpl$LogManagerAccess",
	nullptr,
	nullptr,
	nullptr,
	_LoggingProviderImpl$LogManagerAccess_MethodInfo_,
	nullptr,
	nullptr,
	_LoggingProviderImpl$LogManagerAccess_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"sun.util.logging.internal.LoggingProviderImpl"
};

$Object* allocate$LoggingProviderImpl$LogManagerAccess($Class* clazz) {
	return $of($alloc(LoggingProviderImpl$LogManagerAccess));
}

$Class* LoggingProviderImpl$LogManagerAccess::load$($String* name, bool initialize) {
	$loadClass(LoggingProviderImpl$LogManagerAccess, name, initialize, &_LoggingProviderImpl$LogManagerAccess_ClassInfo_, allocate$LoggingProviderImpl$LogManagerAccess);
	return class$;
}

$Class* LoggingProviderImpl$LogManagerAccess::class$ = nullptr;

			} // internal
		} // logging
	} // util
} // sun