#include "App.h"
#include <SDL_image.h>
#include "utils.h"
#include "Entity.h"

void App::initSdl()
{
	int rendererFlags = SDL_RENDERER_ACCELERATED;
	int windowFlags = 0;

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	window = SDL_CreateWindow("Shooter 01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!window)
	{
		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	renderer = SDL_CreateRenderer(window, -1, rendererFlags);

	if (!renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}
}

void App::doInput(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			exit(0);
			break;

		default:
			break;
		}
	}
}

void App::prepareScene(void)
{
	SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
	SDL_RenderClear(renderer);
}

void App::presentScene(void)
{
	SDL_RenderPresent(renderer);
}

void App::run(void)
{
	initSdl();
	Entity* player = new Entity(this);
	while (true)
	{
		prepareScene();

		doInput();

		player->draw();

		presentScene();

		SDL_Delay(16);
	}
}
