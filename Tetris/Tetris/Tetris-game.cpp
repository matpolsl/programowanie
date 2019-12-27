#include <iomanip>
#include <iostream>
#include <random>
#include <conio.h>
#include <windows.h>
#include "Tetris-zmienne.h"
#include <stdlib.h>

#pragma warning(disable:4996) //usunięcie błędu kompilacji 
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);



using namespace std;

//Random
bool gameoverf() {
    if (gameover) return true;
    return false;
}
bool isCollide(int x2, int y2)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (block[i][j] && boardc[y2 + i][x2 + j] != 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool makeBlocks() {
    x = 4;
    y = 1;
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> obiekt(0, 6);
    int blockType = obiekt(generator);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            block[i][j] = blocks[blockType][i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i + y][j + 4] = board[i + y][j + 4] + block[i][j];

            if (board[i + y][j + 4] > block[i][j])
            {
                gameover = true;
                return true;
            }
        }
    }
    return false;
}

bool rotateBlock(){
    int tmp[4][4]{};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tmp[i][j] = block[i][j];//Tymczasowa kopia bloku
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            block[i][j] = tmp[3 - j][i];//Obrót
        }
    }

    if (isCollide(x, y))// I zatrzymanie jeśli koliduje z czymś
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                block[i][j] = tmp[i][j];
            }
        }
        return true;
    }

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            board[y + i][x + j] -= tmp[i][j];
            board[y + i][x + j] += block[i][j];
        }
    }
    return false;
}

void moveBlock(int x2, int y2)
{

    //Usunięcie bloku z planszy
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[y + i][x + j] -= block[i][j];
        }
    }
    //Aktualizacja kordynatów
    x = x2;
    y = y2;

    // Zapisanie bloku do nowej lokalizacji na planszy
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[y + i][x + j] += block[i][j];
        }
    }
}

void moveBoard(int k) {
    for (int i = k; i > 0; i--) {
        for (int j = 1; j < 11; j++) {
            if (board[i - 1][j] == 9) board[i][j] = boardc[i][j] = 0;
            else board[i][j] = boardc[i][j] = board[i - 1][j];
        }
    }
}

void pts() {
    int l = 0;
    for (int i = 20; i > 1; i--) {
        l = 0;
        for (int j = 1; j < 11; j++) {
            if (board[i][j] != 0) l++;
            if (l == 10) {
                moveBoard(i);
                ptk += 100;
                i++;
            }
        }
    }
}

void saveBlock() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            boardc[y + i][x + j] = board[y + i][x + j];
        }
    }
    newblock = true;
}

void userInput()
{
    char key;

    key = getch();

    switch (key)
    {
    case 'd':
        if (!isCollide(x + 1, y))
        {
            moveBlock(x + 1, y);
        }
        break;
    case 'a':
        if (!isCollide(x - 1, y))
        {
            moveBlock(x - 1, y);
        }
        break;
    case 's':
        if (!isCollide(x, y + 1))
        {
            moveBlock(x, y + 1);
        }
        else {
            saveBlock();
            pts();
        }
        break;
    case ' ':
        rotateBlock();
        break;
    case 'q':
        gameover = true;
        break;
    }
}
void ini() {
    gameover = false;
    ptk = 0;

    for (int j = 0; j < 12; j++) {
        board[0][j] = boardc[0][j] = 9;
    }
    for (int j = 0; j < 12; j++) {
        board[21][j] = boardc[21][j] = 9;
    }
    for (int i = 1; i <= 20; i++) {
        board[i][0] = boardc[i][0] = 9;
        for(int j=1;j<11;j++) board[i][j] = boardc[i][j] = 0;
        board[i][11] = boardc[i][11] = 9;
    }
}

void show() {
    system("cls");
    
    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 12; j++) {
            switch (board[i][j])
            {
            case 9:
                cout.width(2);
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);//Srebny
                cout << "<>";
                break;
            case 0:
                cout.width(2);
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);//Srebny
                cout << " ";
                break;
            case 1:
                cout.width(2);
                SetConsoleTextAttribute(hOut, BACKGROUND_RED);//Czerwony
                cout << " ";
                break;
            case 2:
                cout.width(2);
                SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);//Zielony
                cout << " ";
                break;
            case 3:
                cout.width(2);
                SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | BACKGROUND_RED);
                cout << " ";
                break;
            case 4:
                cout.width(2);
                SetConsoleTextAttribute(hOut, BACKGROUND_BLUE); //Niebieski
                cout << " ";
                break;
            case 5:
                cout.width(2);
                SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_RED);
                cout << " ";
                break;
            case 6:
                cout.width(2);
                SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN);
                cout << " ";
                break;
            case 7:
                cout.width(2);
                SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
                cout << " ";
                break;
            
            }
            cout.width(22);
            if (i == 14 && j == 11) cout << "Obrot: Spacja";
            if (i == 15 && j == 11) cout << "Lewo: a | Prawo: d";
            if (i == 16 && j == 11) cout << "W dol: s";
            if (i == 17 && j == 11) cout << "Zakoncz: q";
        }
        cout << endl;

    }
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "Ilosc punktow: " << ptk;
}

void gameloop() {
    
    if (newblock) {
        makeBlocks();
        newblock = false;
        show();
    }
    
    if (kbhit()) {
        userInput();
        show();
    }
    
}
int score() {
    return ptk;
}
