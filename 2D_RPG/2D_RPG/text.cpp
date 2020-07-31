#include "text.h"

text::text(string word, int xPos, int yPos, float scale) {
	this->word = word;
	int x = xPos;
	int y = yPos;
	for (int i = 0; i < word.size(); i++) {
		sprite letter(0, 0, 10, 21, false, "Sprites/blu.bmp", 0, 0, scale);
		
		//numbers
		if (word.at(i) == '0') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 0, 0, scale);
		}
		else if (word.at(i) == '1') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 10, 0, scale);
		}
		else if (word.at(i) == '2') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 20, 0, scale);
		}
		else if (word.at(i) == '3') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 30, 0, scale);
		}
		else if (word.at(i) == '4') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 40, 0, scale);
		}
		else if (word.at(i) == '5') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 50, 0, scale);
		}
		else if (word.at(i) == '6') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 60, 0, scale);
		}
		else if (word.at(i) == '7') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 70, 0, scale);
		}
		else if (word.at(i) == '8') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 80, 0, scale);
		}
		else if (word.at(i) == '9') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 90, 0, scale);
		}

		//letters
		else if (word.at(i) == 'a') {
			letter.setSprite(0, 0, 11, 21, false, textSprite, 1, 21, scale);
		}
		else if (word.at(i) == 'b') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 12, 21, scale);
		}
		else if (word.at(i) == 'c') {
			letter.setSprite(0, 0, 8, 21, false, textSprite, 22, 21, scale);
		}
		else if (word.at(i) == 'd') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 30, 21, scale);
		}
		else if (word.at(i) == 'e') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 40, 21, scale);
		}
		else if (word.at(i) == 'f') {
			letter.setSprite(0, 0, 6, 21, false, textSprite, 50, 21, scale);
		}
		else if (word.at(i) == 'g') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 56, 21, scale);
		}
		else if (word.at(i) == 'h') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 66, 21, scale);
		}
		else if (word.at(i) == 'i') {
			letter.setSprite(0, 0, 3, 21, false, textSprite, 76, 21, scale);
		}
		else if (word.at(i) == 'j') {
			letter.setSprite(0, 0, 7, 21, false, textSprite, 79, 21, scale);
		}
		else if (word.at(i) == 'k') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 86, 21, scale);
		}
		else if (word.at(i) == 'l') {
			letter.setSprite(0, 0, 4, 21, false, textSprite, 95, 21, scale);
		}
		else if (word.at(i) == 'm') {
			letter.setSprite(0, 0, 16, 21, false, textSprite, 2, 42, scale);
		}
		else if (word.at(i) == 'n') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 18, 42, scale);
		}
		else if (word.at(i) == 'o') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 28, 42, scale);
		}
		else if (word.at(i) == 'p') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 38, 42, scale);
		}
		else if (word.at(i) == 'q') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 48, 42, scale);
		}
		else if (word.at(i) == 'r') {
			letter.setSprite(0, 0, 7, 21, false, textSprite, 58, 42, scale);
		}
		else if (word.at(i) == 's') {
			letter.setSprite(0, 0, 8, 21, false, textSprite, 65, 42, scale);
		}
		else if (word.at(i) == 't') {
			letter.setSprite(0, 0, 6, 21, false, textSprite, 73, 42, scale);
		}
		else if (word.at(i) == 'u') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 79, 42, scale);
		}
		else if (word.at(i) == 'v') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 89, 42, scale);
		}
		else if (word.at(i) == 'w') {
			letter.setSprite(0, 0, 13, 21, false, textSprite, 31, 63, scale);
		}
		else if (word.at(i) == 'x') {
			letter.setSprite(0, 0, 9, 21, false, textSprite, 44, 63, scale);
		}
		else if (word.at(i) == 'y') {
			letter.setSprite(0, 0, 9, 21, false, textSprite, 53, 63, scale);
		}
		else if (word.at(i) == 'z') {
			letter.setSprite(0, 0, 9, 21, false, textSprite, 62, 63, scale);
		}
		else if (word.at(i) == 'A') {
			letter.setSprite(0, 0, 11, 21, false, textSprite, 3, 84, scale);
		}
		else if (word.at(i) == 'B') {
			letter.setSprite(0, 0, 11, 21, false, textSprite, 14, 84, scale);
		}
		else if (word.at(i) == 'C') {
			letter.setSprite(0, 0, 11, 21, false, textSprite, 25, 84, scale);
		}
		else if (word.at(i) == 'D') {
			letter.setSprite(0, 0, 12, 21, false, textSprite, 36, 84, scale);
		}
		else if (word.at(i) == 'E') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 48, 84, scale);
		}
		else if (word.at(i) == 'F') {
			letter.setSprite(0, 0, 9, 21, false, textSprite, 58, 84, scale);
		}
		else if (word.at(i) == 'G') {
			letter.setSprite(0, 0, 12, 21, false, textSprite, 67, 84, scale);
		}
		else if (word.at(i) == 'H') {
			letter.setSprite(0, 0, 12, 21, false, textSprite, 79, 84, scale);
		}
		else if (word.at(i) == 'I') {
			letter.setSprite(0, 0, 7, 21, false, textSprite, 91, 84, scale);
		}
		else if (word.at(i) == 'J') {
			letter.setSprite(0, 0, 5, 21, false, textSprite, 8, 105, scale);
		}
		else if (word.at(i) == 'K') {
			letter.setSprite(0, 0, 11, 21, false, textSprite, 13, 105, scale);
		}
		else if (word.at(i) == 'L') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 24, 105, scale);
		}
		else if (word.at(i) == 'M') {
			letter.setSprite(0, 0, 12, 21, false, textSprite, 34, 105, scale);
		}
		else if (word.at(i) == 'N') {
			letter.setSprite(0, 0, 12, 21, false, textSprite, 46, 105, scale);
		}
		else if (word.at(i) == 'O') {
			letter.setSprite(0, 0, 13, 21, false, textSprite, 58, 105, scale);
		}
		else if (word.at(i) == 'P') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 71, 105, scale);
		}
		else if (word.at(i) == 'Q') {
			letter.setSprite(0, 0, 12, 21, false, textSprite, 81, 105, scale);
		}
		else if (word.at(i) == 'R') {
			letter.setSprite(0, 0, 12, 21, false, textSprite, 4, 126, scale);
		}
		else if (word.at(i) == 'S') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 16, 126, scale);
		}
		else if (word.at(i) == 'T') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 26, 126, scale);
		}
		else if (word.at(i) == 'U') {
			letter.setSprite(0, 0, 12, 21, false, textSprite, 36, 126, scale);
		}
		else if (word.at(i) == 'V') {
			letter.setSprite(0, 0, 12, 21, false, textSprite, 48, 126, scale);
		}
		else if (word.at(i) == 'W') {
			letter.setSprite(0, 0, 15, 21, false, textSprite, 60, 126, scale);
		}
		else if (word.at(i) == 'X') {
			letter.setSprite(0, 0, 10, 21, false, textSprite, 75, 126, scale);
		}
		else if (word.at(i) == 'Y') {
			letter.setSprite(0, 0, 12, 21, false, textSprite, 85, 126, scale);
		}
		else if (word.at(i) == 'Z') {
			letter.setSprite(0, 0, 11, 21, false, textSprite, 45, 147, scale);
		}

		//misc char
		else if (word.at(i) == '.') {
			letter.setSprite(0, 0, 4, 21, false, textSprite, 23, 168, scale);
		}
		else if (word.at(i) == ',') {
			letter.setSprite(0, 0, 5, 21, false, textSprite, 27, 168, scale);
		}
		else if (word.at(i) == '/') {
			letter.setSprite(0, 0, 9, 21, false, textSprite, 32, 168, scale);
		}
		else if (word.at(i) == ':') {
			letter.setSprite(0, 0, 5, 21, false, textSprite, 41, 168, scale);
		}
		else if (word.at(i) == ' ') {
			letter.setSprite(0, 0, 6, 21, false, textSprite, 0, 189, scale);
		}
		else if (word.at(i) == '\n') {
			y += 21 * scale;
			x = xPos;
			letter.setSprite(0, 0, 0, 0, false, textSprite, 0, 0, scale);
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
			sprite letter(0, 0, 6, 21, false, textSprite, 0, 189, scale);
			letters.push_back(letter);
		}
	}
	for (int i = 0; i < word.size(); i++) {
		if (this->word.at(i) != word.at(i)) {
			sprite letter(0, 0, 10, 21, false, "Sprites/blu.bmp", 0, 0, scale);

			//numbers
			if (word.at(i) == '0') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 0, 0, scale);
			}
			else if (word.at(i) == '1') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 10, 0, scale);
			}
			else if (word.at(i) == '2') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 20, 0, scale);
			}
			else if (word.at(i) == '3') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 30, 0, scale);
			}
			else if (word.at(i) == '4') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 40, 0, scale);
			}
			else if (word.at(i) == '5') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 50, 0, scale);
			}
			else if (word.at(i) == '6') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 60, 0, scale);
			}
			else if (word.at(i) == '7') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 70, 0, scale);
			}
			else if (word.at(i) == '8') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 80, 0, scale);
			}
			else if (word.at(i) == '9') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 90, 0, scale);
			}

			//letters
			else if (word.at(i) == 'a') {
				letter.setSprite(0, 0, 11, 21, false, textSprite, 1, 21, scale);
			}
			else if (word.at(i) == 'b') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 12, 21, scale);
			}
			else if (word.at(i) == 'c') {
				letter.setSprite(0, 0, 8, 21, false, textSprite, 22, 21, scale);
			}
			else if (word.at(i) == 'd') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 30, 21, scale);
			}
			else if (word.at(i) == 'e') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 40, 21, scale);
			}
			else if (word.at(i) == 'f') {
				letter.setSprite(0, 0, 6, 21, false, textSprite, 50, 21, scale);
			}
			else if (word.at(i) == 'g') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 56, 21, scale);
			}
			else if (word.at(i) == 'h') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 66, 21, scale);
			}
			else if (word.at(i) == 'i') {
				letter.setSprite(0, 0, 3, 21, false, textSprite, 76, 21, scale);
			}
			else if (word.at(i) == 'j') {
				letter.setSprite(0, 0, 7, 21, false, textSprite, 79, 21, scale);
			}
			else if (word.at(i) == 'k') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 86, 21, scale);
			}
			else if (word.at(i) == 'l') {
				letter.setSprite(0, 0, 4, 21, false, textSprite, 95, 21, scale);
			}
			else if (word.at(i) == 'm') {
				letter.setSprite(0, 0, 16, 21, false, textSprite, 2, 42, scale);
			}
			else if (word.at(i) == 'n') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 18, 42, scale);
			}
			else if (word.at(i) == 'o') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 28, 42, scale);
			}
			else if (word.at(i) == 'p') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 38, 42, scale);
			}
			else if (word.at(i) == 'q') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 48, 42, scale);
			}
			else if (word.at(i) == 'r') {
				letter.setSprite(0, 0, 7, 21, false, textSprite, 58, 42, scale);
			}
			else if (word.at(i) == 's') {
				letter.setSprite(0, 0, 8, 21, false, textSprite, 65, 42, scale);
			}
			else if (word.at(i) == 't') {
				letter.setSprite(0, 0, 6, 21, false, textSprite, 73, 42, scale);
			}
			else if (word.at(i) == 'u') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 79, 42, scale);
			}
			else if (word.at(i) == 'v') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 89, 42, scale);
			}
			else if (word.at(i) == 'w') {
				letter.setSprite(0, 0, 13, 21, false, textSprite, 31, 63, scale);
			}
			else if (word.at(i) == 'x') {
				letter.setSprite(0, 0, 9, 21, false, textSprite, 44, 63, scale);
			}
			else if (word.at(i) == 'y') {
				letter.setSprite(0, 0, 9, 21, false, textSprite, 53, 63, scale);
			}
			else if (word.at(i) == 'z') {
				letter.setSprite(0, 0, 9, 21, false, textSprite, 62, 63, scale);
			}
			else if (word.at(i) == 'A') {
				letter.setSprite(0, 0, 11, 21, false, textSprite, 3, 84, scale);
			}
			else if (word.at(i) == 'B') {
				letter.setSprite(0, 0, 11, 21, false, textSprite, 14, 84, scale);
			}
			else if (word.at(i) == 'C') {
				letter.setSprite(0, 0, 11, 21, false, textSprite, 25, 84, scale);
			}
			else if (word.at(i) == 'D') {
				letter.setSprite(0, 0, 12, 21, false, textSprite, 36, 84, scale);
			}
			else if (word.at(i) == 'E') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 48, 84, scale);
			}
			else if (word.at(i) == 'F') {
				letter.setSprite(0, 0, 9, 21, false, textSprite, 58, 84, scale);
			}
			else if (word.at(i) == 'G') {
				letter.setSprite(0, 0, 12, 21, false, textSprite, 67, 84, scale);
			}
			else if (word.at(i) == 'H') {
				letter.setSprite(0, 0, 12, 21, false, textSprite, 79, 84, scale);
			}
			else if (word.at(i) == 'I') {
				letter.setSprite(0, 0, 7, 21, false, textSprite, 91, 84, scale);
			}
			else if (word.at(i) == 'J') {
				letter.setSprite(0, 0, 5, 21, false, textSprite, 8, 105, scale);
			}
			else if (word.at(i) == 'K') {
				letter.setSprite(0, 0, 11, 21, false, textSprite, 13, 105, scale);
			}
			else if (word.at(i) == 'L') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 24, 105, scale);
			}
			else if (word.at(i) == 'M') {
				letter.setSprite(0, 0, 12, 21, false, textSprite, 34, 105, scale);
			}
			else if (word.at(i) == 'N') {
				letter.setSprite(0, 0, 12, 21, false, textSprite, 46, 105, scale);
			}
			else if (word.at(i) == 'O') {
				letter.setSprite(0, 0, 13, 21, false, textSprite, 58, 105, scale);
			}
			else if (word.at(i) == 'P') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 71, 105, scale);
			}
			else if (word.at(i) == 'Q') {
				letter.setSprite(0, 0, 12, 21, false, textSprite, 81, 105, scale);
			}
			else if (word.at(i) == 'R') {
				letter.setSprite(0, 0, 12, 21, false, textSprite, 4, 126, scale);
			}
			else if (word.at(i) == 'S') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 16, 126, scale);
			}
			else if (word.at(i) == 'T') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 26, 126, scale);
			}
			else if (word.at(i) == 'U') {
				letter.setSprite(0, 0, 12, 21, false, textSprite, 36, 126, scale);
			}
			else if (word.at(i) == 'V') {
				letter.setSprite(0, 0, 12, 21, false, textSprite, 48, 126, scale);
			}
			else if (word.at(i) == 'W') {
				letter.setSprite(0, 0, 15, 21, false, textSprite, 60, 126, scale);
			}
			else if (word.at(i) == 'X') {
				letter.setSprite(0, 0, 10, 21, false, textSprite, 75, 126, scale);
			}
			else if (word.at(i) == 'Y') {
				letter.setSprite(0, 0, 12, 21, false, textSprite, 85, 126, scale);
			}
			else if (word.at(i) == 'Z') {
				letter.setSprite(0, 0, 11, 21, false, textSprite, 45, 147, scale);
			}

			//misc char
			else if (word.at(i) == '.') {
				letter.setSprite(0, 0, 4, 21, false, textSprite, 23, 168, scale);
			}
			else if (word.at(i) == ',') {
				letter.setSprite(0, 0, 5, 21, false, textSprite, 27, 168, scale);
			}
			else if (word.at(i) == '/') {
				letter.setSprite(0, 0, 9, 21, false, textSprite, 32, 168, scale);
			}
			else if (word.at(i) == ':') {
				letter.setSprite(0, 0, 5, 21, false, textSprite, 41, 168, scale);
			}
			else if (word.at(i) == ' ') {
				letter.setSprite(0, 0, 6, 21, false, textSprite, 0, 189, scale);
			}
			else if (word.at(i) == '\n') {
				letter.setSprite(0, 0, 0, 0, false, textSprite, 0, 0, scale);
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