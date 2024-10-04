cmake_minimum_required(VERSION 3.12)
project(GalaxyEngineTests VERSION 0.1.0 LANGUAGES CXX)

set(GALAXY_ENGINE_TEST_SRC_DIR ${PROJECT_SOURCE_DIR}/Tests)

include(${GALAXY_ENGINE_TEST_SRC_DIR}/Events/Events.cmake)

set(GALAXY_ENGINE_TEST_SRC ${GALAXY_ENGINE_TEST_EVENTS_SRC})

find_package(Catch2 CONFIG REQUIRED)

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/Galaxy/src GalaxyEngineTests)

add_executable(GalaxyEngineTests ${GALAXY_ENGINE_TEST_SRC}
                                 ${PROJECT_SOURCE_DIR}/main.cpp
                                 ${PROJECT_SOURCE_DIR}/Listener.cpp)

target_link_libraries(GalaxyEngineTests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(GalaxyEngineTests PRIVATE GalaxyEngine)
target_include_directories(GalaxyEngineTests PRIVATE ${CMAKE_SOURCE_DIR}/Galaxy/src)
set_target_properties(GalaxyEngineTests PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

include(CTest)
include(Catch)
catch_discover_tests(GalaxyEngineTests)
