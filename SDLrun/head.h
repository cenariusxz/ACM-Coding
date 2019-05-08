#include<string>
#include<SDL/SDL.h>
using namespace std;

//SDL初始化
void Init(Uint32 Flags=SDL_INIT_EVERYTHING){
	if(SDL_Init(Flags)<0)
		throw SDL_GetError();
}

//创建界面
SDL_Surface* Creat(int Width,int Height,int Bbp=32,Uint32 Flags=0){
	SDL_Surface *tmp=SDL_SetVideoMode(Width,Height,Bbp,Flags);
	if(!tmp)throw SDL_GetError();
	return tmp;
}

//创建图片层
SDL_Surface* Creat(string Filename){
	SDL_Surface *tmp=SDL_LoadBMP(Filename.c_str());
	if(!tmp)throw SDL_GetError();
	return tmp;
}

void Blit(SDL_Surface *From,SDL_Surface *To,int From_x,int From_y,int To_x,int To_y){
	SDL_Rect offset1;
	offset1.x=From_x;
	offset1.y=From_y;
	SDL_Rect offset2;
	offset2.x=To_x;
	offset2.y=To_y;
	if(SDL_BlitSurface(From,&offset1,To,&offset2)<0)throw SDL_GetError();
}

void Blit(SDL_Surface *From,SDL_Surface *To,int To_x=0,int To_y=0){
	SDL_Rect offset2;
	offset2.x=To_x;
	offset2.y=To_y;
	if(SDL_BlitSurface(From,0,To,&offset2)<0)throw SDL_GetError();
}

void Display(SDL_Surface *Screen){
	if(SDL_Flip(Screen)<0)throw SDL_GetError();
}
