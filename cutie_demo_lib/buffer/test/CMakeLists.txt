cmake_minimum_required(VERSION 3.15)
project(${PROJECT_NAME}_test LANGUAGES CXX C)

set(comp_name buffer)
# Get include directories from target
get_target_property(comp_inc_dir ${comp_name} INCLUDE_DIRECTORIES)

# Get sources files list from target
get_target_property(comp_sources_tmp ${comp_name} SOURCES)
foreach(item ${comp_sources_tmp})
  list(APPEND comp_sources ${CMAKE_CURRENT_LIST_DIR}/../${item})
endforeach()

# Get link libraries from target
# get_target_property(comp_link_libraries ${comp_name} LINK_LIBRARIES)

# Get compile definitions from target
# get_target_property(comp_compile_definitions ${comp_name} COMPILE_DEFINITIONS)

add_cutie_test_target(
  NAME ${PROJECT_NAME}
  TEST suites/test_buffer.cpp
  SOURCES ${comp_sources}
  INCLUDE_DIRECTORIES ${comp_inc_dir}
  COMPILER_DEFINITIONS ${comp_compile_definitions}
  LINK_LIBRARIES ${comp_link_libraries}
)
