//
// Created by tursh on 2/25/23.
//

#ifndef GRINDGAME_ENTITY_H
#define GRINDGAME_ENTITY_H

#include <raylib.h>
#include "TextureAtlas.h"

enum EntityType
{
	PLAYER
};

class Entity
{
public:
	explicit Entity(EntityType type, Vector2 position, Vector2 renderSize, TextureAtlas &textureAtlas);

	const int id;
	const EntityType type;
	Vector2 position;
	Vector2 renderSize;
	TextureAtlas &textureAtlas;

	virtual void update() = 0;
	virtual void render() = 0;

	static Entity *createEntity(EntityType type, Vector2 position, TextureAtlas &textureAtlas);
	static void deleteEntity(Entity *entity);
};


#endif //GRINDGAME_ENTITY_H
