#pragma once
#include "conf.hpp"
#include "Errors.hpp"

class Move
{
private:
    const unordered_set<char> validRotations = {
        'F', 'B', 'R', 'L', 'U', 'D',};
    const unordered_set<char> validInvertions = {
        '!', 'i', '\''};

    const char Double = '2';

    bool ValidateMove(string move) const;

public:
    Move(string move);
    Move(const Move &move);
    Move(char rotationType, bool inverted, bool doubleRotation);

    void setMove(string move);

    // reverse the move
    void reverse();

    char getRotationType() const;
    bool isInverted() const;
    bool isDouble() const;

    bool operator==(const Move &move) const;

    friend ostream &operator<<(ostream &out, const Move &move);

private:
    char rotationType;
    bool inverted = false;
    bool doubleRotation = false;
};
