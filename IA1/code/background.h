#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL/SDL.h>
#include "defs.h"

struct Background
{
	SDL_Surface *backgroundImg;
	SDL_Rect backgroundPos;
};
typedef struct Background Background;


int init_background(Background* B, char* path);
void display_background(Background B,SDL_Surface *screen);
void freeBackground(Background* B);
int loadBackground(Background* B, char* path);
void initBackground(Background* B);

#endif
