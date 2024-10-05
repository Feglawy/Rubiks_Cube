#pragma once
#include <stdexcept>
#include <string>

using namespace std;

class InvalidMove : public exception
{
public:
    InvalidMove(const string &invalid_move,
                const string &message = "Entered an invalid move")
        : message(message), invalid_move(invalid_move), full_message(invalid_move + " " + message) {}

    const char *what() const noexcept override
    {
        return full_message.c_str();
    }

private:
    string message;
    string invalid_move;
    string full_message;
};
