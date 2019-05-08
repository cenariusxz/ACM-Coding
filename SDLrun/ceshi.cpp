#include <iostream>
#include "SDL/SDL.h"
using namespace std;

void pressESCtoQuit();
void doSomeLoopThings();

int main(int argc,char* argv[])
{
	try {
		if ( SDL_Init(SDL_INIT_VIDEO == -1 ))
			throw SDL_GetError();
	}
	catch ( const char* s ) {
		cerr << s << std::endl;
		return -1;
	}
	atexit(SDL_Quit);

	
	SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
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
