#pragma once
#include "Player.h"
#include "Input.h"
#include "Items.h"
class Game
{
public:
	Game();
private:
	Player* player;
	void createPlayer();
	void inputLoop();
	void debugStuff();
	bool gameRunning;
};

