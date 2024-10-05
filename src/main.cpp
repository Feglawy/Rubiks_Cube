#include "rubiks_cube.hpp"
#include "RUBIKS_CUBE/Move.hpp"

int main()
{
    makeConsoleUTF8;
    clearConsole;

    RubiksCube cube;
    cube.shuffle();
    // cube.solve();
    cube.displayCube();

    return EXIT_SUCCESS;
}