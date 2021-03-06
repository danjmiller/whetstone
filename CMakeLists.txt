cmake_minimum_required (VERSION 2.6)

project (Whetstone)

enable_testing()

set(LIB_SRC 
  src/LinkedList.cpp
  src/binaryTree.cpp
  src/StringUtils.cpp
  src/BitTools.cpp
  src/Graph.cpp
)

set(TEST_SRC
  src/test_LinkedList.cpp
  src/test_BinaryTree.cpp
  src/test_StringUtils.cpp
  src/test_BitTools.cpp
  src/test_Graph.cpp
)

#App Stuff
add_library(whetstone ${LIB_SRC})

# Unit Tests
add_executable(runTests ${TEST_SRC})

target_link_libraries(runTests gtest gtest_main)
target_link_libraries(runTests whetstone)

add_test(runTests runTests)

# Source: https://github.com/google/googletest/tree/master/googletest#incorporating-into-an-existing-cmake-project
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
#add_executable(example example.cpp)
#target_link_libraries(example gtest_main)
#add_test(NAME example_test COMMAND example)

