#include<stdio.h>
#include<iostream>
#include"SDL/SDL.h"
using namespace std;

int main(int argc,char* argv[]){
	try{
		if(SDL_Init(SDL_INIT_EVERYTHING)==-1)throw "Could not initialize SDL!";
	}
	catch(const char*s){
		cerr<<s<<endl;
		return -1;
	}
	cout<<"SDL initialized.\n"<<endl;
	SDL_Quit();
	return 0;
}
