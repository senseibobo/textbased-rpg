#include "Stats.h"

Stats::Stats() {
	strength = 0;
	defense = 0;
	agility = 0;
	magic = 0;
	luck = 0;
	health = 0;
	maxHealth = 0;
}

Stats::Stats(int health, int strength, int defense, int agility, int magic, int luck) : Stats()
{
	this->strength = strength;
	this->defense = defense;
	this->agility = agility;
	this->magic = magic;
	this->luck = luck;
	this->health = health;
	this->maxHealth = health;
}

void Stats::display() // this one doesn't display the entity's name, use the Entity::displayStats() method for that
{
	std::cout<<"HP: "<<health<<"/"<<maxHealth<<
		"\nStrength: " << strength <<
		"\nDefense: " << defense <<
		"\nAgility: " << agility <<
		"\nMagic: " << magic <<
		"\nLuck: " << luck << "\n";
}

void Stats::increaseStrength(int amount) {
	strength += amount;
}
void Stats::increaseDefense(int amount) {
	defense += amount;
}
void Stats::increaseAgility(int amount) {
	agility += amount;
}
void Stats::increaseMagic(int amount) {
	magic += amount;
}
void Stats::increaseLuck(int amount) {
	luck += amount;
}
void Stats::increaseHealth(int amount) {
	health += amount;
	if (health > maxHealth) health = maxHealth;
}
void Stats::increaseMaxHealth(int amount, bool increaseHealth) {
	maxHealth += amount;
	if (increaseHealth) this->increaseHealth(amount);
}

void Stats::decreaseStrength(int amount) {
	strength -= amount;
}
void Stats::decreaseDefense(int amount) {
	defense -= amount;
}
void Stats::decreaseAgility(int amount) {
	agility -= amount;
}
void Stats::decreaseMagic(int amount) {
	magic -= amount;
}
void Stats::decreaseLuck(int amount) {
	luck -= amount;
}
void Stats::decreaseHealth(int amount) {
	health -= amount;
	if (health <= 0) health = 0;
}
void Stats::decreaseMaxHealth(int amount, bool decreaseHealth) {
	maxHealth -= amount;
	if (decreaseHealth) this->decreaseHealth(amount);
}

int Stats::getStrength() {
	return strength;
}
int Stats::getDefense() {
	return defense;
}
int Stats::getAgility() {
	return agility;
}
int Stats::getMagic() {
	return magic;
}
int Stats::getLuck() {
	return luck;
}

int Stats::getHealth()
{
	return health;
}
int Stats::getMaxHealth()
{
	return maxHealth;
}