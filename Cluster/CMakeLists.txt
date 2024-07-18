cmake_minimum_required(VERSION 3.12)
project(Cluster VERSION 0.0.1 LANGUAGES CXX)

file(GLOB CLUSTER_SRC
     "*/*.h"
     "*/*.cpp"
     "*/*/*.h"
     "*/*/*.cpp"
     "*/*/*/*.h"
     "*/*/*/*.cpp"
)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Cluster/bin/${CMAKE_BUILD_TYPE})

add_executable(Cluster ${CLUSTER_SRC})

set(CMAKE_INCLUDE_DIRECTORIES)
target_link_libraries(Cluster PRIVATE GalaxyEngine)
target_include_directories(Cluster PRIVATE ${CMAKE_SOURCE_DIR}/Galaxy/src)

cmake_print_variables(CMAKE_SOURCE_DIR)
