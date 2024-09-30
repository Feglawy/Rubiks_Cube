#include "RUBIKS_CUBE/RubiksCube.hpp"

RubiksCube::RubiksCube()
{
    for (int face = 0; face < FACES; face++)
    {
        COLOR faceColor = static_cast<COLOR>(face);
        RubiksCube::fillFace(faceColor);
    }
}

void RubiksCube::fillFace(COLOR face_color)
{
    COLOR(&face_ref)
    [ROWS][COLS] = cube[face_color];
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            face_ref[row][col] = face_color;
        }
    }
}

void RubiksCube::displayFace(COLOR face)
{
    COLOR(&face_ref)
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
    int randomNum = rand() % 101;
    while (randomNum--)
    {
        int rotaionType = rand() % 12;
        switch (rotaionType)
        {
        case 0:
            RubiksCube::rotateFrontClockwise();
            break;
        case 1:
            RubiksCube::rotateFrontInverted();
            break;
        case 2:
            RubiksCube::rotateRightClockwise();
            break;
        case 3:
            RubiksCube::rotateRightInverted();
            break;
        case 4:
            RubiksCube::rotateUpClockwise();
            break;
        case 5:
            RubiksCube::rotateUpInverted();
            break;
        case 6:
            RubiksCube::rotateBackClockwise();
            break;
        case 7:
            RubiksCube::rotateBackInverted();
            break;
        case 8:
            RubiksCube::rotateLeftClockwise();
            break;
        case 9:
            RubiksCube::rotateLeftInverted();
            break;
        case 10:
            RubiksCube::rotateDownClockwise();
            break;
        case 11:
            RubiksCube::rotateDownInverted();
            break;
        }
    }
}

bool RubiksCube::isSolved()
{
    for (int face = 0; face < FACES; face++)
    {
        if (!isFaceSolved(static_cast<COLOR>(face)))
        {
            return false;
        }
    }
    return true;
}

void RubiksCube::rotateFrontClockwise()
{
    RubiksCube::rotateFaceClockwise(FRONT);

    vector<COLOR> temp(SIZE);

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
    vector<COLOR> temp(SIZE);

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
    vector<COLOR> temp(SIZE);

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
    vector<COLOR> temp(SIZE);

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
    vector<COLOR> temp(SIZE);
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
    vector<COLOR> temp(SIZE);
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
    vector<COLOR> temp(SIZE);

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
    vector<COLOR> temp(SIZE);

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
    vector<COLOR> temp(SIZE);

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
    vector<COLOR> temp(SIZE);

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
    vector<COLOR> temp(SIZE);

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

    vector<COLOR> temp(SIZE);
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

// ____________________________________________________________

void RubiksCube::rotateFaceClockwise(COLOR face)
{
    COLOR(&faceRef)
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
void RubiksCube::rotateFaceInverted(COLOR face)
{
    COLOR(&faceRef)
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

bool RubiksCube::isFaceSolved(COLOR face)
{
    COLOR color = face;
    COLOR(&faceRef)
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