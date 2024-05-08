#pragma once
class Inventory;
class Player;
#include "Stuff.h"
#include "Inventory.h"
#include "Stats.h"
#include "Player.h"
#include "Enemies.h"

class Fight;

class Entity
{
public:
	enum class EntityClass {
		Entity,
		Enemy,
		Player,
		Wolf,
		Bear,
		Goat,
		Gnome
	};
	Entity();
	~Entity();
	void displayStats();
	Inventory* getInventory();
	virtual Stats& getStats();
	virtual int getHit(int damage, Entity* source);
	virtual int getHit(int damage);
	virtual void onDeath(Entity* source);
	virtual void onDeath();
	bool isDead() const;
	void setDead(int value);
	void setFight(Fight* fight);
	std::string getName() const;
	static Entity* load(std::ifstream& stream);
	void save(std::ofstream& stream) const;
	virtual EntityClass getEntityClass() const;
protected:
	std::string name;
	Inventory* inventory;
	Stats stats;
	Fight* fight; // stores nullptr if entity isn't fighting
	bool dead;
};

