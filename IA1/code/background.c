#include <SDL/SDL_image.h>
#include "background.h"

//initialiser
void initBackgoundAttributes(Background *Backg)
{
	Backg->backgroundPos.x=0;
	Backg->backgroundPos.y=0;
	Backg->backgroundPos.w=SCREEN_W;
	Backg->backgroundPos.h=SCREEN_H;
}

int loadBackground(Background *Backg, char* path)
{

	Backg->backgroundImg = IMG_Load(path);
	if (Backg->backgroundImg == NULL) {
		printf("Unable to load backround image: %s\n", SDL_GetError());
		return (-1);
	}
	
	
	return (0);
}


int init_background(Background *B, char* path)
{
	int OK;
	OK = loadBackground(B, path);
	if (OK != -1)
	{
		initBackgoundAttributes(B);
	}
	
	return OK;
}



//afficher
void display_background(Background Backg,SDL_Surface *screen)
{
	SDL_BlitSurface(Backg.backgroundImg, &(Backg.backgroundPos), screen,NULL); 
}

//free
void freeBackground(Background *Backg)
{
	SDL_FreeSurface(Backg->backgroundImg);
}
