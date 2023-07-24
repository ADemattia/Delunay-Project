cmake_minimum_required(VERSION 3.9)

project(delaunay LANGUAGES CXX C VERSION 1.0.0)

# Set C++ Standard
################################################################################
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# IMPOSE WARNINGS ON DEBUG
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic-errors")

# IMPOSE CXX FLAGS FOR WINDOWS
if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")
endif (WIN32)

# Add dependencies
################################################################################
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../../externals/Main_Install/eigen3)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../../externals/Main_Install/googletest)

## Eigen3
find_package(Eigen3 CONFIG REQUIRED)
list(APPEND delaunay_LINKED_LIBRARIES PUBLIC Eigen3::Eigen)

## Threads
find_package(Threads REQUIRED)
list(APPEND delaunay_LINKED_LIBRARIES PRIVATE Threads::Threads)

## GTest
find_package(GTest REQUIRED)

list(APPEND delaunay_test_LINKED_LIBRARIES PRIVATE GTest::gtest)
list(APPEND delaunay_test_LINKED_LIBRARIES PRIVATE GTest::gtest_main)
list(APPEND delaunay_test_LINKED_LIBRARIES PRIVATE GTest::gmock)
list(APPEND delaunay_test_LINKED_LIBRARIES PRIVATE GTest::gmock_main)

# Insert Sources
################################################################################
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

list(APPEND delaunay_SOURCES ${delaunay_sources})
list(APPEND delaunay_HEADERS ${delaunay_headers})
list(APPEND delaunay_INCLUDE ${delaunay_includes})

# Insert Tests
################################################################################
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)

list(APPEND delaunay_test_HEADERS ${delaunay_test_headers})
list(APPEND delaunay_test_INCLUDE ${delaunay_test_includes})

# Create executable
################################################################################

add_executable(delaunay_test
	main_test.cpp
	${delaunay_test_HEADERS}
	${delaunay_test_INCLUDE}
	${delaunay_SOURCES}
    ${delaunay_HEADERS})

target_link_libraries(delaunay_test ${delaunay_LINKED_LIBRARIES})
target_link_libraries(delaunay_test ${delaunay_test_LINKED_LIBRARIES})
target_include_directories(delaunay_test PRIVATE ${delaunay_INCLUDE} ${delaunay_test_INCLUDE})
target_compile_options(delaunay_test PUBLIC -fPIC)

gtest_discover_tests(delaunay_test)

add_executable(delaunay_program
	main_program.cpp
	${delaunay_SOURCES}
    ${delaunay_HEADERS})

target_link_libraries(delaunay_program ${delaunay_LINKED_LIBRARIES})
target_include_directories(delaunay_program PRIVATE ${delaunay_INCLUDE})
target_compile_options(delaunay_program PUBLIC -fPIC)
