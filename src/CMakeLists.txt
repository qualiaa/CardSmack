file(GLOB sources *.cpp *.hpp)

include_directories(${CMAKE_SOURCE_DIR}/src/Engine)

add_executable(Cards ${sources})

target_link_libraries(Cards ${Boost_LIBRARIES} ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} tank)
