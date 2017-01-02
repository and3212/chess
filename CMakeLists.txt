cmake_minimum_required(VERSION 3.6)
project(chess)

set(CMAKE_CXX_STANDARD 14)

#set(SOURCE_FILES main.cpp)
file(GLOB SOURCE_FILES
        "*.hpp"
        "*.cpp"
        )

add_executable(main ${SOURCE_FILES})