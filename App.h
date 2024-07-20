#pragma once
#include <SDL.h>
#include <stdio.h>
#include "defs.h"

class App {
	

	void initSdl();
	void doInput(void);
	void prepareScene(void);
	void presentScene(void);

public:
	SDL_Renderer* renderer;
	SDL_Window* window;
	void run(void);
};