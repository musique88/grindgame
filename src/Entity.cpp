//
// Created by tursh on 2/25/23.
//

#include "Entity.h"
#include "Player.h"
#include "TextureAtlas.h"

static int entityCount = 0;

Entity::Entity(EntityType type, Vector2 position, Vector2 renderSize, TextureAtlas &textureAtlas)
		: id(entityCount++), type(type), position(position), renderSize(renderSize), textureAtlas(textureAtlas) {}

void Entity::deleteEntity(Entity *entity)
{
	switch (entity->type)
	{
		case PLAYER:
			delete (Player *) entity;
	}
}

Entity *Entity::createEntity(EntityType type, Vector2 position, TextureAtlas &textureAtlas)
{
	Entity *newEntity = nullptr;

	switch (type)
	{
		case PLAYER:
			newEntity = new Player(position, textureAtlas);
	}

	return newEntity;
}