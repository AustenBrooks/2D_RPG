#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <string>
#include "sprite.h"
#include "character.h"
#include "text.h"
#include "settings.h"

using std::vector;
using std::string;

class window {
private:
	SDL_Window* win;
	SDL_Renderer* renderer;

public:
	window();
	~window();

	void renderBackground(sprite background);
	void renderSprite(sprite s);
	void renderPlatforms(vector<sprite> platforms);
	void renderCharacter(character actor);
	void renderActors(vector<character> actors);
	void renderText(vector<text> allText);

	void drawFrame();

	SDL_Renderer* getRenderer();
};

#endif