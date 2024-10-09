#include "RUBIKS_CUBE/Move.hpp"

bool Move::ValidateMove(string input) const
{
    if (input.length() < 1 || input.length() > 3)
    {
        throw InvalidMove(input, "Move must be 1 to 3 characters long.");
    }

    // Check first character for valid rotation type
    if (validRotations.find(toupper(input[0])) == validRotations.end())
    {
        throw InvalidMove(input, "Invalid rotation type.");
    }

    // If the second character exists, it must be '!', 'i', '\'', or '2'
    if (input.length() > 1)
    {
        char secondChar = input[1];
        if (validInvertions.find(secondChar) == validInvertions.end() && secondChar != '2')
        {
            throw InvalidMove(input, "Invalid second character, must be '!', 'i', '\\'', or '2'.");
        }
    }

    // If the third character exists, it must be '!' or 'i' or '\'', and the second must be '2'
    if (input.length() == 3)
    {
        char secondChar = input[1];
        char thirdChar = input[2];
        if (secondChar != '2' || (thirdChar != '!' && thirdChar != 'i' && thirdChar != '\''))
        {
            throw InvalidMove(input, "Invalid third character, must be '!', 'i', or '\\'' after '2'.");
        }
    }

    return true;
}

Move::Move(string move)
{
    setMove(move);
}

Move::Move(const Move &move)
    : rotationType(move.rotationType), inverted(move.inverted), doubleRotation(move.doubleRotation) {}

Move::Move(char type, bool _inverted, bool _doubleRotation)
{
    string _rotationType(1, type);
    ValidateMove(_rotationType);

    this->rotationType = type;
    this->inverted = _inverted;
    this->doubleRotation = _doubleRotation;
}

void Move::setMove(string move)
{
    Move::ValidateMove(move);

    this->rotationType = toupper(move[0]);
    for (int i = 1; i < move.size(); i++)
    {
        char arg = move[i];
        if (arg == '2')
            this->doubleRotation = true;
        else
            this->inverted = true;
    }
}

void Move::reverse()
{
    this->inverted = !this->inverted;
}

bool Move::operator==(const Move &other) const
{
    if (
        other.rotationType == this->rotationType &&
        other.doubleRotation == this->doubleRotation &&
        other.inverted == this->inverted)
    {
        return true;
    }
    return false;
}

char Move::getRotationType() const
{
    return this->rotationType;
}
bool Move::isInverted() const
{
    return this->inverted;
}
bool Move::isDouble() const
{
    return this->doubleRotation;
}

ostream &operator<<(ostream &out, const Move &move)
{
    char rotation = move.getRotationType();
    string inverted = move.isInverted() ? "!" : "";
    string Double = move.isDouble() ? "2" : "";
    out << rotation << Double << inverted;
    return out;
}