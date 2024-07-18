cmake_minimum_required(VERSION 3.12)
project(GalaxyEngine VERSION 0.1.0 LANGUAGES CXX)

file(GLOB_RECURSE GALAXY_ENGINE_SRC
    "*.h"
    "*.cpp"
)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Galaxy/bin/${CMAKE_BUILD_TYPE})

include(CMakePrintHelpers)
include(${CMAKE_SOURCE_DIR}/cmake/Warnings.cmake)

add_library(GalaxyEngine SHARED ${GALAXY_ENGINE_SRC})
target_compile_definitions(GalaxyEngine PRIVATE GALAXY_ENGINE_EXPORTS)

find_package(spdlog REQUIRED)
find_package(glfw3 REQUIRED)
find_package(nlohmann_json REQUIRED)
# find_package(cxxopts REQUIRED)

target_link_libraries(GalaxyEngine PUBLIC spdlog::spdlog)
target_link_libraries(GalaxyEngine PRIVATE glfw)
target_link_libraries(GalaxyEngine PRIVATE nlohmann_json::nlohmann_json)
# target_link_libraries(GalaxyEngine PRIVATE cxxopts::cxxopts)

if(ENABLE_WARNINGS_GALAXY)
    set_compiler_warnings(GalaxyEngine TRUE)
endif()

set_target_properties(GalaxyEngine PROPERTIES LINK_FLAGS "-Wl,-e,main")

add_custom_command(TARGET GalaxyEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_BINARY_DIR}/Galaxy/bin/${CMAKE_BUILD_TYPE}/libGalaxyEngine.so
    ${CMAKE_BINARY_DIR}/Cluster/bin/${CMAKE_BUILD_TYPE}
)
