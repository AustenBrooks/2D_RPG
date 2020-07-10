#ifndef CHARACTER_H
#define CHARACTER_H

#include "sprite.h"
#include <string>

using std::string;

enum type {player, bandit, soldier, civilian};

enum animation {
	none,
	walkingUp, walkingDown, walkingLeft, walkingRight,
	runningUp, runningDown, runningLeft, runningRight
};

enum facing {up, down, left, right};

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

	int animationFrame;
	animation currentAnimation;
	facing direction;

public:
	character();
	character(string name, type base);


	void moveTo(int xPos, int yPos);


	facing getDirection();

	void setCharSprite(string filename, int spriteSheetX, int spriteSheetY);
	sprite getSprite();
};


#endif