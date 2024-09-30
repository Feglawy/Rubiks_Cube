#pragma once
#include "conf.hpp"

class RubiksCube
{
private:
    COLOR cube[FACES][ROWS][COLS];

public:
    RubiksCube();

    void fillFace(COLOR face);

    void displayFace(COLOR face);
    void displayCube();

    void shuffle();

    bool isSolved();

    void solve();

    void rotateFrontClockwise();
    void rotateFrontInverted();

    void rotateRightClockwise();
    void rotateRightInverted();

    void rotateUpClockwise();
    void rotateUpInverted();

    void rotateBackClockwise();
    void rotateBackInverted();

    void rotateLeftClockwise();
    void rotateLeftInverted();

    void rotateDownClockwise();
    void rotateDownInverted();

private:
    void rotateFaceClockwise(COLOR face);
    void rotateFaceInverted(COLOR face);
    bool isFaceSolved(COLOR face);
};
