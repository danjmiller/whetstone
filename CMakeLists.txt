cmake_minimum_required (VERSION 2.6)

project (Whetstone)

# GTest
#add_subdirectory (gtest-1.7.0)
enable_testing()
#include_directories(${GTEST_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


#App Stuff
add_library(whetstone src/LinkedList.cpp)

# Unit Tests
add_executable(runTests src/test_LinkedList.cpp)
target_link_libraries(runTests gtest gtest_main)

target_link_libraries(runTests whetstone)

add_test(runTests runTests)


