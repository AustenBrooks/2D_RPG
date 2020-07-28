#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

using std::string;

class sprite {
private:
	SDL_Rect r;
	int spriteX;
	int spriteY;
	float scale = 1;
	bool hasCollision;

	string filepath;

	SDL_Surface* loadedSprite;
	SDL_Texture* spriteSheet;

	bool doesSpriteNeedUpdate;

public:
	//constructors
	sprite();
	sprite(int x, int y, int w, int h, bool hasCollision, string filename, int spriteSheetX, int spriteSheetY, float scale);
	sprite(string filename);
	sprite(int x, int y, int w, int h, bool hasCollision, string filename);
	sprite(int w, int h, bool hasCollision, string filename);

	//functions
	void createTexture(SDL_Renderer* renderer);
	void moveTo(int posX, int posY);
	void moveBy(int x, int y);

	//getters
	SDL_Rect getRectangle();
	bool getCollision();
	string getFilePath();
	int getSpriteX();
	int getSpriteY();
	float getScale();
	SDL_Texture* getSpriteSheet();
	bool getNeedsUpdate();

	//setters
	void setSprite(int x, int y, int w, int h, bool hasCollision, string filename, int spriteSheetX, int spriteSheetY, float scale);
	void setSpriteSheet(string filepath);
	void setSpriteSheet(string filepath, int spriteSheetX, int spriteSheetY);
	void setSpriteXY(int spriteSheetX, int spriteSheetY);
	void setAnimFrame(int numFrames);
};

#endif