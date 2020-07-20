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
	player.moveTo(175, 550);
	actors.push_back(player);

	sprite box1(500, 550, 15, 10, true, "Sprites/blu.bmp");
	sprite box2(400, 620, 32, 50, true, "Sprites/blu.bmp");
	sprite box3(450, 600, 32, 50, true, "Sprites/blu.bmp");
	sprite box4(400, 530, 10, 10, true, "Sprites/blu.bmp");
	sprite box5(200, 500, 32, 50, true, "Sprites/blu.bmp");
	sprite box6(150, 600, 32, 50, true, "Sprites/blu.bmp");

	sprite box7(200, 500, 150, 20, true, "Sprites/blu.bmp");
	sprite box8(200, 630, 175, 50, true, "Sprites/blu.bmp");

	platforms.push_back(box1);
	platforms.push_back(box2);
	platforms.push_back(box3);
	platforms.push_back(box4);
	//platforms.push_back(box5);
	platforms.push_back(box6);
	platforms.push_back(box7);
	platforms.push_back(box8);

	bool isMainMenu = true;
	bool isQuitting = false;

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

			
			if (actors.at(0).getCurrentAnimation() == jumping) {
				if (!checkCollision(actors.at(0), platforms, up)) {
					actors.at(0).fall();
				}
			}
			else if (!isGrounded(actors.at(0), platforms) && actors.at(0).getCurrentAnimation() != falling) {
				actors.at(0).fall();
			}
			if (actors.at(0).getCurrentAnimation() == falling) {
				if (!checkCollision(actors.at(0), platforms, down)) {
					actors.at(0).stop();
				}
			}

			//check if the player is animating
			if (actors.at(0).animate()) {
			}

			//collect input
			if (inputs.isKeyPressed(SDL_SCANCODE_W) || inputs.isKeyHeld(SDL_SCANCODE_W)) {
				actors.at(0).crouch();
			}
			if (inputs.isKeyReleased(SDL_SCANCODE_W)) {
				actors.at(0).jump();
			}
			if (inputs.isKeyPressed(SDL_SCANCODE_D) || inputs.isKeyHeld(SDL_SCANCODE_D)) {
				if (checkCollision(actors.at(0), platforms, right)) {
					actors.at(0).walkRight();
				}
				else {
					actors.at(0).walkRightStill();
				}
			}
			else if (inputs.isKeyPressed(SDL_SCANCODE_A) || inputs.isKeyHeld(SDL_SCANCODE_A)) {
				if (checkCollision(actors.at(0), platforms, left)) {
					actors.at(0).walkLeft();
				}
				else {
					actors.at(0).walkLeftStill();
				}
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

			//this is to ensure the game doesn't run > 60 fps, doing it this way does tie physics to fps, which isn't ideal
			elapsedTime = SDL_GetTicks() - timeStart;
			if (elapsedTime < FRAME_TIME) {
				SDL_Delay(FRAME_TIME - elapsedTime);
			}
		}
	}
	return 0;
}