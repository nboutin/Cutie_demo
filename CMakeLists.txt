cmake_minimum_required(VERSION 3.15)
project(Cutie_demo C CXX)

# add_compile_options(-Werror -Wall)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CUTIE_GTEST_XML ON)
set(CUTIE_GTEST_JSON ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CUTIE_DIR Cutie)
include(${CUTIE_DIR}/Cutie.cmake)

add_cutie_test_target(TEST test/test_list.cpp INCLUDE_DIRECTORIES inc)
add_cutie_test_target(TEST test/test_stack.cpp INCLUDE_DIRECTORIES inc)
add_cutie_test_target(TEST test/test_queue.cpp INCLUDE_DIRECTORIES inc)
add_cutie_test_target(TEST test/test_graph.cpp INCLUDE_DIRECTORIES inc)
add_cutie_test_target(TEST test/test_tree.cpp INCLUDE_DIRECTORIES inc)
add_cutie_test_target(TEST test/test_binary_search.cpp INCLUDE_DIRECTORIES inc)
add_cutie_test_target(TEST test/test_array_list.cpp INCLUDE_DIRECTORIES inc)
add_cutie_test_target(TEST test/test_merge_sort.cpp SOURCES src/merge_sort.c)
add_cutie_test_target(TEST test/test_string_builder.cpp SOURCES src/string_builder.cpp)
add_cutie_test_target(TEST test/test_min_heap.cpp SOURCES src/min_heap.cpp)
add_cutie_test_target(TEST test/test_hash_table.cpp SOURCES src/hash_table.c)

add_cutie_test_target(
  TEST comp/comp_b/test/test_comp_b.cpp
  SOURCES comp/comp_b/comp_b.c
  INCLUDE_DIRECTORIES comp/comp_b
  LINK_LIBRARIES comp_a)

add_cutie_all_tests_target()

if (NOT CMAKE_HOST_WIN32)
  add_cutie_coverage_targets() # Use lcov
endif()

add_cutie_coverage_gcovr_targets()
add_cutie_coverage_gcovr_html_targets()

add_subdirectory(comp/comp_a)
