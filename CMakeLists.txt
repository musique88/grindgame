cmake_minimum_required(VERSION 3.0)

project(GrindGame)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Scene.cpp
        src/Scene.h
        src/Entity.cpp
        src/Entity.h
        src/Player.cpp
        src/Player.h
        src/Terrain.cpp
        src/Terrain.h
        src/SimplexNoise.cpp
        src/SimplexNoise.h
        src/TextureAtlas.cpp
        src/TextureAtlas.h)

target_link_libraries(${PROJECT_NAME} raylib)

# Copy resource folder in binary folder
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/res" "$<TARGET_FILE_DIR:${PROJECT_NAME}>/res")