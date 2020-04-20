#include "renderer.h"

#include <iostream>

// int Snake::level;

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create Window
    sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, screen_width,
                                  screen_height, SDL_WINDOW_SHOWN);

    if (nullptr == sdl_window) {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == sdl_renderer) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }
}

Renderer::~Renderer() {
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

void Renderer::Render(Snake const snake, SDL_Point const &food) {
    SDL_Rect block;
    block.w = screen_width / grid_width;
    block.h = screen_height / grid_height;

    for (int i = 0; i < grid_width; i++)
        for (int j = 0; j < grid_height; j++) {
            block.x = i * block.w;
            block.y = j * block.h;
            if ((i + j) % 2 == 0)
                SDL_SetRenderDrawColor(sdl_renderer, 0xA2, 0xD1, 0x49, 0xFF);
            else
                SDL_SetRenderDrawColor(sdl_renderer, 0xAA, 0xD7, 0x51, 0xFF);
            SDL_RenderFillRect(sdl_renderer, &block);
        }

    // Clear screen
    // SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    // SDL_RenderClear(sdl_renderer);

    // Render food
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
    block.x = food.x * block.w;
    block.y = food.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);

    // Render snake's body
    SDL_SetRenderDrawColor(sdl_renderer, 0x48, 0x75, 0xEB, 0xFF);
    for (SDL_Point const &point : snake.body) {
        block.x = point.x * block.w;
        block.y = point.y * block.h;
        SDL_RenderFillRect(sdl_renderer, &block);
    }

    // Render obstacles
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0x00, 0xFF);
    Obstacles ob;
    switch (snake.level) {
        case 1:
            for (auto &i : ob.l1)
                SDL_RenderFillRect(sdl_renderer, &i);
            break;
        case 2:
            for (auto &i : ob.l2)
                SDL_RenderFillRect(sdl_renderer, &i);
            break;
        case 3:
            for (auto &i : ob.l3)
                SDL_RenderFillRect(sdl_renderer, &i);
            break;
        default:
            break;
    }

    // Render snake's head
    block.x = static_cast<int>(snake.head_x) * block.w;
    block.y = static_cast<int>(snake.head_y) * block.h;
    if (snake.alive) {
        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    } else {
        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    }
    SDL_RenderFillRect(sdl_renderer, &block);

    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(std::string diff, int level, int score, int fps) {
    std::string title{"Snake " + diff + " Level: " + std::to_string(level) + " Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(sdl_window, title.c_str());
}
