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
		int elapsedTime = SDL_GetTicks() - timeStart;

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
		if (cursor == quit && inputs.isKeyPressed(SDL_SCANCODE_RETURN)) {
			return true;
		}
		if (cursor == play && inputs.isKeyPressed(SDL_SCANCODE_RETURN)) {
			return false;
		}

		//move cursor down
		if (inputs.isKeyPressed(SDL_SCANCODE_S)) {
			int temp = (int)cursor;
			temp++;
			if (temp > 2) {
				temp = 2;
			}
			cursor = (button)temp;
		}
		//move cursor up
		if (inputs.isKeyPressed(SDL_SCANCODE_W)) {
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

		//delay if over 60 FPS
		elapsedTime = SDL_GetTicks() - timeStart;
		if (elapsedTime < FRAME_TIME) {
			SDL_Delay(FRAME_TIME - elapsedTime);
		}

		//draw the frame
		newWindow.drawFrame(background, buttons);
	}
}


bool checkCollision(character player, vector<sprite> objects, facing direction) {
	int playerX = player.getSprite().getRectangle().x;
	int playerY = player.getSprite().getRectangle().y;
	int playerW = player.getSprite().getRectangle().w;
	int playerH = player.getSprite().getRectangle().h;
	
	int playerLeft = player.getSprite().getRectangle().x;
	int playerRight = player.getSprite().getRectangle().x + player.getSprite().getRectangle().w;
	int playerTop = player.getSprite().getRectangle().y;
	int playerBottom = player.getSprite().getRectangle().y + player.getSprite().getRectangle().h;

	/*
	int farLeft = objects.at(i).getRectangle().x;
	int farRight = objects.at(i).getRectangle().x + objects.at(i).getRectangle().w;
	int top = objects.at(i).getRectangle().y;
	int bottom = objects.at(i).getRectangle().y + objects.at(i).getRectangle().h;
	*/

	int walkDistance = 16;

	if (direction == right) {
		for (int i = 0; i < objects.size(); i++) {
			//if object has collision check its position
			if (objects.at(i).getCollision()) {
				int farLeft = objects.at(i).getRectangle().x;
				int top = objects.at(i).getRectangle().y;
				int bottom = objects.at(i).getRectangle().y + objects.at(i).getRectangle().h;

				//if the object is to the right of player and to the left of where the player will be, check y pos
				if ((playerRight) < farLeft && (playerRight + walkDistance) > farLeft) {
					//if the object is not (above the player or below the players feet) return false
					if (!((playerTop > bottom) || (playerBottom < top))) {
						return false;
					}
				}
			}
		}
		return true;
	}
	if (direction == left) {
		for (int i = 0; i < objects.size(); i++) {
			//if object has collision check its position
			if (objects.at(i).getCollision()) {
				int farRight = objects.at(i).getRectangle().x + objects.at(i).getRectangle().w;
				int top = objects.at(i).getRectangle().y;
				int bottom = objects.at(i).getRectangle().y + objects.at(i).getRectangle().h;

				//if the object is to the left of player and to the right of where the player will be, check y pos
				if ((playerLeft > farRight) && ((playerLeft - walkDistance) < (farRight))) {
					//if the object is not (above the player or below the players feet) return false
					if (!((playerTop > bottom) || (playerBottom < top))) {
						return false;
					}
				}
			}
		}
		return true;
	}
	if (direction == up) {

	}
	if (direction == down) {

	}

}