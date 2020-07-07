#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>

class input {
private:
	bool keyPressed[284] = { false };
	bool keyReleased[284] = { false };
	bool keyHeld[284] = { false };

public:
	input();

	bool isKeyPressed(SDL_Scancode key);
	bool isKeyReleased(SDL_Scancode key);
	bool isKeyHeld(SDL_Scancode key);

	void clearKeys();
	void clearAll();
	void pressKey(SDL_Scancode key);
	void releaseKey(SDL_Scancode key);
};

#endif
