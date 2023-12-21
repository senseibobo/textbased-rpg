#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	Player(std::string name, int strength, int defense, int agility, int magic, int luck);
	Player();
	int rand;
private:
};

