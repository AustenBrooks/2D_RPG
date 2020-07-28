#include "text.h"

text::text(string word, int xPos, int yPos, float scale) {
	this->word = word;
	int x = xPos;
	int y = yPos;
	for (int i = 0; i < word.size(); i++) {
		sprite letter(0, 0, 10, 21, false, "Sprites/blu.bmp", 0, 0, scale);
		
		//numbers
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
		//letters
		else if (word.at(i) == 'a') {
			letter.setSprite(0, 0, 11, 21, false, "Sprites/text.png", 1, 21, scale);
		}
		else if (word.at(i) == 'b') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 12, 21, scale);
		}
		else if (word.at(i) == 'c') {
			letter.setSprite(0, 0, 8, 21, false, "Sprites/text.png", 22, 21, scale);
		}
		else if (word.at(i) == 'd') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 30, 21, scale);
		}
		else if (word.at(i) == 'e') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 40, 21, scale);
		}
		else if (word.at(i) == 'f') {
			letter.setSprite(0, 0, 6, 21, false, "Sprites/text.png", 50, 21, scale);
		}
		else if (word.at(i) == 'g') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 56, 21, scale);
		}
		else if (word.at(i) == 'h') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 66, 21, scale);
		}
		else if (word.at(i) == 'i') {
			letter.setSprite(0, 0, 3, 21, false, "Sprites/text.png", 76, 21, scale);
		}
		else if (word.at(i) == 'j') {
			letter.setSprite(0, 0, 7, 21, false, "Sprites/text.png", 79, 21, scale);
		}
		else if (word.at(i) == 'k') {
			letter.setSprite(0, 0, 10, 21, false, "Sprites/text.png", 86, 21, scale);
		}
		else if (word.at(i) == 'l') {
			letter.setSprite(0, 0, 4, 21, false, "Sprites/text.png", 95, 21, scale);
		}

		//misc char
		else if (word.at(i) == '.') {
			letter.setSprite(0, 0, 4, 21, false, "Sprites/text.png", 27, 168, scale);
		}
		else if (word.at(i) == '/') {
			letter.setSprite(0, 0, 8, 21, false, "Sprites/text.png", 36, 168,  scale);
		}
		else if (word.at(i) == ' ') {
			letter.setSprite(0, 0, 6, 21, false, "Sprites/text.png", 0, 189, scale);
		}
		else if (word.at(i) == '\n') {
			y += 21 * scale;
			x = xPos;
			letter.setSprite(0, 0, 0, 0, false, "Sprites/text.png", 0, 0, 1);
		}

		letter.moveTo(x, y);
		letters.push_back(letter);
		x += letters.at(i).getRectangle().w * scale;
		
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

void text::setText(string word, int xPos, int yPos, float scale) {
	if (this->word == word) {
		return;
	}
	int x = xPos;
	int y = yPos;
	if (this->word.size() > word.size()) {
		for (int i = 0; i < (this->word.size() - word.size()); i++) {
			this->word.pop_back();
			letters.pop_back();
		}
	}
	if (this->word.size() < word.size()) {
		for (int i = 0; i < (word.size() - this->word.size()); i++) {
			this->word.push_back(' ');
			sprite letter(0, 0, 10, 21, false, "Sprites/blu.bmp", 0, 0, scale);
			letters.push_back(letter);
		}
	}
	for (int i = 0; i < word.size(); i++) {
		if (this->word.at(i) != word.at(i)) {
			sprite letter(0, 0, 10, 21, false, "Sprites/blu.bmp", 0, 0, scale);

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

			letter.moveTo(x, y);
			letters.at(i) = letter;
		}

		x += letters.at(i).getRectangle().w * scale;
		if (word.at(i) == '\n') {
			y += 21 * scale;
			x = xPos;
		}
	}
	this->word = word;
}