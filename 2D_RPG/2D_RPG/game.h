#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "input.h"
#include "window.h"
#include "sprite.h"
#include "character.h"
#include "keybinds.h"
#include "text.h"
#include "settings.h"

#include <iostream>

#define FPS 120
#define FRAME_TIME (float)(1000 / FPS)

bool mainMenu(window& newWindow);

bool willCollide(character& player, vector<sprite> objects, facing direction);

bool isGrounded(character& player, vector<sprite> objects);

bool fight(window& newWindow, character& player, character enemy);

#endif