cmake_minimum_required (VERSION 2.8)
project (Particule)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(point2d)
add_subdirectory(particle)
add_subdirectory(force)
add_subdirectory(integrator)
add_subdirectory(console)

# programme main qui link avec la librairie
add_executable(main main.cpp)
target_link_libraries(main point2d particle force console integrator)

## Compilation de gtest
set(GTEST_DIR ~/gtest) # definition du répertoire de GTEST
find_package (Threads) # gtest a besoin de pthread
include_directories(SYSTEM ${GTEST_DIR}/include)
include_directories(${GTEST_DIR})
add_library(gtest ${GTEST_DIR}/src/gtest-all.cc) # gtest - librairie
add_library(gtest_main ${GTEST_DIR}/src/gtest_main.cc) # gtest - 'main'

## Compilation des tests
# executable pour lancer les tests
file(GLOB_RECURSE ALL_TEST_FILES *Test.cpp)
add_executable(runAllTests ${ALL_TEST_FILES})
target_link_libraries(runAllTests point2d particle integrator gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
## Lancement automatique des tests après compilation
add_custom_command(TARGET runAllTests POST_BUILD COMMAND runAllTests)