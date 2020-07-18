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
		sprite charSprite(0, 0, 32, 64, true, "Sprites/basic animations.png", 0, 0);
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
	if (currentAnimation == walkRight) {
		if (!(animationFrame % 4)) {
			charSprite.moveBy(1, 0);
		}
		animationFrame++;

		if (animationFrame <= 16) {
			charSprite.setSpriteXY(66, 0);
		}
		else if (animationFrame <= 32) {
			charSprite.setSpriteXY(33, 0);
			if (animationFrame == 32) {
				currentAnimation = none;
			}
		}
		else if (animationFrame <= 48) {
			charSprite.setSpriteXY(99, 0);
		}
		else if (animationFrame <= 64) {
			charSprite.setSpriteXY(33, 0);
		}
		else if (animationFrame > 64) {
			charSprite.setSpriteXY(33, 0);
			animationFrame = 0;
			currentAnimation = none;
		}
		return true;
	}
	if (currentAnimation == walkRightStill) {
		animationFrame++;

		if (animationFrame <= 16) {
			charSprite.setSpriteXY(66, 0);
		}
		else if (animationFrame <= 32) {
			charSprite.setSpriteXY(33, 0);
			if (animationFrame == 32) {
				currentAnimation = none;
			}
		}
		else if (animationFrame <= 48) {
			charSprite.setSpriteXY(99, 0);
		}
		else if (animationFrame <= 64) {
			charSprite.setSpriteXY(33, 0);
		}
		else if (animationFrame > 64) {
			charSprite.setSpriteXY(33, 0);
			animationFrame = 0;
			currentAnimation = none;
		}
		return true;
	}
	if (currentAnimation == walkLeft) {
		if (animationFrame % 4 == 0) {
			charSprite.moveBy(-1, 0);
		}
		animationFrame++;

		if (animationFrame <= 16) {
			charSprite.setSpriteXY(165, 0);
		}
		else if (animationFrame <= 32) {
			charSprite.setSpriteXY(132, 0);
			if (animationFrame == 32) {
				currentAnimation = none;
			}
		}
		else if (animationFrame <= 48) {
			charSprite.setSpriteXY(198, 0);
		}
		else if (animationFrame <= 64) {
			charSprite.setSpriteXY(132, 0);
		}
		else if (animationFrame > 64) {
			charSprite.setSpriteXY(132, 0);
			animationFrame = 0;
			currentAnimation = none;
		}
		return true;
	}
	if (currentAnimation == walkLeftStill) {
		animationFrame++;

		if (animationFrame <= 16) {
			charSprite.setSpriteXY(165, 0);
		}
		else if (animationFrame <= 32) {
			charSprite.setSpriteXY(132, 0);
			if (animationFrame == 32) {
				currentAnimation = none;
			}
		}
		else if (animationFrame <= 48) {
			charSprite.setSpriteXY(198, 0);
		}
		else if (animationFrame <= 64) {
			charSprite.setSpriteXY(132, 0);
		}
		else if (animationFrame > 64) {
			charSprite.setSpriteXY(132, 0);
			animationFrame = 0;
			currentAnimation = none;
		}
		return true;
	}
	if (currentAnimation == turn) {
		if (animationFrame > 16) {
			animationFrame = 0;
		}
		animationFrame++;

		if (animationFrame == 16) {
			animationFrame = 0;
			currentAnimation = none;
		}
		return true;
	}
}

void character::attack() {
	if (currentAnimation == none) {
		currentAnimation = swing;
		return;
	}
}

void character::rightWalk() {
	if (currentAnimation == none && direction == right) {
		currentAnimation = walkRight;
		return;
	}
	turnRight();	
}

void character::rightWalkStill() {
	if (currentAnimation == none && direction == right) {
		currentAnimation = walkRightStill;
		return;
	}
	turnRight();
}

void character::turnRight() {
	if (currentAnimation == none) {
		charSprite.setSpriteXY(33, 0);
		direction = right;
		currentAnimation = turn;
		return;
	}
}

void character::leftWalk() {
	if (currentAnimation == none && direction == left) {
		currentAnimation = walkLeft;
		return;
	}
	turnLeft();
}

void character::leftWalkStill() {
	if (currentAnimation == none && direction == left) {
		currentAnimation = walkLeftStill;
		return;
	}
	turnLeft();
}

void character::turnLeft() {
	if (currentAnimation == none) {
		charSprite.setSpriteXY(132, 0);
		direction = left;
		currentAnimation = turn;
		return;
	}
}

void character::createTexture(SDL_Renderer* renderer) {
	charSprite.createTexture(renderer);
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