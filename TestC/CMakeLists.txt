cmake_minimum_required(VERSION 3.27.0)
project(Exam1)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

include_directories(src/read_only)
include_directories(src/part1)
include_directories(src/part2)

enable_testing()

add_subdirectory(test)
add_subdirectory(src/read_only)
add_subdirectory(src/part1)
add_subdirectory(src/part2)
