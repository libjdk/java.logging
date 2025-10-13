#machine generated

add_subdirectory("logging")

aux_source_directory("${CMAKE_CURRENT_SOURCE_DIR}" classes.sun.net.www.protocol_0_SRCS)
file(GLOB classes.sun.net.www.protocol_0_HEADERS *.h *.hpp)
source_group("Include" FILES ${classes.sun.net.www.protocol_0_HEADERS}) 
list(LENGTH classes.sun.net.www.protocol_0_SRCS classes.sun.net.www.protocol_0_SRCS_LENGTH)
if(classes.sun.net.www.protocol_0_SRCS_LENGTH)
	add_library(classes.sun.net.www.protocol_0 OBJECT "${classes.sun.net.www.protocol_0_SRCS}" "${classes.sun.net.www.protocol_0_HEADERS}")
	jcpp_enable_bigobj(classes.sun.net.www.protocol_0)
endif()