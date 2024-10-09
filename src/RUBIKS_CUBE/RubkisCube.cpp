#include "RUBIKS_CUBE/RubiksCube.hpp"

RubiksCube::RubiksCube()
{
    for (int face = 0; face < FACES; face++)
    {
        CUBE_PROPERTY faceColor = static_cast<CUBE_PROPERTY>(face);
        RubiksCube::fillFace(faceColor);
    }
}

void RubiksCube::fillFace(CUBE_PROPERTY face_color)
{
    CUBE_PROPERTY(&face_ref)
    [ROWS][COLS] = cube[face_color];
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            face_ref[row][col] = face_color;
        }
    }
}

void RubiksCube::displayFace(CUBE_PROPERTY face)
{
    CUBE_PROPERTY(&face_ref)
    [ROWS][COLS] = cube[face];
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            string color = colorToString(face_ref[row][col]);
            cout << color << " ";
        }
        cout << endl;
    }
    cout << RESETCOLOR;
}

void RubiksCube::displayCube()
{
    const string spaces = string(6, ' ');

    // displaying the top face
    for (int row = 0; row < ROWS; row++)
    {
        cout << spaces;
        for (int col = 0; col < COLS; col++)
        {
            string color = colorToString(cube[TOP][row][col]);
            cout << color;
        }
        cout << endl;
    }

    // displaying the side faces
    for (int row = 0; row < ROWS; row++)
    {
        for (int j = 0; j < COLS * 4; j++)
        {
            int col = j % 3;

            int face = LEFT;
            if (j > 2 && j < 6)
            {
                face = FRONT;
            }
            else if (j > 5 && j < 9)
            {
                face = RIGHT;
            }
            else if (j > 8)
            {
                face = BACK;
            }
            string color = colorToString(cube[face][row][col]);
            cout << color;
        }
        cout << endl;
    }

    // displaying the bottom face
    for (int row = 0; row < ROWS; row++)
    {
        cout << spaces;
        for (int col = 0; col < COLS; col++)
        {
            string color = colorToString(cube[DOWN][row][col]);
            cout << color;
        }
        cout << endl;
    }
    cout << RESETCOLOR;
}

void RubiksCube::shuffle()
{
    srand(time(0));

    int NUM_OF_AT_LEAST_MOVES = 5;
    int RANDOM_MOVES = rand() % 16;

    int randomNum = NUM_OF_AT_LEAST_MOVES + RANDOM_MOVES;
    while (randomNum--)
    {
        Move randMove = RubiksCube::generateRandomMove();
        RubiksCube::rotate(randMove);
    }
}

bool RubiksCube::isSolved()
{
    for (int face = 0; face < FACES; face++)
    {
        if (!isFaceSolved(static_cast<CUBE_PROPERTY>(face)))
        {
            return false;
        }
    }
    return true;
}

void RubiksCube::rotateFrontClockwise()
{
    RubiksCube::rotateFaceClockwise(FRONT);

    CUBE_PROPERTY temp[SIZE];

    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[TOP][ROWS - 1][i];

    for (int i = 0; i < SIZE; i++)
        cube[TOP][ROWS - 1][i] = cube[LEFT][i][COLS - 1];
    for (int i = 0; i < SIZE; i++)
        cube[LEFT][i][COLS - 1] = cube[DOWN][0][i];
    for (int i = 0; i < SIZE; i++)
        cube[DOWN][0][i] = cube[RIGHT][i][0];
    for (int i = 0; i < SIZE; i++)
        cube[RIGHT][i][0] = temp[i];
}

void RubiksCube::rotateFrontInverted()
{
    RubiksCube::rotateFaceInverted(FRONT);
    CUBE_PROPERTY temp[SIZE];

    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[TOP][ROWS - 1][i];

    for (int i = 0; i < SIZE; i++)
        cube[TOP][ROWS - 1][i] = cube[RIGHT][i][0];
    for (int i = 0; i < SIZE; i++)
        cube[RIGHT][i][0] = cube[DOWN][0][i];
    for (int i = 0; i < SIZE; i++)
        cube[DOWN][0][i] = cube[LEFT][i][COLS - 1];
    for (int i = 0; i < SIZE; i++)
        cube[LEFT][i][COLS - 1] = temp[i];
}

