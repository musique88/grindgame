//
// Created by tursh on 2/25/23.
//

#include <raylib.h>
#include "Player.h"
#include "ResManager.h"

Player::Player(const Vector2 &position)
		: Entity(PLAYER, position, {.x = 25, .y = 50}), texture(ResManager::getInstance().getTextureAtlas(ATLAS_TINY_DUNGEON)) {}

void Player::update()
{
	if(IsKeyDown(KEY_W))
	{
		position.y--;
	} if(IsKeyDown(KEY_A)){
		position.x--;
	} if(IsKeyDown(KEY_S)){
		position.y++;
	} if(IsKeyDown(KEY_D)){
		position.x++;
	}
}

void Player::render()
{
	texture.renderSprite((int) AtlasIndex::PLAYER, position);
}
