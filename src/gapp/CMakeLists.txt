# CMake file for gapp /gapp/src/gapp/CMakeLists.txt
# Created on: 23.07.2013
#    Author: zmij

cmake_minimum_required(VERSION 2.6)

set(
	GAPP_HDRS
	gapp.hpp
	Types.hpp
	Hits.hpp
	Tracker.hpp
	${CMAKE_CURRENT_BINARY_DIR}/Config.hpp
)

set(
	GAPP_PRIVATE_HDRS
	detail/urlencode.hpp
	detail/http.hpp
)

set(
	GAPP_SRCS
	gapp.cpp
	Types.cpp
	Hits.cpp
	Tracker.cpp
	detail/urlencode.cpp
	detail/http.cpp
)

set(lib_version "0.0.0")

configure_file(
	Config.in.hpp
	Config.hpp
)

include_directories(
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_BINARY_DIR}/src
)

add_library(
	gapp SHARED
	${GAPP_SRCS} ${GAPP_HDRS}
)

set_target_properties(
	gapp PROPERTIES
	VERSION ${lib_version}
	SOVERSION 0
)

install(
	TARGETS gapp
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)

install(
	FILES ${GAPP_HDRS}
	DESTINATION include/gapp
)
