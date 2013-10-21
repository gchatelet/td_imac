---
goal:Découvrir les tests unitaires. Introduction à gtest.
---
Il est absolument nécessaire de tester le code que l'on écrit. Des bugs peuvent êtres introduits par des modifications ultérieures ou des cas particuliers peuvent engendrer des résultats incohérents.
 - Télécharger [Google Test](https://code.google.com/p/googletest/)
 - Décompressez le code source `~/gtest`
 - Modifiez votre fichier CMakeLists.txt


		cmake_minimum_required (VERSION 2.8)
		project (MyProject)
		
		## Compilation du programme
		add_library(hello_lib function.cpp) # la lib pour les tests et le programme
		
		# programme hello qui link avec la librairie
		add_executable(hello main.cpp)
		target_link_libraries(hello hello_lib)
		
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
		target_link_libraries(runAllTests 
			hello_lib gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
		## Lancement automatique des tests après compilation
		add_custom_command(TARGET runAllTests POST_BUILD COMMAND runAllTests)
 - Lisez les [concepts de bases](https://code.google.com/p/googletest/wiki/Primer#Basic_Concepts)
 - Écrivez votre premier test `FirstTest.cpp` et compiler-le


		include <gtest/gtest.h>
		
		TEST(MyFirstTest, passes){
		        EXPECT_EQ(1,1);
		}
		
		TEST(MyFirstTest, doesnt_pass){
		        EXPECT_EQ("a string", "another string");
		}
 
**NB** : Il existe d'autres [frameworks de tests unitaires pour le C++](http://en.wikipedia.org/wiki/List_of_unit_testing_frameworks#C.2B.2B). `gtest` présente l'avantage d'être gratuit et simple à utiliser.
