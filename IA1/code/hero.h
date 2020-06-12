#ifndef Hero_H
#define Hero_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"
#include "defs.h"


struct hero{
        SDL_Surface * image;
	SDL_Rect positionAnimation [SPRITE_HERO_NbL][SPRITE_HERO_NbCol];
	FRAME Frame;
	SDL_Rect positionAbsolue;
	int vies;
	int is_attacking;
};
typedef struct hero Hero;

int init_hero(Hero* H, char* path);
void update_hero(Hero* H, int Tab_input[], int HE_collision);

void display_hero(Hero H, SDL_Surface* screen);
void freeHero(Hero *H);

int loadHeroImages(Hero * H, char* path);
void initHeroAttributes(Hero *H);

void animateHero(Hero *H, int Tab_input[]);
void moveHero(Hero *H, int Tab_input[]);
void updateHeroScore(Hero* H, int HE_collision);




#endif
