#include <SDL.h>
#include <cstdlib>
#include <iostream>

/**
 * @brief Prints basic information about an SDL_Surface.
 * 
 * This includes width, height, and bytes per pixel. If the surface is null,
 * an error message is printed instead.
 * 
 * @param surface Pointer to the SDL_Surface to inspect.
 */
void print_surface_info(SDL_Surface* surface)
{
    if (surface) {
        std::cout << "Surface info:" << std::endl;
        std::cout << " - Width: " << surface->w << std::endl;
        std::cout << " - Height: " << surface->h << std::endl;
        std::cout << " - Bytes per pixel: " << surface->format->BytesPerPixel << std::endl;
    } else {
        std::cerr << "Surface is null." << std::endl;
    }
}

/**
 * @brief Initializes SDL and creates a new window.
 * 
 * This function initializes the SDL video subsystem and creates a centered window
 * with the specified dimensions. If initialization or window creation fails, 
 * appropriate error messages are logged and nullptr is returned.
 * 
 * @param windowName Title of the window.
 * @param width Width of the window in pixels.
 * @param height Height of the window in pixels.
 * @return SDL_Window* Pointer to the created SDL_Window, or nullptr on failure.
 */
SDL_Window* create_window(const char* windowName, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL init failed: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_Window* window = SDL_CreateWindow(
        windowName, 
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 
        width, height, 
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return nullptr;
    }

    return window;
}

/**
 * @brief Retrieves the SDL_Surface associated with a window.
 * 
 * @param window Pointer to the SDL_Window whose surface is to be retrieved.
 * @return SDL_Surface* Pointer to the window's surface, or nullptr on failure.
 */
SDL_Surface* get_window_surface(SDL_Window* window)
{
    if (!window) return nullptr;

    SDL_Surface* surface = SDL_GetWindowSurface(window);
    if (!surface) {
        std::cerr << "Failed to get window surface: " << SDL_GetError() << std::endl;
    }
    return surface;
}

/**
 * @brief Updates the window surface to display any modifications made to it.
 * 
 * Typically called after drawing or filling the surface.
 * 
 * @param window Pointer to the SDL_Window to refresh.
 */
void refresh_window(SDL_Window* window)
{
    if (!window) return;
    SDL_UpdateWindowSurface(window);
}

/**
 * @brief Cleans up SDL resources associated with the window.
 * 
 * Destroys the given SDL_Window and shuts down all initialized SDL subsystems.
 * 
 * @param window Pointer to the SDL_Window to destroy. Can be nullptr.
 */
void cleanup_window(SDL_Window* window)
{
    if (window) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}
