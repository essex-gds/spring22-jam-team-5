cmake_minimum_required(VERSION 3.20)

project(ProjectRoot)

set(CMAKE_CXX_STANDARD 20)

set(LIBS_INCLUDE_DIR "")

add_subdirectory(Libs)
add_subdirectory(Game)

