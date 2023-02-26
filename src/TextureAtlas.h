//
// Created by tursh on 2/25/23.
//

#ifndef GRINDGAME_TEXTUREATLAS_H
#define GRINDGAME_TEXTUREATLAS_H


#include <raylib.h>

/**
 * An atlas index is defined as x + y * atlas.width. x and y being the position from the top left corner
 * Ex.: 1 2 3
 *		4 5 6
 *		7 8 9
 */
enum class AtlasIndex {
	PLAYER = 84
};

struct TextureAtlas
{
	Texture2D atlas;
	Vector2 atlasSize;
	Vector2 spriteSize;

	TextureAtlas(Texture2D atlasTexture, Vector2 atlasSize);

	Rectangle getAtlasCoords(int index);

	void renderSprite(int index, Vector2 position);
};


#endif //GRINDGAME_TEXTUREATLAS_H
