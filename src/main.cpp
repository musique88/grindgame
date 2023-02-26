#include <raylib.h>
#include "Scene.h"

#define WINDOW_HEIGTH 720
#define WINDOW_WIDTH 438

int main(int argc, const char *argv[])
{
	InitWindow(WINDOW_HEIGTH, WINDOW_WIDTH, "Grind Game");

	Scene scene;

	Vector2 playerPosition{
			.x =  (float) GetRandomValue(0, WINDOW_WIDTH),
			.y =  (float) GetRandomValue(0, WINDOW_HEIGTH)};

	scene.createEntity(PLAYER, playerPosition);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(LIGHTGRAY);

		scene.update();
		scene.render();

		EndDrawing();
	}

	return 0;
}
