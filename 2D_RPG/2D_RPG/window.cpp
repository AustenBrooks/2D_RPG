#include "window.h"

window::window() {

	if (FULLSCREEN) {
		//this will stretch the window to fullscreen
		SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN, &win, &renderer);
	}
	else {
		SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE, &win, &renderer);
		SDL_SetWindowTitle(win, "RPG");

		SDL_RenderSetLogicalSize(renderer, 1280, 720);

		//integerscale will stop artifacting from resizable windows,
		//makes resize letterbox unless the render size and window size are perfectly scalable
		//SDL_RenderSetIntegerScale(renderer, SDL_TRUE);
	}
}

window::~window() {
	SDL_DestroyWindow(win);
}

void window::renderBackground(sprite background) {
	SDL_RenderClear(renderer);
	renderSprite(background);
}

void window::renderSprite(sprite s) {
	SDL_Rect r;
	r.x = s.getSpriteX();
	r.y = s.getSpriteY();
	r.w = s.getRectangle().w;
	r.h = s.getRectangle().h;

	SDL_Rect l;
	l = s.getRectangle();
	l.w = r.w * s.getScale();
	l.h = r.h * s.getScale();

	SDL_RenderCopy(renderer, s.getSpriteSheet(), &r, &l);
}

void window::renderPlatforms(vector<sprite> platforms) {
	for (int i = 0; i < platforms.size(); i++) {
		renderSprite(platforms.at(i));
	}
}

void window::renderCharacter(character actor) {
	renderSprite(actor.getSprite());
}

void window::renderActors(vector<character> actors) {
	for (int i = 0; i < actors.size(); i++) {
		renderSprite(actors.at(i).getSprite());
	}
}

void window::renderText(vector<text> allText) {
	for (int i = 0; i < allText.size(); i++) {
		vector<sprite> word = allText.at(i).getLetters();
		for (int j = 0; j < word.size(); j++) {
			renderSprite(word.at(j));
		}
	}
}

void window::drawFrame() {
	SDL_RenderPresent(renderer);
}

SDL_Renderer* window::getRenderer() {
	return renderer;
}