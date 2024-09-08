cmake_minimum_required(VERSION 3.12)
project(Galaxy VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

include(${PROJECT_SOURCE_DIR}/cmake/Testing.cmake)

#Set source directories for engine library and editor
set(GALAXY_SRC_DIR ${PROJECT_SOURCE_DIR}/Galaxy/src)
set(CLUSTER_SRC_DIR ${PROJECT_SOURCE_DIR}/Cluster/src)

set(TESTS_DIR ${PROJECT_SOURCE_DIR}/Tests)

include(${CMAKE_SOURCE_DIR}/external/vcpkg/scripts/buildsystems/vcpkg.cmake)

option(CREATE_TEST_GALAXY "Create the test build for engine lib" ON)
option(CREATE_TEST_CLUSTER "Create the test build for engine editor" OFF)
option(ENABLE_WARNINGS_GALAXY "Enable compile warnings for engine lib" ON)


add_subdirectory(Galaxy)
add_subdirectory(Cluster)

add_testing(CREATE_TEST_GALAXY CREATE_TEST_CLUSTER)



