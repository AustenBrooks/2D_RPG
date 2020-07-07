#include <SDL.h>
#include "window.h"
#include "input.h"
#include "game.h"
#include "sprite.h"

int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	window newWindow(1280, 720);
	SDL_Event events;
	input inputs;

	sprite background("Sprites/forest.bmp");
	vector<sprite> platforms;
	vector<sprite> actors;

	background.createTexture(newWindow.getRenderer());
	
	while (1) {
		int timeStart = SDL_GetTicks();
		int elapsedTime = SDL_GetTicks() - timeStart;
		bool animating = false;
		while (elapsedTime < FRAME_TIME) {
			inputs.clearKeys();
			SDL_PollEvent(&events);

			newWindow.drawFrame(background, platforms, actors);
			if (events.type == SDL_KEYDOWN && events.key.repeat == false) {
				inputs.pressKey(events.key.keysym.scancode);
			}
			if (events.type == SDL_KEYUP) {
				inputs.releaseKey(events.key.keysym.scancode);
			}
			if (events.type == SDL_QUIT || inputs.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
				return 0;
			}

			elapsedTime = SDL_GetTicks() - timeStart;
			if (elapsedTime < FRAME_TIME) {
				SDL_Delay(FRAME_TIME - elapsedTime);
			}
		}
		for (int i = 0; i < actors.size(); i++) {
			if (actors.at(i).getNeedsUpdate()) {
				actors.at(i).createTexture(newWindow.getRenderer());
			}
		}

		//create an index order based on Ypos of sprites
		/*vector<int> spritePosY;
		vector<int> indexOrder;
		for (int i = 0; i < actors.size(); i++) {
			int rectY = actors.at(i).getRectangle().y;
			bool isHigher = false;
			int indexHigher = -1;
			int j;
			for (j = 0; j < spritePosY.size(); j++) {
				if (rectY < spritePosY.at(j)) {
					isHigher = true;
					indexHigher = j;
					break;
				}
			}
			if (isHigher) {
				spritePosY.insert(spritePosY.begin() + j, rectY);
				indexOrder.insert(indexOrder.begin() + j, i);
			}
			else {
				spritePosY.push_back(rectY);
				indexOrder.push_back(i);
			}
		}

		//reaarange actors based on indexOrder
		for (int i = 0; i < actors.size(); ++i) {
			while (i != indexOrder.at(i)) {
				int newIndex = indexOrder.at(i);
				sprite temp = actors.at(i);
				actors.at(i) = actors.at(newIndex);
				actors.at(newIndex) = temp;

				indexOrder.at(i) = indexOrder.at(newIndex);
				indexOrder.at(newIndex) = newIndex;

				if (i == playerIndex) {
					playerIndex = newIndex;
				}
				else if (newIndex == playerIndex) {
					playerIndex = i;
				}
			}
		}
		///*/
	}
	return 0;
}
