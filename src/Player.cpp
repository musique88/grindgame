//
// Created by tursh on 2/25/23.
//

#include <raylib.h>
#include "Player.h"
#include "TextureAtlas.h"

Player::Player(const Vector2 &position, TextureAtlas &textureAtlas) : Entity(PLAYER, position, {.x = 25, .y = 50}, textureAtlas) {}

void Player::update()
{

}

void Player::render()
{
	textureAtlas.renderSprite((int) AtlasIndex::PLAYER, position);
}
