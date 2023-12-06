cmake_minimum_required(VERSION 3.10)
project(lab02)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab03 main.cpp ./src/Figure.cpp ./src/Point.cpp ./src/Rectangle.cpp ./src/Square.cpp ./src/Triangle.cpp ./src/Vector.cpp)

enable_testing()
add_executable(tests ./test.cpp ./src/Figure.cpp ./src/Point.cpp ./src/Rectangle.cpp ./src/Square.cpp ./src/Triangle.cpp ./src/Vector.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)