void RubiksCube::rotateRightClockwise()
{
    RubiksCube::rotateFaceClockwise(RIGHT);
    CUBE_PROPERTY temp[SIZE];

    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[TOP][i][COLS - 1];

    for (int i = 0; i < SIZE; i++)
        cube[TOP][i][COLS - 1] = cube[FRONT][i][COLS - 1];
    for (int i = 0; i < SIZE; i++)
        cube[FRONT][i][COLS - 1] = cube[DOWN][i][COLS - 1];
    for (int i = 0; i < SIZE; i++)
        cube[DOWN][i][COLS - 1] = cube[BACK][i][0];
    for (int i = 0; i < SIZE; i++)
        cube[BACK][i][0] = temp[i];
}

void RubiksCube::rotateRightInverted()
{
    RubiksCube::rotateFaceInverted(RIGHT);
    CUBE_PROPERTY temp[SIZE];

    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[TOP][i][COLS - 1];

    for (int i = 0; i < SIZE; i++)
        cube[TOP][i][COLS - 1] = cube[BACK][i][0];
    for (int i = 0; i < SIZE; i++)
        cube[BACK][i][0] = cube[DOWN][i][COLS - 1];
    for (int i = 0; i < SIZE; i++)
        cube[DOWN][i][COLS - 1] = cube[FRONT][i][COLS - 1];
    for (int i = 0; i < SIZE; i++)
        cube[FRONT][i][COLS - 1] = temp[i];
}

void RubiksCube::rotateUpClockwise()
{
    RubiksCube::rotateFaceClockwise(TOP);
    CUBE_PROPERTY temp[SIZE];
    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[FRONT][0][i];
    for (int i = 0; i < SIZE; i++)
        cube[FRONT][0][i] = cube[RIGHT][0][i];
    for (int i = 0; i < SIZE; i++)
        cube[RIGHT][0][i] = cube[BACK][0][i];
    for (int i = 0; i < SIZE; i++)
        cube[BACK][0][i] = cube[LEFT][0][i];
    for (int i = 0; i < SIZE; i++)
        cube[LEFT][0][i] = temp[i];
}

void RubiksCube::rotateUpInverted()
{
    RubiksCube::rotateFaceInverted(TOP);
    CUBE_PROPERTY temp[SIZE];
    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[FRONT][0][i];

    for (int i = 0; i < SIZE; i++)
        cube[FRONT][0][i] = cube[LEFT][0][i];
    for (int i = 0; i < SIZE; i++)
        cube[LEFT][0][i] = cube[BACK][0][i];
    for (int i = 0; i < SIZE; i++)
        cube[BACK][0][i] = cube[RIGHT][0][i];
    for (int i = 0; i < SIZE; i++)
        cube[RIGHT][0][i] = temp[i];
}

void RubiksCube::rotateBackClockwise()
{
    RubiksCube::rotateFaceClockwise(BACK);
    CUBE_PROPERTY temp[SIZE];

    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[TOP][0][i];
    for (int i = 0; i < SIZE; i++)
        cube[TOP][0][i] = cube[RIGHT][i][COLS - 1];
    for (int i = 0; i < SIZE; i++)
        cube[RIGHT][i][COLS - 1] = cube[DOWN][ROWS - 1][i];
    for (int i = 0; i < SIZE; i++)
        cube[DOWN][ROWS - 1][i] = cube[LEFT][i][0];
    for (int i = 0; i < SIZE; i++)
        cube[LEFT][i][0] = temp[i];
}

void RubiksCube::rotateBackInverted()
{
    RubiksCube::rotateFaceInverted(BACK);
    CUBE_PROPERTY temp[SIZE];

    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[TOP][0][i];
    for (int i = 0; i < SIZE; i++)
        cube[TOP][0][i] = cube[LEFT][i][0];
    for (int i = 0; i < SIZE; i++)
        cube[LEFT][i][0] = cube[DOWN][ROWS - 1][i];
    for (int i = 0; i < SIZE; i++)
        cube[DOWN][ROWS - 1][i] = cube[RIGHT][i][COLS - 1];
    for (int i = 0; i < SIZE; i++)
        cube[RIGHT][i][COLS - 1] = temp[i];
}

void RubiksCube::rotateLeftClockwise()
{
    RubiksCube::rotateFaceClockwise(LEFT);
    CUBE_PROPERTY temp[SIZE];

    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[TOP][i][0];

    for (int i = 0; i < SIZE; i++)
        cube[TOP][i][0] = cube[BACK][i][COLS - 1];
    for (int i = 0; i < SIZE; i++)
        cube[BACK][i][COLS - 1] = cube[DOWN][i][0];
    for (int i = 0; i < SIZE; i++)
        cube[DOWN][i][0] = cube[FRONT][i][0];
    for (int i = 0; i < SIZE; i++)
        cube[FRONT][i][0] = temp[i];
}

