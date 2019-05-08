#include<iostream>
#include"SDL/SDL.h"
using namespace std;

void beginSDL(){
	if(SDL_WasInit(SDL_INIT_EVERYTHING)!=0){
		cout<<"SDL is already running./n";
		return;
	}
	if(SDL_Init(SDL_INIT_EVERYTHING)==-1){
		throw "Unable to init SDL!";
	}
	cout<<"SDL is running successfully./n";
	return;
}

void endSDL(){
	if(SDL_WasInit(SDL_INIT_EVERYTHING)==0){
		cout<<"SDL was NOT running!/n";
		return;
	}
	SDL_Quit();
	cout<<"SDL_Quit successfully./n";
	return;
}
