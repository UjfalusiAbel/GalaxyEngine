cmake_minimum_required(VERSION 3.12)
project(GalaxyEngine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

#Include system submodules
include(${GALAXY_SRC_DIR}/Core/Core.cmake)
include(${GALAXY_SRC_DIR}/Events/Events.cmake)
include(${GALAXY_SRC_DIR}/Math/Math.cmake)

#Add include directories
include_directories(${GALAXY_SRC_DIR})

#Set sources
set(GALAXY_ENGINE_SRC "")

#Append sources to target
list(APPEND GALAXY_ENGINE_SRC ${CORE_SOURCES} 
                       ${EVENT_SOURCES} 
                       ${MATH_SOURCES} 
                       ${GALAXY_SRC_DIR}/Galaxy.hpp)
message(${GALAXY_ENGINE_SRC})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Galaxy/bin/${CMAKE_BUILD_TYPE})

include(CMakePrintHelpers)
include(${CMAKE_SOURCE_DIR}/cmake/Warnings.cmake)

add_library(GalaxyEngine SHARED ${GALAXY_ENGINE_SRC})
target_compile_definitions(GalaxyEngine PRIVATE GALAXY_ENGINE_EXPORTS)

#Include all vcpkg packages
find_package(spdlog REQUIRED)
find_package(glfw3 REQUIRED)
find_package(nlohmann_json REQUIRED)

#Link libraries into project
target_link_libraries(GalaxyEngine PUBLIC spdlog::spdlog)
target_link_libraries(GalaxyEngine PRIVATE glfw)
target_link_libraries(GalaxyEngine PRIVATE nlohmann_json::nlohmann_json)


#Check compiler warnings
if(ENABLE_WARNINGS_GALAXY)
    set_compiler_warnings(GalaxyEngine OFF)
endif()


set_target_properties(GalaxyEngine PROPERTIES LINK_FLAGS "-Wl,-e,main")

#Copy library to executable folder
add_custom_command(TARGET GalaxyEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_BINARY_DIR}/Galaxy/bin/${CMAKE_BUILD_TYPE}/libGalaxyEngine.so
    ${CMAKE_BINARY_DIR}/Cluster/bin/${CMAKE_BUILD_TYPE}
)
