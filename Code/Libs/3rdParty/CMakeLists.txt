cmake_minimum_required(VERSION 3.20)
project(3rdParty)

# grab includes
set(3RD_PARTY_INCLUDE_DIR "")

add_subdirectory(SDL)
set(3RD_PARTY_INCLUDE_DIR ${3RD_PARTY_INCLUDE_DIR} ${CMAKE_CURRENT_LIST_DIR}/SDL/include)

# set in parents scope
set(3RD_PARTY_INCLUDE_DIR ${3RD_PARTY_INCLUDE_DIR} PARENT_SCOPE)