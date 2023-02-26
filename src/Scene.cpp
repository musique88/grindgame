//
// Created by tursh on 2/25/23.
//

#include "Scene.h"

int Scene::createEntity(EntityType type, Vector2 position)
{
	Entity *newEntity = Entity::createEntity(type, position);
	int id = addEntity(newEntity);

	return id;
}

int Scene::deleteEntity(int id)
{
	auto it = entities.find(id);

	if(it == entities.end())
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
	for(auto entity : entities){
		entity.second->update();
	}
}

void Scene::render()
{
	for(auto entity : entities){
		entity.second->render();
	}
}
