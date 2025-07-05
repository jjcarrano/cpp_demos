cmake_minimum_required(VERSION 3.25)
project(my_cpp_app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define target name once
set(TARGET_NAME my_cpp_app)

find_package(fmt CONFIG REQUIRED)

# Automatically gather all .cpp files in src/
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

add_executable(${TARGET_NAME} ${SRC_FILES})

target_include_directories(${TARGET_NAME} PRIVATE include)

target_link_libraries(${TARGET_NAME} PRIVATE fmt::fmt)
