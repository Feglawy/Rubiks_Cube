#include "rubiks_cube.hpp"

int main()
{
    RubiksCube cube;
    cube.rotateBottomClockwise();

    cube.displayCube();
    return EXIT_SUCCESS;
}