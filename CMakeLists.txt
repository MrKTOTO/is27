cmake_minimum_required(VERSION 3.10)
project(project_name)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(sharov src/main.cpp src/sharov.cpp)
add_executable(svyatov src/main.cpp src/svyatov.cpp)
add_executable(zhdanov src/main.cpp src/zhdanov.cpp)
add_executable(sulaimonov src/main.cpp src/MS.cpp)
add_executable(main src/main.cpp src/main.cpp cmake-build-debug/peshehonov.cpp)

