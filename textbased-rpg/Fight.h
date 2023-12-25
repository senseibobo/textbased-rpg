#pragma once
#include "Stuff.h"
#include "Player.h"
class Fight
{
public:
	Fight(Player* player, Entity* enemy);
	~Fight();
	void attack(Entity* source, Entity* target);
private:
	Entity* enemy;
	Player* player;
	bool fighting;
};

