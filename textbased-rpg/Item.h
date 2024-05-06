#pragma once
class Entity;
#include "Stuff.h"
#include "Entity.h"

class Item
{
public:
	enum class ItemType {
		Useable,
		Equippable,
		Key,
		Material 
	};
	bool operator==(const Item& other) const { return &other == this; }
	bool operator==(const Item* other) const { return other == this; }
	
	Item();
	Item(std::string name, ItemType type, std::string description);
	virtual void onEquip(Entity* entity);
	virtual void onUnequip(Entity* entity);
	virtual void onUse(Entity* entity);
	virtual bool isConsumable() const;
	virtual bool isEquipped() const;
	virtual void displayInfo() const;
	virtual void displayInlineInfo() const;
	std::string getName();
	Item::ItemType getType();
	void setConsumable(bool value);
	void setEquippable(bool value);
protected:
	std::string name;
	std::string description;
	ItemType type;
	bool consumable;
	bool equipped;
	std::string getTypeString() const;
};

