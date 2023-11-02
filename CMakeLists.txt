cmake_minimum_required(VERSION 3.10)
project(leetcode)
set(CMAKE_CXX_STANDARD 17)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/src/base
)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)
add_executable(main main.cc ${SRC_FILES})