#include <java.logging.h>

#include <java.base.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>
#include <module-info>

#include <java/util/logging/ConsoleHandler.h>
#include <java/util/logging/ErrorManager.h>
#include <java/util/logging/FileHandler.h>
#include <java/util/logging/FileHandler$1.h>
#include <java/util/logging/FileHandler$InitializationErrorManager.h>
#include <java/util/logging/FileHandler$MeteredStream.h>
#include <java/util/logging/Filter.h>
#include <java/util/logging/Formatter.h>
#include <java/util/logging/Handler.h>
#include <java/util/logging/Handler$1.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/Level$KnownLevel.h>
#include <java/util/logging/Level$RbAccess.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/LogManager$1.h>
#include <java/util/logging/LogManager$2.h>
#include <java/util/logging/LogManager$3.h>
#include <java/util/logging/LogManager$4.h>
#include <java/util/logging/LogManager$5.h>
#include <java/util/logging/LogManager$6.h>
#include <java/util/logging/LogManager$7.h>
#include <java/util/logging/LogManager$Cleaner.h>
#include <java/util/logging/LogManager$CloseOnReset.h>
#include <java/util/logging/LogManager$ConfigProperty.h>
#include <java/util/logging/LogManager$LogNode.h>
#include <java/util/logging/LogManager$LoggerContext.h>
#include <java/util/logging/LogManager$LoggerContext$1.h>
#include <java/util/logging/LogManager$LoggerWeakRef.h>
#include <java/util/logging/LogManager$LoggingProviderAccess.h>
#include <java/util/logging/LogManager$ModType.h>
#include <java/util/logging/LogManager$RootLogger.h>
#include <java/util/logging/LogManager$SystemLoggerContext.h>
#include <java/util/logging/LogManager$VisitedLoggers.h>
#include <java/util/logging/LogRecord.h>
#include <java/util/logging/LogRecord$CallerFinder.h>
#include <java/util/logging/Logger.h>
#include <java/util/logging/Logger$ConfigurationData.h>
#include <java/util/logging/Logger$LoggerBundle.h>
#include <java/util/logging/Logger$RbAccess.h>
#include <java/util/logging/Logger$SystemLoggerHelper.h>
#include <java/util/logging/Logger$SystemLoggerHelper$1.h>
#include <java/util/logging/Logging.h>
#include <java/util/logging/LoggingMXBean.h>
#include <java/util/logging/LoggingPermission.h>
#include <java/util/logging/MemoryHandler.h>
#include <java/util/logging/SimpleFormatter.h>
#include <java/util/logging/SocketHandler.h>
#include <java/util/logging/StreamHandler.h>
#include <java/util/logging/StreamHandler$1.h>
#include <java/util/logging/XMLFormatter.h>
#include <sun/net/www/protocol/http/logging/HttpLogFormatter.h>
#include <sun/util/logging/internal/LoggingProviderImpl.h>
#include <sun/util/logging/internal/LoggingProviderImpl$JULWrapper.h>
#include <sun/util/logging/internal/LoggingProviderImpl$LogManagerAccess.h>


