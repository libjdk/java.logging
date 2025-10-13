#ifndef _java_util_logging_SocketHandler_h_
#define _java_util_logging_SocketHandler_h_
//$ class java.util.logging.SocketHandler
//$ extends java.util.logging.StreamHandler

#include <java/util/logging/StreamHandler.h>

namespace java {
	namespace net {
		class Socket;
	}
}
namespace java {
	namespace util {
		namespace logging {
			class LogRecord;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class $import SocketHandler : public ::java::util::logging::StreamHandler {
	$class(SocketHandler, $NO_CLASS_INIT, ::java::util::logging::StreamHandler)
public:
	SocketHandler();
	void init$();
	void init$($String* host, int32_t port);
	virtual void close() override;
	void connect();
	virtual void publish(::java::util::logging::LogRecord* record) override;
	::java::net::Socket* sock = nullptr;
	$String* host = nullptr;
	int32_t port = 0;
};

		} // logging
	} // util
} // java

#endif // _java_util_logging_SocketHandler_h_