#ifndef OBSTACLES_H
#define OBSTACLES_H

#include <vector>

#include "SDL.h"
#include "constants.h"

class Obstacles {
   public:
    int block_h = kScreenHeight / kGridHeight;
    int block_w = kScreenWidth / kGridWidth;
    std::vector<SDL_Rect> l1{
        SDL_Rect{0, 0, kScreenWidth, block_h},
        SDL_Rect{0, kScreenHeight - block_h, kScreenWidth, kScreenHeight},
        SDL_Rect{0, 0, block_w, kScreenHeight},
        SDL_Rect{kScreenWidth - block_w, 0, kScreenWidth, kScreenHeight},
    };
    std::vector<SDL_Rect> l2{
        SDL_Rect{kScreenWidth / 4, kScreenHeight / 4, block_w, kScreenHeight / 2},
        SDL_Rect{kScreenWidth * 3 / 4, kScreenHeight / 4, block_w, kScreenHeight / 2},
    };
    std::vector<SDL_Rect> l3{
        SDL_Rect{0, 0, kScreenWidth, block_h},
        SDL_Rect{0, kScreenHeight - block_h, kScreenWidth, kScreenHeight},
        SDL_Rect{0, 0, block_w, kScreenHeight},
        SDL_Rect{kScreenWidth - block_w, 0, kScreenWidth, kScreenHeight},
        SDL_Rect{kScreenWidth / 4, kScreenHeight / 4, block_w, kScreenHeight / 2},
        SDL_Rect{kScreenWidth * 3 / 4, kScreenHeight / 4, block_w, kScreenHeight / 2},
    };
};
#endif