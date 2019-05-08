#include <iostream>
#include <string>
#include "SDL/SDL.h"
using namespace std;

class ScreenSurface
{
	private:
		static int screenNum;
		int width;
		int height;
		int bpp;
		Uint32 flags;
		SDL_Surface* pScreen;
	public:
		ScreenSurface();
		ScreenSurface(int w, int h, int b = 0, Uint32 f = 0);
		~ScreenSurface();
		SDL_Surface* point() const;
		void flip() const;
};

class DisplaySurface
{
	private:
		string fileName;
		SDL_Surface* pSurface;
		SDL_Surface* pScreen;
	public:
		DisplaySurface(string file_name, const ScreenSurface& screen);
		~DisplaySurface();
		SDL_Surface* point() const;
		void blit() const;
		void blit(int at_x, int at_y) const;
		void blit(int at_x, int at_y,
				int from_x, int from_y, int w, int h,
				int delta_x = 2, int delta_y = 2) const;
		void blitToSurface(const DisplaySurface& dst_surface,
				int at_x = 0, int at_y = 0) const;
		void blitToSurface(const DisplaySurface& dst_surface,
				int at_x, int at_y,
				int from_x, int from_y, int w, int h,
				int delta_x = 2, int delta_y = 2) const;
};

class ErrorInfo
{
	private:
		string info;
	public:
		ErrorInfo():info("Unknown ERROR!")
	{}
		ErrorInfo(const char* c_str)
		{
			info = string(c_str);
		}
		ErrorInfo(const string& str):info(str)
	{}
		void show() const
		{
			std::cerr << info << std::endl;
		}
};

int ScreenSurface::screenNum = 0;

ScreenSurface::ScreenSurface():
	width(640), height(480), bpp(32), flags(0)
{
	if ( screenNum > 0 )
		throw ErrorInfo("DONOT create more than ONE screen!");
	if ( SDL_Init(SDL_INIT_VIDEO < 0 ) )
		throw ErrorInfo(SDL_GetError());
	pScreen = SDL_SetVideoMode(width, height, bpp, flags);
	screenNum++;
}

ScreenSurface::ScreenSurface(int w, int h, int b, Uint32 f):
	width(w), height(h), bpp(b), flags(f)
{
	if ( screenNum > 0 )
		throw ErrorInfo("DONOT create more than ONE screen!");
	if ( SDL_Init(SDL_INIT_VIDEO < 0 ) )
		throw ErrorInfo(SDL_GetError());
	pScreen = SDL_SetVideoMode(width, height, bpp, flags);
	screenNum++;
}

ScreenSurface::~ScreenSurface()
{
	SDL_Quit();
}

SDL_Surface* ScreenSurface::point() const
{
	return pScreen;
}

void ScreenSurface::flip() const
{
	if ( SDL_Flip(pScreen) < 0 )
		throw ErrorInfo(SDL_GetError());
}

//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

//VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
//class DisplaySurface

DisplaySurface::DisplaySurface(std::string file_name, const ScreenSurface& screen):
	fileName(file_name)
{
	pSurface = SDL_LoadBMP(file_name.c_str());
	if ( pSurface == 0 )
		throw ErrorInfo(SDL_GetError());
	pScreen = screen.point();
}

DisplaySurface::~DisplaySurface()
{
	SDL_FreeSurface(pSurface);
}

SDL_Surface* DisplaySurface::point() const
{
	return pSurface;
}

void DisplaySurface::blit() const
{
	if ( SDL_BlitSurface(pSurface, 0, pScreen, 0) < 0 )
		throw ErrorInfo(SDL_GetError());
}


void DisplaySurface::blit(int at_x, int at_y) const
{
	SDL_Rect offset;
	offset.x = at_x;
	offset.y = at_y;

	if ( SDL_BlitSurface(pSurface, 0, pScreen, &offset) < 0 )
		throw ErrorInfo(SDL_GetError());
}