#define $classEntry(name, clazz) {name, clazz::load$, $getMark(clazz)}
::java::lang::ClassEntry _java$logging_classes_[] = {
	$classEntry("java.util.logging.ConsoleHandler", ::java::util::logging::ConsoleHandler),
	$classEntry("java.util.logging.ErrorManager", ::java::util::logging::ErrorManager),
	$classEntry("java.util.logging.FileHandler", ::java::util::logging::FileHandler),
	$classEntry("java.util.logging.FileHandler$1", ::java::util::logging::FileHandler$1),
	$classEntry("java.util.logging.FileHandler$InitializationErrorManager", ::java::util::logging::FileHandler$InitializationErrorManager),
	$classEntry("java.util.logging.FileHandler$MeteredStream", ::java::util::logging::FileHandler$MeteredStream),
	$classEntry("java.util.logging.Filter", ::java::util::logging::Filter),
	$classEntry("java.util.logging.Formatter", ::java::util::logging::Formatter),
	$classEntry("java.util.logging.Handler", ::java::util::logging::Handler),
	$classEntry("java.util.logging.Handler$1", ::java::util::logging::Handler$1),
	$classEntry("java.util.logging.Level", ::java::util::logging::Level),
	$classEntry("java.util.logging.Level$KnownLevel", ::java::util::logging::Level$KnownLevel),
	$classEntry("java.util.logging.Level$RbAccess", ::java::util::logging::Level$RbAccess),
	$classEntry("java.util.logging.LogManager", ::java::util::logging::LogManager),
	$classEntry("java.util.logging.LogManager$1", ::java::util::logging::LogManager$1),
	$classEntry("java.util.logging.LogManager$2", ::java::util::logging::LogManager$2),
	$classEntry("java.util.logging.LogManager$3", ::java::util::logging::LogManager$3),
	$classEntry("java.util.logging.LogManager$4", ::java::util::logging::LogManager$4),
	$classEntry("java.util.logging.LogManager$5", ::java::util::logging::LogManager$5),
	$classEntry("java.util.logging.LogManager$6", ::java::util::logging::LogManager$6),
	$classEntry("java.util.logging.LogManager$7", ::java::util::logging::LogManager$7),
	$classEntry("java.util.logging.LogManager$Cleaner", ::java::util::logging::LogManager$Cleaner),
	$classEntry("java.util.logging.LogManager$CloseOnReset", ::java::util::logging::LogManager$CloseOnReset),
	$classEntry("java.util.logging.LogManager$ConfigProperty", ::java::util::logging::LogManager$ConfigProperty),
	$classEntry("java.util.logging.LogManager$LogNode", ::java::util::logging::LogManager$LogNode),
	$classEntry("java.util.logging.LogManager$LoggerContext", ::java::util::logging::LogManager$LoggerContext),
	$classEntry("java.util.logging.LogManager$LoggerContext$1", ::java::util::logging::LogManager$LoggerContext$1),
	$classEntry("java.util.logging.LogManager$LoggerWeakRef", ::java::util::logging::LogManager$LoggerWeakRef),
	$classEntry("java.util.logging.LogManager$LoggingProviderAccess", ::java::util::logging::LogManager$LoggingProviderAccess),
	$classEntry("java.util.logging.LogManager$ModType", ::java::util::logging::LogManager$ModType),
	$classEntry("java.util.logging.LogManager$RootLogger", ::java::util::logging::LogManager$RootLogger),
	$classEntry("java.util.logging.LogManager$SystemLoggerContext", ::java::util::logging::LogManager$SystemLoggerContext),
	$classEntry("java.util.logging.LogManager$VisitedLoggers", ::java::util::logging::LogManager$VisitedLoggers),
	$classEntry("java.util.logging.LogRecord", ::java::util::logging::LogRecord),
	$classEntry("java.util.logging.LogRecord$CallerFinder", ::java::util::logging::LogRecord$CallerFinder),
	$classEntry("java.util.logging.Logger", ::java::util::logging::Logger),
	$classEntry("java.util.logging.Logger$ConfigurationData", ::java::util::logging::Logger$ConfigurationData),
	$classEntry("java.util.logging.Logger$LoggerBundle", ::java::util::logging::Logger$LoggerBundle),
	$classEntry("java.util.logging.Logger$RbAccess", ::java::util::logging::Logger$RbAccess),
	$classEntry("java.util.logging.Logger$SystemLoggerHelper", ::java::util::logging::Logger$SystemLoggerHelper),
	$classEntry("java.util.logging.Logger$SystemLoggerHelper$1", ::java::util::logging::Logger$SystemLoggerHelper$1),
	$classEntry("java.util.logging.Logging", ::java::util::logging::Logging),
	$classEntry("java.util.logging.LoggingMXBean", ::java::util::logging::LoggingMXBean),
	$classEntry("java.util.logging.LoggingPermission", ::java::util::logging::LoggingPermission),
	$classEntry("java.util.logging.MemoryHandler", ::java::util::logging::MemoryHandler),
	$classEntry("java.util.logging.SimpleFormatter", ::java::util::logging::SimpleFormatter),
	$classEntry("java.util.logging.SocketHandler", ::java::util::logging::SocketHandler),
	$classEntry("java.util.logging.StreamHandler", ::java::util::logging::StreamHandler),
	$classEntry("java.util.logging.StreamHandler$1", ::java::util::logging::StreamHandler$1),
	$classEntry("java.util.logging.XMLFormatter", ::java::util::logging::XMLFormatter),
	$classEntry("sun.net.www.protocol.http.logging.HttpLogFormatter", ::sun::net::www::protocol::http::logging::HttpLogFormatter),
	$classEntry("sun.util.logging.internal.LoggingProviderImpl", ::sun::util::logging::internal::LoggingProviderImpl),
	$classEntry("sun.util.logging.internal.LoggingProviderImpl$JULWrapper", ::sun::util::logging::internal::LoggingProviderImpl$JULWrapper),
	$classEntry("sun.util.logging.internal.LoggingProviderImpl$LogManagerAccess", ::sun::util::logging::internal::LoggingProviderImpl$LogManagerAccess)
};

