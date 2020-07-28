#include "text.h"

text::text(string word, int xPos, int yPos, float scale) {
	int numSpaces = 0;
	for (int i = 0; i < word.size(); i++) {
		sprite letter;

		if (word.at(i) == '0') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 0, 0, scale);
		}
		else if (word.at(i) == '1') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 10, 0, scale);
		}
		else if (word.at(i) == '2') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 20, 0, scale);
		}
		else if (word.at(i) == '3') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 30, 0, scale);
		}
		else if (word.at(i) == '4') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 40, 0, scale);
		}
		else if (word.at(i) == '5') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 50, 0, scale);
		}
		else if (word.at(i) == '6') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 60, 0, scale);
		}
		else if (word.at(i) == '7') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 70, 0, scale);
		}
		else if (word.at(i) == '8') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 80, 0, scale);
		}
		else if (word.at(i) == '9') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 90, 0, scale);
		}


		else if (word.at(i) == '\n') {
			++numSpaces;
			letter.setSprite(0, 0, 0, 0, false, "Sprites/text.png", 0, 0, 1);
		}

		int x = xPos;
		int y = yPos + numSpaces * (21 * scale);

		for (int j = 0; j < i; j++) {
			x += (letters.at(j).getRectangle().w * scale);
		}
		letter.moveTo(x, y);
		
		letters.push_back(letter);
	}
}

void text::createTextures(SDL_Renderer* renderer) {
	for (int i = 0; i < letters.size(); i++) {
		if (letters.at(i).getNeedsUpdate()) {
			letters.at(i).createTexture(renderer);
		}
	}
}

vector<sprite> text::getLetters() {
	return letters;
}