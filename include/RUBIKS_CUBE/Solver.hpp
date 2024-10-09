#include "conf.hpp"
#include "Move.hpp"
#include "RubiksCube.hpp"

class Solver
{
public:
    Solver(CUBE_PROPERTY (&_cube)[FACES][ROWS][COLS]) : cube(_cube) {}
    Solver(RubiksCube _cube) : cube(_cube) {}
    virtual void solve() = 0;

protected:
    RubiksCube cube;
    stack<Move> moveHistory;
};

class CFOP : public Solver
{
public:
    void solve() override;

private:
    void cross();
    void f2l();
    void oll();
    void pll();
};

class ZZ : public Solver
{
public:
    void solve() override;

private:
};

class Metha : public Solver
{
public:
    void solve() override;

private:
};

class Roux : public Solver
{
public:
    void solve() override;

private:
};
