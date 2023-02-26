//
// Created by tursh on 2/25/23.
//

#ifndef GRINDGAME_SCENE_H
#define GRINDGAME_SCENE_H


#include <vector>
#include <unordered_map>
#include "Entity.h"
#include "Terrain.h"

class Scene
{
	// <id, ptr>
	std::unordered_map<int, Entity *> entities;

	Terrain terrain;

	Texture2D textureAtlas;

public:
	Scene();
	/**
	 * Create a entity
	 * @return The new entity id or -1 if an error occurred
	 */
	int createEntity(EntityType type, Vector2 position);

	/**
	 * Add entity in the scene scope -> Will be rendered and can be deleted by scene for optimisation
	 * @return The entity id or -1 if an error occurred
	 */
	int addEntity(Entity *entity);

	/**
	 * Delete entity with given id if in scene scope
	 * @return Success: 0, else error code
	 */
	int deleteEntity(int id);

	void update();

	void render();
};


#endif //GRINDGAME_SCENE_H
