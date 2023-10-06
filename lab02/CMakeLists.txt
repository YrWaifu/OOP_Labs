cmake_minimum_required(VERSION 3.10)
project(lab02)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab02 main.cpp ./src/Thirteen.cpp)

enable_testing()
add_executable(tests ./tests/tests.cpp ./src/Thirteen.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)