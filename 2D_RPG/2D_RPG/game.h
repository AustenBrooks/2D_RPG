#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "input.h"
#include "window.h"
#include "sprite.h"
#include "character.h"

bool mainMenu(window& newWindow, input inputs);

bool checkCollision(character& player, vector<sprite> objects, facing direction);

bool isGrounded(character& player, vector<sprite> objects);

#define FPS 60
#define FRAME_TIME (float)(1000 / FPS)

#endif