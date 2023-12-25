#pragma once
#include "Stuff.h"
#include "Inventory.h"
#include "Stats.h"

class Fight;

class Entity
{
public:
	Entity();
	void displayStats();
	Inventory& getInventory();
	virtual Stats& getStats();
	virtual int getHit(int damage, Entity* source);
	virtual int getHit(int damage);
	virtual void onDeath(Entity* source);
	virtual void onDeath();
	bool isDead() const;
	void setDead(int value);
	void setFight(Fight* fight);
	std::string getName() const;
protected:
	std::string name;
	Inventory inventory;
	Stats stats;
	Fight* fight; // stores nullptr if entity isn't fighting
	bool dead;
};

