#ifndef CHARACTER_H
#define CHARACTER_H

#include "sprite.h"
#include <string>

using std::string;

enum type {player, bandit, soldier, civilian};

enum animation {
	none,
	walkLeft, walkRight, turn,
	walkLeftStill, walkRightStill,
	jump, crouch, fall,
	swing
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

	int animationFrame = 0;
	animation currentAnimation = none;
	facing direction = right;

public:
	//constructors
	character();
	character(string name, type base);

	//class functions
	void moveTo(int xPos, int yPos);
	bool animate();

	void attack();

	void rightWalk();
	void rightWalkStill();
	void turnRight();

	void leftWalk();
	void leftWalkStill();
	void turnLeft();

	void createTexture(SDL_Renderer* renderer);

	//getters
	facing getDirection();
	sprite getSprite();

	//setters
	void setCharSprite(string filename, int spriteSheetX, int spriteSheetY);
};

#endif