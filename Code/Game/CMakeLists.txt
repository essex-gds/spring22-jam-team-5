cmake_minimum_required(VERSION 3.20)
project(Bawl)

include(CMakePrintHelpers)
cmake_print_variables(LIBS_INCLUDE_DIR)

set(CMAKE_CXX_STANDARD 20)

set(BAWL_SRC "")

set(BAWL_PCH
        Prefix/Bawl.pch)

set(BAWL_SRC
        ${BAWL_PCH}
        main.cpp
        Sys/NString.cpp
        Level/Level.cpp
        Display/Display.cpp
        Display/Camera.cpp
        ResourceManagement/TextureMap.cpp
        ResourceManagement/FileReader.cpp
        State/GameHandler.cpp

        State/StateStack.cpp
        State/States/EntryState.cpp
        State/States/TestState.cpp
        State/States/SpriteTransitionState.cpp
        State/States/EntityUpdateState.cpp
        State/States/TextChoiceState.cpp
        State/States/MainMenuState.cpp
        State/States/LevelLoadState.cpp
        State/States/GameState.cpp

        Entity/Entity.cpp
        Entity/Entities/EntityWithHealth.h
        Entity/Entities/Player.cpp
        Entity/Entities/Bullet.cpp
        Entity/Entities/ShipSpawnerEntity.cpp
        Entity/Entities/StandardShip.cpp
        Entity/Entities/SeekerShip.cpp
        Entity/Entities/bossShip.cpp

        Entity/Components/Timer.cpp
        Entity/Components/ColourShift.cpp
        Entity/Components/Pointer.cpp
        )

include_directories(
        Display
        Level
        Prefix
        ResourceManagement
        Sys
        State
        State/States
        Entity
        Entity/Entities
        Entity/Components
)

add_executable(Bawl ${BAWL_SRC})

target_precompile_headers(Bawl PRIVATE  ${BAWL_PCH})
target_include_directories(Bawl PUBLIC ${LIBS_INCLUDE_DIR})

target_link_libraries(Bawl SDL2main SDL2-static)
