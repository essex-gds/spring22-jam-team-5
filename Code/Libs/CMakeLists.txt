cmake_minimum_required(VERSION 3.20)
project(Libs)

set(LIBS_INCLUDE_DIR "")

add_subdirectory(3rdParty)
set(LIBS_INCLUDE_DIR ${LIBS_INCLUDE_DIR} ${3RD_PARTY_INCLUDE_DIR})

add_subdirectory(gUse)
set(LIBS_INCLUDE_DIR ${LIBS_INCLUDE_DIR} ${G_USE_INCLUDE_DIR})

set(LIBS_INCLUDE_DIR ${LIBS_INCLUDE_DIR} PARENT_SCOPE)