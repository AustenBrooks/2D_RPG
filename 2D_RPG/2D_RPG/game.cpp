#include "game.h"


bool mainMenu(window& newWindow, input inputs) {

	SDL_Event events;
	sprite background("Sprites/mainMenu.png");

	enum button { play = 0, settings = 1, quit = 2 };
	button cursor = play;

	while (1) {
		vector<sprite> buttons;
		sprite playButton(1000, 260, 200, 100, false, "Sprites/play.png", 0, 0);
		sprite settingsButton(1000, 360, 200, 100, false, "Sprites/settings.png", 0, 0);
		sprite quitButton(1000, 460, 200, 100, false, "Sprites/quit.png", 0, 0);
		buttons.push_back(playButton);
		buttons.push_back(settingsButton);
		buttons.push_back(quitButton);

		int timeStart = SDL_GetTicks();

		inputs.clearKeys();
		SDL_PollEvent(&events);

		//collect input
		if (events.type == SDL_KEYDOWN && events.key.repeat == false) {
			inputs.pressKey(events.key.keysym.scancode);
		}
		if (events.type == SDL_KEYUP) {
			inputs.releaseKey(events.key.keysym.scancode);
		}
		if (events.type == SDL_QUIT) {
			return true;
		}

		//do whatever button is selected
		if (cursor == quit && inputs.isKeyPressed(KEY_ENTER)) {
			return true;
		}
		if (cursor == play && inputs.isKeyPressed(KEY_ENTER)) {
			return false;
		}

		//move cursor down
		if (inputs.isKeyPressed(KEY_DOWN)) {
			int temp = (int)cursor;
			temp++;
			if (temp > 2) {
				temp = 2;
			}
			cursor = (button)temp;
		}
		//move cursor up
		if (inputs.isKeyPressed(KEY_UP)) {
			int temp = (int)cursor;
			temp--;
			if (temp < 0) {
				temp = 0;
			}
			cursor = (button)temp;
		}

		//highlight selected button
		if ((int)cursor == 0) {
			buttons.at(0).setSpriteSheet("Sprites/playSelected.png");
		}
		if ((int)cursor == 1) {
			buttons.at(1).setSpriteSheet("Sprites/settingsSelected.png");
		}
		if ((int)cursor == 2) {
			buttons.at(2).setSpriteSheet("Sprites/quitSelected.png");
		}

		//update all textures
		for (int i = 0; i < buttons.size(); i++) {
			if (buttons.at(i).getNeedsUpdate()) {
				buttons.at(i).createTexture(newWindow.getRenderer());
			}
		}
		if (background.getNeedsUpdate()) {
			background.createTexture(newWindow.getRenderer());
		}

		//draw the frame
		newWindow.drawFrame(background, buttons);

		//delay if over FPS
		int elapsedTime = SDL_GetTicks() - timeStart;
		if (elapsedTime < FRAME_TIME) {
			SDL_Delay(FRAME_TIME - elapsedTime);
		}
	}
}


