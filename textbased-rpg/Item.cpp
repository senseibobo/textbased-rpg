#include "Item.h"

Item::Item() {
	this->name = "[Unnamed item]";
	this->type = ItemType::Equippable;
	description = "[No description]";
	consumable = false;
	equipped = false;
}

Item::Item(std::string name, ItemType type, std::string description) : Item() {
	this->name = name;
	this->type = type;
	this->description = description;
}

void Item::onEquip(Entity* entity)
{
	equipped = true;
}

void Item::onUnequip(Entity* entity)
{
	equipped = false;
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
