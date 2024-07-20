#pragma once
#include <SDL_image.h>

SDL_Texture* loadTexture(char* filename, SDL_Renderer* renderer);
void blit(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y);