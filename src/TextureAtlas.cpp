//
// Created by tursh on 2/25/23.
//

#include "TextureAtlas.h"

TextureAtlas::TextureAtlas(Texture2D atlasTexture, Vector2 atlasSize)
		: atlas(atlasTexture), atlasSize(atlasSize),
		  spriteSize({.x = (float) atlasTexture.width / atlasSize.x, .y = (float) atlasTexture.height / atlasSize.y})
{}

Rectangle TextureAtlas::getAtlasCoords(int index)
{
	return Rectangle{
			.x = (float) (index % (int) atlasSize.x) * spriteSize.x,
			.y = (float) (index / (int) atlasSize.y) * spriteSize.y,
			.width = spriteSize.x,
			.height = spriteSize.y
	};
}

void TextureAtlas::renderSprite(int index, Vector2 position)
{
	Rectangle atlasCoords = getAtlasCoords(index);

	DrawTextureRec(
			atlas,
			atlasCoords,
			position,
			WHITE
	);
}
