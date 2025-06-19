#include <SDL.h>
#include <cstdlib>
#include <iostream>

void print_random_data(SDL_Surface* surface)
{
    if (surface) {
        int bytesPerPixel = surface->format->BytesPerPixel;
        std::cout << "Bytes per pixel: " << bytesPerPixel << std::endl;
    }
}

int main()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL init failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow(
        "Blinking Screen", 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        900, 700, 
        SDL_WINDOW_SHOWN  // Important: make window visible
    );

    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Get surface and print info
    SDL_Surface* surface = SDL_GetWindowSurface(window);
    print_random_data(surface);

    // Fill with a color so we can see something
    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 255, 0, 0)); // Red
    
    // CRUCIAL: Update the window surface to display changes
    SDL_UpdateWindowSurface(window);

    std::cout << "Window should be visible now. Waiting 3 seconds..." << std::endl;
    
    // Wait 3 seconds
    SDL_Delay(3000);

    // Cleanup
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}