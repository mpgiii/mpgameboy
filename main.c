#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 800;
const int HEIGHT = 600;

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Hello, world!",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
        SDL_WINDOW_ALLOW_HIGHDPI);

    if (!window) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event windowEvent;

    while (SDL_QUIT != windowEvent.type) {
        SDL_PollEvent(&windowEvent);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}