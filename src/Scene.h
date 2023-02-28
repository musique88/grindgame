//
// Created by tursh on 2/25/23.
//

#ifndef GRINDGAME_SCENE_H
#define GRINDGAME_SCENE_H


#include <vector>
#include <unordered_map>
#include "Entity.h"
#include "Terrain.h"
#include "TextureAtlas.h"
#include "Player.h"

#define WINDOW_HEIGHT 720
#define WINDOW_WIDTH 438

class Scene
{
	// <id, ptr>
	std::unordered_map<int, Entity *> entities;

	Terrain terrain;

	Player *player;

	Camera2D camera{.offset={WINDOW_HEIGHT/2, WINDOW_WIDTH/2}, .target={0, 0}, .rotation=0, .zoom=1};

public:
	Scene();

	~Scene();

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
