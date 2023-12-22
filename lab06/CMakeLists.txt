cmake_minimum_required(VERSION 3.8)

project(lab06)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDART 20) 
set(CMAKE_CXX_STANDART_REQUIRED ON) 

add_executable(lab06 main.cpp npc.hpp robber.hpp wolf.hpp bear.hpp npc.cpp robber.cpp wolf.cpp bear.cpp) 

enable_testing()
add_executable(tests test.cpp npc.hpp robber.hpp wolf.hpp bear.hpp npc.cpp robber.cpp wolf.cpp bear.cpp)

target_link_libraries(lab06 ${GTEST_LIBRARIES})
add_test(NAME BASIC COMMAND lab06)