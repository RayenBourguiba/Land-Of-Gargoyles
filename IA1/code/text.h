#ifndef TEXT_H
#define TEXT_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
struct text {
	SDL_Rect positionText;
	char txt[20];
	SDL_Color couleurTxt;
	SDL_Color couleurShadow;
	TTF_Font* police;
};
typedef struct text Text;

int  init_text(Text* T, char* path);
void update_txt(Text* T, int viesHero);
void displayText(Text T,SDL_Surface *screen);
void freeText(Text* T);
void initTextAttributes(Text* T);
int loadFont(Text* T, char* path);
//void displayText(TTF_Font *police,Text *T,SDL_Surface *screen,int viesHero);

#endif
