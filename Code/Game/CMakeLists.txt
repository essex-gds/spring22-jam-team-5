cmake_minimum_required(VERSION 3.20)
project(MainGame)

add_executable(MainGame main.cpp)

target_include_directories(MainGame PUBLIC ${SDL_INCLUDE_DIR} )

target_link_libraries(MainGame SDL2main SDL2-static)
