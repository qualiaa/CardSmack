CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

project(Cards)
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

find_package(SFML 2.0 REQUIRED system window audio graphics)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(Threads REQUIRED)
find_package(Boost 1.53.0 REQUIRED)
add_subdirectory(Tank)

include_directories(${Boost_INCLUDE_DIR})
include_directories(${SFML_INCLUDE_DIR})
include_directories(${TANK_INCLUDE_DIRS})

message("Boost_INCLUDE_DIR ${Boost_INCLUDE_DIR}")
message("SFML_INCLUDE_DIR ${SFML_INCLUDE_DIR}")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

option(COTIRE "Use Cotire" ON)
if(COTIRE)
    include(cotire)
endif(COTIRE)

if (NOT MSVC)
    set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
endif(NOT MSVC)

if (APPLE)
    set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ ${CMAKE_CXX_FLAGS}")
    set(CMAKE_LD_FLAGS "-stdlib=libc++ ${CMAKE_LD_FLAGS}")
endif(APPLE)

set(CMAKE_BUILD_TYPE Debug)

if(NOT MSVC)
    option(WARN "Compile using all warnings" ON)
endif(NOT MSVC)

if(WARN)
    set (CMAKE_CXX_FLAGS "-Wall -Werror ${CMAKE_CXX_FLAGS} -Wno-mismatched-tags")
endif(WARN)

set (CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}" )

add_subdirectory(src)
file(COPY "res" DESTINATION ${CMAKE_BINARY_DIR})
