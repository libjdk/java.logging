#machine generated

add_subdirectory("internal")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.util.logging_SRCS)
file(GLOB classes.sun.util.logging_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.util.logging_HEADERS}) 
list(LENGTH classes.sun.util.logging_SRCS classes.sun.util.logging_SRCS_LENGTH)
if(classes.sun.util.logging_SRCS_LENGTH)
	add_library(classes.sun.util.logging OBJECT "${classes.sun.util.logging_SRCS}" "${classes.sun.util.logging_HEADERS}")
	jcpp_enable_bigobj(classes.sun.util.logging)
endif()