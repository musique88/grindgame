//
// Created by tursh on 2/25/23.
//

#include <raylib.h>
#include "Player.h"

Player::Player(const Vector2 &position) : Entity(PLAYER, position, {.x = 25, .y = 50}) {}

void Player::update()
{

}

void Player::render()
{
	DrawRectangleV(position, renderSize, BLUE);
}
