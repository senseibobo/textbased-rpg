#include "Item.h"

Item::Item() {
	this->name = "[Unnamed item]";
	this->type = ItemType::Equippable;
	description = "[No description]";
	consumable = false;
	equipped = false;
	cost = 0;
}

Item::Item(std::string name, ItemType type, std::string description, int cost) : Item() {
	this->name = name;
	this->type = type;
	this->description = description;
	this->cost = cost;
}

void Item::onEquip(Entity* entity)
{
	equipped = true;
}

void Item::onUnequip(Entity* entity)
{
	equipped = false;
}

void Item::onUse(Entity* entity) 
{
	std::cout << "Item succesfully used1\n";
	/*if (isConsumable()) {
		std::cout << "REMOVED";
		std::cin >> name;
		entity->getInventory()->removeItem(this);
	}*/
}

bool Item::isConsumable() const
{
	return type == ItemType::Useable and consumable;
}

bool Item::isEquipped() const
{
	return type == ItemType::Equippable and equipped;
}

void Item::displayInfo() const {
	std::string typeString = getTypeString();
	std::cout << "Item: " << name << "\n"<<
		description<<
		"\nType: " << typeString;
	if (isConsumable())
		std::cout << "\nConsumable";
	std::cout << "\n";
}

std::string Item::getTypeString() const {
	std::string typeString;
	switch (type) {
	case ItemType::Useable: typeString = "Useable"; break;
	case ItemType::Equippable: typeString = "Equippable"; break;
	case ItemType::Key: typeString = "Key"; break;
	case ItemType::Material: typeString = "Material"; break;
	}
	return typeString;
}

void Item::displayInlineInfo() const {
	std::string typeString = getTypeString();
	std::cout << "Item: " << name << ", Type: " << typeString;
	if (isConsumable()) std::cout << ", Consumable";
	std::cout << ", Description: " << description ;
	std::cout << "\n";
}

Item::ItemClass Item::getItemClass() const
{
	return ItemClass::Item;
}

std::string Item::getName()
{
	return name;
}

Item::ItemType Item::getType() {
	return type;
}

void Item::setConsumable(bool value) {
	consumable = value;
}

Item* Item::load(std::ifstream& stream)
{
	Item* item;
	ItemClass itemClass;
	int _itemClass;
	std::string _name;
	bool _equipped;
	stream >> _itemClass >> _name >> _equipped;
	itemClass = (ItemClass)_itemClass;
	switch (itemClass) {
	case ItemClass::Item:
		item = new Item();
		break;
	case ItemClass::PogoStick:
		item = new Items::PogoStick();
		break;
	case ItemClass::Cigarettes:
		item = new Items::Cigarettes();
		break;
	case ItemClass::Steroids:
		item = new Items::Steroids();
		break;
	}
	item->equipped = _equipped;
	replace_character(_name, '_', ' ');
	item->name = _name;
	return item;
}

void Item::save(std::ofstream& stream)
{
	ItemClass itemClass = getItemClass();

	std::string n2(name);
	replace_character(n2, ' ', '_');
	stream << (int)itemClass << " " << n2 << " " << equipped << "\n";
}

int Item::getCost()
{
	return cost;
}
