#include <iostream>
#include "SDL/SDL.h"
using namespace std;

const int SCREEN_WIDTH = 640;    // 0 means use current width.
const int SCREEN_HEIGHT = 480;    // 0 means use current height.
const int SCREEN_BPP = 32;        // 0 means use current bpp.
const Uint32 SCREEN_FLAGS = SDL_SWSURFACE;    // SDL_SWSURFACE == 0,surface in system memory.


void pressESCtoQuit();
void doSomeLoopThings();

int main(int argc,char* argv[])
{
	try {
		if ( SDL_Init(SDL_INIT_VIDEO) == -1 )
			throw SDL_GetError();
	}
	catch ( const char* s ) {
		cerr << s << std::endl;
		return -1;
	}
	atexit(SDL_Quit);

	SDL_Surface* pScreen = 0;
	pScreen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SCREEN_FLAGS);    // Creat a SDL window, and get the window's surface.
	try {
		if ( pScreen == 0 )
			throw SDL_GetError();
	}
	catch ( const char* s ) {
		std::cerr << "SDL_SetVideoMode() failed!/n" << s << std::endl;
		SDL_Quit();
		return -1;
	}



	SDL_Surface* pShownBMP = 0;
	pShownBMP = SDL_LoadBMP("hw.bmp"); // Load a BMP file, and convert it as a surface.
	try {
		if ( pShownBMP == 0 )
			throw SDL_GetError();
	}
	catch ( const char* s ) {
		std::cerr << "SDL_LoadBMP() failed!/n" << s << std::endl;
		SDL_Quit();
		return -1;
	}




	SDL_Rect* pSrcRect = 0;    // If pSrcRect is NULL, the entire source surface is copied. 

	SDL_Rect* pDstRect = 0;    // If pDstRect is NULL, then the destination position (upper left corner) is (0, 0).
	try {
		if ( SDL_BlitSurface(pShownBMP, pSrcRect, pScreen, pDstRect) != 0 )    // Put the BMP's surface on the SDL window's surface.
			throw SDL_GetError();
	}
	catch ( const char* s ) {
		std::cerr << "SDL_BlitSurface() failed!/n" << s << std::endl;
		SDL_Quit();
		return -1;
	}
	cout << "Program is running, press ESC to quit.\n";
	pressESCtoQuit();
	cout << "GAME OVER" << endl;

	return 0;
}

void pressESCtoQuit()
{
	cout << "pressESCtoQuit() function begin\n";
	bool gameOver = false;
	while( gameOver == false ){
		SDL_Event gameEvent;
		SDL_PollEvent(&gameEvent);
		if ( &gameEvent != 0 ){
			if ( gameEvent.type == SDL_QUIT ){
				gameOver = true;
			}
			if ( gameEvent.type == SDL_KEYDOWN ){
				if ( gameEvent.key.keysym.sym == SDLK_ESCAPE ){
					gameOver = true;
				}
			}
		}
//		doSomeLoopThings();
	}
	return;
}

void doSomeLoopThings()
{
	std::cout << ".";
	return;
}
