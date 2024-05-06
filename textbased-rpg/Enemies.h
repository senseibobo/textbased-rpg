#pragma once
#include "Enemy.h"


// health strenght defense agility magic luck
namespace Enemies {
	class Wolf : public Enemy {
	public:
		Wolf() {
			name = "Wolf";
			stats = Stats(10, 2, 2, 6, 0, 0);
		}
	};
	class Bear : public Enemy {
	public:
		Bear() {
			name = "Bear";
			stats = Stats(40, 5, 4, 3, 0, 0);
		}
	};
	class Goat : public Enemy {
	public:
		Goat() {
			name = "Goat";
			stats = Stats(15, 7, 7, 8, 0, 5);
		}
	};
	class Gnome : public Enemy {
	public:
		Gnome() {
			name = "Gnome";
			stats = Stats(10, 3, 2, 20, 10, 10);
		}
	};
}