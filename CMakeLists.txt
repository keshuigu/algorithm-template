cmake_minimum_required(VERSION 3.20)

project(algorithm-template VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(MAKE_TEST "Build algorithm-template's unit tests" ON)

set(PUBLIC_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/algorithm_template")

include_directories(
  "${PROJECT_BINARY_DIR}/include"
)

file(GLOB HEADERS "${PUBLIC_INCLUDE_DIR}/*.h")
file(GLOB IMPLEMENTS "${PROJECT_SOURCE_DIR}/implements/*.cc")

add_library(algorithm-template "")
target_sources(algorithm-template
  PUBLIC
    # header
    ${HEADERS}
  PRIVATE
    # implements
    ${IMPLEMENTS}

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

file(GLOB TESTS "${PROJECT_SOURCE_DIR}/tests/*.cc")

add_executable(algorithm-template-tests "")
target_sources(algorithm-template-tests
  PRIVATE
    ${TESTS}
)
target_link_libraries(algorithm-template-tests algorithm-template gmock gtest gtest_main)
add_test(NAME "algorithm-template-tests" COMMAND "algorithm-template-tests")

function(addtests test_file)
    get_filename_component(test_target_name "${test_file}" NAME_WE)
    add_executable("${test_target_name}" "")
    target_sources("${test_target_name}"
      PRIVATE
        "${test_file}"
    )
    target_link_libraries("${test_target_name}" algorithm-template gmock gtest gtest_main)
    add_test(NAME "${test_target_name}" COMMAND "${test_target_name}")
endfunction()

# 为每个测试文件生成单独的测试可执行文件
foreach(TEST_FILE ${TESTS})
  addtests(${TEST_FILE})
endforeach()
