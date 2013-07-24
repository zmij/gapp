# CMake file for gapp
# Created on: 23.07.2013
#    Author: zmij

cmake_minimum_required(VERSION 2.6)

project(gapp)

set(PROJECT_VERSION 1.0)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

set(
	BOOST_COMPONENTS
	system
)

find_package(Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)

add_definitions("-std=c++0x")

add_subdirectory(src)

# TODO Check for test build necessity
enable_testing()
add_subdirectory(t)

install(
	FILES Findgapp.cmake
	DESTINATION share/cmake/Modules
)
