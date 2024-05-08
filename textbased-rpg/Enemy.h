#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:
	EntityClass getEntityClass() const override {
		return EntityClass::Enemy;
	}
};

