#include "RUBIKS_CUBE/Solver.hpp"

bool isEdgePiece(int row, int col)
{
    bool isEdge = row == 0 && col == 1 ||
                  row == 1 && col == 0 ||
                  row == 1 && col == 2 ||
                  row == 2 && col == 1;
    return isEdge;
}

void CFOP::cross()
{
}
void CFOP::f2l()
{
}
void CFOP::oll()
{
}
void CFOP::pll()
{
}

void CFOP::solve()
{
}
