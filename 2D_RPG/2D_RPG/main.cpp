#include <SDL.h>
#include "window.h"
#include "input.h"
#include "game.h"
#include "sprite.h"
#include "character.h"
#include "text.h"

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Event events;
	window newWindow(1280, 720);
	input inputs;

	sprite background("Sprites/forest.png");
	vector<sprite> platforms;
	vector<character> actors;

	character player("austen", player);
	player.moveTo(175, 550);
	actors.push_back(player);

	sprite bottom(0, 720, 1280, 1, true, "Sprites/blu.bmp");

	sprite floor(410, 32, true, "Sprites/blu.bmp");
	floor.moveTo(160, 640);

	sprite ceiling(224, 32, true, "Sprites/blu.bmp");
	ceiling.moveTo(160, 448);

	sprite box(32, 4, true, "Sprites/blu.bmp");

	platforms.push_back(bottom);
	platforms.push_back(floor);
	platforms.push_back(ceiling);

	for (int i = 0; i < 6; i++) {
		platforms.push_back(box);
	}

	platforms.at(3).moveTo(400, 608);
	platforms.at(4).moveTo(448, 592);
	platforms.at(5).moveTo(516, 532);
	platforms.at(6).moveTo(432, 480);
	platforms.at(7).moveTo(400, 432);

	platforms.at(8).moveTo(120, 624);

	bool isMainMenu = true;
	bool isQuitting = false;

	fight(newWindow, inputs, actors.at(0), actors.at(0));
	text one("here is some sample text \nnot all will show", 120, 120, 1);

	while (1) {
		if (background.getNeedsUpdate()) {
			background.createTexture(newWindow.getRenderer());
		}
		one.createTextures(newWindow.getRenderer());
		newWindow.drawFrame(background, one.getLetters());
	}

	while (1) {
		if (isMainMenu) {
			isQuitting = mainMenu(newWindow, inputs);
			isMainMenu = false;
		}

		if (isQuitting) {
			return 0;
		}
		int timeStart = SDL_GetTicks();
		int elapsedTime = SDL_GetTicks() - timeStart;

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

		//if you're not grounded and not already jumping/falling, then fall
		if (!isGrounded(actors.at(0), platforms) && actors.at(0).getCurrentAnimation() != falling && actors.at(0).getCurrentAnimation() != jumping) {
			actors.at(0).fall();
		}

		//check if the player is animating
		if (actors.at(0).getCurrentAnimation() != none) {
			if (actors.at(0).getCurrentAnimation() == crouching) {
				if (inputs.isKeyReleased(KEY_JUMP)) {
					actors.at(0).jump();
				}
			}
			else if (actors.at(0).getCurrentAnimation() == jumping) {
				if (willCollide(actors.at(0), platforms, up)) {
					actors.at(0).fall();
				}
			}
			if (actors.at(0).getCurrentAnimation() == falling) {
				if (willCollide(actors.at(0), platforms, down)) {
					actors.at(0).stop();
				}
			}
			else if (actors.at(0).getCurrentAnimation() == walkingRight) {
				if (inputs.isKeyReleased(KEY_RIGHT)) {
					actors.at(0).stop();
				}
				else if (willCollide(actors.at(0), platforms, right)) {
					actors.at(0).stop();
					actors.at(0).walkRightStill();
				}
			}
			else if (actors.at(0).getCurrentAnimation() == walkingLeft) {
				if (inputs.isKeyReleased(KEY_LEFT)) {
					actors.at(0).stop();
				}
				else if (willCollide(actors.at(0), platforms, left)) {
					actors.at(0).stop();
					actors.at(0).walkLeftStill();
				}
			}
			actors.at(0).animate();
		}

		//collect input
		if (inputs.isKeyPressed(KEY_JUMP) || inputs.isKeyHeld(KEY_JUMP)) {
			actors.at(0).crouch();
		}
		if (inputs.isKeyPressed(KEY_RIGHT) || inputs.isKeyHeld(KEY_RIGHT)) {
			actors.at(0).walkRight();
		}
		else if (inputs.isKeyPressed(KEY_LEFT) || inputs.isKeyHeld(KEY_LEFT)) {
			actors.at(0).walkLeft();
		}

		//TODO: add the game lol

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

		//this is to ensure the game doesn't run > fps, doing it this way does tie physics to fps, which isn't ideal
		elapsedTime = SDL_GetTicks() - timeStart;
		if (elapsedTime < FRAME_TIME) {
			SDL_Delay(FRAME_TIME - elapsedTime);
		}
	}
	return 0;
}