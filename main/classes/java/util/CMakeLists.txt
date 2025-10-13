#machine generated

add_subdirectory("logging")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.java.util_SRCS)
file(GLOB classes.java.util_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.java.util_HEADERS}) 
list(LENGTH classes.java.util_SRCS classes.java.util_SRCS_LENGTH)
if(classes.java.util_SRCS_LENGTH)
	add_library(classes.java.util OBJECT "${classes.java.util_SRCS}" "${classes.java.util_HEADERS}")
	jcpp_enable_bigobj(classes.java.util)
endif()