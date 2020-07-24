#include "character.h"

//constructors
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
		sprite charSprite(0, 0, 32, 64, true, "Sprites/basic animations.png", 33, 0);
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

//functions
void character::moveTo(int xPos, int yPos) {
	charSprite.moveTo(xPos, yPos);
}

void character::moveBy(int xPos, int yPos) {
	charSprite.moveBy(xPos, yPos);
}

//returns bool to determine if player input should be ignored
void character::animate() {
	if (currentAnimation == none) {
		return;
	}
	if (currentAnimation == walkingRight) {
		animationFrame++;
		if (!(animationFrame % 3)) {
			charSprite.moveBy(1, 0);
		}

		if (animationFrame <= 16) {
			charSprite.setSpriteXY(66, 0);
		}
		else if (animationFrame <= 32) {
			charSprite.setSpriteXY(33, 0);
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
		return;
	}
	if (currentAnimation == walkingRightStill) {
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
		return;
	}
	if (currentAnimation == walkingLeft) {
		animationFrame++;
		if (!(animationFrame % 3)) {
			charSprite.moveBy(-1, 0);
		}

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
		return;
	}
	if (currentAnimation == walkingLeftStill) {
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
		return;
	}
	if (currentAnimation == turning) {
		animationFrame++;

		if (animationFrame == 16) {
			animationFrame = 0;
			currentAnimation = none;
		}
		return;
	}
	if (currentAnimation == crouching) {
		animationFrame++;
		if (animationFrame > 24) {
			animationFrame = 24;
		}
		return;
	}
	if (currentAnimation == jumping) {
		animationFrame++;

		if (animationFrame <= jumpFrame) {
			if (animationFrame < jumpFrame / 2) {
				charSprite.moveBy(0, -2);
			}
			else if (animationFrame < 3 * jumpFrame / 4) {
				charSprite.moveBy(0, -1);
			}
			else if (!(animationFrame % 2)) {
				charSprite.moveBy(0, -1);
			}

			if (direction == right) {
				if (!(animationFrame % 2)) {
					charSprite.moveBy(1, 0);
				}
				charSprite.setSpriteXY(264, 0);
			}
			else if (direction == left) {
				if (!(animationFrame % 2)) {
					charSprite.moveBy(-1, 0);
				}
				charSprite.setSpriteXY(330, 0);
			}
		}
		else if (animationFrame > jumpFrame) {
			jumpFrame = 0;
			animationFrame = 0;
			currentAnimation = falling;
		}
		return;
	}
	if (currentAnimation == falling) {
		animationFrame++;

		if (animationFrame < 12) {
			if (!(animationFrame % 2)) {
				charSprite.moveBy(0, 1);
			}
		}
		else if (animationFrame < 24) {
			charSprite.moveBy(0, 1);
		}
		else {
			charSprite.moveBy(0, 2);
		}

		if (direction == right) {
			if (!(animationFrame % 2)) {
				charSprite.moveBy(1, 0);
			}
		}
		else if (direction == left) {
			if (!(animationFrame % 2)) {
				charSprite.moveBy(-1, 0);
			}
		}
		return;
	}
}

void character::attack() {
	if (currentAnimation == none) {
		//currentAnimation = swinging;
	}
}

void character::walkRight() {
	if (currentAnimation == none && direction == right) {
		currentAnimation = walkingRight;
		return;
	}
	turnRight();	
}

void character::walkRightStill() {
	if (currentAnimation == none && direction == right) {
		currentAnimation = walkingRightStill;
		return;
	}
	turnRight();
}

void character::turnRight() {
	if (currentAnimation == none) {
		charSprite.setSpriteXY(33, 0);
		direction = right;
		currentAnimation = turning;
		animationFrame = 0;
	}
}

void character::walkLeft() {
	if (currentAnimation == none && direction == left) {
		currentAnimation = walkingLeft;
		return;
	}
	turnLeft();
}

void character::walkLeftStill() {
	if (currentAnimation == none && direction == left) {
		currentAnimation = walkingLeftStill;
		return;
	}
	turnLeft();
}

void character::turnLeft() {
	if (currentAnimation == none) {
		charSprite.setSpriteXY(132, 0);
		direction = left;
		currentAnimation = turning;
		animationFrame = 0;
	}
}

void character::crouch() {
	if ((currentAnimation == none || currentAnimation == walkingRight || currentAnimation == walkingRightStill) && direction == right) {
		charSprite.setSpriteXY(231, 0);
		currentAnimation = crouching;
		animationFrame = 0;
	}
	else if ((currentAnimation == none || currentAnimation == walkingLeft || currentAnimation == walkingLeftStill) && direction == left) {
		charSprite.setSpriteXY(297, 0);
		currentAnimation = crouching;
		animationFrame = 0;
	}
}

void character::jump() {
	if (currentAnimation == crouching) {
		currentAnimation = jumping;
		jumpFrame = animationFrame * 2;
		animationFrame = 0;
	}
}

void character::fall() {
	currentAnimation = falling;
	animationFrame = 0;
}

void character::stop() {
	currentAnimation = none;
	animationFrame = 0;
	if (direction == right) {
		charSprite.setSpriteXY(33, 0);
	}
	else if (direction == left) {
		charSprite.setSpriteXY(132, 0);
	}
	else if (direction == down) {
		charSprite.setSpriteXY(0, 0);
	}
}

void character::bonk() {
	direction = down;
}

void character::createTexture(SDL_Renderer* renderer) {
	charSprite.createTexture(renderer);
}

//getters
animation character::getCurrentAnimation() {
	return currentAnimation;
}

facing character::getDirection() {
	return direction;
}

sprite character::getSprite() {
	return charSprite;
}

//setters
void character::setCharSprite(string filename, int spriteSheetX, int spriteSheetY) {
	charSprite.setSpriteSheet(filename, spriteSheetX, spriteSheetY);
}