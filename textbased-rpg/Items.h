#pragma once
#include "Stuff.h"
#include "Item.h"
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
	};

	class Cigarettes : public Item {
	public:
		Cigarettes() : Item(
			"",
			ItemType::Useable,
			"Smoke a pack (+1LU)",
			3
		) {

			name = std::string("Cigarete ");
			name += marke[rand() % 3] + " ";
			if (rand() % 2 == 0) {
				name += modeli[rand() % 3] + " ";
				if (rand() % 2 == 0) {
					name += sufiksi[rand() % 2] + " ";
				}
			}
			if (rand() % 4 == 0) name += "100 ";
			name += boje[rand() % 5] + " ";
			if (rand() % 2 == 0) name += duzine[rand() % 3] + " ";
			if (rand() % 3 == 0) name += "Slim ";
			name = name.substr(0, name.size() - 1);
			setConsumable(true);
		}
		void onUse(Entity* entity) override {
			Item::onUse(entity);
		}
	protected:
		const std::vector<std::string> marke = { "Winston", "Marlboro", "Lucky Strike" };
		const std::vector<std::string> modeli = { "Fine", "Extra Cut", "Compact" };
		const std::vector<std::string> sufiksi = { "Plus", "Refined" };
		const std::vector<std::string> duzine = { "L", "XL", "S" };
		const std::vector<std::string> boje = { "Plavi", "Zlatni", "Crni", "Crveni", "Srebrni" };
	};
}