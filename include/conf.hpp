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

enum COLOR
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
    FRONT = RED,   // Red face
    BACK = PINK,   // PINK face
    RIGHT = BLUE,  // Blue face
    LEFT = GREEN   // Green face
};

const static int FACES = 6;
const static int SIZE = 3;
const static int ROWS = SIZE;
const static int COLS = SIZE;

static string colorToString(COLOR color)
{
    switch (color)
    {
    case WHITE:
        return "\033[37m W";
    case YELLOW:
        return "\033[33m Y";
    case RED:
        return "\033[31m R";
    case PINK:
        return "\033[35m P";
    case BLUE:
        return "\033[34m B";
    case GREEN:
        return "\033[32m G";
    default:
        return "\033[0m ?";
    }
}