void RubiksCube::rotateLeftInverted()
{
    RubiksCube::rotateFaceInverted(LEFT);
    CUBE_PROPERTY temp[SIZE];

    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[TOP][i][0];

    for (int i = 0; i < SIZE; i++)
        cube[TOP][i][0] = cube[FRONT][i][0];
    for (int i = 0; i < SIZE; i++)
        cube[FRONT][i][0] = cube[DOWN][i][0];
    for (int i = 0; i < SIZE; i++)
        cube[DOWN][i][0] = cube[BACK][i][COLS - 1];
    for (int i = 0; i < SIZE; i++)
        cube[BACK][i][COLS - 1] = temp[i];
}

void RubiksCube::rotateDownClockwise()
{
    RubiksCube::rotateFaceClockwise(DOWN);
    CUBE_PROPERTY temp[SIZE];

    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[FRONT][ROWS - 1][i];
    for (int i = 0; i < SIZE; i++)
        cube[FRONT][ROWS - 1][i] = cube[LEFT][ROWS - 1][i];
    for (int i = 0; i < SIZE; i++)
        cube[LEFT][ROWS - 1][i] = cube[BACK][ROWS - 1][i];
    for (int i = 0; i < SIZE; i++)
        cube[BACK][ROWS - 1][i] = cube[RIGHT][ROWS - 1][i];
    for (int i = 0; i < SIZE; i++)
        cube[RIGHT][ROWS - 1][i] = temp[i];
}

void RubiksCube::rotateDownInverted()
{
    RubiksCube::rotateFaceInverted(DOWN);

    CUBE_PROPERTY temp[SIZE];
    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[FRONT][ROWS - 1][i];
    for (int i = 0; i < SIZE; i++)
        cube[FRONT][ROWS - 1][i] = cube[RIGHT][ROWS - 1][i];
    for (int i = 0; i < SIZE; i++)
        cube[RIGHT][ROWS - 1][i] = cube[BACK][ROWS - 1][i];
    for (int i = 0; i < SIZE; i++)
        cube[BACK][ROWS - 1][i] = cube[LEFT][ROWS - 1][i];
    for (int i = 0; i < SIZE; i++)
        cube[LEFT][ROWS - 1][i] = temp[i];
}

void RubiksCube::middleSliceTurn()
{
    CUBE_PROPERTY temp[SIZE];
    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[TOP][i][SIZE / 2];
    for (int i = 0; i < SIZE; i++)
        cube[TOP][i][SIZE / 2] = cube[BACK][i][SIZE / 2];
    for (int i = 0; i < SIZE; i++)
        cube[BACK][i][SIZE / 2] = cube[DOWN][i][SIZE / 2];
    for (int i = 0; i < SIZE; i++)
        cube[DOWN][i][SIZE / 2] = cube[FRONT][i][SIZE / 2];
    for (int i = 0; i < SIZE; i++)
        cube[FRONT][i][SIZE / 2] = temp[i];
}

void RubiksCube::middleInvertSliceTurn()
{
    CUBE_PROPERTY temp[SIZE];
    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[TOP][i][SIZE / 2];
    for (int i = 0; i < SIZE; i++)
        cube[TOP][i][SIZE / 2] = cube[FRONT][i][SIZE / 2];
    for (int i = 0; i < SIZE; i++)
        cube[FRONT][i][SIZE / 2] = cube[DOWN][i][SIZE / 2];
    for (int i = 0; i < SIZE; i++)
        cube[DOWN][i][SIZE / 2] = cube[BACK][i][SIZE / 2];
    for (int i = 0; i < SIZE; i++)
        cube[BACK][i][SIZE / 2] = temp[i];
}

void RubiksCube::equatorialSliceTurn()
{
    CUBE_PROPERTY temp[SIZE];
    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[FRONT][SIZE / 2][i];
    for (int i = 0; i < SIZE; i++)
        cube[FRONT][SIZE / 2][i] = cube[LEFT][SIZE / 2][i];
    for (int i = 0; i < SIZE; i++)
        cube[LEFT][SIZE / 2][i] = cube[BACK][SIZE / 2][i];
    for (int i = 0; i < SIZE; i++)
        cube[BACK][SIZE / 2][i] = cube[RIGHT][SIZE / 2][i];
    for (int i = 0; i < SIZE; i++)
        cube[RIGHT][SIZE / 2][i] = temp[i];
}

