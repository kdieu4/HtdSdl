#pragma once
#include "Entity.h"
#include <SDL.h>
#include "App.h"

class Player : public Entity
{
public:

	void userInput();
	Player();
	Player(App* app) : Entity(app){}
	~Player();

private:

};

Player::Player()
{
}


Player::~Player()
{
}

inline void Player::userInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			exit(0);
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				y -= 10;
				break;
			case SDLK_DOWN:
				y += 10;
				break;
			case SDLK_LEFT:
				x -= 10;
				break;
			case SDLK_RIGHT:
				x += 10;
				break;
			default:
				break;
			}
			break;

		default:
			break;
		}
	}
}