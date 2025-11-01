#ifndef _java_util_logging_LogManager$LoggingProviderAccess_h_
#define _java_util_logging_LogManager$LoggingProviderAccess_h_
//$ class java.util.logging.LogManager$LoggingProviderAccess
//$ extends sun.util.logging.internal.LoggingProviderImpl$LogManagerAccess
//$ implements java.security.PrivilegedAction

#include <java/security/PrivilegedAction.h>
#include <sun/util/logging/internal/LoggingProviderImpl$LogManagerAccess.h>

#pragma push_macro("INSTANCE")
#undef INSTANCE

namespace java {
	namespace lang {
		class Module;
	}
}
namespace java {
	namespace util {
		namespace logging {
			class LogManager;
			class Logger;
		}
	}
}

namespace java {
	namespace util {
		namespace logging {

class LogManager$LoggingProviderAccess : public ::sun::util::logging::internal::LoggingProviderImpl$LogManagerAccess, public ::java::security::PrivilegedAction {
	$class(LogManager$LoggingProviderAccess, 0, ::sun::util::logging::internal::LoggingProviderImpl$LogManagerAccess, ::java::security::PrivilegedAction)
public:
	LogManager$LoggingProviderAccess();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	virtual ::java::util::logging::Logger* demandLoggerFor(::java::util::logging::LogManager* manager, $String* name, ::java::lang::Module* module) override;
	virtual $Object* run() override;
	virtual $String* toString() override;
	static ::java::util::logging::LogManager$LoggingProviderAccess* INSTANCE;
};

		} // logging
	} // util
} // java

#pragma pop_macro("INSTANCE")

#endif // _java_util_logging_LogManager$LoggingProviderAccess_h_