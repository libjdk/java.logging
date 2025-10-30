#include <java/util/logging/Formatter.h>

#include <java/text/MessageFormat.h>
#include <java/util/MissingResourceException.h>
#include <java/util/ResourceBundle.h>
#include <java/util/logging/Handler.h>
#include <java/util/logging/LogRecord.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $MethodInfo = ::java::lang::MethodInfo;
using $MessageFormat = ::java::text::MessageFormat;
using $MissingResourceException = ::java::util::MissingResourceException;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Handler = ::java::util::logging::Handler;
using $LogRecord = ::java::util::logging::LogRecord;

namespace java {
	namespace util {
		namespace logging {

$MethodInfo _Formatter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(static_cast<void(Formatter::*)()>(&Formatter::init$))},
	{"format", "(Ljava/util/logging/LogRecord;)Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{"formatMessage", "(Ljava/util/logging/LogRecord;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"getHead", "(Ljava/util/logging/Handler;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"getTail", "(Ljava/util/logging/Handler;)Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _Formatter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.util.logging.Formatter",
	"java.lang.Object",
	nullptr,
	nullptr,
	_Formatter_MethodInfo_
};

$Object* allocate$Formatter($Class* clazz) {
	return $of($alloc(Formatter));
}

void Formatter::init$() {
}

$String* Formatter::getHead($Handler* h) {
	return ""_s;
}

$String* Formatter::getTail($Handler* h) {
	return ""_s;
}

$String* Formatter::formatMessage($LogRecord* record) {
	$useLocalCurrentObjectStackCache();
	$var($String, format, $nc(record)->getMessage());
	$var($ResourceBundle, catalog, record->getResourceBundle());
	if (catalog != nullptr) {
		try {
			$assign(format, catalog->getString(format));
		} catch ($MissingResourceException& ex) {
		}
	}
	try {
		$var($ObjectArray, parameters, record->getParameters());
		if (parameters == nullptr || $nc(parameters)->length == 0) {
			return format;
		}
		int32_t index = -1;
		int32_t fence = $nc(format)->length() - 1;
		while ((index = format->indexOf((int32_t)u'{', index + 1)) > -1) {
			if (index >= fence) {
				break;
			}
			char16_t digit = format->charAt(index + 1);
			if (digit >= u'0' && digit <= u'9') {
				return $MessageFormat::format(format, parameters);
			}
		}
		return format;
	} catch ($Exception& ex) {
		return format;
	}
	$shouldNotReachHere();
}

Formatter::Formatter() {
}

$Class* Formatter::load$($String* name, bool initialize) {
	$loadClass(Formatter, name, initialize, &_Formatter_ClassInfo_, allocate$Formatter);
	return class$;
}

$Class* Formatter::class$ = nullptr;

		} // logging
	} // util
} // java