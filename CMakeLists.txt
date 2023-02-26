project(GrindGame)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Scene.cpp
        src/Scene.h
        src/Entity.cpp
        src/Entity.h
        src/Player.cpp
        src/Player.h)

target_link_libraries(${PROJECT_NAME} raylib)