void DisplaySurface::blit(int at_x, int at_y,
		int from_x, int from_y, int w, int h,
		int delta_x, int delta_y) const
{
	SDL_Rect offset;
	offset.x = at_x - delta_x;
	offset.y = at_y - delta_y;

	SDL_Rect dest;
	dest.x = from_x - delta_x;
	dest.y = from_y - delta_y;
	dest.w = w + delta_x*2;
	dest.h = h + delta_y*2;

	if ( SDL_BlitSurface(pSurface, &dest, pScreen, &offset) < 0 )
		throw ErrorInfo(SDL_GetError());
}

void DisplaySurface::blitToSurface(const DisplaySurface& dst_surface, int at_x, int at_y) const
{
	SDL_Rect offset;
	offset.x = at_x;
	offset.y = at_y;

	if ( &dst_surface == this )
		throw ErrorInfo("Cannot blit surface to itself!");

	if ( SDL_BlitSurface(pSurface, 0, dst_surface.point(), &offset) < 0 )
		throw ErrorInfo(SDL_GetError());
}

void DisplaySurface::blitToSurface(const DisplaySurface& dst_surface,
		int at_x, int at_y,
		int from_x, int from_y, int w, int h,
		int delta_x, int delta_y) const
{
	SDL_Rect offset;
	offset.x = at_x - delta_x;
	offset.y = at_y - delta_y;

	SDL_Rect dest;
	dest.x = from_x - delta_x;
	dest.y = from_y - delta_y;
	dest.w = w + delta_x*2;
	dest.h = h + delta_y*2;

	if ( &dst_surface == this )
		throw ErrorInfo("Cannot blit surface to itself!");

	if ( SDL_BlitSurface(pSurface, &dest, dst_surface.point(), &offset) < 0 )
		throw ErrorInfo(SDL_GetError());
}




int game(int argc, char* argv[]);
int main(int argc ,char* argv[])
{
	int mainRtn = 0;
	try {
		mainRtn = game(argc, argv);
	}
	catch ( const ErrorInfo& info ) {
		info.show();
		return -1;
	}

	return mainRtn;
}

int game(int argc ,char* argv[]){
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	ScreenSurface screen(SCREEN_WIDTH, SCREEN_HEIGHT);
	DisplaySurface backGround("bg.bmp", screen);
	DisplaySurface frontImage("image.bmp", screen);
	backGround.blit();
	screen.flip();
	int xpos = 0;
	int ypos = 0;
	int px = 0;
	int py = 0;
	int x=0;
	int y=0;
	const int IMG_WIDTH = 128;
	const int IMG_HEIGHT = 128;
	bool gameOver = false;
	bool flag=false;
	while( gameOver == false ){
		SDL_Event gameEvent;
		while ( SDL_PollEvent(&gameEvent) != 0 ){
			if ( gameEvent.type == SDL_QUIT ){
				gameOver = true;
			}
			if ( gameEvent.type == SDL_KEYUP ){
				if ( gameEvent.key.keysym.sym == SDLK_ESCAPE ){
					gameOver = true;
				}
			}
		//	if ( gameEvent.type == SDL_MOUSEMOTION ) {
		//		px = gameEvent.motion.x;
		//		py = gameEvent.motion.y;
		//	}
			if(gameEvent.type == SDL_MOUSEBUTTONDOWN){
				if(gameEvent.button.button==SDL_BUTTON_LEFT){
					int nx=gameEvent.button.x;
					int ny=gameEvent.button.y;
					if(nx>=xpos&&nx<=xpos+128&&ny>=ypos&&ny<=ypos+128){
						flag=true;
						x=nx-xpos,y=ny-ypos;
					}
				}
			}
			if(gameEvent.type == SDL_MOUSEBUTTONUP)flag=false;
			if(flag&&gameEvent.type==SDL_MOUSEMOTION){
				xpos=gameEvent.motion.x-x;
				ypos=gameEvent.motion.y-y;
			}
		}
//		if ( xpos < px )xpos++;
//		if ( xpos > px )xpos--;
//		if ( ypos < py )ypos++;
//		if ( ypos > py )ypos--;
		backGround.blit(0,0);
		frontImage.blit(xpos, ypos);
		screen.flip();
	}

	return 0;
}
