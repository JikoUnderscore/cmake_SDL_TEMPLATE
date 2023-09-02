#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#undef main
#include <iostream>


int main() {
    SDL_Renderer* renderer{};
    SDL_Window* window{};
    bool isRunning{ false };
    bool fullscreen;
    fullscreen = false;
    auto flags = 0;
    flags = SDL_WINDOW_RESIZABLE;
    if (fullscreen) {
        flags = flags | SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL_Init failed: %s\n", SDL_GetError());
        return -1;
    }
    printf("Subsystems Initialized!\n");
    window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, flags);
    if (window == nullptr) {
        printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
        return -1;
    }
    printf("Window Created!\n");


    SDL_SetWindowMinimumSize(window, 100, 100);
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr) {
        printf("SDL_CreateRenderer failed: %s\n", SDL_GetError());
        return -1;
    }
    (void)SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
    printf("Renderer created!\n");
    (void)SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    isRunning = true;
    while (isRunning) {
        { // events
            for (SDL_Event e{}; SDL_PollEvent(&e) == 1;) {
                switch (e.type) {
                    case SDL_QUIT: {
                        printf("quiting game\n");
                        isRunning = false;
                    } break;

                    default:
                        break;
                }
            }
        }


        {
            // update
        }


        { // render
            SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
            SDL_RenderClear(renderer);

            // your stuff to render would typically go here.
            SDL_RenderPresent(renderer);
        }
    }

    // frees memory associated with renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window); // error here
    SDL_Quit();


    return 0;
}
