# CMake file for gapp /gapp/src/gapp/CMakeLists.txt
# Created on: 23.07.2013
#    Author: zmij

cmake_minimum_required(VERSION 2.6)

configure_file(config.in.hpp config.hpp)


set(
	GAPP_HDRS
	asio_config.hpp
	gapp.hpp
	types.hpp
	hits.hpp
	tracker.hpp
	${CMAKE_CURRENT_BINARY_DIR}/config.hpp
)

set(
	GAPP_PRIVATE_HDRS
	detail/urlencode.hpp
	detail/http.hpp
)

set(
	GAPP_SRCS
	gapp.cpp
		types.cpp
		hits.cpp
	tracker.cpp
	detail/urlencode.cpp
	detail/http.cpp
)

set(lib_version "0.0.0")

include_directories(
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_BINARY_DIR}/src
)

add_library(
	gapp SHARED
	${GAPP_SRCS} ${GAPP_HDRS}
)
if(NOT STANDALONE_ASIO)
	target_link_libraries(gapp ${Boost_SYSTEM_LIBRARIES})
endif()
set_target_properties(
	gapp PROPERTIES
	VERSION ${lib_version}
	SOVERSION 0
)

target_link_libraries(
	gapp
	${Boost_LIBRARIES}
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
