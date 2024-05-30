cmake_minimum_required(VERSION 3.12)
project(GalaxyEngine VERSION 0.0.1 LANGUAGES CXX)


file(GLOB galaxy_engine_src
     "*/*.h"
     "*/*.cpp"
     "*/*/*.h"
     "*/*/*.cpp"
     "*/*/*/*.h"
     "*/*/*/*.cpp"
)


set(CMAKE_CXX_STANDARD 20)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Galaxy/bin/${CMAKE_BUILD_TYPE})

set(CMAKE_TOOLCHAIN_FILE /home/ujfalusiabel/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
include(CMakePrintHelpers)

#cmake_print_variables(galaxy_engine_src)

add_library(GalaxyEngine SHARED ${galaxy_engine_src})
target_compile_definitions(GalaxyEngine PRIVATE GALAXY_ENGINE_EXPORTS)

find_package(spdlog CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(GalaxyEngine PUBLIC spdlog::spdlog)
target_link_libraries(GalaxyEngine PRIVATE glfw)

set_target_properties(GalaxyEngine PROPERTIES LINK_FLAGS "-Wl,-e,main")


add_custom_command(TARGET GalaxyEngine POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/Galaxy/bin/${CMAKE_BUILD_TYPE}/libGalaxyEngine.so  ${CMAKE_BINARY_DIR}/Cluster/bin/${CMAKE_BUILD_TYPE} )