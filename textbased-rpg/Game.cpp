#include "Game.h"

Game::Game()
{
	level = -1;
	player = new Player();
	player->setGame(this);
	player->getInventory()->addItem(new Items::PogoStick);
	initLevelEnemies();

	inputLoop();
	
	delete player;
}

void Game::initLevelEnemies() {
	enemies = new Enemy* [4];
	enemies[0] = new Enemies::Wolf();
	enemies[1] = new Enemies::Bear();
	enemies[2] = new Enemies::Goat();
	enemies[3] = new Enemies::Gnome();
}

void Game::endGame() {
	std::cout << "GAME OVER!\n";
	gameRunning = false;
}

Player* Game::getPlayer()
{
	return player;
}

Fight* Game::nextLevel() {
	level += 1;
	Fight* fight = new Fight(player, enemies[level]);
	return fight;
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

void Game::inputLoop() {
	gameRunning = true;
	int i = 0;
	while (gameRunning) {
		std::cout << "1. Check inventory\n" <<
			"2. Check stats\n" <<
			"3. Acquire steroids\n" <<
			"4. Use item\n" <<
			"5. Quit\n" <<
			"6. Equip item\n" <<
			"7. Fight a wolf\n" <<
			"8. Next Level\n";
		i++;
		int input = Input::getIntInput(1, 8);
		//system("cls");
		Items::Steroids* steroids;
		Item* item;
		Fight* fight;
		switch (input) {
		case 1:
			player->getInventory()->displayItems();
			break;
		case 2:
			player->displayStats();
			break;
		case 3:
			player->getInventory()->addItem(new Items::Steroids);
			break;
		case 4:
			item = player->getInventory()->itemSelection([](Item* i1) -> bool {
				return i1->getType() == Item::ItemType::Useable;
				});
			if(item)
				item->onUse(player);
			break;
		case 5:
			gameRunning = false;
			break;
		case 6:
			item = player->getInventory()->itemSelection([](Item* i1) -> bool {
				return i1->getType() == Item::ItemType::Equippable;
				});
			if (item)
				item->onEquip(player);
			break;
		case 7:
			fight = new Fight(player,new Enemies::Wolf());
			break;
		case 8:
			nextLevel();
			break;
		}
	}
}