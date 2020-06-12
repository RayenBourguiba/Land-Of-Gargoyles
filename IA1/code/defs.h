#ifndef _DEFS_H
#define _DEFS_H

#define waiting 1
#define following 2
#define attack 3


#define BACKGND_W 1600
#define BACKGND_H 600
#define Hero_WIDTH 100
#define Hero_HEIGHT 100
#define Ennemi_WIDTH 100
#define Ennemi_HEIGHT 100
#define SCREEN_W 1600
#define SCREEN_H 600
#define SPRITE_HERO_NbL 4	// nombre d'images par ligne dans sprite sheet ace
#define SPRITE_HERO_NbCol 4	// nombre d'images par colonne dans sprite sheet ace
#define SPRITE_ENNEMI_NbL 4	// nombre d'images par ligne dans sprite sheet gargoyle
#define SPRITE_ENNEMI_NbCol 4	// nombre d'images par colonne dans sprite sheet gargoyle






typedef int bool;
enum { false, true };

typedef struct FRAME
{
	int i;	//num ligne imagette à afficher du sprite sheet
	int j;	//num ligne imagette à afficher du sprite sheet
}FRAME;

#endif
