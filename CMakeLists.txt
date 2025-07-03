cmake_minimum_required(VERSION 3.25)
project(my_cpp_app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -- INSERT_POINT:FIND_PACKAGE --
find_package(fmt CONFIG REQUIRED)

add_executable(my_cpp_app src/main.cpp)
target_link_libraries(my_cpp_app PRIVATE
# -- INSERT_POINT:TARGET_LINK_LIBRARIES --
    fmt::fmt
)
