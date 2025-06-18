#include <SDL2/SDL.h>
#include <cstdlib>


void print_random_data(SDL_Surface* surface)
{
    int bytesPerPixel = surface->format->BytesPerPixel;
}

int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Blinking Screen", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 700, 0);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    print_random_data(surface);
    SDL_Delay(500);
    
}