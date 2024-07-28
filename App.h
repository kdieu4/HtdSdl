#pragma once
#include <SDL.h>
#include <stdio.h>
#include "defs.h"
#include "ScreenMode.h"

class App {
	

	void initSdl();
	void doInput(void);
	void prepareScene(void);
	void presentScene(void);

public:
	SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Surface* currentSurface;
	ScreenMode screenMode = Surface;
	void run(void);
};