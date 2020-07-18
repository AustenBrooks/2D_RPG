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
	player.moveTo(300, 600);
	actors.push_back(player);

	sprite box1(350, 700, 32, 50, true, "Sprites/blu.bmp", 0, 0);
	sprite box2(400, 500, 32, 50, true, "Sprites/blu.bmp", 0, 0);
	sprite box3(450, 600, 32, 50, true, "Sprites/blu.bmp", 0, 0);
	sprite box4(250, 700, 32, 50, true, "Sprites/blu.bmp", 0, 0);
	sprite box5(200, 500, 32, 50, true, "Sprites/blu.bmp", 0, 0);
	sprite box6(150, 600, 32, 50, true, "Sprites/blu.bmp", 0, 0);

	platforms.push_back(box1);
	platforms.push_back(box2);
	platforms.push_back(box3);
	platforms.push_back(box4);
	platforms.push_back(box5);
	platforms.push_back(box6);

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
					if (checkCollision(actors.at(0), platforms, right)) {
						actors.at(0).rightWalk();
					}
					else {
						actors.at(0).rightWalkStill();
					}
				}
				else if (inputs.isKeyPressed(SDL_SCANCODE_A) || inputs.isKeyHeld(SDL_SCANCODE_A)) {
					if (checkCollision(actors.at(0), platforms, left)) {
						actors.at(0).leftWalk();
					}
					else {
						actors.at(0).leftWalkStill();
					}
				}

				//TODO: add the game lol

			}

			//update all textures for sprites
			for (int i = 0; i < actors.size(); i++) {
				if (actors.at(i).getSprite().getNeedsUpdate()) {
					actors.at(i).createTexture(newWindow.getRenderer());
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
			newWindow.drawFrame(background, platforms, actors);

			//this is to ensure the game doesn't run > 60 fps, doing it this way does tie physics to fps, which isn't ideal
			elapsedTime = SDL_GetTicks() - timeStart;
			if (elapsedTime < FRAME_TIME) {
				SDL_Delay(FRAME_TIME - elapsedTime);
			}
		}
	}
	return 0;
}