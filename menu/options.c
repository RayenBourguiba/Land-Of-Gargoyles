#include "options.h"

/**
* @file options.c
* @brief Testing options.
* @author Rayen Bourguiba
* @version 0.1
*
* Testing program for quit from the game 
*
*/
void option(SDL_Surface *screen)
{
  SDL_Surface *background=NULL;
  opt c;
  SDL_Rect posback;
  SDL_Event event;
  int n=0,x=0;
  int done=1;

  c.pos.x=90;
  c.pos.y=70;

  posback.x=600;
  posback.y=500;

  background=IMG_Load("menu.png");
  c.op[0]=SDL_LoadBMP("son0.bmp");
  c.op[1]=SDL_LoadBMP("son1.bmp");
  c.op[2]=SDL_LoadBMP("son2.bmp");

  c.backbutton[0]=SDL_LoadBMP("back0.BMP");
  c.backbutton[1]=SDL_LoadBMP("back1.BMP");
  c.backbutton[2]=SDL_LoadBMP("back2.BMP");
  while (done!=0)
  {
      SDL_BlitSurface(background,NULL,screen,NULL);
      SDL_BlitSurface(c.backbutton[n],NULL,screen,&posback);
      SDL_BlitSurface(c.op[x],NULL,screen,&c.pos);
      SDL_Flip(screen);
      SDL_WaitEvent(&event);
          switch(event.type)
          {
          case SDL_QUIT:
                done=0;
                break;
          case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                done=0;
                break;
                        case SDLK_LEFT:
            if (x==0)
            {
                x=1;
            }else if (x==1)
            {
                x=2;
            }
            break;
        case SDLK_RIGHT:
           if (x==2)
            {
                x=1;
            }else if (x==1)
            {
                x=0;
            }
            break;
          }
            case SDL_MOUSEMOTION:
                if ((event.motion.x>600) && (event.motion.y>500) && (event.motion.x<765) && (event.motion.y<550))
                {
                    n=1;
                }else
                {
                    n=0;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ((event.motion.x>600) && (event.motion.y>500) && (event.motion.x<765) && (event.motion.y<550))
                {
                    SDL_BlitSurface(c.backbutton[2],NULL,screen,&posback);
                    SDL_Flip(screen);
                    SDL_Delay(50);
                    done=0;
                    //return 1;
                    //SDL_FreeSurface(backbutton[1]);
                   // SDL_FreeSurface(backbutton[2]);
                }
                break;
          }
  }
}
