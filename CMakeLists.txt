cmake_minimum_required (VERSION 2.6)

project (Whetstone)

enable_testing()

set(LIB_SRC 
  src/LinkedList.cpp
  src/binaryTree.cpp
)

set(TEST_SRC
  src/test_LinkedList.cpp
  src/test_BinaryTree.cpp
)

#App Stuff
add_library(whetstone ${LIB_SRC})

# Unit Tests
add_executable(runTests ${TEST_SRC})

target_link_libraries(runTests gtest gtest_main)
target_link_libraries(runTests whetstone)

add_test(runTests runTests)


