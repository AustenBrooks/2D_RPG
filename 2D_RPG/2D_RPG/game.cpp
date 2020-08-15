#include "game.h"


bool mainMenu(window& gameWindow) {
	input inputs;
	SDL_Event events;
	sprite background("Sprites/mainMenu.png");

	enum button { play = 0, settings = 1, quit = 2 };
	button cursor = play;

	while (1) {
		vector<sprite> buttons;
		sprite playButton(1000, 260, 200, 100, false, "Sprites/play.png", 0, 0, 1);
		sprite settingsButton(1000, 360, 200, 100, false, "Sprites/settings.png", 0, 0, 1);
		sprite quitButton(1000, 460, 200, 100, false, "Sprites/quit.png", 0, 0, 1);
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
		else if ((int)cursor == 1) {
			buttons.at(1).setSpriteSheet("Sprites/settingsSelected.png");
		}
		else if ((int)cursor == 2) {
			buttons.at(2).setSpriteSheet("Sprites/quitSelected.png");
		}

		//update all textures
		for (int i = 0; i < buttons.size(); i++) {
			buttons.at(i).createTexture(gameWindow.getRenderer());
		}
		background.createTexture(gameWindow.getRenderer());

		//draw 1 frame
		gameWindow.renderBackground(background);
		gameWindow.renderPlatforms(buttons);
		gameWindow.drawFrame();

		//delay if over FPS
		int elapsedTime = SDL_GetTicks() - timeStart;
		if (elapsedTime < FRAME_TIME) {
			SDL_Delay(FRAME_TIME - elapsedTime);
		}
	}
}

bool fight(window& gameWindow, character& player, character enemy) {
	input inputs;
	SDL_Event events;
	sprite background("Sprites/forest.png");

	enemy.moveTo(650, 550);
	bool isPaused = AUTO_COMBAT_PAUSE;

	enum action { none, attack, items, cast };
	action playerQueue = none;
	action enemyQueue = attack;
	float pScale = player.getSprite().getScale();
	float eScale = enemy.getSprite().getScale();

	player.setScale(2);
	enemy.setScale(2);

	text playerStats(player.displayStats(), 220, 500, .5);
	text enemyStats(enemy.displayStats(), 500, 500, .5);
	text pause("PAUSED", 550, 100, 1);

	sprite icons(510, 240, 195, 64, false, "Sprites/icons.png");
	text keyAttack("U", 535, 304, 1);
	text keyItem("I", 600, 304, 1);
	text keyCast("O", 660, 304, 1);

	int frame = 0;

	//combine all text
	vector<text> allText;
	allText.push_back(pause);
	allText.push_back(playerStats);
	allText.push_back(enemyStats);
	allText.push_back(keyAttack);
	allText.push_back(keyItem);
	allText.push_back(keyCast);

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
		else if (inputs.isKeyPressed(KEY_ATTACK)) {
			playerQueue = attack;
		}
		else if (inputs.isKeyPressed(KEY_ITEMS)) {
			playerQueue = items;
		}
		else if (inputs.isKeyPressed(KEY_CAST)) {
			playerQueue = cast;
		}

		//if game isnt paused, then do the fight
		if (!isPaused) {
			allText.at(0).setText("", 550, 120, 1);
			frame++;
			if (player.canAct()) {
				if (playerQueue == attack) {
					enemy.defendPhysical(player.attack());
					//playerQueue = none;
					std::cout << "player attacks \n";
				}
				else if (playerQueue == items) {
					player.potion();
					std::cout << "player uses potion \n";
					playerQueue = none;
				}
				else if (playerQueue == cast) {
					float dmg = player.cast(fireball);
					if (dmg > 0) {
						enemy.defendMagical(dmg);
						std::cout << "player cast fireball \n";
					}
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
			}
			allText.at(1).setText(player.displayStats(), 220, 500, .5);
			allText.at(2).setText(enemy.displayStats(), 500, 500, .5);
		}
		else {
			allText.at(0).setText("PAUSED", 550, 120, 1);
		}

		//update all textures
		background.createTexture(gameWindow.getRenderer());
		icons.createTexture(gameWindow.getRenderer());
		pause.createTextures(gameWindow.getRenderer());
		player.createTexture(gameWindow.getRenderer());
		enemy.createTexture(gameWindow.getRenderer());
		for (int i = 0; i < allText.size(); i++) {
			allText.at(i).createTextures(gameWindow.getRenderer());
		}

		//draw 1 frame
		gameWindow.renderBackground(background);
		gameWindow.renderCharacter(player);
		gameWindow.renderCharacter(enemy);
		gameWindow.renderSprite(icons);
		gameWindow.renderText(allText);
		gameWindow.drawFrame();

		//delay if over FPS
		int elapsedTime = SDL_GetTicks() - timeStart;
		if (elapsedTime < FRAME_TIME) {
			SDL_Delay(FRAME_TIME - elapsedTime);
		}
	}

	player.setScale(pScale);
	enemy.setScale(eScale);

	if (player.isAlive()) {
		int points = player.gainXP(enemy.getXpFromKill());
		if (points) {
			player.levelAttributes(chooseStats(gameWindow, player, points));
		}
		return true;
	}
	else {
		return false;
	}
}

