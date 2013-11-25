cmake_minimum_required (VERSION 2.8)
project (Hamlet)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# programme main qui link avec la librairie
add_executable(main main.cpp)
target_link_libraries(main)