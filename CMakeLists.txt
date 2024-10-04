cmake_minimum_required(VERSION 3.12)
project(Galaxy VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

include(${PROJECT_SOURCE_DIR}/cmake/Testing.cmake)

#Set source directories for engine library, editor and tests
set(GALAXY_SRC_DIR ${PROJECT_SOURCE_DIR}/Galaxy/src)
set(CLUSTER_SRC_DIR ${PROJECT_SOURCE_DIR}/Cluster/src)
set(TESTS_DIR ${PROJECT_SOURCE_DIR}/Tests)

include(${CMAKE_SOURCE_DIR}/external/vcpkg/scripts/buildsystems/vcpkg.cmake)

#Setting for tests, warnings, docs
set(CREATE_TEST_GALAXY ON)
set(CREATE_TEST_CLUSTER OFF)
set(ENABLE_WARNINGS_GALAXY ON)

#Adding projects
add_subdirectory(Galaxy)
add_subdirectory(Cluster)

#Adding tests
add_testing(${CREATE_TEST_GALAXY} ${CREATE_TEST_CLUSTER})