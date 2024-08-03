#pragma once
#include <SDL_image.h>
#include "utils.h"
#include "App.h"

class Entity
{
public:
	int x;
	int y;
	SDL_Texture* texture;
	App* app;
	Entity();
	Entity(App* app);
	~Entity();

	void draw();

private:

};

Entity::Entity()
{
	
}

inline Entity::Entity(App* app)
{
	x = 100;
	y = 100;
	this->app = app;
	texture = loadTexture(PLANE_1_RED, this->app->renderer);
}

Entity::~Entity()
{
}

void Entity::draw()
{
	switch (app->screenMode)
	{
	case Renderer:
		blit(app->renderer, texture, x, y);
		break;
	default:
		break;
	}
}
