#include <SDL.h>
#include "window.h"
#include "input.h"
#include "game.h"
#include "sprite.h"
#include "character.h"

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Event events;
	window newWindow(1280, 720);
	input inputs;

	sprite background("Sprites/forest.png");
	vector<sprite> platforms;
	vector<character> actors;

	character player("austen", player);
	player.moveTo(120, 600);
	actors.push_back(player);

	bool isMainMenu = true;
	bool isQuitting = false;

	while (1) {	
		if (isMainMenu) {
			isQuitting = mainMenu(newWindow, inputs);
			isMainMenu = false;
		}

		if (isQuitting) {
			break;
		}
		
		int timeStart = SDL_GetTicks();
		int elapsedTime = SDL_GetTicks() - timeStart;
		bool animating = false;

		while (elapsedTime < FRAME_TIME) {
			inputs.clearKeys();
			SDL_PollEvent(&events);

			if (events.type == SDL_KEYDOWN && events.key.repeat == false) {
				inputs.pressKey(events.key.keysym.scancode);
			}
			if (events.type == SDL_KEYUP) {
				inputs.releaseKey(events.key.keysym.scancode);
			}
			if (events.type == SDL_QUIT) {
				return 0;
			}

			//check if the player is animating
			if (actors.at(0).animate());
			//if not, collect input
			else {
				if (inputs.isKeyPressed(SDL_SCANCODE_D) || inputs.isKeyHeld(SDL_SCANCODE_D)) {
					actors.at(0).rightWalk();
				}
				else if (inputs.isKeyPressed(SDL_SCANCODE_A) || inputs.isKeyHeld(SDL_SCANCODE_A)) {
					actors.at(0).leftWalk();
				}

				//TODO: add the game lol

			}

			//turn actors into sprite vector
			vector<sprite> charSprites;
			for (int i = 0; i < actors.size(); i++) {
				charSprites.push_back(actors.at(i).getSprite());
			}

			//update all textures for sprites
			for (int i = 0; i < charSprites.size(); i++) {
				if (charSprites.at(i).getNeedsUpdate()) {
					charSprites.at(i).createTexture(newWindow.getRenderer());
				}
			}
			for (int i = 0; i < platforms.size(); i++) {
				if (platforms.at(i).getNeedsUpdate()) {
					platforms.at(i).createTexture(newWindow.getRenderer());
				}
			}
			if (background.getNeedsUpdate()) {
				background.createTexture(newWindow.getRenderer());
			}

			//draw 1 frame
			newWindow.drawFrame(background, platforms, charSprites);

			//this is to ensure the game doesn't run > 60 fps, doing it this way does tie physics to fps, which isn't ideal
			elapsedTime = SDL_GetTicks() - timeStart;
			if (elapsedTime < FRAME_TIME) {
				SDL_Delay(FRAME_TIME - elapsedTime);
			}
		}
	}
	return 0;
}
