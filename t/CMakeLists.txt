# CMake file for gapp /gapp/t/CMakeLists.txt
# Created on: 23.07.2013
#    Author: zmij

cmake_minimum_required(VERSION 2.6)

set(Boost_USE_STATIC_LIBS ON)

find_package( Boost COMPONENTS unit_test_framework REQUIRED )

if (NOT TRACK_ID)
	set( TRACK_ID UA-42658449-2 )
endif()

if (NOT MOCK_URL)
	set( MOCK_URL http://localhost )
endif()

configure_file(TestConfig.in.hpp TestConfig.hpp)

include_directories(
	${Boost_INCLUDE_DIRS}
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_BINARY_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
)

set(
	TESTS_SRC
	test_gapp.cpp
)

set(
	TEST test_${PROJECT_NAME}
)

add_executable(
	${TEST} ${TESTS_SRC}
)

target_link_libraries(
	${TEST}
	${Boost_LIBRARIES}
	gapp
)

add_test(
	NAME ${PROJECT_NAME}
	COMMAND ${TEST}
)
