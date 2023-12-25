#pragma once
#include "Stuff.h"
class Stats
{
public:
	Stats();
	Stats(int health, int strength, int defense, int agility, int magic, int luck);
	void display();
	void increaseStrength(int amount);
	void increaseDefense(int amount);
	void increaseAgility(int amount);
	void increaseMagic(int amount);
	void increaseLuck(int amount);
	void increaseHealth(int amount);
	void increaseMaxHealth(int amount, bool increaseHealth);
	void decreaseStrength(int amount);
	void decreaseDefense(int amount);
	void decreaseAgility(int amount);
	void decreaseMagic(int amount);
	void decreaseLuck(int amount);
	void decreaseHealth(int amount);
	void decreaseMaxHealth(int amount, bool decreaseHealth);
	int getStrength();
	int getDefense();
	int getAgility();
	int getMagic();
	int getLuck();
	int getHealth();
	int getMaxHealth();
private:
	int strength;
	int defense;
	int agility;
	int magic;
	int luck;
	int maxHealth;
	int health;
};

