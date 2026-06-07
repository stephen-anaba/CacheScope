cmake_minimum_required(VERSION 3.20)

project(CacheScope)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    cachescope

    src/main.cpp
    src/hash/hash_set.cpp
)
