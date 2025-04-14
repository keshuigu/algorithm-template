cmake_minimum_required(VERSION 3.20)

project(algorithm-template VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

option(MAKE_TEST "Build algorithm-template's unit tests" ON)

set(PUBLIC_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/algorithm_template")

include_directories(
  "${PROJECT_BINARY_DIR}/include"

)

add_library(algorithm-template "")
target_sources(algorithm-template
  PUBLIC
    # header
    "${PUBLIC_INCLUDE_DIR}/bits_trick.h"

    # implements
    "implements/bits_trick.cc"

)

target_include_directories(algorithm-template
  PUBLIC
    "${PROJECT_SOURCE_DIR}/include"
)

set_target_properties(algorithm-template
  PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION ${PROJECT_VERSION_MAJOR}
)

# TEST

enable_testing()
set(install_gtest OFF)

add_subdirectory("third_party/googletest")

add_executable(algorithm-template-tests "")
target_sources(algorithm-template-tests
  PRIVATE
    "tests/bits_trick_test.cc"
)
target_link_libraries(algorithm-template-tests algorithm-template gtest gtest_main)
add_test(NAME "algorithm-template-tests" COMMAND "algorithm-template-tests")