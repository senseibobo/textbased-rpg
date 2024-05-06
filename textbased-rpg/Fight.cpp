#include "Fight.h"

bool doubleMoveCheck(Entity* entity) {
	int agility = entity->getStats().getAgility();
	float s = (float)agility * (float)agility;
	float chance = s / (s + 350.0);
	float r = (float)(rand()) / (float)(RAND_MAX);
	bool doubleMove = r < chance;
	if (doubleMove)
		std::cout << entity->getName() << " gets another turn due to agility!\n";
	return doubleMove;
}

Fight::Fight(Player* player, Entity* enemy) {
	this->enemy = enemy;
	this->player = player;
	player->setFight(this);
	enemy->setFight(this);
	fighting = true;
	while (fighting) {
		Item* item;
		// player's turn
		do {
		std::cout << "You are fighting "<<enemy->getName()<<".\n";
		std::cout << "1. Attack\n" <<
			"2. Use item\n" <<
			"3. Equip/Unequip item\n" <<
			"4. Flee\n";
		int input = Input::getIntInput(1, 4);
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
		} while (fighting and doubleMoveCheck(player));
		if (!fighting) break;
		do {
			attack(enemy, player);
		} while (fighting and doubleMoveCheck(enemy));
	}
	delete this;
}
Fight::~Fight() {
	player->setFight(nullptr);
	enemy->setFight(nullptr);
	delete enemy;
}

void Fight::attack(Entity* source, Entity* target) {
	int sourceDamage = source->getStats().getStrength();

	// calculate critical
	int luck = source->getStats().getLuck();
	float s = (float)luck * (float)luck;
	float chance = s / (s + 500.0);
	float r = (float)(rand()) / (float)(RAND_MAX);
	if (r < chance) {
		sourceDamage *= 2;
		std::cout << "CRITICAL HIT!\n";
	}

	int damageTaken = target->getHit(sourceDamage, source);

	std::cout << source->getName() << " attacks " << 
		target->getName() << " for " << damageTaken << " damage.\n";

	std::cout << target->getName() << ": " << 
		target->getStats().getHealth() << "/" << 
		target->getStats().getMaxHealth() << "HP\n";

	if (target->isDead()) {
		std::cout << target->getName() << " died.\n";
		fighting = false;
	}
}
