#include "Terrain.h"
#include "ResManager.h"
#include <raylib.h>
#include <iostream>
#include "Constants.h"
#include "TextureAtlas.h"

Terrain::Terrain()
		: noise(1, 100), atlas(ResManager::getInstance().getTextureAtlas(ATLAS_TINY_DUNGEON))
{
}

unsigned int Terrain::getTile(Vector2 position)
{
	return noise.noise(position.x, position.y) > 0.5 ? 1 : 0;
}

void Terrain::move(Vector2 position) 
{
	Vector2 tilePosition = {.x=position.x/TILE_SIZE, .y=position.y/TILE_SIZE};
    this->position = tilePosition;
}

void Terrain::drawTile(Rectangle screenPosition, Vector2 mapPosition)
{
	DrawTextureTiled(
			atlas.atlas,
			atlas.getAtlasCoords(getTile(mapPosition) == 1 ? (int)AtlasIndex::STONE_BLOCK: (int)AtlasIndex::DIRT_GROUND),
			screenPosition,
			{(float) 0, (float) 0},
			0.f,
			1.f,
			WHITE
	);
}

void Terrain::update()
{

}

void Terrain::render()
{
	for (int j = position.y - (renderSize / 2); j < position.y + (renderSize / 2); j++)
	{
		for (int i = position.x - (renderSize / 2); i < position.x + (renderSize / 2); i++)
		{
			drawTile({(float) i * 20, (float) j * 20, 20, 20}, {(float) i / 20.f, (float) j / 10.f});
		}
	}
}