bool willCollide(character& player, vector<sprite> objects, facing direction) {
	int playerLeft = player.getSprite().getRectangle().x;
	int playerRight = player.getSprite().getRectangle().x + player.getSprite().getRectangle().w;
	int playerTop = player.getSprite().getRectangle().y;
	int playerBottom = player.getSprite().getRectangle().y + player.getSprite().getRectangle().h;

	int walkDistance = 1;

	//for falling/jumping
	int maxFall = 2;
	int maxJump = 2;
	int maxSideMovement = 1;

	facing momentum = player.getDirection();

	if (direction == right) {
		for (int i = 0; i < objects.size(); i++) {
			//if object has collision check its position
			if (objects.at(i).getCollision()) {
				int farLeft = objects.at(i).getRectangle().x;
				int top = objects.at(i).getRectangle().y;
				int bottom = objects.at(i).getRectangle().y + objects.at(i).getRectangle().h;

				//if the object is to the right of player and to the left of where the player will be, check y pos
				if (playerRight <= farLeft && (playerRight + walkDistance) >= farLeft) {
					//if the object is not (above the player or below the players feet) return true
					if (!(playerTop > bottom || playerBottom <= top)) {
						return true;
					}
				}
			}
		}
		return false;
	}
	if (direction == left) {
		for (int i = 0; i < objects.size(); i++) {
			//if object has collision check its position
			if (objects.at(i).getCollision()) {
				int farRight = objects.at(i).getRectangle().x + objects.at(i).getRectangle().w;
				int top = objects.at(i).getRectangle().y;
				int bottom = objects.at(i).getRectangle().y + objects.at(i).getRectangle().h;

				//if the object is to the left of player and to the right of where the player will be, check y pos
				if (playerLeft > farRight && (playerLeft - walkDistance) <= farRight) {
					//if the object is not (above the player or below the players feet) return true
					if (!(playerTop > bottom || playerBottom <= top)) {
						return true;
					}
				}
			}
		}
		return false;
	}
	if (direction == up) {
		for (int i = 0; i < objects.size(); i++) {
			//if object has collision check its position
			if (objects.at(i).getCollision()) {
				int farLeft = objects.at(i).getRectangle().x;
				int farRight = objects.at(i).getRectangle().x + objects.at(i).getRectangle().w;
				int top = objects.at(i).getRectangle().y;
				int bottom = objects.at(i).getRectangle().y + objects.at(i).getRectangle().h;

				//if the bottom of the object is above the player and below where they will be, check xpos
				if (playerTop >= bottom && (playerTop - maxJump) <= bottom) {
					//if the object is not to the right of the player
					if (!(playerRight < farRight && playerRight < farLeft)) {
						//if the object is not to the left of the player
						if (!(playerLeft > farRight && playerLeft > farLeft)) {
							return true;
						}
					}
				}
				if (momentum == right) {
					//if the object is to the right of player and to the left of where the player will be, check y pos
					if (playerRight <= farLeft && (playerRight + maxSideMovement) >= farLeft) {
						//if the object is not (above the player or below the players feet) return true
						if (!(playerTop > bottom || playerBottom < top)) {
							player.bonk();
							return true;
						}
					}
				}
				else if (momentum == left) {
					//if the object is to the left of player and to the right of where the player will be, check y pos
					if (playerLeft > farRight && (playerLeft - maxSideMovement) <= farRight) {
						//if the object is not (above the player or below the players feet) return true
						if (!(playerTop > bottom || playerBottom < top)) {
							player.bonk();
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	if (direction == down) {
		for (int i = 0; i < objects.size(); i++) {
			//if object has collision check its position
			if (objects.at(i).getCollision()) {
				int farLeft = objects.at(i).getRectangle().x;
				int farRight = objects.at(i).getRectangle().x + objects.at(i).getRectangle().w;
				int top = objects.at(i).getRectangle().y;
				int bottom = objects.at(i).getRectangle().y + objects.at(i).getRectangle().h;

				//if the top of the object is below the player and above where they will be, check xpos
				if (playerBottom <= top && (playerBottom + maxFall) >= top) {
					//if the object is not to the right of the player
					if (!(playerRight < farRight && playerRight < farLeft)) {
						//if the object is not to the left of the player
						if (!(playerLeft > farRight && playerLeft > farLeft)) {
							int difference = top - playerBottom;
							player.moveBy(0, difference);
							return true;

						}
					}
				}
				if (momentum == right) {
					//if the object is to the right of player and to the left of where the player will be, check y pos
					if (playerRight <= farLeft && (playerRight + maxSideMovement) >= farLeft) {
						//if the object is not (above the player or below the players feet) return true
						if (!(playerTop > bottom || playerBottom < top)) {
							player.bonk();
							return false;
						}
					}
				}
				else if (momentum == left) {
					//if the object is to the left of player and to the right of where the player will be, check y pos
					if (playerLeft > farRight && (playerLeft - maxSideMovement) <= farRight) {
						//if the object is not (above the player or below the players feet) return true
						if (!(playerTop > bottom || playerBottom < top)) {
							player.bonk();
							//returns false because the player still needs to fall
							return false;
						}
					}
				}
			}
		}
		return false;
	}
}

bool isGrounded(character& player, vector<sprite> objects) {
	int playerLeft = player.getSprite().getRectangle().x;
	int playerRight = player.getSprite().getRectangle().x + player.getSprite().getRectangle().w;
	int playerTop = player.getSprite().getRectangle().y;
	int playerBottom = player.getSprite().getRectangle().y + player.getSprite().getRectangle().h;
	
	for (int i = 0; i < objects.size(); i++) {
		//if object has collision check its position
		if (objects.at(i).getCollision()) {
			int farLeft = objects.at(i).getRectangle().x;
			int farRight = objects.at(i).getRectangle().x + objects.at(i).getRectangle().w;
			int top = objects.at(i).getRectangle().y;
			int bottom = objects.at(i).getRectangle().y + objects.at(i).getRectangle().h;

			//if the top of the object is below the player and above where they will be, check xpos
			if (playerBottom == top) {
				//if the object is not to the right of the player
				if (!(playerRight < farRight && playerRight < farLeft)) {
					//if the object is not to the left of the player
					if (!(playerLeft > farRight && playerLeft > farLeft)) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

void fight(window& newWindow, input inputs, character& player, character enemy) {
	SDL_Event events;
	sprite background("Sprites/forest.png");

	enemy.moveTo(350, 550);
	bool isPaused = true;
	
	enum action { none, attack, items, cast };
	action playerQueue = none;
	action enemyQueue = attack;

	int frame = 0;
	while (player.isAlive() && enemy.isAlive()) {
		int timeStart = SDL_GetTicks();

		inputs.clearKeys();
		SDL_PollEvent(&events);

		//collect input
		if (events.type == SDL_KEYDOWN && events.key.repeat == false) {
			inputs.pressKey(events.key.keysym.scancode);
		}
		if (events.type == SDL_KEYUP) {
			inputs.releaseKey(events.key.keysym.scancode);
		}
		
		if (inputs.isKeyPressed(KEY_PAUSE)) {
			isPaused = !isPaused;
		}
		if (inputs.isKeyPressed(KEY_ATTACK)) {
			playerQueue = attack;
		}
		if (inputs.isKeyPressed(KEY_ITEMS)) {
			playerQueue = items;
		}
		
		//if game isnt paused, then do the fight
		if(!isPaused) {
			frame++;
			if (player.canAct()) {
				if (playerQueue == attack) {
					enemy.defendPhysical(player.attack());
					//playerQueue = none;
					std::cout << "player attacks \n";
				}
				else if (playerQueue == items) {
					//use item
					playerQueue = none;
				}
			}
			if (enemy.canAct()) {
				if (enemyQueue == attack) {
					player.defendPhysical(enemy.attack());
					//enemyQueue = none;
					std::cout << "enemy attacks \n";
				}
			}
			if (!(frame % FPS)) {
				player.regen();
				enemy.regen();
				std::cout << "Player \n";
				player.displayStats();
				std::cout << "Enemy \n";
				enemy.displayStats();
			}
		}

		//update all textures
		if (player.getSprite().getNeedsUpdate()) {
			player.createTexture(newWindow.getRenderer());
		}
		if (enemy.getSprite().getNeedsUpdate()) {
			enemy.createTexture(newWindow.getRenderer());
		}
		if (background.getNeedsUpdate()) {
			background.createTexture(newWindow.getRenderer());
		}
		
		//draw the frame
		newWindow.drawFrame(background, player, enemy);

		//delay if over FPS
		int elapsedTime = SDL_GetTicks() - timeStart;
		if (elapsedTime < FRAME_TIME) {
			SDL_Delay(FRAME_TIME - elapsedTime);
		}
	}
}