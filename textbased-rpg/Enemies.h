#pragma once
#include "Enemy.h"

namespace Enemies {
	class Wolf : public Enemy {
	public:
		Wolf() {
			name = "Wolf";
			stats = Stats(10, 2, 2, 6, 0, 0);
		}
	};
}