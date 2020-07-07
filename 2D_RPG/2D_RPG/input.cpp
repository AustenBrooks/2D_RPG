#include "input.h"

input::input() {
}

bool input::isKeyPressed(SDL_Scancode key) {
	return keyPressed[key];
}

bool input::isKeyReleased(SDL_Scancode key) {
	return keyReleased[key];
}

bool input::isKeyHeld(SDL_Scancode key) {
	return keyHeld[key];
}

void input::clearKeys() {
	for (int i = 0; i < 284; i++) {
		keyPressed[i] = false;
		keyReleased[i] = false;
	}
}

void input::clearAll() {
	for (int i = 0; i < 284; i++) {
		keyPressed[i] = false;
		keyReleased[i] = false;
		keyHeld[i] = false;
	}
}

void input::pressKey(SDL_Scancode key) {
	keyPressed[key] = true;
	keyHeld[key] = true;
}
void input::releaseKey(SDL_Scancode key) {
	keyReleased[key] = true;
	keyHeld[key] = false;
}

