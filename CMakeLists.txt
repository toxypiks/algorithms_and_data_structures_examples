cmake_minimum_required(VERSION 3.16)
project(byte_pair_encoding)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(QUICKSORT_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/quicksort.c
  )

add_executable(quicksort)
target_sources(quicksort
 PRIVATE
  ${QUICKSORT_SRC}
)

set(KNUTH_MORRIS_PRATT_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/knuth_morris_pratt.c
  )

add_executable(knuth_morris_pratt)
target_sources(knuth_morris_pratt
 PRIVATE
  ${KNUTH_MORRIS_PRATT_SRC}
)

set(INSERTION_SORT_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/insertion_sort.c
  )

add_executable(insertion_sort)
target_sources(insertion_sort
 PRIVATE
  ${INSERTION_SORT_SRC}
)

set(HEAP_SORT_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/heap_sort.c
  )

add_executable(heap_sort)
target_sources(heap_sort
 PRIVATE
  ${HEAP_SORT_SRC}
)

set(SINGLY_LINKED_LIST_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/singly_linked_list.c
  )

add_executable(singly_linked_list)
target_sources(singly_linked_list
 PRIVATE
  ${SINGLY_LINKED_LIST_SRC}
)

set(DOUBLY_LINKED_LIST_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/doubly_linked_list.c
  )

add_executable(doubly_linked_list)
target_sources(doubly_linked_list
 PRIVATE
  ${DOUBLY_LINKED_LIST_SRC}
)

set(BINARY_TREE_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/binary_tree.c
  )

add_executable(binary_tree)
target_sources(binary_tree
 PRIVATE
  ${BINARY_TREE_SRC}
)

set(AVL_TREE_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/avl_tree.c
  )

add_executable(avl_tree)
target_sources(avl_tree
 PRIVATE
  ${AVL_TREE_SRC}
)
