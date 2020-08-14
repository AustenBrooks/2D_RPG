#include <SDL.h>
#include "window.h"
#include "input.h"
#include "game.h"
#include "sprite.h"
#include "character.h"
#include "text.h"
#include "settings.h"

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Event events;

	window gameWindow;
	input inputs;

	sprite background("Sprites/forest.png");
	vector<sprite> platforms;
	vector<sprite> unloadedPlatforms;
	vector<character> actors;
	vector<character> unloadedActors;

	character austen("austen", player);
	character enemy("enemy", player);
	
	austen.moveTo(175, 550);
	enemy.moveTo(300, 576);
	enemy.turnLeft();

	actors.push_back(austen);
	unloadedActors.push_back(enemy);

	sprite bottom(0, 720, 1280, 1, true, "Sprites/blu.bmp");

	sprite floor(160, 640, 410, 32, true, "Sprites/blu.bmp");

	sprite ceiling(160, 448, 224, 32, true, "Sprites/blu.bmp");

	sprite box(32, 4, true, "Sprites/blu.bmp");

	platforms.push_back(bottom);
	platforms.push_back(floor);
	platforms.push_back(ceiling);

	for (int i = 0; i < 7; i++) {
		platforms.push_back(box);
	}

	platforms.at(3).moveTo(400, 608);
	platforms.at(4).moveTo(448, 592);
	platforms.at(5).moveTo(516, 532);
	platforms.at(6).moveTo(432, 480);
	platforms.at(7).moveTo(400, 432);

	platforms.at(8).moveTo(120, 624);
	
	platforms.at(9).moveTo(720, 700);

	bool isMainMenu = true;
	bool isQuitting = false;

	//fight(gameWindow, actors.at(0), actors.at(1));
	
	//correction frame is used to approximate the characters animation frame
	//this is only used when moving everything but the player
	//TODO: FIND A BETTER WAY TO DO THIS
	int correctionFrame = 0;

	while (1) {
		if (isMainMenu) {
			isQuitting = mainMenu(gameWindow);
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
		if (!isGrounded(actors.at(0), platforms) && actors.at(0).getCurrentAnimation() != falling && actors.at(0).getCurrentAnimation() != fallingStill && actors.at(0).getCurrentAnimation() != jumping && actors.at(0).getCurrentAnimation() != jumpingStill) {
			actors.at(0).fall();
		}

		//used for storing jump/fall direction/distance
		int sideDistance = 0;
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
				else if (actors.at(0).getSprite().getRectangle().x > (WINDOW_WIDTH / 2 - 32) && actors.at(0).getSprite().getRectangle().x < (WINDOW_WIDTH / 2 + 32)) {
					actors.at(0).vertJump();
				}
			}
			if (actors.at(0).getCurrentAnimation() == jumpingStill) {
				if (willCollide(actors.at(0), platforms, up)) {
					actors.at(0).fall();
				}
				else if (actors.at(0).getSprite().getRectangle().x > (WINDOW_WIDTH / 2 - 32) && actors.at(0).getSprite().getRectangle().x < (WINDOW_WIDTH / 2 + 32)) {
					if (actors.at(0).getDirection() == left) {
						sideDistance = 1;
					}
					if (actors.at(0).getDirection() == right) {
						sideDistance = -1;
					}

					correctionFrame++;
					if (!(correctionFrame % 2)) {
						background.moveBy(sideDistance, 0);
						for (int i = 0; i < platforms.size(); i++) {
							platforms.at(i).moveBy(sideDistance, 0);
						}
						for (int i = 0; i < unloadedPlatforms.size(); i++) {
							unloadedPlatforms.at(i).moveBy(sideDistance, 0);
						}
						for (int i = 1; i < actors.size(); i++) {
							actors.at(i).moveBy(sideDistance, 0);
						}
						for (int i = 0; i < unloadedActors.size(); i++) {
							unloadedActors.at(i).moveBy(sideDistance, 0);
						}
					}
				}
			}
			if (actors.at(0).getCurrentAnimation() == falling) {
				if (willCollide(actors.at(0), platforms, down)) {
					actors.at(0).stop();
				}
				else if (actors.at(0).getSprite().getRectangle().x > (WINDOW_WIDTH / 2 - 32) && actors.at(0).getSprite().getRectangle().x < (WINDOW_WIDTH / 2 + 32)) {
					actors.at(0).vertFall();
				}
			}
			if (actors.at(0).getCurrentAnimation() == fallingStill) {
				if (willCollide(actors.at(0), platforms, down)) {
					actors.at(0).stop();
				}
				else if (actors.at(0).getSprite().getRectangle().x > (WINDOW_WIDTH / 2 - 32) && actors.at(0).getSprite().getRectangle().x < (WINDOW_WIDTH / 2 + 32)) {
					if (actors.at(0).getDirection() == left) {
						sideDistance = 1;
					}
					if (actors.at(0).getDirection() == right) {
						sideDistance = -1;
					}

					correctionFrame++;
					if (!(correctionFrame % 2)) {
						background.moveBy(sideDistance, 0);
						for (int i = 0; i < platforms.size(); i++) {
							platforms.at(i).moveBy(sideDistance, 0);
						}
						for (int i = 0; i < unloadedPlatforms.size(); i++) {
							unloadedPlatforms.at(i).moveBy(sideDistance, 0);
						}
						for (int i = 1; i < actors.size(); i++) {
							actors.at(i).moveBy(sideDistance, 0);
						}
						for (int i = 0; i < unloadedActors.size(); i++) {
							unloadedActors.at(i).moveBy(sideDistance, 0);
						}
					}
				}
			}
			else if (actors.at(0).getCurrentAnimation() == walkingRight) {
				if (inputs.isKeyReleased(KEY_RIGHT)) {
					actors.at(0).stop();
				}
				//if the player is within a 64 pixel box centered in the middle of the screen
				else if (actors.at(0).getSprite().getRectangle().x > (WINDOW_WIDTH / 2 - 32) && actors.at(0).getSprite().getRectangle().x < (WINDOW_WIDTH / 2 + 32)) {
					actors.at(0).stop(); 
					actors.at(0).walkRightStill();
				}
				else if (willCollide(actors.at(0), platforms, right)) {
					actors.at(0).stop();
					actors.at(0).walkRightStill();
				}
			}
			else if (actors.at(0).getCurrentAnimation() == walkingRightStill) {
				if (inputs.isKeyReleased(KEY_RIGHT)) {
					actors.at(0).stop();
				}
				else if (willCollide(actors.at(0), platforms, right));

				//if the player is within a 64 pixel box centered in the middle of the screen
				else if (actors.at(0).getSprite().getRectangle().x > (WINDOW_WIDTH / 2 - 32) && actors.at(0).getSprite().getRectangle().x < (WINDOW_WIDTH / 2 + 32)) {
					//move everything other than the player over
					correctionFrame++;
					if (!(correctionFrame % 3)) {
						background.moveBy(-1, 0);
						for (int i = 0; i < platforms.size(); i++) {
							platforms.at(i).moveBy(-1, 0);
						}
						for (int i = 0; i < unloadedPlatforms.size(); i++) {
							unloadedPlatforms.at(i).moveBy(-1, 0);
						}
						for (int i = 1; i < actors.size(); i++) {
							actors.at(i).moveBy(-1, 0);
						}
						for (int i = 0; i < unloadedActors.size(); i++) {
							unloadedActors.at(i).moveBy(-1, 0);
						}
					}
				}
			}
			else if (actors.at(0).getCurrentAnimation() == walkingLeft) {
				if (inputs.isKeyReleased(KEY_LEFT)) {
					actors.at(0).stop();
				}
				//if the player is within a 64 pixel box centered in the middle of the screen
				else if (actors.at(0).getSprite().getRectangle().x > (WINDOW_WIDTH / 2 - 32) && actors.at(0).getSprite().getRectangle().x < (WINDOW_WIDTH / 2 + 32)) {
					actors.at(0).stop();
					actors.at(0).walkLeftStill();
				}
				else if (willCollide(actors.at(0), platforms, left)) {
					actors.at(0).stop();
					actors.at(0).walkLeftStill();
				}
			}
			else if (actors.at(0).getCurrentAnimation() == walkingLeftStill) {
				if (inputs.isKeyReleased(KEY_LEFT)) {
					actors.at(0).stop();
				}
				else if (willCollide(actors.at(0), platforms, left));

				//if the player is within a 64 pixel box centered in the middle of the screen
				else if (actors.at(0).getSprite().getRectangle().x > (WINDOW_WIDTH / 2 - 32) && actors.at(0).getSprite().getRectangle().x < (WINDOW_WIDTH / 2 + 32)) {
					//move everything other than the player over
					correctionFrame++;
					if (!(correctionFrame % 3)) {
						background.moveBy(1, 0);
						for (int i = 0; i < platforms.size(); i++) {
							platforms.at(i).moveBy(1, 0);
						}
						for (int i = 0; i < unloadedPlatforms.size(); i++) {
							unloadedPlatforms.at(i).moveBy(1, 0);
						}
						for (int i = 1; i < actors.size(); i++) {
							actors.at(i).moveBy(1, 0);
						}
						for (int i = 0; i < unloadedActors.size(); i++) {
							unloadedActors.at(i).moveBy(1, 0);
						}
					}
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



		//unload offscreen sprites
		vector<int> unloadIndex;
		for (int i = 0; i < platforms.size(); i++) {
			int platLeft = platforms.at(i).getRectangle().x;
			int platRight = platforms.at(i).getRectangle().x + platforms.at(i).getRectangle().w;
			
			if (platRight < 0 || platLeft > WINDOW_WIDTH) {
				unloadIndex.push_back(i);
			}
		}

		for (int i = unloadIndex.size() - 1; i >= 0; i--) {
			int index = unloadIndex.at(i);
			unloadedPlatforms.push_back(platforms.at(index));
			platforms.erase(platforms.begin() + index);
		}
		unloadIndex.clear();

		//reload onscreen sprites
		vector<int> loadIndex;
		for (int i = 0; i < unloadedPlatforms.size(); i++) {
			int platLeft = unloadedPlatforms.at(i).getRectangle().x;
			int platRight = unloadedPlatforms.at(i).getRectangle().x + unloadedPlatforms.at(i).getRectangle().w;
			
			if (platRight > 0 && platLeft < WINDOW_WIDTH) {
				loadIndex.push_back(i);
			}
		}

		for (int i = loadIndex.size() - 1; i >= 0; i--) {
			int index = loadIndex.at(i);
			platforms.push_back(unloadedPlatforms.at(index));
			unloadedPlatforms.erase(unloadedPlatforms.begin() + index);
		}
		loadIndex.clear();

		//unload offscreen actors
		for (int i = 1; i < actors.size(); i++) {
			int actorLeft = actors.at(i).getSprite().getRectangle().x;
			int actorRight = actors.at(i).getSprite().getRectangle().x + actors.at(i).getSprite().getRectangle().w;
			
			if (actorRight < 0 || actorLeft > WINDOW_WIDTH) {
				unloadIndex.push_back(i);
			}
		}

		for (int i = unloadIndex.size() - 1; i >= 0; i--) {
			int index = unloadIndex.at(i);
			unloadedActors.push_back(actors.at(index));
			actors.erase(actors.begin() + index);
		}
		unloadIndex.clear();

		//reload onscreen actors
		for (int i = 0; i < unloadedActors.size(); i++) {
			int actorLeft = unloadedActors.at(i).getSprite().getRectangle().x;
			int actorRight = unloadedActors.at(i).getSprite().getRectangle().x + unloadedActors.at(i).getSprite().getRectangle().w;
			
			if (actorRight > 0 && actorLeft < WINDOW_WIDTH) {
				loadIndex.push_back(i);
			}
		}

		for (int i = loadIndex.size() - 1; i >= 0; i--) {
			int index = loadIndex.at(i);
			actors.push_back(unloadedActors.at(index));
			unloadedActors.erase(unloadedActors.begin() + index);
		}
		loadIndex.clear();


		//update all textures for sprites
		for (int i = 0; i < actors.size(); i++) {
			actors.at(i).createTexture(gameWindow.getRenderer());
		}
		for (int i = 0; i < platforms.size(); i++) {
			platforms.at(i).createTexture(gameWindow.getRenderer());
		}
		background.createTexture(gameWindow.getRenderer());

		//draw 1 frame
		gameWindow.renderBackground(background);
		gameWindow.renderPlatforms(platforms);
		gameWindow.renderActors(actors);
		gameWindow.drawFrame();

		//this is to ensure the game doesn't run > fps, doing it this way does tie physics to fps, which isn't ideal
		elapsedTime = SDL_GetTicks() - timeStart;
		if (elapsedTime < FRAME_TIME) {
			SDL_Delay(FRAME_TIME - elapsedTime);
		}
	}
	return 0;
}