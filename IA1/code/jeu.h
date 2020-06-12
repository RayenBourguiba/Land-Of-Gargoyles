#ifndef JEU_H
#define JEU_H

#include <SDL/SDL.h>
#include "defs.h"
#include "background.h"
#include "ennemi.h"
#include "hero.h"
#include "text.h"

void get_input(int Tab_input[], SDL_Event event);
int jouer(SDL_Surface * screen);

#endif
