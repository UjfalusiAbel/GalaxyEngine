cmake_minimum_required(VERSION 3.12)
project(Galaxy VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(Galaxy)
add_subdirectory(Cluster)

