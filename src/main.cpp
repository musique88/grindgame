#include <raylib.h>

int main(int argc, const char *argv[])
{
	InitWindow(720, 438, "Grind Game");

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(LIGHTGRAY);
		DrawText("Grind Game is now started", 720 / 2, 438 / 2, 20, GREEN);

		EndDrawing();
	}

	return 0;
}
