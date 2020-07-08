#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <string>
#include "sprite.h"
#include "character.h"

using std::vector;
using std::string;

class window {
private:
	SDL_Window* win;
	SDL_Renderer* renderer;

	int windowWidth;
	int windowHeight;

public:
	window();
	window(int width, int height);
	~window();

	void drawFrame(sprite background, vector<sprite> platforms, vector<sprite> actors);
	void renderSprite(sprite s);

	SDL_Renderer* getRenderer();
};


#endif