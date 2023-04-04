cmake_minimum_required(VERSION 3.14)
project(cutie_demo)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(cmake/get_cpm.cmake)
include(cmake/CPM.cmake)
include(cmake/cutie_config.cmake)

add_subdirectory(cutie_demo_lib)

# After add_subdirectory to collect all tests
add_cutie_all_tests_target()

if (NOT CMAKE_HOST_WIN32)
  add_cutie_coverage_targets() # Uses lcov
endif()

add_cutie_coverage_gcovr_targets()
add_cutie_coverage_gcovr_html_targets()
