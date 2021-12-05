#include <iostream>
#include <windows.h>
using namespace std;

// Gamefield accurate to the gameboy version

int nFieldWidth = 12;
int nFieldHeight = 18;

// All the field which we play on is stored in unsigned char why tho?

unsigned char *pField = nullptr;
wstring tetromino[7];

//Default command line size
int nScreenWidth = 80;
int nScreenHeight = 30;

/*
    Rotate funtion :int rotate(int x,int y,int angle)

    Description : Custom function for rotating the 1-d tetromino array for 0,90,180,270 degree

    Parameters :
        x x co-ordinate of the array
        y y co-ordinate of the array
        angle angle by which the tetromino should be rotated only 4 options present(0,90,180,270)

    return :   
        int the new index of the rotated point

*/
int rotate(int px, int py, int angle)
{
    switch (angle % 4)
    {
    case 0:
        return 4 * py + px;
    case 1:
        return 12 + py - (4 * px);
    case 2:
        return 15 - px - (4 * py);
    case 3:
        return 3 - py + (4 * px);
    default:
        cerr << "The entered value for angle should be 0,1,2,3" << endl;
        exit(1);
    }
}

int main()
{

    // Create assets
    // there are 7 (1-sided) tetrominos
    // the reason why we add L before wstring is https://stackoverflow.com/questions/402283/stdwstring-vs-stdstring (check this for reference)
    // to print wstring use wcout

    /*
        0  1  2  3
        4  5  6  7
        8  9  10 11
        12 13 14 15 

        Index calcution done this way x axis starts from top left and goes right
        y axis starts from top left and goes down
        index i=y*width from origin + x

        After 90 clockwise rotation
        
        12  8   4  0
        13  9   5  1
        14  10  6  2
        15  11  7  3

        the formula for index i changes
        index i=



    */

    // "I" tetromino
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");

    //"O"  tetromino
    tetromino[0].append(L"....");
    tetromino[0].append(L".XX.");
    tetromino[0].append(L".XX.");
    tetromino[0].append(L"....");

    //"T" tetromino
    tetromino[0].append(L"..X.");
    tetromino[0].append(L".XX.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"....");

    //"J" tetromino
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L".XX.");
    tetromino[0].append(L"....");

    //"L" tetromino
    tetromino[0].append(L".X..");
    tetromino[0].append(L".X..");
    tetromino[0].append(L".XX.");
    tetromino[0].append(L"....");

    //"S" tetromino
    tetromino[0].append(L".X..");
    tetromino[0].append(L".XX.");
    tetromino[0].append(L"..X.");
    tetromino[0].append(L"....");

    //"Z" tetromino
    tetromino[0].append(L"..X.");
    tetromino[0].append(L".XX.");
    tetromino[0].append(L".X..");
    tetromino[0].append(L"....");

    // we are using 1d array because of some advantage(Update later)

    // Set the board boundary to 9 and everthing inside that to zero

    pField = new unsigned char[nFieldWidth * nFieldHeight]; // Create play boundary

    for (int i = 0; i < nFieldWidth; i++)
    {
        for (int j = 0; j < nFieldHeight; j++)
        {
            pField[nFieldWidth * i + j] = (i == 0 || i == nFieldWidth - 1 || j == nFieldHeight - 1) ? 9 : 0;
        }
    }

    // Setting up the console window

    wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight];
    for (int i = 0; i < nScreenHeight * nScreenWidth; i++)
        screen[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten=0;

    // Instead of cout we are sending the console output directly to the command line

    // Display frame
    // WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);

    return 0;
}