#include<stdio.h>
#include "head.h"
//#include<SDL2/SDL.h>
using namespace std;

void Run(){
	SDL_Surface *pScreen=Creat(640,530);

	SDL_Surface *pic1=Creat("pic1.bmp");
	SDL_Surface *pic2=Creat("pic2.bmp");
	SDL_Surface *back1=Creat("back1.bmp");
	SDL_Surface *button1=Creat("button1.bmp");

	Blit(pic1,pScreen);
	Blit(back1,pScreen,0,480);
	Blit(button1,pScreen,0,480);

	Display(pScreen);

	bool Over=0,Mdown=0;
	int xpos=0,ypos=480;
	int x=0,y=0;
	int atx=0,aty=480;
	while(!Over){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type)
			{
				case SDL_QUIT:
					Over=1;
					break;
				case SDL_KEYUP:
					if(event.key.keysym.sym==SDLK_ESCAPE)Over=1;
					break;
				case SDL_MOUSEBUTTONDOWN:
					if(event.button.button==SDL_BUTTON_LEFT){
						int nx=event.button.x;
						int ny=event.button.y;
						if(nx>=atx&&nx<=atx+320&&ny>=aty&&ny<=aty+50){
							Mdown=1;
							x=nx-xpos;
						}
					}
					break;
				case SDL_MOUSEBUTTONUP:
					if(event.button.button==SDL_BUTTON_LEFT){
						Mdown=0;
						if(atx<=160){
							while(atx>0){
								atx-=2;
								Blit(back1,pScreen,0,480);
								Blit(button1,pScreen,atx,480);
								Display(pScreen);
							}
							if(atx<0)atx=0;
							xpos=0;
						}
						else{
							while(atx<320){
								atx+=2;
								Blit(back1,pScreen,0,480);
								Blit(button1,pScreen,atx,480);
								Display(pScreen);
							}
							if(atx>320)atx=320;
							xpos=320;
						}
					}
					break;
				case SDL_MOUSEMOTION:
					if(Mdown){
						xpos=event.motion.x-x;
						atx=xpos;
						if(atx<0)atx=0;
						if(atx>320)atx=320;
						if(atx<=160)Blit(pic1,pScreen);
						else Blit(pic2,pScreen);
						Blit(back1,pScreen,0,480);
						Blit(button1,pScreen,atx,480);
						Display(pScreen);
					}
					break;
				default:
					break;
			}
		}
	}
}

int main(){
	Init();
	Run();
	SDL_Quit();
	return 0;
}
