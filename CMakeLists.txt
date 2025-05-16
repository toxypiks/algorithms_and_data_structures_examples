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
