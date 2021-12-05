#include <iostream>
using namespace std;

wstring tetromino[7];

int main()
{

    // Create assets
    // there are 7 (1-sided) tetrominos
    // the reason why we add L before wstring is https://stackoverflow.com/questions/402283/stdwstring-vs-stdstring (check this for reference)
    // to print wstring use wcout

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


    wcout << "this tetromino is " << tetromino[0] << endl;

    return 0;
}