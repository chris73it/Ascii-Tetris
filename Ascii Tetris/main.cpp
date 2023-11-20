#include <Windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include "main.h"

using namespace std;

const unsigned int FRAME_DELAY = 50;
const unsigned int FINAL_DELAY = 5000;

const int SCREEN_WIDTH = 120;   // Console Screen Size X (columns)
const int SCREEN_HEIGHT = 30;    // Console Screen Size Y (rows)

bool isScreenOneCurrent = true;
wchar_t* screen1 = new wchar_t[SCREEN_WIDTH * SCREEN_HEIGHT];
wchar_t* screen2 = new wchar_t[SCREEN_WIDTH * SCREEN_HEIGHT];
wchar_t* screens[] = { screen1, screen2 };
wchar_t* screenCurrent = screen1;
wchar_t* screenNext = screen2;

wstring tetraminos[7];

int main()
{
    /*
    * Initialize data structures.
    */

    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    drawBlankField(screen1);
    drawBlankField(screen2);

    tetraminos[0].append(L"..X.");
    tetraminos[0].append(L"..X.");
    tetraminos[0].append(L"..X.");
    tetraminos[0].append(L"..X.");

    tetraminos[1].append(L"..X.");
    tetraminos[1].append(L".XX.");
    tetraminos[1].append(L".X..");
    tetraminos[1].append(L"....");

    tetraminos[2].append(L".X..");
    tetraminos[2].append(L".XX.");
    tetraminos[2].append(L"..X.");
    tetraminos[2].append(L"....");

    tetraminos[3].append(L"....");
    tetraminos[3].append(L".XX.");
    tetraminos[3].append(L".XX.");
    tetraminos[3].append(L"....");

    tetraminos[4].append(L"..X.");
    tetraminos[4].append(L".XX.");
    tetraminos[4].append(L"..X.");
    tetraminos[4].append(L"....");

    tetraminos[5].append(L"....");
    tetraminos[5].append(L".XX.");
    tetraminos[5].append(L"..X.");
    tetraminos[5].append(L"..X.");

    tetraminos[6].append(L"....");
    tetraminos[6].append(L".XX.");
    tetraminos[6].append(L".X..");
    tetraminos[6].append(L".X..");

    // Main Loop
    bool bGameOver = false;
    while (!bGameOver)
    {
        // Display Current Screen
        WriteConsoleOutputCharacter(hConsole, screenCurrent, SCREEN_WIDTH * SCREEN_HEIGHT, { 0,0 }, &dwBytesWritten);

        // Small Step = 1 Game Tick
        std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(FRAME_DELAY));
    }

    // Exiting
    std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(FINAL_DELAY));
    CloseHandle(hConsole);
    return 0;
}

void drawBlankField(wchar_t* screen)
{
    for (size_t index = 0; index < SCREEN_HEIGHT * SCREEN_WIDTH; index++)
    {
        screen[index] = L' ';
    }
}
