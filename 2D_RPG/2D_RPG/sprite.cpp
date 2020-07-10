#include "sprite.h"

sprite::sprite() {
	r.x = 0;
	r.y = 0;
	r.w = 16;
	r.h = 16;
	hasCollision = true;
	filepath = "Sprite/BLU.bmp";
	spriteX = 0;
	spriteY = 0;
	currentAnimation = none;
	direction = right;
	animationFrame = 0;
	doesSpriteNeedUpdate = true;
}

sprite::sprite(int x, int y, int w, int h, bool hasCollision, string filename, int spriteSheetX, int spriteSheetY) {
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	this->hasCollision = hasCollision;
	filepath = filename;
	spriteX = spriteSheetX;
	spriteY = spriteSheetY;
	currentAnimation = none;
	direction = down;
	animationFrame = 0;
	doesSpriteNeedUpdate = true;
	loadedSprite = IMG_Load(filepath.c_str());
}

//for setting background image
sprite::sprite(string filename) {
	r.x = 0;
	r.y = 0;
	r.w = 1280;
	r.h = 720;
	hasCollision = false;
	filepath = filename;
	spriteX = 0;
	spriteY = 0;
	currentAnimation = none;
	direction = down;
	animationFrame = 0;
	doesSpriteNeedUpdate = true;
	loadedSprite = IMG_Load(filepath.c_str());
}

void sprite::createTexture(SDL_Renderer* renderer) {
	SDL_Texture* spriteSheet = SDL_CreateTextureFromSurface(renderer, loadedSprite);
	this->spriteSheet = spriteSheet;
	doesSpriteNeedUpdate = false;
}

void sprite::moveTo(int posX, int posY) {
	r.x = posX;
	r.y = posY;
}

SDL_Rect sprite::getRectangle() {
	return r;
}

bool sprite::getCollision() {
	return hasCollision;
}

string sprite::getFilePath() {
	return filepath;
}

int sprite::getSpriteX() {
	return spriteX;
}

int sprite::getSpriteY() {
	return spriteY;
}

SDL_Texture* sprite::getSpriteSheet() {
	return spriteSheet;
}

bool sprite::getNeedsUpdate() {
	return doesSpriteNeedUpdate;
}

facing sprite::getDirection() {
	return direction;
}

void sprite::setSprite(int x, int y, int w, int h, bool hasCollision, string filename, int spriteSheetX, int spriteSheetY) {
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	this->hasCollision = hasCollision;
	filepath = filename;
	spriteX = spriteSheetX;
	spriteY = spriteSheetY;
	currentAnimation = none;
	direction = down;
	animationFrame = 0;
	doesSpriteNeedUpdate = true;
	loadedSprite = IMG_Load(filepath.c_str());
}

void sprite::setSpriteSheet(string filepath) {
	this->filepath = filepath;
	loadedSprite = IMG_Load(filepath.c_str());
	doesSpriteNeedUpdate = true;
}

