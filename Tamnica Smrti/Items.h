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
			"Jump on your enemies (+2ST) (+4AG)"
		) {}
		void onEquip(Entity* entity) override {
			entity->increaseStrength(2);
			entity->increaseAgility(4);
		}
		void onUnequip(Entity* entity) override {
			entity->decreaseStrength(2);
			entity->decreaseAgility(4);
		}
	};

	class Steroids : public Item {
	public:
		Steroids() : Item(
			"Steroids",
			ItemType::Useable,
			"Get some gains (+1ST)"
		) {
			setConsumable(true);
		}
		void onUse(Entity* entity) override {
			entity->increaseStrength(1);
			std::cout << "You used steroids! (+1ST) (-1BS)\n";
		}
	};
}