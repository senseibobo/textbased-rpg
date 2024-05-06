#include "Fight.h"

Fight::Fight(Player* player, Entity* enemy) {
	this->enemy = enemy;
	this->player = player;
	player->setFight(this);
	enemy->setFight(this);
	fighting = true;
	while (fighting) {
		// player's turn
		std::cout << "You are fighting "<<enemy->getName()<<".\n";
		std::cout << "1. Attack\n" <<
			"2. Use item\n" <<
			"3. Equip/Unequip item\n" <<
			"4. Flee\n";
		int input = Input::getIntInput(1, 4);
		Item* item;
		switch (input) {
			case 1:
				attack(player, enemy);
				break;
			case 2:
				if (!player->getInventory()->selectUseItem()) continue;
				break;
			case 3:
				if (!player->getInventory()->selectEquipItem()) continue;
				break;
			case 4:
				fighting = false;
				break;
		}
		if (!fighting) break;
		attack(enemy, player);
	}
	delete this;
}
Fight::~Fight() {
	player->setFight(nullptr);
	enemy->setFight(nullptr);
	delete enemy;
}

void Fight::attack(Entity* source, Entity* target) {
	int damage = target->getHit(source->getStats().getStrength(), source);
	std::cout << source->getName() << " attacks " << target->getName() << " for " << damage << " damage.\n";
	std::cout << target->getName() << ": " << target->getStats().getHealth() << "/" << target->getStats().getMaxHealth() << "HP\n";
	if (target->isDead()) {
		std::cout << target->getName() << " died.\n";
		fighting = false;
	}
}
