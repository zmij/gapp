# CMake file for gapp
# Created on: 23.07.2013
#    Author: zmij

cmake_minimum_required(VERSION 2.6)

project(gapp)

set(PROJECT_VERSION 1.2)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

option(STANDALONE_ASIO "Use standalone asio instead of boost::asio" OFF)
option(BUILD_TESTS "Build tests for gapp library" ON)
option(DEBUG_RESPONCE_OUTPUT "Output gapp service response" OFF)

if(STANDALONE_ASIO)
	set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules" )
	find_package(asio 1.10 REQUIRED)
	add_definitions("-DSTANDALONE_ASIO")
endif()

set(
		BOOST_COMPONENTS
		system
)
find_package(Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_definitions("-std=c++11")

if(DEBUG_RESPONCE_OUTPUT)
	add_definitions("-DDEBUG_RESPONCE_OUTPUT")
endif()
if(NOT GOOGLE_POST_URL)
	set(GOOGLE_POST_URL "http://www.google-analytics.com/collect")
endif()

add_subdirectory(src)

if (BUILD_TESTS)
	enable_testing()
	add_subdirectory(t)
endif()

install(
	FILES Findgapp.cmake
	DESTINATION ${CMAKE_ROOT}/Modules
)
