#pragma once
#include "Stuff.h"
#include "Inventory.h"

class Entity
{
public:
	Entity();
	Entity(std::string name, int strength, int defense, int agility, int magic, int luck);
	void displayStats();
	Inventory& getInventory();
	void increaseStrength(int amount);
	void increaseDefense(int amount);
	void increaseAgility(int amount);
	void increaseMagic(int amount);
	void increaseLuck(int amount);
	void decreaseStrength(int amount);
	void decreaseDefense(int amount);
	void decreaseAgility(int amount);
	void decreaseMagic(int amount);
	void decreaseLuck(int amount);
private:
	std::string name;
	int strength;
	int defense;
	int agility;
	int magic;
	int luck;
	Inventory inventory;
};