attributes chooseStats(window& gameWindow, character& player, int points) {
	input inputs;
	SDL_Event events;
	sprite background("Sprites/mainMenu.png");

	attributes incAttr = { 0 };
	enum button { strength = 0, dexterity = 1, wisdom = 2, endurance = 3, agility = 4, intelligence = 5 };
	button cursor = strength;

	vector<sprite> buttons;
	{
		sprite str(1000, 260, 222, 60, false, "Sprites/attributes.png", 0, 0, 1);
		sprite dex(1000, 360, 222, 60, false, "Sprites/attributes.png", 222, 0, 1);
		sprite wis(1000, 460, 222, 60, false, "Sprites/attributes.png", 444, 0, 1);
		sprite end(1000, 260, 222, 60, false, "Sprites/attributes.png", 0, 60, 1);
		sprite agi(1000, 360, 222, 60, false, "Sprites/attributes.png", 222, 60, 1);
		sprite intel(1000, 460, 222, 60, false, "Sprites/attributes.png", 444, 60, 1);

		buttons.push_back(str);
		buttons.push_back(wis);
		buttons.push_back(dex);
		buttons.push_back(end);
		buttons.push_back(agi);
		buttons.push_back(intel);
	}
	while (1) {
		int timeStart = SDL_GetTicks();

		if (points == 0) {
			return incAttr;
		}

		buttons.at(0).setSpriteXY(buttons.at(0).getSpriteX(), 0);
		buttons.at(1).setSpriteXY(buttons.at(1).getSpriteX(), 0);
		buttons.at(2).setSpriteXY(buttons.at(2).getSpriteX(), 0);
		buttons.at(3).setSpriteXY(buttons.at(3).getSpriteX(), 60);
		buttons.at(4).setSpriteXY(buttons.at(4).getSpriteX(), 60);
		buttons.at(5).setSpriteXY(buttons.at(5).getSpriteX(), 60);

		inputs.clearKeys();
		SDL_PollEvent(&events);

		//collect input
		if (events.type == SDL_KEYDOWN && events.key.repeat == false) {
			inputs.pressKey(events.key.keysym.scancode);
		}
		if (events.type == SDL_KEYUP) {
			inputs.releaseKey(events.key.keysym.scancode);
		}

		//move cursor left
		if (inputs.isKeyPressed(KEY_LEFT)) {
			int temp = (int)cursor;
			if (temp == 0 || temp == 3) {
				temp += 2;
			}
			else {
				temp--;
			}
			cursor = (button)temp;
		}
		//move cursor right
		if (inputs.isKeyPressed(KEY_RIGHT)) {
			int temp = (int)cursor;
			if (temp == 2 || temp == 5) {
				temp -= 2;
			}
			else {
				temp++;
			}
			cursor = (button)temp;
		}
		//move cursor down
		if (inputs.isKeyPressed(KEY_DOWN)) {
			int temp = (int)cursor;
			if (temp < 3) {
				temp += 3;
			}
			else {
				temp -= 3;
			}
			cursor = (button)temp;
		}
		//move cursor up
		if (inputs.isKeyPressed(KEY_UP)) {
			int temp = (int)cursor;
			if (temp > 2) {
				temp -= 3;
			}
			else {
				temp += 3;
			}
			cursor = (button)temp;
		}
		//confirms selection
		if (inputs.isKeyPressed(KEY_ENTER)) {
			int temp = (int)cursor;
			switch (temp) {
			case 0:
				incAttr.strength += 1;
			case 1:
				incAttr.dexterity += 1;
			case 2:
				incAttr.wisdom += 1;
			case 3:
				incAttr.endurance += 1;
			case 4:
				incAttr.agility += 1;
			case 5:
				incAttr.intelligence += 1;
			}
			points--;
		}

		//highlight selected option
		buttons.at((int)cursor).setSpriteXY(buttons.at((int)cursor).getSpriteX(), buttons.at((int)cursor).getSpriteY() + 120);

		//update all textures
		for (int i = 0; i < buttons.size(); i++) {
			buttons.at(i).createTexture(gameWindow.getRenderer());
		}
		background.createTexture(gameWindow.getRenderer());

		//draw 1 frame
		gameWindow.renderBackground(background);
		gameWindow.renderPlatforms(buttons);
		gameWindow.drawFrame();

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