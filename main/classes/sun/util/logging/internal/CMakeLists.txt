#machine generated

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.util.logging.int_2_SRCS)
file(GLOB classes.sun.util.logging.int_2_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.util.logging.int_2_HEADERS}) 
list(LENGTH classes.sun.util.logging.int_2_SRCS classes.sun.util.logging.int_2_SRCS_LENGTH)
if(classes.sun.util.logging.int_2_SRCS_LENGTH)
	add_library(classes.sun.util.logging.int_2 OBJECT "${classes.sun.util.logging.int_2_SRCS}" "${classes.sun.util.logging.int_2_HEADERS}")
	jcpp_enable_bigobj(classes.sun.util.logging.int_2)
endif()