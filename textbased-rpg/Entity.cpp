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

Entity* Entity::load(std::ifstream& stream)
{
	Entity* entity;
	EntityClass _entityClass;
	int _ec;
	stream >> _ec;
	_entityClass = (EntityClass)_ec;
	if (_entityClass == EntityClass::Entity) entity = new Entity();
	else if (_entityClass == EntityClass::Enemy) entity = new Enemy();
	else if (_entityClass == EntityClass::Player) entity = new Player();
	else if (_entityClass == EntityClass::Wolf) entity = new Enemies::Wolf();
	else if (_entityClass == EntityClass::Bear) entity = new Enemies::Bear();
	else if (_entityClass == EntityClass::Goat) entity = new Enemies::Goat();
	else if (_entityClass == EntityClass::Gnome) entity = new Enemies::Gnome();
}

void Entity::save(std::ofstream& stream) const
{
}

Entity::EntityClass Entity::getEntityClass() const
{
	return EntityClass::Entity;
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
