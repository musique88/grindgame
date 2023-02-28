//
// Created by tursh on 2/25/23.
//

#include "Scene.h"


Scene::Scene() {}

Scene::~Scene()
{
	for (auto entity: entities)
		Entity::deleteEntity(entity.second);
}

int Scene::createEntity(EntityType type, Vector2 position)
{
	Entity *newEntity = Entity::createEntity(type, position);
	int id = addEntity(newEntity);

	if(type == PLAYER)
		player = dynamic_cast<Player *>(newEntity);

	return id;
}

int Scene::deleteEntity(int id)
{
	auto it = entities.find(id);

	if (it == entities.end())
		return -1;

	Entity::deleteEntity(it->second);

	return 0;
}

int Scene::addEntity(Entity *entity)
{
	entities[entity->id] = entity;
	return entity->id;
}

void Scene::update()
{
	for (auto entity: entities)
	{
		entity.second->update();
	}
	terrain.move(player->position);
	terrain.update();
}

void Scene::render()
{
	camera.target = player->position;


	BeginMode2D(camera);

	terrain.render();

	for (auto entity: entities)
	{
		entity.second->render();
	}
	EndMode2D();

	DrawFPS(0, 0);
}
