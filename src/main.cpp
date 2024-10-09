#include "rubiks_cube.hpp"
#include "RUBIKS_CUBE/GameManager.hpp"
#include "RUBIKS_CUBE/Move.hpp"

int main()
{
    makeConsoleUTF8;
    clearConsole;

    GameManager game;
    game.run();

    return EXIT_SUCCESS;
}