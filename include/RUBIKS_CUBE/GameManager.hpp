#pragma once
#include "conf.hpp"
#include "Move.hpp"
#include "RubiksCube.hpp"

class GameManager
{
private:
    RubiksCube cube;
    stack<Move> moveHistory;

public:
    GameManager() = default;

    void run();
    void exit();

private:
    void input();
    void doMove(const string inpMove);
    void undoLastMove();

    void displayMoveHistory();
};
