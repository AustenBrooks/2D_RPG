#ifndef CHARACTER_H
#define CHARACTER_H

#include "sprite.h"
#include <string>

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
	void animate();

	void attack();

	void walkRight();
	void walkRightStill();
	void turnRight();

	void walkLeft();
	void walkLeftStill();
	void turnLeft();

	void crouch();
	void jump();
	void fall();
	void stop();

	void bonk();

	void createTexture(SDL_Renderer* renderer);

	//getters
	animation getCurrentAnimation();
	facing getDirection();
	sprite getSprite();

	//setters
	void setCharSprite(string filename, int spriteSheetX, int spriteSheetY);
};

#endif