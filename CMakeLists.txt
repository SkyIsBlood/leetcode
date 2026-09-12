cmake_minimum_required(VERSION 3.20)
project(LeetCode CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable debug symbols and sanitizers for local checks
add_compile_options(-Wall -Wextra -fsanitize=address,undefined -g)
add_link_options(-fsanitize=address,undefined)

# 1. Main target: Active problem in current/
file(GLOB CURRENT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/current/*.cpp")

if(CURRENT_SOURCES)
    list(GET CURRENT_SOURCES 0 ACTIVE_CPP)
    add_executable(solve ${ACTIVE_CPP})
endif()
option(ENABLE_ASAN "Enable Address/Leak Sanitizer" OFF)

if(ENABLE_ASAN)
    add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address)
endif()
