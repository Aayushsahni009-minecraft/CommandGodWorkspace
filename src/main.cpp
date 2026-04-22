#include <SDL.h>
#include <iostream>
#include "ManifestGenerator.h"

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return 1;
    }

    // Create a Window (This will fill the phone screen)
    SDL_Window* window = SDL_CreateWindow("Command God Workspace", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if (!window) {
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;

    // Main App Loop
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
        }

        // Just a clear screen for now (Green like Minecraft grass!)
        SDL_Surface* screen = SDL_GetWindowSurface(window);
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 50, 150, 50));
        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}