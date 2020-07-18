#include "window.h"

window::window() {
	windowWidth = 1280;
	windowHeight = 720;

	SDL_CreateWindowAndRenderer(windowWidth, windowHeight, 0, &win, &renderer);
	SDL_SetWindowTitle(win, "Default");
}

window::window(int width, int height) {
	windowWidth = width;
	windowHeight = height;

	SDL_CreateWindowAndRenderer(windowWidth, windowHeight, SDL_WINDOW_RESIZABLE, &win, &renderer);
	SDL_SetWindowTitle(win, "RPG");

	SDL_RenderSetLogicalSize(renderer, width, height);
}

window::~window() {
	SDL_DestroyWindow(win);
}

void window::drawFrame(sprite background, vector<sprite> buttons) {
	SDL_RenderClear(renderer);

	renderSprite(background);

	for (int i = 0; i < buttons.size(); i++) {
		renderSprite(buttons.at(i));
	}

	SDL_RenderPresent(renderer);
}

void window::drawFrame(sprite background, vector<sprite> platforms, vector<character> actors) {
	SDL_RenderClear(renderer);

	renderSprite(background);

	for (int i = 0; i < platforms.size(); i++) {
		renderSprite(platforms.at(i));
	}

	for (int i = 0; i < actors.size(); i++) {
		renderSprite(actors.at(i).getSprite());
	}

	SDL_RenderPresent(renderer);
}

void window::renderSprite(sprite s) {
	SDL_Rect r;
	r.x = s.getSpriteX();
	r.y = s.getSpriteY();
	r.w = s.getRectangle().w;
	r.h = s.getRectangle().h;

	SDL_RenderCopy(renderer, s.getSpriteSheet(), &r, &s.getRectangle());
}

SDL_Renderer* window::getRenderer() {
	return renderer;
}