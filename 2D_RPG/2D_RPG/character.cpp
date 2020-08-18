#include "character.h"

//constructors
//default constructor should never be called, but is here just in case
character::character() {
	sprite charSprite;
	this->charSprite = charSprite;

	attribute.strength = 10;
	attribute.endurance = 10;
	attribute.dexterity = 10;
	attribute.agility = 10;
	attribute.wisdom = 10;
	attribute.intelligence= 10;

	level = 1;
	xp = 0;

	health = 50;
	stamina = 50;
	magic = 50;

	healthRegen = .001;
	staminaRegen = .01;
	magicRegen = .01;

	damage = 5;
	speed = 1;
	armor = 0;

	spellCost = 1;
	spellMag = 1;

	string name = "Bob";
}

character::character(string name, type base) {
	if (base == player) {
		sprite charSprite(0, 0, 32, 64, true, "Sprites/basic animations.png", 33, 0, 1);
		this->charSprite = charSprite;

		attribute.strength = 10;
		attribute.endurance = 10;
		attribute.dexterity = 10;
		attribute.agility = 10;
		attribute.wisdom = 10;
		attribute.intelligence = 10;

		level = 1;
		xp = 0;
		/*
		health = 50;
		stamina = 50;
		magic = 50;
		*/
		calcStats();

		currentHealth = health;
		currentStamina = stamina;
		currentMagic = magic;
		/*
		healthRegen = .001;
		staminaRegen = .01;
		magicRegen = .01;

		damage = 5;
		speed = 1;
		armor = 0;

		spellCost = 1;
		spellMag = 1;
		*/
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

void character::createTexture(SDL_Renderer* renderer) {
	if (charSprite.getNeedsUpdate()) {
		charSprite.createTexture(renderer);
	}
}

//animation functions
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
			charSprite.setAnimFrame(2);
		}
		else if (animationFrame <= 32) {
			charSprite.setAnimFrame(1);
		}
		else if (animationFrame <= 48) {
			charSprite.setAnimFrame(3);
		}
		else if (animationFrame <= 64) {
			charSprite.setAnimFrame(1);
		}
		else if (animationFrame > 64) {
			charSprite.setAnimFrame(1);
			animationFrame = 0;
			currentAnimation = none;
		}
		return;
	}
	if (currentAnimation == walkingRightStill) {
		animationFrame++;

		if (animationFrame <= 16) {
			charSprite.setAnimFrame(2);
		}
		else if (animationFrame <= 32) {
			charSprite.setAnimFrame(1);
		}
		else if (animationFrame <= 48) {
			charSprite.setAnimFrame(3);
		}
		else if (animationFrame <= 64) {
			charSprite.setAnimFrame(1);
		}
		else if (animationFrame > 64) {
			charSprite.setAnimFrame(1);
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
			charSprite.setAnimFrame(5);
		}
		else if (animationFrame <= 32) {
			charSprite.setAnimFrame(4);
		}
		else if (animationFrame <= 48) {
			charSprite.setAnimFrame(6);
		}
		else if (animationFrame <= 64) {
			charSprite.setAnimFrame(4);
		}
		else if (animationFrame > 64) {
			charSprite.setAnimFrame(4);
			animationFrame = 0;
			currentAnimation = none;
		}
		return;
	}
	if (currentAnimation == walkingLeftStill) {
		animationFrame++;

		if (animationFrame <= 16) {
			charSprite.setAnimFrame(5);
		}
		else if (animationFrame <= 32) {
			charSprite.setAnimFrame(4);
		}
		else if (animationFrame <= 48) {
			charSprite.setAnimFrame(6);
		}
		else if (animationFrame <= 64) {
			charSprite.setAnimFrame(4);
		}
		else if (animationFrame > 64) {
			charSprite.setAnimFrame(4);
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
				charSprite.setAnimFrame(8);
			}
			else if (direction == left) {
				if (!(animationFrame % 2)) {
					charSprite.moveBy(-1, 0);
				}
				charSprite.setAnimFrame(10);
			}
		}
		else if (animationFrame > jumpFrame) {
			jumpFrame = 0;
			animationFrame = 0;
			currentAnimation = falling;
		}
		return;
	}
	if (currentAnimation == jumpingStill) {
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
		}
		else if (animationFrame > jumpFrame) {
			jumpFrame = 0;
			animationFrame = 0;
			currentAnimation = fallingStill;
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
	if (currentAnimation == fallingStill) {
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
		return;
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
		charSprite.setAnimFrame(1);
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
		charSprite.setAnimFrame(4);
		direction = left;
		currentAnimation = turning;
		animationFrame = 0;
	}
}

