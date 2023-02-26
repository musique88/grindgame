#include <raylib.h>
#include "Terrain.h"

int main(int argc, const char *argv[])
{
	InitWindow(720, 438, "Grind Game");
    Terrain terrain;
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
        for (int j = 0; j < 20; j++) {
            for (int i = 0; i < 20; i++) { 
                terrain.drawTile({(float)j * 20, (float)i * 20, 20, 20}, {(float)j / 20.f, (float)i/10.f});
            }
        }
        DrawFPS(0, 0);
		DrawText("Grind Game is now started", 720 / 2, 438 / 2, 20, GREEN);

		EndDrawing();
	}

	return 0;
}
