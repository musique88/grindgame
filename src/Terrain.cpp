#include "Terrain.h"
#include "ResManager.h"
#include <raylib.h>
#include <iostream>

Terrain::Terrain()
		: noise(1, 100), atlas(ResManager::getInstance().getTexture(ResManager::TINY_DUNGEON_TEXTURE))
{
}

unsigned int Terrain::getTile(Vector2 position)
{
	return noise.noise(position.x, position.y) > 0.5 ? 1 : 0;
}

void Terrain::move(Vector2 position) 
{
    this->position = position;
}

Rectangle getRectangleFromIndex(unsigned int index)
{
	return {((float) (index % 12)) * 16, ((float) (index / 12)) * 16, 16, 16};
}

void Terrain::drawTile(Rectangle screenPosition, Vector2 mapPosition)
{
	Rectangle rect = getRectangleFromIndex(getTile(mapPosition) == 1 ? 14 : 0);
	DrawTextureTiled(
			atlas,
			getRectangleFromIndex(getTile(mapPosition) == 1 ? 14 : 0),
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

