cmake_minimum_required(VERSION 3.20)
project(3rdParty)

add_subdirectory(SDL)
set(SDL_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/SDL/include)