const char* _java$logging_packages_[] = {
	"java.util.logging",
	"sun.net.www.protocol.http.logging",
	"sun.util.logging.internal"
};

void java$logging$PreloadClass(void* eventData) {
	::java::lang::PreloadClassEvent* event = (::java::lang::PreloadClassEvent*)eventData;
	int32_t length = $lengthOf(_java$logging_classes_);
	for (int i = 0; i < length; i++) {
		::java::lang::ClassEntry* classEntry = &_java$logging_classes_[i];
		if (event->preinit) {
			if ($hasFlag(classEntry->mark, $PREINIT)) {
				classEntry->loader(nullptr, true);
				continue;
			}
		}
		if (event->preload) {
			if ($hasFlag(classEntry->mark, $PRELOAD) || $hasFlag(classEntry->mark, $PREINIT)) {
				classEntry->loader(nullptr, false);
			}
		}
	}
}

void java$logging$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$logging$PreloadClass(eventData);
	}
	if (eventType == JCPP_LIB_EVENT_TYPE_THREAD_START) {
		$onLibThreadStart(eventData);
	}
}

$StringArray* java$logging$GetPackages() {
	int32_t length = $lengthOf(_java$logging_packages_);
	$var($StringArray, packages, $new($StringArray, length));
	for (int32_t i = 0; i < length; i++) {
		packages->set(i, $str(_java$logging_packages_[i]));
	}
	return packages;
}

::java::lang::ClassEntry* java$logging$GetClassEntry($String* name) {
	int32_t begin = 0;
	int32_t end = $lengthOf(_java$logging_classes_) - 1;
	while (begin <= end) {
		int32_t mid = begin + (end - begin) / 2;
		::java::lang::ClassEntry* classEntry = &_java$logging_classes_[mid];
		int32_t ret = name->compareTo(classEntry->name);
		if (ret < 0) {
			end = mid - 1;
		} else if (ret > 0) {
			begin = mid + 1;
		} else {
			return classEntry;
		}
	}
	return nullptr;
}

$bytes* java$logging$GetResource($String* name) {
	return nullptr;
}

void java$logging::init() {
	::java$base::init();
	::java::lang::Library lib = {
		"java.logging", "17.35", "",
		&_java$logging_ModuleInfo_,
		java$logging$LibEventAction,
		java$logging$GetPackages,
		java$logging$GetClassEntry,
		java$logging$GetResource
	};
	$System::addLibrary(&lib);
}