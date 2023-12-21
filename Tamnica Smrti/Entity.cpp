#include "Entity.h"

Entity::Entity(std::string name, int strength, int defense, int agility, int magic, int luck):Entity() {
	this->name = name;
	this->strength = strength;
	this->defense = defense;
	this->agility = agility;
	this->magic = magic;
	this->luck = luck;
}

Entity::Entity() {
	name = "[Unnamed entity]";
	strength = 0;
	defense = 0;
	agility = 0;
	magic = 0;
	luck = 0;
	inventory = Inventory();
	inventory.setOwner(this);
}

void Entity::increaseStrength(int amount) {
	strength += amount;
}
void Entity::increaseDefense(int amount) {
	defense += amount;
}
void Entity::increaseAgility(int amount) {
	agility += amount;
}
void Entity::increaseMagic(int amount) {
	magic += amount;
}
void Entity::increaseLuck(int amount) {
	luck += amount;
}
void Entity::decreaseStrength(int amount) {
	strength -= amount;
}
void Entity::decreaseDefense(int amount) {
	defense -= amount;
}
void Entity::decreaseAgility(int amount) {
	agility -= amount;
}
void Entity::decreaseMagic(int amount) {
	magic -= amount;
}
void Entity::decreaseLuck(int amount) {
	luck -= amount;
}

void Entity::displayStats() {
	std::cout << name << "'s stats:" <<
		"\nStrength: " << strength <<
		"\nDefense: " << defense <<
		"\nAgility: " << agility <<
		"\nMagic: " << magic <<
		"\nLuck: " << luck << "\n";
}

Inventory& Entity::getInventory()
{
	return inventory;
}