void RubiksCube::equatorialInvertSliceTurn()
{
    CUBE_PROPERTY temp[SIZE];
    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[FRONT][SIZE / 2][i];
    for (int i = 0; i < SIZE; i++)
        cube[FRONT][SIZE / 2][i] = cube[RIGHT][SIZE / 2][i];
    for (int i = 0; i < SIZE; i++)
        cube[RIGHT][SIZE / 2][i] = cube[BACK][SIZE / 2][i];
    for (int i = 0; i < SIZE; i++)
        cube[BACK][SIZE / 2][i] = cube[LEFT][SIZE / 2][i];
    for (int i = 0; i < SIZE; i++)
        cube[LEFT][SIZE / 2][i] = temp[i];
}

void RubiksCube::standingSliceTurn()
{
    CUBE_PROPERTY temp[SIZE];
    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[TOP][SIZE / 2][i];
    for (int i = 0; i < SIZE; i++)
        cube[TOP][SIZE / 2][i] = cube[LEFT][i][SIZE / 2];
    for (int i = 0; i < SIZE; i++)
        cube[LEFT][i][SIZE / 2] = cube[DOWN][SIZE / 2][i];
    for (int i = 0; i < SIZE; i++)
        cube[DOWN][SIZE / 2][i] = cube[RIGHT][i][SIZE / 2];
    for (int i = 0; i < SIZE; i++)
        cube[RIGHT][i][SIZE / 2] = temp[i];
}

void RubiksCube::standingInvertSliceTurn()
{
    CUBE_PROPERTY temp[SIZE];
    for (int i = 0; i < SIZE; i++)
        temp[i] = cube[TOP][SIZE / 2][i];
    for (int i = 0; i < SIZE; i++)
        cube[TOP][SIZE / 2][i] = cube[RIGHT][i][SIZE / 2];
    for (int i = 0; i < SIZE; i++)
        cube[RIGHT][i][SIZE / 2] = cube[DOWN][SIZE / 2][i];
    for (int i = 0; i < SIZE; i++)
        cube[DOWN][SIZE / 2][i] = cube[LEFT][i][SIZE / 2];
    for (int i = 0; i < SIZE; i++)
        cube[LEFT][i][SIZE / 2] = temp[i];
}

// ____________________________________________________________
void RubiksCube::rotate(const Move &move)
{
    char rotationType = move.getRotationType();
    bool isInverted = move.isInverted();
    bool isDouble = move.isDouble();

    auto rotationFunctions = rotationMap.at(rotationType);

    // Perform the rotation
    auto rotateFunction = isInverted ? rotationFunctions.second : rotationFunctions.first;

    if (isDouble)
    {
        rotateFunction(); // Rotate once
        rotateFunction(); // Rotate twice for double rotation
    }
    else
    {
        rotateFunction();
    }
}
// ____________________________________________________________

void RubiksCube::rotateFaceClockwise(CUBE_PROPERTY face)
{
    CUBE_PROPERTY(&faceRef)
    [ROWS][COLS] = this->cube[face];

    // transpose the face
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = i; j < COLS; j++)
        {
            swap(faceRef[i][j], faceRef[j][i]);
        }
    }

    // reverse each column
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS / 2; j++)
        {
            swap(faceRef[i][j], faceRef[i][COLS - j - 1]);
        }
    }
}
void RubiksCube::rotateFaceInverted(CUBE_PROPERTY face)
{
    CUBE_PROPERTY(&faceRef)
    [ROWS][COLS] = this->cube[face];

    // transpose the face
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = i; j < COLS; j++)
        {
            swap(faceRef[i][j], faceRef[j][i]);
        }
    }

    // reverse each row
    for (int i = 0; i < ROWS / 2; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            swap(faceRef[i][j], faceRef[ROWS - i - 1][j]);
        }
    }
}

bool RubiksCube::isFaceSolved(CUBE_PROPERTY face)
{
    CUBE_PROPERTY color = cube[face][0][0];
    CUBE_PROPERTY(&faceRef)
    [ROWS][COLS] = this->cube[face];

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (faceRef[row][col] != color)
            {
                return false;
            }
        }
    }
    return true;
}

Move RubiksCube::generateRandomMove()
{

    std::random_device rd;
    std::mt19937 gen(rd());

    // Randomly pick a face (rotation type)
    std::uniform_int_distribution<> faceDist(0, validRotations.size() - 1);
    char rotationType = validRotations[faceDist(gen)];

    // Randomly pick if it's inverted
    std::uniform_int_distribution<> boolDist(0, 1);
    bool isInverted = boolDist(gen);

    // Randomly pick if it's a double rotation
    bool isDouble = boolDist(gen);

    return Move(rotationType, isInverted, isDouble);
}