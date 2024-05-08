#pragma once
#include "Stuff.h"
class Item;
#include "Item.h"
class Entity;
#include "Entity.h"

namespace Items {
	class PogoStick : public Item {
	public:
		PogoStick() : Item(
			"Pogo Stick", 
			ItemType::Equippable,
			"Jump on your enemies (+2ST) (+4AG)",
			10
		) {}
		void onEquip(Entity* entity) override {
			Item::onEquip(entity);
			entity->getStats().increaseStrength(2);
			entity->getStats().increaseAgility(4);
		}
		void onUnequip(Entity* entity) override {
			Item::onUnequip(entity);
			entity->getStats().decreaseStrength(2);
			entity->getStats().decreaseAgility(4);
		}
		ItemClass getItemClass() const override {
			return ItemClass::PogoStick;
		}
 	};

	class Steroids : public Item {
	public:
		Steroids() : Item(
			"Steroids",
			ItemType::Useable,
			"Get some gains (+1ST)",
			5
		) {
			setConsumable(true);
		}
		void onUse(Entity* entity) override {
			Item::onUse(entity);
			entity->getStats().increaseStrength(1);
			std::cout << "You used steroids! (+1ST) (-1BS)\n";
		}
		ItemClass getItemClass() const override {
			return ItemClass::Steroids;
		}
	};

	class Cigarettes : public Item {
	public:
		Cigarettes() : Item(
			"",
			ItemType::Useable,
			"Smoke a cigarette (-1HP) (+1LU)",
			3
		) {

			name = std::string("Cigarettes ");
			name += marke[rand() % marke.size()] + " ";
			if (rand() % 2 == 0) {
				name += modeli[rand() % modeli.size()] + " ";
				if (rand() % 2 == 0)
					name += sufiksi[rand() % sufiksi.size()] + " ";
			}
			if (rand() % 4 == 0) name += "100's ";
			if (rand() % 2 == 0) name += boje[rand() % boje.size()] + " ";
			if (rand() % 2 == 0) name += duzine[rand() % duzine.size()] + " ";
			if (rand() % 3 == 0) name += "Slim ";
			name = name.substr(0, name.size() - 1);
			setConsumable(true);
		}
		
		void onUse(Entity* entity) override {
			Item::onUse(entity);
			entity->getStats().increaseLuck(1);
			entity->getStats().decreaseHealth(1);
			if (entity->getStats().getHealth() == 0) {
				entity->getStats().increaseHealth(1);
				std::cout << "You almost die from the cigarette.";
			}
			std::cout << "You smoke a cigarette. You feel disgusting! (-1HP) (+1LU)\n";
		}
		ItemClass getItemClass() const override {
			return ItemClass::Cigarettes;
		}
	protected:
		const std::vector<std::string> marke = { "Winston", "Marlboro", "Lucky Strike" };
		const std::vector<std::string> modeli = { "Fine", "Extra Cut", "Compact", "Extra Flavor"};
		const std::vector<std::string> sufiksi = { "Plus", "Refined" };
		const std::vector<std::string> duzine = { "L", "XL", "S" };
		const std::vector<std::string> boje = { "Blue", "Gold", "Black", "Red", "Silver" };
	};
}