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
		sprite charSprite(0, 0, 32, 64, true, "Sprites/Mario x2.png", 2, 2);
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

void character::setCharSprite(string filename, int spriteSheetX, int spriteSheetY) {
	SDL_Rect r;
	r = this->charSprite.getRectangle();
	sprite charSprite(r.x, r.y, r.w, r.h, this->charSprite.getCollision(), filename, spriteSheetX, spriteSheetY);
	this->charSprite = charSprite;
}
sprite character::getSprite() {
	return charSprite;
}
