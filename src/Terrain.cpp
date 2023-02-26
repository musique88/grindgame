#include "Terrain.h"
#include <raylib.h>
#include <iostream>

Terrain::Terrain(Texture2D &textureAtlas)
    :noise(1, 100), atlas(textureAtlas)
{
}

unsigned int Terrain::getTile(Vector2 position) {
    return noise.noise(position.x, position.y) > 0.5 ? 1 : 0;
}

Rectangle getRectangleFromIndex(unsigned int index) {
    return {((float)(index % 12)) * 16, ((float)(index / 12)) * 16, 16, 16};
}

void Terrain::drawTile(Rectangle screenPosition, Vector2 mapPosition) {
    Rectangle rect = getRectangleFromIndex(getTile(mapPosition) == 1 ? 14 : 0);
    DrawTextureTiled(
        atlas, 
        getRectangleFromIndex(getTile(mapPosition) == 1 ? 14 : 0), 
        screenPosition, 
        {(float)0, (float)0}, 
        0.f, 
        1.f, 
        WHITE
    );
}

void Terrain::render()
{
	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 20; i++)
		{
			drawTile({(float) j * 20, (float) i * 20, 20, 20}, {(float) j / 20.f, (float) i / 10.f});
		}
	}
}

