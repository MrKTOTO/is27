cmake_minimum_required(VERSION 3.10)
project(untitled2)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp)
add_executable(sharov main.cpp sharov.cpp)
add_executable(svyatov main.cpp svyatov.cpp)
add_executable(zhdanov main.cpp zhdanov.cpp)
add_executable(sulaimonov main.cpp MS.cpp)