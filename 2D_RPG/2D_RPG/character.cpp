#include "character.h"

//default constructor should never be called, but is here just in case
character::character() {
	sprite charSprite;
	this->charSprite = charSprite;

	strength = 10;
	endurance = 10;
	dexterity = 10;
	agility = 10;
	wisdom = 10;
	intelligence= 10;

	level = 1;
	xp = 0;

	health = 50;
	stamina = 50;
	magic = 50;

	healthRegen = 1;
	staminaRegen = 1;
	magicRegen = 1;

	damage = 5;
	speed = 1;
	armor = 0;

	string name = "Bob";
}

character::character(string name, type base) {
	if (base == player) {
		sprite charSprite(0, 0, 32, 64, true, "Sprites/Mario.png", 2, 2);
		this->charSprite = charSprite;

		strength = 10;
		endurance = 10;
		dexterity = 10;
		agility = 10;
		wisdom = 10;
		intelligence = 10;

		level = 1;
		xp = 0;

		health = 50;
		stamina = 50;
		magic = 50;

		healthRegen = 1;
		staminaRegen = 1;
		magicRegen = 1;

		damage = 5;
		speed = 1;
		armor = 0;
	}

	this->name = name;
}

void character::moveTo(int xPos, int yPos) {
	charSprite.moveTo(xPos, yPos);
}

//returns bool to determine if player input should be ignored
bool character::animate() {
	if (currentAnimation == none) {
		return false;
	}
	else if (currentAnimation == swing && direction == right) {
		animationFrame++;
		if (animationFrame <= 2) {
			charSprite.setSpriteXY(444, 2);
		}
		else if (animationFrame <= 4) {
			charSprite.setSpriteXY(478, 2);
		}
		else if (animationFrame <= 6) {
			charSprite.setSpriteXY(512, 2);
		}
		else if (animationFrame <= 10) {
			charSprite.setSpriteXY(546, 2);
		}
		if (animationFrame > 10) {
			charSprite.setSpriteXY(2, 2);
			animationFrame = 0;
			currentAnimation = none;
		}
	}
}

void character::attack() {
	if (currentAnimation == none) {
		currentAnimation = swing;
	}
}

facing character::getDirection() {
	return direction;
}

sprite character::getSprite() {
	return charSprite;
}

void character::setCharSprite(string filename, int spriteSheetX, int spriteSheetY) {
	charSprite.setSpriteSheet(filename, spriteSheetX, spriteSheetY);
}