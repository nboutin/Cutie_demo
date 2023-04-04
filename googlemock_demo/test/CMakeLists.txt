

add_cutie_test_target(
  NAME test_gmock_demo
  TEST ${CMAKE_CURRENT_LIST_DIR}/ut_gmock_demo.cpp
  SOURCES ${CMAKE_CURRENT_LIST_DIR}/../src/gmock_demo.c
  INCLUDE_DIRECTORIES ${CMAKE_CURRENT_LIST_DIR}/../include
  COMPILER_DEFINITIONS STATIC=
)
