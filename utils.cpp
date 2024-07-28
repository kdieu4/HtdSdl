#include <SDL.h>
#include <SDL_image.h>
#include<string>
#include "utils.h"
using namespace std;

SDL_Texture* loadTexture(string filename, SDL_Renderer* renderer)
{
    SDL_Texture* texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename.c_str());

    texture = IMG_LoadTexture(renderer, filename.c_str());

    return texture;
}

void blit(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

SDL_Surface* loadSurface(string path)
{
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    }

    return loadedSurface;
}
