#pragma once
class Entity;
#include "Stuff.h"
#include "Entity.h"
namespace Items {
	class PogoStick;
	class Cigarettes;
	class Steroids;
}

#include "Items.h"

class Item
{
public:
	enum class ItemClass {
		Item,
		PogoStick,
		Steroids,
		Cigarettes
	};

	enum class ItemType {
		Useable,
		Equippable,
		Key,
		Material 
	};
	bool operator==(const Item& other) const { return &other == this; }
	bool operator==(const Item* other) const { return other == this; }
	
	Item();
	Item(std::string name, ItemType type, std::string description, int cost);
	virtual void onEquip(Entity* entity);
	virtual void onUnequip(Entity* entity);
	virtual void onUse(Entity* entity);
	virtual bool isConsumable() const;
	virtual bool isEquipped() const;
	virtual void displayInfo() const;
	virtual void displayInlineInfo() const;
	virtual ItemClass getItemClass() const;
	std::string getName();
	Item::ItemType getType();
	int getCost();
	void setConsumable(bool value);
	static Item* load(std::ifstream& stream);
	void save(std::ofstream& stream);
protected:
	std::string name;
	std::string description;
	ItemType type;
	bool consumable;
	bool equipped;
	int cost;
	std::string getTypeString() const;
};

