#ifndef TEXT_H
#define TEXT_H

#include <SDL.h>
#include <string>
#include <vector>
#include "sprite.h"

using std::string;
using std::vector;

class text {
private:
	string word;
	vector<sprite> letters;


public:
	//constructor
	text(string word, int xPos, int yPos, float scale);

	//function
	void createTextures(SDL_Renderer* renderer);
		
	//getter
	vector<sprite> getLetters();	

	//setter
	void setText(string word, int xPos, int yPos, float scale);
};

#endif