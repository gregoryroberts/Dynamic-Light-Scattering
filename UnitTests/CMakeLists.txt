cmake_minimum_required(VERSION 3.0)

project(UnitTests)

# set the standard to c++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# output the executable to a directory called Bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)

# need environment variable for base -- DLS_CODE_BASE
include_directories("$ENV{DLS_CODE_BASE}")

# add all of the tests here
add_subdirectory(Utils/StringToNumber)

# add_executable(TestApp Source/TestApp.cc)