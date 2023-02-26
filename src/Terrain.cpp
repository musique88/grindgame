#include "Terrain.hpp"
#include <raylib.h>

Terrain::Terrain()
    :noise(1, 100)
{
    atlas = LoadTexture("tilemap_packed.png");
}

unsigned int Terrain::get_tile(Vector2 position) {
    return noise.noise(position.x, position.y) > 0.5 ? 1 : 0;
}

