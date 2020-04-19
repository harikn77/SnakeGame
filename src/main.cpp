#include <iostream>

#include "constants.h"
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
    int diff;
    std::cout << "Choose difficulty!\n";
    std::cout << "1.Easy\n2.Medium\n3.Hard\n";
    std::cin >> diff;
    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight, diff);
    game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Level: " << game.GetLevel() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";
    return 0;
}