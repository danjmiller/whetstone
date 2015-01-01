cmake_minimum_required (VERSION 2.6)

project (Whetstone)

enable_testing()

#App Stuff
add_library(whetstone src/LinkedList.cpp src/binaryTree.cpp)


# Unit Tests
add_executable(runTests src/test_LinkedList.cpp)
target_link_libraries(runTests gtest gtest_main)

target_link_libraries(runTests whetstone)

add_test(runTests runTests)


