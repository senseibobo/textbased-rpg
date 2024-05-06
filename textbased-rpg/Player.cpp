#include "Player.h"

Player::Player() : Entity() {
	create();
}

void Player::onDeath() {
	Entity::onDeath();
	game->endGame();
}

void Player::setGame(Game* game)
{
	this->game = game;
}

void Player::create() {
	std::string name;
	std::cout << "Enter your player name: ";
	std::cin >> name;
	std::cout << "(note: classes only affect the starting items and stats, none of this is permanent)\n";
	std::cout << "Choose a class:\n"
		<< "1. Knight\n"
		<< "2. Battle Mage\n"
		<< "3. Druid\n"
		<< "4. Ninja\n"
		<< "5. Trickster\n"
		<< "6. John\n";
	int classChosen = Input::getIntInput(1, 6);
	int s = 0, d = 0, a = 0, m = 0, l = 0;
	switch (classChosen) {
	case 1: s = 6; d = 8; a = 2; m = 1; l = 3; break; // Knight
	case 2: s = 5; d = 4; a = 3; m = 6; l = 2; break; // Battle Mage
	case 3: s = 2; d = 3; a = 3; m = 6; l = 6; break; // Druid
	case 4: s = 5; d = 2; a = 8; m = 2; l = 3; break; // Ninja
	case 5: s = 4; d = 2; a = 8; m = 1; l = 5; break; // Trickster
	case 6: s = 1; d = 1; a = 200; m = 1; l = 1; break; // John
	}
	this->name = name;
	stats = Stats(10,s,d,a,m,l);
}
