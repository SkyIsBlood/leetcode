cmake_minimum_required(VERSION 3.20)
project(LeetCode CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable debug symbols and sanitizers for local checks
add_compile_options(-Wall -Wextra -fsanitize=address,undefined -g)
add_link_options(-fsanitize=address,undefined)

# 1. Main target: Active problem in current/
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/current/problem.cpp")
    add_executable(solve current/problem.cpp)
endif()

# 2. Archive targets: Automatically build any file moved to completed/
file(GLOB COMPLETED_SOURCES "completed/*.cpp")
foreach(FILE ${COMPLETED_SOURCES})
    get_filename_component(TARGET_NAME ${FILE} NAME_WE)
    add_executable(${TARGET_NAME} ${FILE})
endforeach()