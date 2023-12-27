cmake_minimum_required(VERSION 3.8)

project(fLR7)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(fLRp7 main.cpp ./src/bear.cpp ./src/factory.cpp ./src/fight.cpp ./src/npc.cpp ./src/observer.cpp ./src/robber.cpp ./src/werewolf.cpp)
add_executable(fLRt7 test.cpp ./src/bear.cpp ./src/factory.cpp ./src/fight.cpp ./src/npc.cpp ./src/observer.cpp ./src/robber.cpp ./src/werewolf.cpp)

enable_testing()
target_link_libraries(fLRp7 Threads::Threads)
target_link_libraries(fLRt7 ${GTEST_LIBRARIES} Threads::Threads)
add_test(NAME BASIC COMMAND fLRt7)