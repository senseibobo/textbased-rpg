#include "Player.h"

Player::Player(std::string name, int strength, int defense, int agility, int magic, int luck) :
	Entity(name, strength, defense, agility, magic, luck) {
}

Player::Player() : Entity() {

}