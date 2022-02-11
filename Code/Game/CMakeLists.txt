cmake_minimum_required(VERSION 3.20)
project(Bawl)

include(CMakePrintHelpers)
cmake_print_variables(LIBS_INCLUDE_DIR)

set(CMAKE_CXX_STANDARD 20)

set(BAWL_SRC "")

# set srcs ( not sure if this is dumb )

set(BAWL_PCH
        Prefix/Bawl.pch)

set(BAWL_SRC
        ${BAWL_PCH}
        main.cpp
        Level/Level.cpp
        Display/Display.cpp
        ResourceManagement/TextureMap.cpp
)


add_executable(Bawl ${BAWL_SRC})

target_precompile_headers(Bawl PRIVATE  ${BAWL_PCH})

target_include_directories(Bawl PUBLIC ${LIBS_INCLUDE_DIR})

target_link_libraries(Bawl SDL2main SDL2-static)
