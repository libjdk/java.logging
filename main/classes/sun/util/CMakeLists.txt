#machine generated

add_subdirectory("logging")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.util_SRCS)
file(GLOB classes.sun.util_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.util_HEADERS}) 
list(LENGTH classes.sun.util_SRCS classes.sun.util_SRCS_LENGTH)
if(classes.sun.util_SRCS_LENGTH)
	add_library(classes.sun.util OBJECT "${classes.sun.util_SRCS}" "${classes.sun.util_HEADERS}")
	jcpp_enable_bigobj(classes.sun.util)
endif()