cmake_minimum_required(VERSION 3.14)
project(PacmanSFML)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()

set(CMAKE_PREFIX_PATH C:/)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.h src/ResourceHandler.cpp src/ResourceHandler.h src/GameObjects/pac.cpp src/GameObjects/pac.h)

set(SOURCE_FILES
        src/main.cpp src/Game.cpp src/Game.h src/ResourceHandler.cpp src/ResourceHandler.h src/FreeFuncs.cpp
        src/ImageLayer.cpp src/LayerGroup.cpp src/Map.cpp src/miniz.c src/miniz.h src/Object.cpp src/ObjectGroup.cpp
        src/ObjectTypes.cpp src/Property.cpp src/TileLayer.cpp src/Tileset.cpp src/detail/pugixml.cpp src/GameObjects/GameObject.cpp src/GameObjects/GameObject.h src/GameObjects/pac.cpp src/GameObjects/pac.h src/GameObjects/coins.cpp src/GameObjects/coins.h src/GameObjects/BoundingBox.cpp src/GameObjects/BoundingBox.h src/GameObjects/Vector2.cpp src/GameObjects/Vector2.h  src/tile.cpp src/tile.h src/GameObjects/ship.h src/GameObjects/ship.cpp)

add_executable(PacmanSFML ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

target_link_libraries (PacmanSFML sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Data/)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)