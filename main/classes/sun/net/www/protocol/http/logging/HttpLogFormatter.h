#ifndef _sun_net_www_protocol_http_logging_HttpLogFormatter_h_
#define _sun_net_www_protocol_http_logging_HttpLogFormatter_h_
//$ class sun.net.www.protocol.http.logging.HttpLogFormatter
//$ extends java.util.logging.SimpleFormatter

#include <java/util/logging/SimpleFormatter.h>

namespace java {
	namespace util {
		namespace logging {
			class LogRecord;
		}
	}
}
namespace java {
	namespace util {
		namespace regex {
			class Pattern;
		}
	}
}

namespace sun {
	namespace net {
		namespace www {
			namespace protocol {
				namespace http {
					namespace logging {

class HttpLogFormatter : public ::java::util::logging::SimpleFormatter {
	$class(HttpLogFormatter, 0, ::java::util::logging::SimpleFormatter)
public:
	HttpLogFormatter();
	void init$();
	virtual $String* format(::java::util::logging::LogRecord* record) override;
	static $volatile(::java::util::regex::Pattern*) pattern;
	static $volatile(::java::util::regex::Pattern*) cpattern;
};

					} // logging
				} // http
			} // protocol
		} // www
	} // net
} // sun

#endif // _sun_net_www_protocol_http_logging_HttpLogFormatter_h_