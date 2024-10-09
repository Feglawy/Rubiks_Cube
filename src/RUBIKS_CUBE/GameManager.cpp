#include "RUBIKS_CUBE/GameManager.hpp"

void GameManager::run()
{
    cube.shuffle();
    while (!cube.isSolved())
    {
        cube.displayCube();
        GameManager::input();
        clearConsole;
    }
    cube.displayCube();
    cout << "You have solved the cube after " << moveHistory.size() << " Moves" << endl;
    GameManager::displayMoveHistory();
    pauseConsole;
    cout << "Press any key to continue" << endl;
    GameManager::exit();
}

void GameManager::exit()
{
    std::exit(EXIT_SUCCESS);
}

void GameManager::input()
{
    string inp;

    cout << "Valid Moves are F, B, R, L, U, D." << endl;
    cout << "2 for Double rotation and ! or ` for counter clockwise." << endl;
    cout << "Z to undo your last move." << endl;
    cout << "M to display your moves." << endl;
    cout << "0 to exit." << endl;

    cout << ">> ";
    cin >> inp;
    std::for_each(inp.begin(), inp.end(), [](char &a)
                  { a = toupper(a); });
    if (inp == "Z")
    {
        GameManager::undoLastMove();
    }
    else if (inp == "M")
    {
        GameManager::displayMoveHistory();
        cout << "Press any key to continue" << endl;
        pauseConsole;
    }
    else if (inp == "0")
    {
        GameManager::exit();
    }
    else
    {
        GameManager::doMove(inp);
    }
}

void GameManager::doMove(string inpMove)
{
    try
    {
        Move move(inpMove);
        this->cube.rotate(move);
        this->moveHistory.push(move);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        pauseConsole;
    }
}

void GameManager::undoLastMove()
{
    if (moveHistory.empty())
    {
        cout << "There is no moves yet to undo." << endl;
        return;
    }
    Move lastMove = this->moveHistory.top();
    lastMove.reverse();
    this->cube.rotate(lastMove);
    this->moveHistory.pop();
}

void GameManager::displayMoveHistory()
{
    stack<Move> temp = this->moveHistory;
    if (temp.empty())
    {
        cout << "There is no moves yet." << endl;
    }
    while (temp.size())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}