cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_STANDARD 11)

project(Monitor)

set(SOURCE_EXE main.cpp)
set(SOURCE_LIB ./Monitor/Monitor.cpp)

add_library(Monitor STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})

target_link_libraries(main Monitor)
