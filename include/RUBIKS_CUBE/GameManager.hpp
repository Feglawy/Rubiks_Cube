#include "conf.hpp"
#include "Move.hpp"
#include "RubiksCube.hpp"

class GameManager
{
private:
    RubiksCube cube;
    stack<Move> moveHistory;

public:
    GameManager();

    void undoLastMove();
    void displayMoveHistory();
};
