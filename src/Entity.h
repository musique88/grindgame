//
// Created by tursh on 2/25/23.
//

#ifndef GRINDGAME_ENTITY_H
#define GRINDGAME_ENTITY_H

#include <raylib.h>

enum EntityType
{
	PLAYER
};

class Entity
{
public:
	explicit Entity(EntityType type, Vector2 position, Vector2 renderSize);

	const int id;
	const EntityType type;
	Vector2 position;
	Vector2 renderSize;

	virtual void update() = 0;
	virtual void render() = 0;

	static Entity *createEntity(EntityType type, Vector2 position);
	static void deleteEntity(Entity *entity);
};


#endif //GRINDGAME_ENTITY_H
