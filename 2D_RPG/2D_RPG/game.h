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

bool mainMenu(window& gameWindow);

bool fight(window& gameWindow, character& player, character& enemy);

attributes chooseStats(window& gamewindow, character& player, int points);

bool willCollide(character& player, vector<sprite> objects, facing direction);

bool isGrounded(character& player, vector<sprite> objects);


#endif