#include <java/util/logging/XMLFormatter.h>

#include <java/lang/AbstractStringBuilder.h>
#include <java/lang/Appendable.h>
#include <java/lang/StackTraceElement.h>
#include <java/nio/charset/Charset.h>
#include <java/time/Instant.h>
#include <java/time/format/DateTimeFormatter.h>
#include <java/time/temporal/Temporal.h>
#include <java/time/temporal/TemporalAccessor.h>
#include <java/util/Calendar.h>
#include <java/util/GregorianCalendar.h>
#include <java/util/ResourceBundle.h>
#include <java/util/logging/Formatter.h>
#include <java/util/logging/Handler.h>
#include <java/util/logging/Level.h>
#include <java/util/logging/LogManager.h>
#include <java/util/logging/LogRecord.h>
#include <jcpp.h>

#undef DAY_OF_MONTH
#undef HOUR_OF_DAY
#undef ISO_INSTANT
#undef MINUTE
#undef MONTH
#undef SECOND
#undef YEAR

using $StackTraceElementArray = $Array<::java::lang::StackTraceElement>;
using $AbstractStringBuilder = ::java::lang::AbstractStringBuilder;
using $Appendable = ::java::lang::Appendable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $StackTraceElement = ::java::lang::StackTraceElement;
using $Charset = ::java::nio::charset::Charset;
using $Instant = ::java::time::Instant;
using $DateTimeFormatter = ::java::time::format::DateTimeFormatter;
using $Temporal = ::java::time::temporal::Temporal;
using $TemporalAccessor = ::java::time::temporal::TemporalAccessor;
using $Calendar = ::java::util::Calendar;
using $GregorianCalendar = ::java::util::GregorianCalendar;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Formatter = ::java::util::logging::Formatter;
using $Handler = ::java::util::logging::Handler;
using $Level = ::java::util::logging::Level;
using $LogManager = ::java::util::logging::LogManager;
using $LogRecord = ::java::util::logging::LogRecord;

