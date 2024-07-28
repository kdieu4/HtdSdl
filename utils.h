#pragma once
#include <SDL_image.h>
#include<string>
using namespace std;

SDL_Texture* loadTexture(string filename, SDL_Renderer* renderer);
void blit(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y);
SDL_Surface* loadSurface(string path);