#include "Entity.h"

Entity::Entity() {
	name = "[Unnamed entity]";
	stats = Stats();
	dead = false;
	inventory = new Inventory();
	inventory->setOwner(this);
}

Entity::~Entity()
{
	delete inventory;
}


int Entity::getHit(int damage, Entity* source) {
	int damageTaken = std::max(1, damage - stats.getDefense());
	stats.decreaseHealth(damageTaken);
	if (stats.getHealth() <= 0) onDeath(source);
	return damageTaken;
}

int Entity::getHit(int damage)
{
	return getHit(damage, nullptr);
}

void Entity::onDeath(Entity* source) {
	onDeath();
}
void Entity::onDeath() {
	dead = true;
}

bool Entity::isDead() const
{
	return dead;
}

void Entity::setDead(int value)
{
	dead = value;
}

void Entity::setFight(Fight* fight)
{
	this->fight = fight;
}

std::string Entity::getName() const {
	return name;
}

void Entity::displayStats() {
	std::cout << name << "'s stats:\n";
	stats.display();
}

Inventory* Entity::getInventory()
{
	return inventory;
}

Stats& Entity::getStats()
{
	return stats;
}
