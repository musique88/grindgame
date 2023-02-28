#include <raylib.h>
#include "Scene.h"

#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 438

int main(int argc, const char *argv[])
{
	InitWindow(WINDOW_HEIGHT, WINDOW_WIDTH, "Grind Game");

	Scene scene;

	Vector2 playerPosition{
			.x =  WINDOW_HEIGHT / 2.0f,
			.y =  WINDOW_WIDTH / 2.0f};

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
