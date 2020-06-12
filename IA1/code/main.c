#include "defs.h"
#include "jeu.h"
#include <SDL/SDL.h>


int main ( int argc, char** argv )
{

	SDL_Surface *screen;
	// initialize SDL video
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) 
	{
		printf( "Unable to init SDL: %s\n", SDL_GetError() );
		return 1;
	}

	// make sure SDL cleans up before exit
	atexit(SDL_Quit);

	// create a new window
	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32,
	                          SDL_HWSURFACE|SDL_DOUBLEBUF | SDL_SRCALPHA);
	if ( !screen ) 
	{
		printf("Unable to set %d * %d video: %s\n",SCREEN_W, SCREEN_H, SDL_GetError());
		return 1;
	}


	jouer(screen);


	// all is well ;)
	printf("Exited cleanly\n");
	return 0;
}