namespace java {
	namespace util {
		namespace logging {

$FieldInfo _XMLFormatter_FieldInfo_[] = {
	{"manager", "Ljava/util/logging/LogManager;", nullptr, $PRIVATE | $FINAL, $field(XMLFormatter, manager)},
	{"useInstant", "Z", nullptr, $PRIVATE | $FINAL, $field(XMLFormatter, useInstant)},
	{}
};

$MethodInfo _XMLFormatter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(XMLFormatter::*)()>(&XMLFormatter::init$))},
	{"a2", "(Ljava/lang/StringBuilder;I)V", nullptr, $PRIVATE, $method(static_cast<void(XMLFormatter::*)($StringBuilder*,int32_t)>(&XMLFormatter::a2))},
	{"appendISO8601", "(Ljava/lang/StringBuilder;J)V", nullptr, $PRIVATE, $method(static_cast<void(XMLFormatter::*)($StringBuilder*,int64_t)>(&XMLFormatter::appendISO8601))},
	{"escape", "(Ljava/lang/StringBuilder;Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(XMLFormatter::*)($StringBuilder*,$String*)>(&XMLFormatter::escape))},
	{"format", "(Ljava/util/logging/LogRecord;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"getHead", "(Ljava/util/logging/Handler;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"getTail", "(Ljava/util/logging/Handler;)Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _XMLFormatter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.util.logging.XMLFormatter",
	"java.util.logging.Formatter",
	nullptr,
	_XMLFormatter_FieldInfo_,
	_XMLFormatter_MethodInfo_
};

$Object* allocate$XMLFormatter($Class* clazz) {
	return $of($alloc(XMLFormatter));
}

void XMLFormatter::init$() {
	$useLocalCurrentObjectStackCache();
	$Formatter::init$();
	$set(this, manager, $LogManager::getLogManager());
	this->useInstant = (this->manager == nullptr) || $nc(this->manager)->getBooleanProperty($$str({$($of(this)->getClass()->getName()), ".useInstant"_s}), true);
}

void XMLFormatter::a2($StringBuilder* sb, int32_t x) {
	if (x < 10) {
		$nc(sb)->append(u'0');
	}
	$nc(sb)->append(x);
}

void XMLFormatter::appendISO8601($StringBuilder* sb, int64_t millis) {
	$var($GregorianCalendar, cal, $new($GregorianCalendar));
	cal->setTimeInMillis(millis);
	$nc(sb)->append(cal->get($Calendar::YEAR));
	sb->append(u'-');
	a2(sb, cal->get($Calendar::MONTH) + 1);
	sb->append(u'-');
	a2(sb, cal->get($Calendar::DAY_OF_MONTH));
	sb->append(u'T');
	a2(sb, cal->get($Calendar::HOUR_OF_DAY));
	sb->append(u':');
	a2(sb, cal->get($Calendar::MINUTE));
	sb->append(u':');
	a2(sb, cal->get($Calendar::SECOND));
}

void XMLFormatter::escape($StringBuilder* sb, $String* text$renamed) {
	$var($String, text, text$renamed);
	if (text == nullptr) {
		$assign(text, "<null>"_s);
	}
	for (int32_t i = 0; i < $nc(text)->length(); ++i) {
		char16_t ch = text->charAt(i);
		if (ch == u'<') {
			$nc(sb)->append("&lt;"_s);
		} else if (ch == u'>') {
			$nc(sb)->append("&gt;"_s);
		} else if (ch == u'&') {
			$nc(sb)->append("&amp;"_s);
		} else {
			$nc(sb)->append(ch);
		}
	}
}

$String* XMLFormatter::format($LogRecord* record) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder, 500));
	sb->append("<record>\n"_s);
	$var($Instant, instant, $nc(record)->getInstant());
	sb->append("  <date>"_s);
	if (this->useInstant) {
		$init($DateTimeFormatter);
		$nc($DateTimeFormatter::ISO_INSTANT)->formatTo(instant, sb);
	} else {
		appendISO8601(sb, $nc(instant)->toEpochMilli());
	}
	sb->append("</date>\n"_s);
	sb->append("  <millis>"_s);
	sb->append($nc(instant)->toEpochMilli());
	sb->append("</millis>\n"_s);
	int32_t nanoAdjustment = $nc(instant)->getNano() % 0x000F4240;
	if (this->useInstant && nanoAdjustment != 0) {
		sb->append("  <nanos>"_s);
		sb->append(nanoAdjustment);
		sb->append("</nanos>\n"_s);
	}
	sb->append("  <sequence>"_s);
	sb->append(record->getSequenceNumber());
	sb->append("</sequence>\n"_s);
	$var($String, name, record->getLoggerName());
	if (name != nullptr) {
		sb->append("  <logger>"_s);
		escape(sb, name);
		sb->append("</logger>\n"_s);
	}
	sb->append("  <level>"_s);
	escape(sb, $($nc($(record->getLevel()))->toString()));
	sb->append("</level>\n"_s);
	if (record->getSourceClassName() != nullptr) {
		sb->append("  <class>"_s);
		escape(sb, $(record->getSourceClassName()));
		sb->append("</class>\n"_s);
	}
	if (record->getSourceMethodName() != nullptr) {
		sb->append("  <method>"_s);
		escape(sb, $(record->getSourceMethodName()));
		sb->append("</method>\n"_s);
	}
	sb->append("  <thread>"_s);
	sb->append(record->getLongThreadID());
	sb->append("</thread>\n"_s);
	if (record->getMessage() != nullptr) {
		$var($String, message, formatMessage(record));
		sb->append("  <message>"_s);
		escape(sb, message);
		sb->append("</message>"_s);
		sb->append("\n"_s);
	}
	$var($ResourceBundle, bundle, record->getResourceBundle());
	try {
		if (bundle != nullptr && bundle->getString($(record->getMessage())) != nullptr) {
			sb->append("  <key>"_s);
			escape(sb, $(record->getMessage()));
			sb->append("</key>\n"_s);
			sb->append("  <catalog>"_s);
			escape(sb, $(record->getResourceBundleName()));
			sb->append("</catalog>\n"_s);
		}
	} catch ($Exception& ex) {
	}
	$var($ObjectArray, parameters, record->getParameters());
	if (parameters != nullptr && parameters->length != 0 && $nc($(record->getMessage()))->indexOf((int32_t)u'{') == -1) {
		{
			$var($ObjectArray, arr$, parameters);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($Object0, parameter, arr$->get(i$));
				{
					sb->append("  <param>"_s);
					try {
						escape(sb, $($nc($of(parameter))->toString()));
					} catch ($Exception& ex) {
						sb->append("???"_s);
					}
					sb->append("</param>\n"_s);
				}
			}
		}
	}
	if (record->getThrown() != nullptr) {
		$var($Throwable, th, record->getThrown());
		sb->append("  <exception>\n"_s);
		sb->append("    <message>"_s);
		escape(sb, $($nc(th)->toString()));
		sb->append("</message>\n"_s);
		$var($StackTraceElementArray, trace, $nc(th)->getStackTrace());
		{
			$var($StackTraceElementArray, arr$, trace);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($StackTraceElement, frame, arr$->get(i$));
				{
					sb->append("    <frame>\n"_s);
					sb->append("      <class>"_s);
					escape(sb, $($nc(frame)->getClassName()));
					sb->append("</class>\n"_s);
					sb->append("      <method>"_s);
					escape(sb, $($nc(frame)->getMethodName()));
					sb->append("</method>\n"_s);
					if ($nc(frame)->getLineNumber() >= 0) {
						sb->append("      <line>"_s);
						sb->append(frame->getLineNumber());
						sb->append("</line>\n"_s);
					}
					sb->append("    </frame>\n"_s);
				}
			}
		}
		sb->append("  </exception>\n"_s);
	}
	sb->append("</record>\n"_s);
	return sb->toString();
}

$String* XMLFormatter::getHead($Handler* h) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	$var($String, encoding, nullptr);
	sb->append("<?xml version=\"1.0\""_s);
	if (h != nullptr) {
		$assign(encoding, h->getEncoding());
	} else {
		$assign(encoding, nullptr);
	}
	if (encoding == nullptr) {
		$assign(encoding, $nc($($Charset::defaultCharset()))->name());
	}
	try {
		$var($Charset, cs, $Charset::forName(encoding));
		$assign(encoding, $nc(cs)->name());
	} catch ($Exception& ex) {
	}
	sb->append(" encoding=\""_s);
	sb->append(encoding);
	sb->append("\""_s);
	sb->append(" standalone=\"no\"?>\n"_s);
	sb->append("<!DOCTYPE log SYSTEM \"logger.dtd\">\n"_s);
	sb->append("<log>\n"_s);
	return sb->toString();
}

$String* XMLFormatter::getTail($Handler* h) {
	return "</log>\n"_s;
}

XMLFormatter::XMLFormatter() {
}

$Class* XMLFormatter::load$($String* name, bool initialize) {
	$loadClass(XMLFormatter, name, initialize, &_XMLFormatter_ClassInfo_, allocate$XMLFormatter);
	return class$;
}

$Class* XMLFormatter::class$ = nullptr;

		} // logging
	} // util
} // java