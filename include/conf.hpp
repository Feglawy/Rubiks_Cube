#pragma once
#include <bits/stdc++.h>

using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

#define read (void)freopen("../input.txt", "r", stdin);
#define write (void)freopen("../output.txt", "w", stdout);
#define clearConsole system("cls");
#define pauseConsole system("pause");
#define makeConsoleUTF8 system("chcp 65001");

#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef double long dl;
typedef unsigned long long ull;

enum CUBE_PROPERTY
{
    // Colors
    WHITE,  // 0
    YELLOW, // 1
    RED,    // 2
    PINK,   // 3
    BLUE,   // 4
    GREEN,  // 5

    // Faces (aliases)
    TOP = WHITE,   // White face
    DOWN = YELLOW, // Yellow face
    FRONT = GREEN, // Red face
    BACK = BLUE,   // PINK face
    RIGHT = RED,   // Blue face
    LEFT = PINK    // Green face
};

// !NOTE it only works on 3*3 cube
const static int FACES = 6;
const static int SIZE = 3;
const static int ROWS = SIZE;
const static int COLS = SIZE;

const string RESETCOLOR = "\033[0m";
const string WHITECOLOR = "\033[37m";
const string YELLOWCOLOR = "\033[33m";
const string REDCOLOR = "\033[31m";
const string PINKCOLOR = "\033[35m";
const string BLUECOLOR = "\033[34m";
const string GREENCOLOR = "\033[32m";

static string colorToString(CUBE_PROPERTY color)
{
    // const string BLOCK = "\u2588\u2588";

    switch (color)
    {
    case WHITE:
        return WHITECOLOR + " W";
    case YELLOW:
        return YELLOWCOLOR + " Y";
    case RED:
        return REDCOLOR + " R";
    case PINK:
        return PINKCOLOR + " P";
    case BLUE:
        return BLUECOLOR + " B";
    case GREEN:
        return GREENCOLOR + " G";
    default:
        return RESETCOLOR + " ?";
    }
}
