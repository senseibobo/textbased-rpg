#pragma once
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
private:
	Player* player;
	void inputLoop();
	void debugStuff();
	bool gameRunning;
};

