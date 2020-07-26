#ifndef CHARACTER_H
#define CHARACTER_H

#include "sprite.h"
#include <string>
#include <iostream>

using std::string;

enum type {player, bandit, soldier, civilian};

enum animation {
	none,
	walkingLeft, walkingRight,
	walkingLeftStill, walkingRightStill,
	turning,
	crouching, jumping, falling
};

enum facing {up, down, left, right};

class character {
private:
	sprite charSprite;

	//combat stats
	int strength, endurance;
	int dexterity, agility;
	int wisdom, intelligence;

	int level, xp;

	float health, stamina, magic;
	float currentHealth, currentStamina, currentMagic;
	float healthRegen, staminaRegen, magicRegen;

	float damage, speed, armor;

	int attackFrame = 0;

	string name;

	//sprite + animation functions
	int animationFrame = 0;
	int jumpFrame = 0;
	animation currentAnimation = none;
	facing direction = right;

public:
	//constructors
	character();
	character(string name, type base);

	//class functions
	void moveTo(int xPos, int yPos);
	void moveBy(int xPos, int yPos);
	void createTexture(SDL_Renderer* renderer);
	
	//animation functions
	void animate();

	void walkRight();
	void walkRightStill();
	void turnRight();

	void walkLeft();
	void walkLeftStill();
	void turnLeft();

	void crouch();
	void jump();
	void fall();
	void bonk();

	void stop();

	//combat functions
	bool isAlive();
	bool canAct();
	void defendPhysical(float damage);
	float attack();
	void cast();
	void regen();
	void displayStats();

	//getters
	animation getCurrentAnimation();
	facing getDirection();
	sprite getSprite();

	//setters
	void setSpriteSheet(string filename, int spriteSheetX, int spriteSheetY);
};

#endif