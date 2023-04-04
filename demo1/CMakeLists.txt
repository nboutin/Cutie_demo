
set(CMAKE_INCLUDE_CURRENT_DIR ON)

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
