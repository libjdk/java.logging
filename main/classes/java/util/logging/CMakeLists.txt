#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.java.util.logging_SRCS)
file(GLOB classes.java.util.logging_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.java.util.logging_HEADERS}) 
list(LENGTH classes.java.util.logging_SRCS classes.java.util.logging_SRCS_LENGTH)
if(classes.java.util.logging_SRCS_LENGTH)
	add_library(classes.java.util.logging OBJECT "${classes.java.util.logging_SRCS}" "${classes.java.util.logging_HEADERS}")
	jcpp_enable_bigobj(classes.java.util.logging)
endif()