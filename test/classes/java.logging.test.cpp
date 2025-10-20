#include <java.logging.test.h>

#include <java.logging.h>
#include <java.base.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>

void java$logging$test$PreloadClass(void* eventData) {
}

void java$logging$test$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$logging$test$PreloadClass(eventData);
	}
	if (eventType == JCPP_LIB_EVENT_TYPE_THREAD_START) {
		$onLibThreadStart(eventData);
	}
}

$StringArray* java$logging$test$GetPackages() {
	return nullptr;
}

::java::lang::ClassEntry* java$logging$test$GetClassEntry($String* name) {
	return nullptr;
}

$bytes* java$logging$test$GetResource($String* name) {
	return nullptr;
}

void java$logging$test::init() {
	::java$logging::init();
	::java$base::init();
	::java::lang::Library lib = {
		"java.logging.test", "17.35", "",
		nullptr,
		java$logging$test$LibEventAction,
		java$logging$test$GetPackages,
		java$logging$test$GetClassEntry,
		java$logging$test$GetResource
	};
	$System::addLibrary(&lib);
	$System::init();
}