void character::crouch() {
	if ((currentAnimation == none || currentAnimation == walkingRight || currentAnimation == walkingRightStill) && direction == right) {
		charSprite.setAnimFrame(7);
		currentAnimation = crouching;
		animationFrame = 0;
	}
	else if ((currentAnimation == none || currentAnimation == walkingLeft || currentAnimation == walkingLeftStill) && direction == left) {
		charSprite.setAnimFrame(9);
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

void character::vertJump() {
	currentAnimation = jumpingStill;
}

void character::vertFall() {
	currentAnimation = fallingStill;
}

void character::bonk() {
	direction = down;
}

void character::stop() {
	currentAnimation = none;
	animationFrame = 0;
	if (direction == right) {
		charSprite.setAnimFrame(1);
	}
	else if (direction == left) {
		charSprite.setAnimFrame(4);
	}
	else if (direction == down) {
		charSprite.setAnimFrame(0);
	}
}

//combat functions
bool character::isAlive() {
	if (currentHealth > 0) {
		return true;
	}
	return false;
}

bool character::canAct() {
	attackFrame++;
	if (attackFrame >= 300 / speed) {
		attackFrame = 300 / speed;
		return true;
	}
	return false;
}

void character::defendPhysical(float dmg) {
	float def = armor / (float)100;
	if (def > .85) {
		def = .85;
	}
	currentHealth -= (dmg - (dmg * def));
}

void character::defendMagical(float dmg) {
	currentHealth -= dmg;
}

float character::attack() {
	attackFrame = 0;
	float stamBoost = currentStamina / stamina;
	float dmg = damage * stamBoost;
	return dmg;
}

void character::potion() {
	currentHealth += 10;
	if (currentHealth > health) {
		currentHealth = health;
	}
	attackFrame = 0;
}

float character::cast(spells spell) {
	float magBoost = currentMagic / magic;
	if (spell == fireball) {
		if (currentMagic < (15*spellCost)) {
			return 0;
		}
		float dmg = (10 + 5 * magBoost) * spellMag;
		currentMagic -= 15 * spellCost;
		attackFrame = 0;
		return dmg;
	}
	else {
		//error if somehow no applicable spells are passed
		return 0;
	}
}


void character::regen() {
	currentHealth += healthRegen * health;
	currentStamina += staminaRegen * stamina;
	currentMagic += magicRegen * magic;

	if (currentHealth > health) {
		currentHealth = health;
	}
	if (currentStamina > stamina){
		currentStamina = stamina;
	}
	if (currentMagic > magic) {
		currentMagic = magic;
	}
}

string character::displayStats() {
	std::stringstream stream;
	stream << name << ": \n";
	stream << "HP: " << std::fixed << std::setprecision(2) << currentHealth << " / " << std::fixed << std::setprecision(2) << health << '\n';
	stream << "ST: " << std::fixed << std::setprecision(2) << currentStamina << " / " << std::fixed << std::setprecision(2) << stamina << '\n';
	stream << "MP: " << std::fixed << std::setprecision(2) << currentMagic << " / " << std::fixed << std::setprecision(2) << magic << '\n';

	string stats = stream.str();
	return stats;
}


//returns how many points the player will get to put into attrubutes
int character::gainXP(int xpGained) {
	int points = 0;
	
	xp += xpGained;
	while (xp > 100 * level) {
		xp -= 100 * level;
		level++;

		if (!(level % 5)) {
			points++;
		}
		if (!(level % 10)) {
			points++;
		}
		calcStats();
	}

	return points;
}

void character::levelAttributes(attributes increaseAttribute) {
	attribute.strength += increaseAttribute.strength;
	attribute.endurance += increaseAttribute.endurance;
	attribute.dexterity += increaseAttribute.dexterity;
	attribute.agility += increaseAttribute.agility;
	attribute.wisdom += increaseAttribute.wisdom;
	attribute.intelligence += increaseAttribute.intelligence;
}

void character::calcStats() {
	health = 5 * (attribute.endurance + level);
	stamina = 5 * (attribute.agility + level);
	magic = 5 * (attribute.intelligence + level);

	healthRegen = (float) attribute.strength / 10000.0;
	staminaRegen = (float) attribute.dexterity / 1000.0;
	magicRegen = (float) attribute.wisdom / 1000.0;

	damage = 5.0 * ((float) attribute.strength / 10.0);
	speed = (float) attribute.dexterity / 10.0;
	spellCost = 10.0 / (float) attribute.wisdom;

	spellMag = (float) attribute.intelligence / 10.0;
}

//getters
int character::getXpFromKill() {
	return level * 5;
}

attributes character::getAttribute() {
	return attribute;
}

animation character::getCurrentAnimation() {
	return currentAnimation;
}

facing character::getDirection() {
	return direction;
}

sprite character::getSprite() {
	return charSprite;
}

int character::getAnimationFrame() {
	return animationFrame;
}

//setters
void character::setSpriteSheet(string filename, int spriteSheetX, int spriteSheetY) {
	charSprite.setSpriteSheet(filename, spriteSheetX, spriteSheetY);
}

void character::setScale(float scaler) {
	charSprite.setScale(scaler);
}