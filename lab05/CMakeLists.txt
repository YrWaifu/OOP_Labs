cmake_minimum_required(VERSION 3.8)
#требования к версии

project(lab05)
#имя проекта

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDART 20)
set(CMAKE_CXX_STANDART_REQUIRED ON)

add_executable(lab05 main.cpp ./include/allocator.hpp ./include/myqueue.hpp)

# enable_testing()
# add_executable(tests tests.cpp ./include/allocator.hpp ./include/vector.hpp)

# target_link_libraries(tests ${GTEST_LIBRARIES})
# add_test(NAME BASIC COMMAND tests)