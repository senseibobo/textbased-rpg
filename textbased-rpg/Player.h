#pragma once
class Game;
#include "Entity.h"
#include "Game.h"
class Player : public Entity
{
public:
	Player();
	void onDeath();
	void create();
	void setGame(Game* game);
	EntityClass getEntityClass() const override {
		return EntityClass::Player;
	}
private:
	Game* game;
};

