#pragma once
class Player;
#include "Player.h"
#include "Input.h"
#include "Items.h"
#include "Enemies.h"
#include "Fight.h"
class Game
{
public:
	Game();
	Player* getPlayer();
	Fight* nextLevel();
	void endGame();
private:
	Player* player;
	void initLevelEnemies();
	void inputLoop();
	void debugStuff();
	bool gameRunning;
	int level;
	Enemy** enemies;
};

