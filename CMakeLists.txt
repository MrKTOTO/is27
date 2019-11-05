cmake_minimum_required(VERSION 3.10)
project(project_name)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(cmake_testapp src/main.cpp lib/sharov.cpp lib/peshehonov.cpp lib/manin.cpp) #lib/perevezencev.cpp lib/Puhov_Create.cpp)
