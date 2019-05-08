#include "head.h"
#include<stdio.h>
#include<time.h>

int main(){
	Init();
	SDL_Surface *p=Creat(640,480);
	Display(p);
	SDL_Surface *back=Creat("pic1.bmp");
	SDL_Surface *p1=Creat("image.bmp");
	SDL_Surface *p2=Creat("image.bmp");
	SDL_Surface *p3=Creat("image.bmp");

	int posx[4],posy[4];
	bool Over=0;
	int t=0;
	posx[1]=100,posy[1]=100;
	posx[2]=100,posy[2]=300;
	posx[3]=500,posy[3]=100;
	int tt=0;
	int minn=100000000;
	while(!Over){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			switch(event.type)
			{
				case SDL_QUIT:
					Over=1;
					break;
				case SDL_KEYUP:
					switch(event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							Over=1;
							break;
						case SDLK_w:
							posy[1]-=20;
							if(tt==0)tt=clock();
							else{
								int tt2=clock();
								if(tt2-tt<minn)minn=tt2-tt;
								tt=tt2;
							}
							if(posy[1]<0)posy[1]=0;
							break;
						case SDLK_s:
							posy[1]+=20;
							if(posy[1]>350)posy[1]=350;
							break;
						case SDLK_a:
							posx[1]-=20;
							if(posx[1]<0)posx[1]=0;
							break;
						case SDLK_d:
							posx[1]+=20;
							if(posx[1]>510)posx[1]=510;
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}
		}
		int t2=clock();
		if(t2-t>300000){
			for(int i=2;i<=3;++i){
				int tmp=rand()%4;
				switch(tmp){
					case 0:
						posy[i]-=20;
						if(posy[i]<0)posy[i]=0;
						break;
					case 1:
						posy[i]+=20;
						if(posy[i]>350)posy[i]=350;
						break;
					case 2:
						posx[i]-=20;
						if(posx[i]<0)posx[i]=0;
						break;
					case 3:
						posx[i]+=20;
						if(posx[i]>510)posx[i]=510;
						break;
					default:
						break;
				}
			}
			t=clock();
		}

		Blit(back,p);
		Blit(p1,p,posx[1],posy[1]);
		Blit(p2,p,posx[2],posy[2]);
		Blit(p3,p,posx[3],posy[3]);
		Display(p);
	}

	SDL_Quit();
	return 0;
}
