#include "main.h"
/**
* @file main.c
* @brief Testing Program.
* @author OH my code 
* @version 0.1
* @date may 01, 2019
*
* Testing program for menu of the game 
*
*/
/**
* @brief To initialize the background b of the menu  .
* @param b the background
* @param url the url of the image
* @return int
*/
int main ( int argc, char** argv )
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *screen=NULL;
    SDL_Surface *background=NULL;
    buttons b;
    screen=SDL_SetVideoMode (1200,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Land Of Gargoyles",NULL);//titre de la fenetre
    SDL_WarpMouse(screen->w / 2, screen->h / 2);
    SDL_EnableKeyRepeat(100,100);
    background =IMG_Load("menu.png");
    SDL_Rect background_pos;
    SDL_Rect pxy,pxin,pxset,pxexit;
    SDL_Event event;
    background_pos.x=0;
    background_pos.y=0;
    pxy.x=20;
    pxy.y=200;
    pxin.x=20;
    pxin.y=300;
    pxset.x=20;
    pxset.y=400;
    pxexit.x=20;
    pxexit.y=500;
    int pp=2,op=0,ex=0,ins=0,t;
    int done=1;
    int motion=330;
    b.play[0]=IMG_Load("start.png");
    b.play[1]=IMG_Load("start1.png");
    b.play[2]=IMG_Load("start2.png");
    b.instructions[0]=IMG_Load("credits.png");
    b.instructions[1]=IMG_Load("credits1.png");
    b.instructions[2]=IMG_Load("credits2.png");
    b.setting[0]=IMG_Load("settings.png");
    b.setting[1]=IMG_Load("settings1.png");
    b.setting[2]=IMG_Load("settings2.png");
    b.exit[0]=IMG_Load("exit.png");
    b.exit[1]=IMG_Load("exit1.png");
    b.exit[2]=IMG_Load("exit2.png");
while (done!=0)
    {
        SDL_BlitSurface(background,NULL,screen,NULL);
        SDL_BlitSurface(b.play[pp],NULL,screen,&pxy);
        SDL_BlitSurface(b.instructions[ins],NULL,screen,&pxin);
        SDL_BlitSurface(b.setting[op],NULL,screen,&pxset);
        SDL_BlitSurface(b.exit[ex],NULL,screen,&pxexit);
        SDL_Flip(screen);
        t=0;
        if (SDL_WaitEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT :
                if (quit(screen)==1)
                    done=0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                   if (quit(screen)==1)
                        done=0;
                    break;
                case SDLK_UP:
                    if (pp==1 && t==0)
                    {
                        ex=1;
                        pp=0;
                        op=0;
                        ins=0;
                        t=1;
                    }
                    else if(ins==1 && t==0)
                    {
                        pp=1;
                        op=0;
                        ex=0;
                        ins=0;
                        t=1;
                    }
                    else if (op==1 && t==0)
                    {
                        ins=1;
                        ex=0;
                        pp=0;
                        op=0;
                        t=1;
                    }
                    else if (ex==1 && t==0)
                    {
                        op=1;
                        ex=0;
                        pp=0;
                        ins=0;
                        t=0;
                    }
                    break;
                case SDLK_DOWN:
                    if (pp==1 && t==0)
                    {
                        ins=1;
                        ex=0;
                        op=0;
                        pp=0;
                        t=1;
                    }
                    else if(ins==1 && t==0)
                    {
                        pp=0;
                        op=1;
                        ex=0;
                        ins=0;
                        t=1;
                    }
                    else if (op==1 && t==0)
                    {
                        ex=1;
                        pp=0;
                        ins=0;
                        op=0;
                        t=1;
                    }
                    else if (ex==1 && t==0)
                    {
                        pp=1;
                        op=0;
                        ins=0;
                        ex=0;
                        t=1;
                    }
                    break;
                case SDLK_RETURN:
                    if (pp==1)
                    {
                        SDL_BlitSurface(b.play[2],NULL,screen,&pxy);
                        SDL_Flip(screen);
                        //SDL_Delay(200);
                        //return NEW_GAME;
                    }
                    else if (ins==1)
                    {
                         SDL_BlitSurface(b.instructions[2],NULL,screen,&pxin);
                        SDL_Flip(screen);
                      instructions(screen);
                       ins=0;
                        //SDL_Delay(200);
                        //return OPTION;
                    }
                    else if (op==1)
                    {
                        SDL_BlitSurface(b.setting[2],NULL,screen,&pxset);
                        SDL_Flip(screen);
                        //SDL_Delay(200);
                        option(screen);
                    }
                    else if (ex==1)
                    {
                        SDL_BlitSurface(b.exit[2],NULL,screen,&pxexit);
                        SDL_Flip(screen);
                    if (quit(screen)==1)
                            done=0;
                        //SDL_Delay(200);
                    }
                    break;
                }
                break;
            case SDL_MOUSEMOTION:
                ex=0;
                pp=0;
                op=0;
                t=0;
                if ((event.motion.x>20)&&(event.motion.y>200)&&(event.motion.x<300)&&(event.motion.y<280) && (t==0) && (pp==0))
                {
                    pp=1;
                    ex=0;
                    ins=0;
                    op=0;
                    t=1;
                }
                else if ((event.motion.x>20)&&(event.motion.y>300)&&(event.motion.x<300)&&(event.motion.y<380) &&(t==0)&& (ins==0))
                {
                    ex=0;
                    pp=0;
                    ins=1;
                    op=0;
                    t=1;
                }
                else if ((event.motion.x>20)&&(event.motion.y>400)&&(event.motion.x<300)&&(event.motion.y<480)&&(t==0)&& (op==0))
                {
                    ex=0;
                    pp=0;
                    ins=0;
                    op=1;
                    t=1;
                }
                else if ((event.motion.x>20)&&(event.motion.y>500)&&(event.motion.x<300)&&(event.motion.y<580)&&(t==0)&& (ex==0))
                {
                    ex=1;
                    pp=0;
                    ins=0;
                    op=0;
                    t=1;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button==SDL_BUTTON_LEFT)
                {
                    if ((event.motion.x>20)&&(event.motion.y>200)&&(event.motion.x<300)&&(event.motion.y<280)&&(pp==1))
                    {
                        pp=2;
                        //SDL_Delay (200);
                        //play(screen);
                        //return NEW_GAME;
                    }
                    else if ((event.motion.x>20)&&(event.motion.y>300)&&(event.motion.x<300)&&(event.motion.y<380)&&(ins==1))
                    {
                        SDL_BlitSurface(b.instructions[2],NULL,screen,&pxin);
                        SDL_Flip(screen);
                        instructions(screen);
                       //ins=0;
                        //SDL_Delay (200);
                        //return OPTION;
                    }
                    else if ((event.motion.x>20)&&(event.motion.y>400)&&(event.motion.x<300)&&(event.motion.y<480)&&(op==1))
                    {
                        op=2;
                        option(screen);
                        //SDL_Delay (200);
                        //return OPTION;
                    }
                    else if (ex==1)
                    {
                        SDL_BlitSurface(b.exit[2],NULL,screen,&pxexit);
                        SDL_Flip(screen);
                        //SDL_Delay (200);
                        if (quit(screen)==1)
                            done=0;
                    }
                }
                break;
            }
        }
    }
    SDL_FreeSurface(background);
    SDL_FreeSurface(b.play[2]);
    SDL_FreeSurface(b.setting[2]);
    SDL_FreeSurface(b.exit[2]);
    SDL_FreeSurface(b.instructions[2]);
    SDL_Quit();
    return 0 ;
    }
/**
* @brief To clean the background b .
* @param b the buttons 
* @param url the url of the image
* @return Nothing
*/
void cleanmenu(SDL_Surface *background)
{
    buttons b;
    SDL_FreeSurface(background);
    SDL_FreeSurface(b.play[2]);
    SDL_FreeSurface(b.setting[2]);
    SDL_FreeSurface(b.exit[2]);
    SDL_FreeSurface(b.instructions[2]);
}
