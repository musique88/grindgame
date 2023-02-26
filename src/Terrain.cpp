#include "Terrain.h"
#include <raylib.h>
#include <iostream>

Terrain::Terrain()
    :noise(1, 100)
{
    atlas = LoadTexture("tilemap_packed.png");
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

