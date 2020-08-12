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

	//this will stretch the window to fullscreen
	//SDL_CreateWindowAndRenderer(windowWidth, windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN, &win, &renderer);
	
	SDL_CreateWindowAndRenderer(windowWidth, windowHeight, SDL_WINDOW_RESIZABLE, &win, &renderer);
	SDL_SetWindowTitle(win, "RPG");
	
	SDL_RenderSetLogicalSize(renderer, 1280, 720);

	//integerscale will stop artifacting from resizable windows,
	//makes resize letterbox unless the render size and window size are perfectly scalable
	//SDL_RenderSetIntegerScale(renderer, SDL_TRUE);
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

	for (int i = 1; i < actors.size(); i++) {
		renderSprite(actors.at(i).getSprite());
	}
	renderSprite(actors.at(0).getSprite());

	SDL_RenderPresent(renderer);
}

void window::drawFrame(sprite background, character player, character enemy, vector<sprite> letters) {
	SDL_RenderClear(renderer);
	renderSprite(background);

	renderSprite(player.getSprite());
	renderSprite(enemy.getSprite());

	for (int i = 0; i < letters.size(); i++) {
		renderSprite(letters.at(i));
	}
	
	SDL_RenderPresent(renderer);
}

void window::writeText(vector<sprite> text) {
	for (int i = 0; i < text.size(); i++) {
		renderSprite(text.at(i));
	}
	SDL_RenderPresent(renderer);
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

SDL_Renderer* window::getRenderer() {
	return renderer;
}