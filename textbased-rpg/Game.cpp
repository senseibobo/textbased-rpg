#include "Game.h"

Game::Game()
{
	createPlayer();
	player->getInventory().addItem(new Items::PogoStick);
	inputLoop();
	delete player;
}

void Game::debugStuff() { // random debug stuff
	using namespace std;
	cout << "\n";
	player->displayStats();
	Item* pogo = new Items::PogoStick();
	cout << endl;
	pogo->displayInfo();
	cout << endl;
	pogo->onEquip(player);
	player->displayStats();
	Item* steroids = new Items::Steroids();
	steroids->onUse(player);
	player->displayStats();
}

void Game::createPlayer() {
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
	case 6: s = 1; d = 1; a = 1; m = 1; l = 1; break; // John
	}
	player = new Player(name,s,d,a,m,l);
}

void Game::inputLoop() {
	gameRunning = true;
	int i = 0;
	while (gameRunning) {
		std::cout << "1. Check inventory\n" <<
			"2. Check stats\n" <<
			"3. Acquire steroids\n" <<
			"4. Use item\n" <<
			"5. Quit\n" <<
			"6. Equip item\n";
		i++;
		int input = Input::getIntInput(1, 6);
		system("cls");
		Items::Steroids* steroids;
		Item* item;
		switch (input) {
		case 1:
			player->getInventory().displayItems();
			break;
		case 2:
			player->displayStats();
			break;
		case 3:
			player->getInventory().addItem(new Items::Steroids);
			break;
		case 4:
			item = player->getInventory().itemSelection([](Item* i1) -> bool {
				return i1->getType() == Item::ItemType::Useable;
				});
			item->onUse(player);
			break;
		case 5:
			gameRunning = false;
			break;
		case 6:
			item = player->getInventory().itemSelection([](Item* i1) -> bool {
				return i1->getType() == Item::ItemType::Equippable;
				});
			item->onEquip(player);
			break;
		}
	}
}