file(GLOB sources *.cpp *.hpp)

include_directories(${CMAKE_SOURCE_DIR}/src/Engine)

add_executable(Cards ${sources})

target_link_libraries(Cards tank)
