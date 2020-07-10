#ifndef CHARACTER_H
#define CHARACTER_H

#include "sprite.h"
#include <string>

enum type {player, bandit, soldier, civilian};

class character : sprite{
private:
	sprite charSprite;

	int strength, endurance;
	int dexterity, agility;
	int wisdom, intelligence;

	int level;
	int xp;

	float health, stamina, magic;
	float healthRegen, staminaRegen, magicRegen;

	float damage;
	float speed;
	float armor;

	string name;

public:
	character();
	character(string name, type base);

	void setCharSprite(string filename, int spriteSheetX, int spriteSheetY);
	sprite getSprite();
};


#endif