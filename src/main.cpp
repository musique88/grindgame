#include <raylib.h>
#include "Scene.h"

#define WINDOW_HEIGTH 720
#define WINDOW_WIDTH 438

int main(int argc, const char *argv[])
{
	InitWindow(WINDOW_HEIGTH, WINDOW_WIDTH, "Grind Game");

	Scene scene;

	Vector2 playerPosition{
			.x =  (float) GetRandomValue(0, WINDOW_HEIGTH - 50),
			.y =  (float) GetRandomValue(0, WINDOW_WIDTH - 50)};

	scene.createEntity(PLAYER, playerPosition);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawText("Grind Game is now started", 720 / 2, 438 / 2, 20, GREEN);

		scene.update();
		scene.render();

		EndDrawing();
	}

	return 0;
}
