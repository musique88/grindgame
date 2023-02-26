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

}

void Player::render()
{
	texture.renderSprite((int) AtlasIndex::PLAYER, position);
}
