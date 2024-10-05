#pragma once
#include "conf.hpp"
#include "Move.hpp"
class RubiksCube
{
private:
    CUBE_PROPERTY cube[FACES][ROWS][COLS];
    const vector<char> validRotations = {
        'F', 'B', 'R', 'L', 'U', 'D'};

    using RotationFunction = function<void()>;

    unordered_map<char, pair<RotationFunction, RotationFunction>> rotationMap = {
        {'F', {bind(&RubiksCube::rotateFrontClockwise, this), bind(&RubiksCube::rotateFrontInverted, this)}},
        {'R', {bind(&RubiksCube::rotateRightClockwise, this), bind(&RubiksCube::rotateRightInverted, this)}},
        {'U', {bind(&RubiksCube::rotateUpClockwise, this), bind(&RubiksCube::rotateUpInverted, this)}},
        {'B', {bind(&RubiksCube::rotateBackClockwise, this), bind(&RubiksCube::rotateBackInverted, this)}},
        {'L', {bind(&RubiksCube::rotateLeftClockwise, this), bind(&RubiksCube::rotateLeftInverted, this)}},
        {'D', {bind(&RubiksCube::rotateDownClockwise, this), bind(&RubiksCube::rotateDownInverted, this)}},
        // {'M', {bind(&RubiksCube::middleSliceTurn, this), bind(&RubiksCube::middleInvertSliceTurn, this)}},
        // {'E', {bind(&RubiksCube::equatorialSliceTurn, this), bind(&RubiksCube::equatorialInvertSliceTurn, this)}},
        // {'S', {bind(&RubiksCube::standingSliceTurn, this), bind(&RubiksCube::standingInvertSliceTurn, this)}},
    };

public:
    RubiksCube();

    // displays a specific face of the cube
    void displayFace(CUBE_PROPERTY face);

    // displays the cube in a 2d way
    void displayCube();

    // shuffles the cube in a random way
    void shuffle();

    // returns whether or not the cube is solved or not
    bool isSolved();
    // Checks if a single face is solved or not
    bool isFaceSolved(CUBE_PROPERTY face);

    // solves the entire cube (NOT IMPLEMENTED YET)
    void solve();

    // F
    void rotateFrontClockwise();
    // F`
    void rotateFrontInverted();

    // R
    void rotateRightClockwise();
    // R`
    void rotateRightInverted();

    // U
    void rotateUpClockwise();
    // U`
    void rotateUpInverted();

    // B
    void rotateBackClockwise();
    // B`
    void rotateBackInverted();

    // L
    void rotateLeftClockwise();
    // L`
    void rotateLeftInverted();

    // D
    void rotateDownClockwise();
    // D`
    void rotateDownInverted();

    // M
    void middleSliceTurn();
    // M`
    void middleInvertSliceTurn();

    // E
    void equatorialSliceTurn();
    // E`
    void equatorialInvertSliceTurn();

    // S
    void standingSliceTurn();
    // S`
    void standingInvertSliceTurn();

    void rotate(const Move &move);

private:
    // fills a specfic face with the corosponding color
    void fillFace(CUBE_PROPERTY face);

    void rotateFaceClockwise(CUBE_PROPERTY face);
    void rotateFaceInverted(CUBE_PROPERTY face);

    Move generateRandomMove();
};
