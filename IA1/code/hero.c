#include "hero.h"


int init_hero(Hero* H, char* path)
{
	int OK;

	OK = loadHeroImages(H, path);
	if (OK != -1)
	{
		initHeroAttributes(H);
	}
	
	return OK;
}

int loadHeroImages(Hero * H, char* path)
{
	H->image = IMG_Load(path);

	if(H->image == NULL) {
		printf("Unable to load Hero gif:%s\n", SDL_GetError());
		return (-1);
	}

	return (0);
}


void initHeroAttributes(Hero* H)
{	
	int i, j;	
	
	H->positionAbsolue.x = 0;
	H->positionAbsolue.y = 0.8 * BACKGND_H - Hero_HEIGHT;
	H->positionAbsolue.w = Hero_WIDTH;
	H->positionAbsolue.h = Hero_HEIGHT;
	H->Frame.i = 0;
	H->Frame.j = 0;
	
        // Faire le calcul des SDL_Rect des positions de toutes 
	// les imagettes une seule fois à l'initialisation
	for (i = 0; i < SPRITE_HERO_NbL; i++)
	{	for(j = 0; j < SPRITE_HERO_NbCol; j++)
		{	
			H->positionAnimation[i][j].x = j * Hero_WIDTH;
			H->positionAnimation[i][j].y = i * Hero_HEIGHT;
			H->positionAnimation[i][j].w = Hero_WIDTH;  
			H->positionAnimation[i][j].h = Hero_HEIGHT;
		}
	}
	H->vies = 100;
	H->is_attacking = 0;	
}


void display_hero(Hero H, SDL_Surface* screen)
{
	if (H.vies!=0)
	SDL_BlitSurface(H.image, &H.positionAnimation[H.Frame.i][H.Frame.j], screen, &H.positionAbsolue);
}


void update_hero(Hero* H, int Tab_input[], int HE_collision)
{

	animateHero(H, Tab_input);
	moveHero(H, Tab_input);
	updateHeroScore(H, HE_collision);
}


void animateHero(Hero *H, int Tab_input[])
{
	// mise a jour du numero de l'imagette 
		if(Tab_input[SDLK_RIGHT])
		{
			H->Frame.i = 0;
			H->Frame.j ++;    
			if (H->Frame.j == SPRITE_HERO_NbCol)   
		 		H->Frame.j = 0;
		}
		if(Tab_input[SDLK_LEFT])
		{
			H->Frame.i = 1;
			H->Frame.j ++;    
			if (H->Frame.j == SPRITE_HERO_NbCol)   
		 		H->Frame.j = 0;
		}	
}

void moveHero(Hero *H, int Tab_input[])
{
	if(Tab_input[SDLK_RIGHT])
        	H->positionAbsolue.x +=20;   
	if(Tab_input[SDLK_LEFT])
        	H->positionAbsolue.x -=20;   
}



void updateHeroScore(Hero* H, int HE_collision)
{
	if(HE_collision)
		if(H->vies > 0)
			H->vies --;
}


void freeHero(Hero *H)
{
	SDL_FreeSurface(H->image);
}
