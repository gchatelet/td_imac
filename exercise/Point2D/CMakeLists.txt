cmake_minimum_required (VERSION 2.8)
project (Point2D)

## Compilation du programme
add_library(point_lib Point2D.cpp) # la lib pour les tests et le programme

# programme main qui link avec la librairie
add_executable(main main.cpp)
target_link_libraries(main point_lib)

## Compilation de gtest
set(GTEST_DIR ~/gtest) # definition du répertoire de GTEST
find_package (Threads) # gtest a besoin de pthread
include_directories(SYSTEM ${GTEST_DIR}/include)
include_directories(${GTEST_DIR})
add_library(gtest ${GTEST_DIR}/src/gtest-all.cc) # gtest - librairie
add_library(gtest_main ${GTEST_DIR}/src/gtest_main.cc) # gtest - 'main'

## Compilation des tests
# executable pour lancer les tests
file(GLOB ALL_TEST_FILES *Test.cpp)
add_executable(runAllTests ${ALL_TEST_FILES})
target_link_libraries(runAllTests point_lib gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
## Lancement automatique des tests après compilation
add_custom_command(TARGET runAllTests POST_BUILD COMMAND runAllTests)