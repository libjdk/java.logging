#include <sun/net/www/protocol/http/logging/HttpLogFormatter.h>

#include <java/lang/CharSequence.h>
#include <java/util/logging/LogRecord.h>
#include <java/util/logging/SimpleFormatter.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <jcpp.h>

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $LogRecord = ::java::util::logging::LogRecord;
using $SimpleFormatter = ::java::util::logging::SimpleFormatter;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace http {
					namespace logging {

$FieldInfo _HttpLogFormatter_FieldInfo_[] = {
	{"pattern", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(HttpLogFormatter, pattern)},
	{"cpattern", "Ljava/util/regex/Pattern;", nullptr, $PRIVATE | $STATIC | $VOLATILE, $staticField(HttpLogFormatter, cpattern)},
	{}
};

$MethodInfo _HttpLogFormatter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpLogFormatter::*)()>(&HttpLogFormatter::init$))},
	{"format", "(Ljava/util/logging/LogRecord;)Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _HttpLogFormatter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"sun.net.www.protocol.http.logging.HttpLogFormatter",
	"java.util.logging.SimpleFormatter",
	nullptr,
	_HttpLogFormatter_FieldInfo_,
	_HttpLogFormatter_MethodInfo_
};

$Object* allocate$HttpLogFormatter($Class* clazz) {
	return $of($alloc(HttpLogFormatter));
}

$volatile($Pattern*) HttpLogFormatter::pattern = nullptr;
$volatile($Pattern*) HttpLogFormatter::cpattern = nullptr;

void HttpLogFormatter::init$() {
	$SimpleFormatter::init$();
	if (HttpLogFormatter::pattern == nullptr) {
		$assignStatic(HttpLogFormatter::pattern, $Pattern::compile("\\{[^\\}]*\\}"_s));
		$assignStatic(HttpLogFormatter::cpattern, $Pattern::compile("[^,\\] ]{2,}"_s));
	}
}

$String* HttpLogFormatter::format($LogRecord* record) {
	$useLocalCurrentObjectStackCache();
	$var($String, sourceClassName, $nc(record)->getSourceClassName());
	bool var$0 = sourceClassName == nullptr;
	if (!var$0) {
		bool var$1 = $nc(sourceClassName)->startsWith("sun.net.www.protocol.http"_s);
		var$0 = !(var$1 || $nc(sourceClassName)->startsWith("sun.net.www.http"_s));
	}
	if (var$0) {
		return $SimpleFormatter::format(record);
	}
	$var($String, src, record->getMessage());
	$var($StringBuilder, buf, $new($StringBuilder, "HTTP: "_s));
	if ($nc(src)->startsWith("sun.net.www.MessageHeader@"_s)) {
		$var($Matcher, match, $nc(HttpLogFormatter::pattern)->matcher(src));
		while ($nc(match)->find()) {
			int32_t i = match->start();
			int32_t j = match->end();
			$var($String, s, src->substring(i + 1, j - 1));
			if (s->startsWith("null: "_s)) {
				$assign(s, s->substring(6));
			}
			if (s->endsWith(": null"_s)) {
				$assign(s, s->substring(0, s->length() - 6));
			}
			buf->append("\t"_s)->append(s)->append("\n"_s);
		}
	} else if (src->startsWith("Cookies retrieved: {"_s)) {
		$var($String, s, src->substring(20));
		buf->append("Cookies from handler:\n"_s);
		while (s->length() >= 7) {
			if (s->startsWith("Cookie=["_s)) {
				$var($String, s2, s->substring(8));
				int32_t c = s2->indexOf("Cookie2=["_s);
				if (c > 0) {
					$assign(s2, s2->substring(0, c - 1));
					$assign(s, s2->substring(c));
				} else {
					$assign(s, ""_s);
				}
				if (s2->length() < 4) {
					continue;
				}
				$var($Matcher, m, $nc(HttpLogFormatter::cpattern)->matcher(s2));
				while ($nc(m)->find()) {
					int32_t i = m->start();
					int32_t j = m->end();
					if (i >= 0) {
						$var($String, cookie, s2->substring(i + 1, j > 0 ? j - 1 : s2->length() - 1));
						buf->append("\t"_s)->append(cookie)->append("\n"_s);
					}
				}
			}
			if (s->startsWith("Cookie2=["_s)) {
				$var($String, s2, s->substring(9));
				int32_t c = s2->indexOf("Cookie=["_s);
				if (c > 0) {
					$assign(s2, s2->substring(0, c - 1));
					$assign(s, s2->substring(c));
				} else {
					$assign(s, ""_s);
				}
				$var($Matcher, m, $nc(HttpLogFormatter::cpattern)->matcher(s2));
				while ($nc(m)->find()) {
					int32_t i = m->start();
					int32_t j = m->end();
					if (i >= 0) {
						$var($String, cookie, s2->substring(i + 1, j > 0 ? j - 1 : s2->length() - 1));
						buf->append("\t"_s)->append(cookie)->append("\n"_s);
					}
				}
			}
		}
	} else {
		buf->append(src)->append("\n"_s);
	}
	return buf->toString();
}

void clinit$HttpLogFormatter($Class* class$) {
	$assignStatic(HttpLogFormatter::pattern, nullptr);
	$assignStatic(HttpLogFormatter::cpattern, nullptr);
}

HttpLogFormatter::HttpLogFormatter() {
}

$Class* HttpLogFormatter::load$($String* name, bool initialize) {
	$loadClass(HttpLogFormatter, name, initialize, &_HttpLogFormatter_ClassInfo_, clinit$HttpLogFormatter, allocate$HttpLogFormatter);
	return class$;
}

$Class* HttpLogFormatter::class$ = nullptr;

					} // logging
				} // http
			} // protocol
		} // www
	} // net
} // sun