#include "text.h"

text::text(string word, int xPos, int yPos, float scale) {
	this->word = word;
	int x = xPos;
	int y = yPos;
	for (int i = 0; i < word.size(); i++) {
		sprite letter(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, "Sprites/blu.bmp", 0, 0, scale);
		
		//numbers
		if (word.at(i) == '0') {
			int spriteLine = 0;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == '1') {
			int spriteLine = 1;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == '2') {
			int spriteLine = 2;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == '3') {
			int spriteLine = 3;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == '4') {
			int spriteLine = 4;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == '5') {
			int spriteLine = 5;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == '6') {
			int spriteLine = 6;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == '7') {
			int spriteLine = 7;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == '8') {
			int spriteLine = 8;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == '9') {
			int spriteLine = 9;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}

		//letters
		else if (word.at(i) == 'a') {
			int spriteLine = 10;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'b') {
			int spriteLine = 11;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'c') {
			int spriteLine = 12;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'd') {
			int spriteLine = 13;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'e') {
			int spriteLine = 14;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'f') {
			int spriteLine = 15;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'g') {
			int spriteLine = 16;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'h') {
			int spriteLine = 17;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'i') {
			int spriteLine = 18;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'j') {
			int spriteLine = 19;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'k') {
			int spriteLine = 20;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'l') {
			int spriteLine = 21;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'm') {
			int spriteLine = 22;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'n') {
			int spriteLine = 23;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'o') {
			int spriteLine = 24;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'p') {
			int spriteLine = 25;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'q') {
			int spriteLine = 26;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'r') {
			int spriteLine = 27;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 's') {
			int spriteLine = 28;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 't') {
			int spriteLine = 29;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'u') {
			int spriteLine = 30;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'v') {
			int spriteLine = 31;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'w') {
			int spriteLine = 32;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'x') {
			int spriteLine = 33;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'y') {
			int spriteLine = 34;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'z') {
			int spriteLine = 35;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'A') {
			int spriteLine = 36;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'B') {
			int spriteLine = 37;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'C') {
			int spriteLine = 38;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'D') {
			int spriteLine = 39;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'E') {
			int spriteLine = 40;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'F') {
			int spriteLine = 41;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'G') {
			int spriteLine = 42;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'H') {
			int spriteLine = 43;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'I') {
			int spriteLine = 44;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'J') {
			int spriteLine = 45;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'K') {
			int spriteLine = 46;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'L') {
			int spriteLine = 47;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'M') {
			int spriteLine = 48;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'N') {
			int spriteLine = 49;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'O') {
			int spriteLine = 50;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'P') {
			int spriteLine = 51;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'Q') {
			int spriteLine = 52;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'R') {
			int spriteLine = 53;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'S') {
			int spriteLine = 54;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'T') {
			int spriteLine = 55;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'U') {
			int spriteLine = 56;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'V') {
			int spriteLine = 57;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'W') {
			int spriteLine = 58;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'X') {
			int spriteLine = 59;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'Y') {
			int spriteLine = 60;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == 'Z') {
			int spriteLine = 61;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}

		//misc char
		else if (word.at(i) == ',') {
			int spriteLine = 62;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == '.') {
			int spriteLine = 63;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == '/') {
			int spriteLine = 64;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == ':') {
			int spriteLine = 65;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == ' ') {
			int spriteLine = 66;
			letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
		}
		else if (word.at(i) == '\n') {
			y += TEXT_HEIGHT * scale;
			x = xPos;
			letter.setSprite(0, 0, 0, 0, false, TEXT_SPRITE, 0, 0, scale);
		}

		letter.moveTo(x, y);
		letters.push_back(letter);

		if(word.at(i) != '\n'){
			x += TEXT_WIDTH * scale;
		}
		//x += letters.at(i).getRectangle().w * scale;
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
		int diff = this->word.size() - word.size();
		for (int i = 0; i < diff; i++) {
			this->word.pop_back();
			letters.pop_back();
		}
	}
	if (this->word.size() < word.size()) {
		int diff = word.size() - this->word.size();
		for (int i = 0; i < diff; i++) {
			this->word += ' ';
			sprite letter(0, 0, 6, 21, false, TEXT_SPRITE, 0, 189, scale);
			letters.push_back(letter);
		}
	}
	for (int i = 0; i < word.size(); i++) {
		if (this->word.at(i) != word.at(i)) {
			sprite letter(0, 0, 10, 21, false, "Sprites/blu.bmp", 0, 0, scale);

			//numbers
			if (word.at(i) == '0') {
				int spriteLine = 0;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == '1') {
				int spriteLine = 1;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == '2') {
				int spriteLine = 2;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == '3') {
				int spriteLine = 3;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == '4') {
				int spriteLine = 4;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == '5') {
				int spriteLine = 5;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == '6') {
				int spriteLine = 6;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == '7') {
				int spriteLine = 7;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == '8') {
				int spriteLine = 8;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == '9') {
				int spriteLine = 9;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}

			//letters
			else if (word.at(i) == 'a') {
				int spriteLine = 10;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'b') {
				int spriteLine = 11;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'c') {
				int spriteLine = 12;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'd') {
				int spriteLine = 13;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'e') {
				int spriteLine = 14;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'f') {
				int spriteLine = 15;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'g') {
				int spriteLine = 16;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'h') {
				int spriteLine = 17;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'i') {
				int spriteLine = 18;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'j') {
				int spriteLine = 19;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'k') {
				int spriteLine = 20;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'l') {
				int spriteLine = 21;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'm') {
				int spriteLine = 22;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'n') {
				int spriteLine = 23;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'o') {
				int spriteLine = 24;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'p') {
				int spriteLine = 25;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'q') {
				int spriteLine = 26;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'r') {
				int spriteLine = 27;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 's') {
				int spriteLine = 28;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 't') {
				int spriteLine = 29;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'u') {
				int spriteLine = 30;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'v') {
				int spriteLine = 31;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'w') {
				int spriteLine = 32;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'x') {
				int spriteLine = 33;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'y') {
				int spriteLine = 34;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'z') {
				int spriteLine = 35;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'A') {
				int spriteLine = 36;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'B') {
				int spriteLine = 37;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'C') {
				int spriteLine = 38;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'D') {
				int spriteLine = 39;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'E') {
				int spriteLine = 40;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'F') {
				int spriteLine = 41;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'G') {
				int spriteLine = 42;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'H') {
				int spriteLine = 43;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'I') {
				int spriteLine = 44;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'J') {
				int spriteLine = 45;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'K') {
				int spriteLine = 46;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'L') {
				int spriteLine = 47;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'M') {
				int spriteLine = 48;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'N') {
				int spriteLine = 49;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'O') {
				int spriteLine = 50;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'P') {
				int spriteLine = 51;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'Q') {
				int spriteLine = 52;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'R') {
				int spriteLine = 53;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'S') {
				int spriteLine = 54;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'T') {
				int spriteLine = 55;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'U') {
				int spriteLine = 56;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'V') {
				int spriteLine = 57;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'W') {
				int spriteLine = 58;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'X') {
				int spriteLine = 59;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'Y') {
				int spriteLine = 60;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == 'Z') {
				int spriteLine = 61;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}

			//misc char
			else if (word.at(i) == ',') {
				int spriteLine = 62;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == '.') {
				int spriteLine = 63;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == '/') {
				int spriteLine = 64;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == ':') {
				int spriteLine = 65;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == ' ') {
				int spriteLine = 66;
				letter.setSprite(0, 0, TEXT_WIDTH, TEXT_HEIGHT, false, TEXT_SPRITE, 0, spriteLine * TEXT_HEIGHT, scale);
			}
			else if (word.at(i) == '\n') {
				letter.setSprite(0, 0, 0, 0, false, TEXT_SPRITE, 0, 0, scale);
			}

			letter.moveTo(x, y);
			letters.at(i) = letter;
		}
		else {
			letters.at(i).moveTo(x, y);
		}

		x += letters.at(i).getRectangle().w * scale;
		if (word.at(i) == '\n') {
			y += TEXT_HEIGHT * scale;
			x = xPos;
		}
	}
	this->word = word;
}