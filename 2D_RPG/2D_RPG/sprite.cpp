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
	doesSpriteNeedUpdate = true;
}

sprite::sprite(int x, int y, int w, int h, bool hasCollision, string filename, int spriteSheetX, int spriteSheetY, float scale) {
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	this->hasCollision = hasCollision;
	filepath = filename;
	spriteX = spriteSheetX;
	spriteY = spriteSheetY;
	this->scale = scale;
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
	doesSpriteNeedUpdate = true;
	loadedSprite = IMG_Load(filepath.c_str());
}

//for creating objects/platforms
sprite::sprite(int x, int y, int w, int h, bool hasCollision, string filename) {
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	this->hasCollision = hasCollision;
	filepath = filename;
	spriteX = 0;
	spriteY = 0;
	doesSpriteNeedUpdate = true;
	loadedSprite = IMG_Load(filepath.c_str());
}

sprite::sprite(int w, int h, bool hasCollision, string filename) {
	r.x = 0;
	r.y = 0;
	r.w = w;
	r.h = h;
	this->hasCollision = hasCollision;
	filepath = filename;
	spriteX = 0;
	spriteY = 0;
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

void sprite::moveBy(int x, int y) {
	r.x += x;
	r.y += y;
	if (r.x < 0) {
		r.x = 0;
	}
	if (r.y < 0) {
		r.y = 0;
	}
	if (r.x > (1280 - r.w)) {
		r.x = (1280 - r.w);
	}
	if (r.y > (720 - r.h)) {
		r.y = (720 - r.h);
	}
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

float sprite::getScale() {
	return scale;
}

SDL_Texture* sprite::getSpriteSheet() {
	return spriteSheet;
}

bool sprite::getNeedsUpdate() {
	return doesSpriteNeedUpdate;
}

void sprite::setSprite(int x, int y, int w, int h, bool hasCollision, string filename, int spriteSheetX, int spriteSheetY, float scale) {
	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	this->hasCollision = hasCollision;
	filepath = filename;
	spriteX = spriteSheetX;
	spriteY = spriteSheetY;
	this->scale = scale;
	doesSpriteNeedUpdate = true;
	loadedSprite = IMG_Load(filepath.c_str());
}

void sprite::setSpriteSheet(string filepath) {
	this->filepath = filepath;
	loadedSprite = IMG_Load(filepath.c_str());
	doesSpriteNeedUpdate = true;
}

void sprite::setSpriteSheet(string filepath, int spriteSheetX, int spriteSheetY) {
	spriteX = spriteSheetX;
	spriteY = spriteSheetY;

	this->filepath = filepath;
	loadedSprite = IMG_Load(filepath.c_str());
	doesSpriteNeedUpdate = true;
}

void sprite::setSpriteXY(int spriteSheetX, int spriteSheetY) {
	spriteX = spriteSheetX;
	spriteY = spriteSheetY;
}

void sprite::setAnimFrame(int numFrames) {
	spriteX = numFrames * (r.w + 1);
}