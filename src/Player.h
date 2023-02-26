//
// Created by tursh on 2/25/23.
//

#ifndef GRINDGAME_PLAYER_H
#define GRINDGAME_PLAYER_H


#include "Entity.h"

class Player : public Entity
{
public:
	Player(const Vector2 &position);

	void update() override;

	void render() override;
};


#endif //GRINDGAME_PLAYER_H
