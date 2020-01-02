#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "Tetris-menu.h"
#include "Tetris-game.h"
#include <conio.h>
#include <windows.h>
#pragma warning(disable:4996) //usuniêcie b³êdu kompilacji 
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);
int logo = 0;

using namespace std;
void scoreboard() {
    system("cls");
    ifstream baza("D:/Tetris/scoreboard.txt");
    string linia;
    cout << "  #####" << endl;
    cout << " #     #  ####   ####  #####  ###### #####   ####    ##   #####  #####" << endl;
    cout << " #       #    # #    # #    # #      #    # #    #  #  #  #    # #    #" << endl;
    cout << "  #####  #      #    # #    # #####  #####  #    # #    # #    # #    #" << endl;
    cout << "       # #      #    # #####  #      #    # #    # ###### #####  #    #" << endl;
    cout << " #     # #    # #    # #   #  #      #    # #    # #    # #   #  #    #" << endl;
    cout << "  #####   ####   ####  #    # ###### #####   ####  #    # #    # #####" << endl;
    cout << "_______________________________________________________________________" << endl;
    int i = 1;
    if (baza) {
        while (getline(baza, linia)) {
            cout.width(30);
            cout << i << "." << linia << endl;
            i++;
        }
    }
    else {
        cout << "Blad! Nie znaleziono bazy w lokalizacji: D:/Tetris/scoreboard.txt" << endl;
    }
    
    cout << "Zakoncz program[q]" << endl;
    cout << "Menu[m]" << endl;
    char key;
    key = getch();
    switch (key){
    case 'q':
        break;
    case 'm':
        system("cls");
        menu();
        break;
    }

}
void send(int w, string name) {
    ofstream baza("D:/Tetris/scoreboard.txt", ios::app);
    if (baza) {
        baza << name << " " << w << endl;
        cout << "Zapisano"<<endl;
    }
    baza.close();
    ifstream bazaR("D:/Tetris/scoreboard.txt");
    int liczba;
    string nazwa;
    int TabW[100];
    string TabN[100];
    int i = 0;
    while (bazaR >> nazwa >> liczba) {
        TabW[i] = liczba;
        TabN[i] = nazwa;
        i++;
    }
    bazaR.close();
    string tmp;
    int n = i;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n - i; j++) //pêtla wewnêtrzna
            if (TabW[j - 1] < TabW[j]) {
                //zamiana miejscami
                swap(TabW[j - 1], TabW[j]);
                tmp = TabN[j - 1];
                TabN[j - 1] = TabN[j];
                TabN[j] = tmp;
            }
    ofstream baza2("D:/Tetris/scoreboard.txt");
    if (baza2) {
        for (int i = 0; i < n; i++)
        baza2 << TabN[i] << " " << TabW[i] << endl;
    }
    baza2.close();



}
void gra() {
    ini();
    while (!gameoverf())
        gameloop();
    system("cls");
    cout << "Game over" << endl << "Twoj wynik to: " << score() << endl << "Czy chcesz zapisac go nqa tablicy?:[t/n]";
    bool F = true;
    char key;
    while (F) {
        key = getch();
        string name;

        switch (key) {
        case 't':
            F = false;
            cout << "Wprowadz nazwe: ";
            cin >> name;
            system("cls");
            send(score(), name);
            menu();
            break;
        case 'n':
            F = false;
            system("cls");
            menu();
            break;
        }
    }
}
void logoshow() {
    SetConsoleTextAttribute(hOut2, FOREGROUND_GREEN | FOREGROUND_BLUE);
    switch (logo) {
    case 0:
        cout << "               ___           ___           ___                    ___           ___           ___           ___                       ___      " << endl;
        cout << "              /\\  \\         /\\  \\         /\\  \\                  /\\  \\         /\\  \\         /\\  \\         /\\  \\          ___        /\\  \\     " << endl;
        cout << "             /::\\  \\       /::\\  \\       /::\\  \\                 \\:\\  \        /::\\  \\        \\:\\  \\       /::\\  \\        /\\  \\      /::\\  \\    " << endl;
        cout << "            /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\                 \\:\\  \\     /:/\\:\\  \\        \\:\\  \\     /:/\\:\\  \\       \\:\\  \\    /:/\\ \\  \\   " << endl;
        cout << "           /:/  \\:\\  \\   /::\\~\\:\\  \\   /::\\~\\:\\  \\                /::\\  \\   /::\\~\\:\\  \\       /::\\  \\   /::\\~\\:\\  \\      /::\\__\\  _\\:\\~\\ \\  \\  " << endl;
        cout << "          /:/__/_\\:\\__\\ /:/\\:\\ \\:\\__\\ /:/\\:\\ \\:\\__\\              /:/\\:\\__\\ /:/\\:\\ \\:\\__\\     /:/\\:\\__\\ /:/\\:\\ \\:\\__\\  __/:/\\/__/ /\\ \\:\\ \\ \\__\\ " << endl;
        cout << "          \\:\\  /\\ \\/__/ \\/_|::\\/:/  / \\/__\\:\\/:/  /             /:/  \\/__/ \\:\\~\\:\\ \\/__/    /:/  \\/__/ \\/_|::\\/:/  / /\\/:/  /    \\:\\ \\:\\ \\/__/ " << endl;
        cout << "           \\:\\ \\:\\__\\      |:|::/  /       \\::/  /             /:/  /       \\:\\ \\:\\__\\     /:/  /         |:|::/  /  \\::/__/      \\:\\ \\:\\__\\  " << endl;
        cout << "            \\:\\/:/  /      |:|\\/__/        /:/  /              \\/__/         \\:\\ \\/__/     \\/__/          |:|\\/__/    \\:\\__\\       \\:\\/:/  /  " << endl;
        cout << "             \\::/  /       |:|  |         /:/  /                              \\:\\__\\                      |:|  |       \\/__/        \\::/  /   " << endl;
        cout << "              \\/__/         \\|__|         \\/__/                                \\/__/                       \\|__|                     \\/__/    " << endl;
        logo = 1;
        break;
    case 1:
        cout << "               ___           ___           ___                                  ___                         ___                       ___     " << endl;
        cout << "              /\\__\\         /\\  \\         /\\  \\                                /\\__\\                       /\\  \\                     /\\__\\    " << endl;
        cout << "             /:/ _/_       /::\\  \\       /::\\  \\                  ___         /:/ _/_         ___         /::\\  \\       ___         /:/ _/_   " << endl;
        cout << "            /:/ /\\  \\     /:/\\:\\__\\     /:/\\:\\  \\                /\\__\\       /:/ /\\__\\       /\\__\\       /:/\\:\\__\\     /\\__\\       /:/ /\\  \\  " << endl;
        cout << "           /:/ /::\\  \\   /:/ /:/  /    /:/ /::\\  \\              /:/  /      /:/ /:/ _/_     /:/  /      /:/ /:/  /    /:/__/      /:/ /::\\  \\ " << endl;
        cout << "          /:/__\\/\\:\\__\\ /:/_/:/__/___ /:/_/:/\\:\\__\\            /:/__/      /:/_/:/ /\\__\\   /:/__/      /:/_/:/__/___ /::\\  \\     /:/_/:/\\:\\__\\" << endl;
        cout << "          \\:\\  \\ /:/  / \\:\\/:::::/  / \\:\\/:/  \\/__/           /::\\  \\      \\:\\/:/ /:/  /  /::\\  \\      \\:\\/:::::/  / \\/\\:\\  \\__  \\:\\/:/ /:/  /" << endl;
        cout << "           \\:\\  /:/  /   \\::/~~/~~~~   \\::/__/               /:/\\:\\  \\      \\::/_/:/  /  /:/\\:\\  \\      \\::/~~/~~~~   ~~\\:\\/\\__\\  \\::/ /:/  / " << endl;
        cout << "            \\:\\/:/  /     \\:\\~~\\        \\:\\  \\               \\/__\\:\\  \\      \\:\\/:/  /   \\/__\\:\\  \\      \\:\\~~\\          \\::/  /   \\/_/:/  /  " << endl;
        cout << "             \\::/  /       \\:\\__\\        \\:\\__\\                   \\:\\__\\      \\::/  /         \\:\\__\\      \\:\\__\\         /:/  /      /:/  /   " << endl;
        cout << "              \\/__/         \\/__/         \\/__/                    \\/__/       \\/__/           \\/__/       \\/__/         \\/__/       \\/__/    " << endl;
        logo = 2;
        break;
    case 2:
        cout << "               ___           ___           ___                                ___                       ___                       ___     " << endl;
        cout << "              /  /\\         /  /\\         /  /\\                   ___        /  /\\          ___        /  /\\        ___          /  /\\   " << endl;
        cout << "             /  /:/_       /  /::\\       /  /::\\                 /  /\\      /  /:/_        /  /\\      /  /::\\      /  /\\        /  /:/_   " << endl;
        cout << "            /  /:/ /\\     /  /:/\\:\\     /  /:/\\:\\               /  /:/     /  /:/ /\\      /  /:/     /  /:/\\:\\    /  /:/       /  /:/ /\\  " << endl;
        cout << "           /  /:/_/::\\   /  /:/~/:/    /  /:/~/::\\             /  /:/     /  /:/ /:/_    /  /:/     /  /:/~/:/   /__/::\\      /  /:/ /::\\ " << endl;
        cout << "          /__/:/__\\/\\:\\ /__/:/ /:/___ /__/:/ /:/\\:\\           /  /::\\    /__/:/ /:/ /\\  /  /::\\    /__/:/ /:/___ \\__\\/\\:\\__  /__/:/ /:/\\:\\" << endl;
        cout << "          \\  \\:\\ /~~/:/ \\  \\:\\/:::::/ \\  \\:\\/:/__\\/          /__/:/\\:\\   \\  \\:\\/:/ /:/ /__/:/\\:\\   \\  \\:\\/:::::/    \\  \\:\\/\\ \\  \\:\\/:/~/:/" << endl;
        cout << "           \\  \\:\\  /:/   \\  \\::/~~~~   \\  \\::/               \\__\\/  \\:\\   \\  \\::/ /:/  \\__\\/  \\:\\   \\  \\::/~~~~      \\__\\::/  \\  \\::/ /:/ " << endl;
        cout << "            \\  \\:\\/:/     \\  \\:\\        \\  \\:\\                    \\  \\:\\   \\  \\:\\/:/        \\  \\:\\   \\  \\:\\          /__/:/    \\__\\/ /:/  " << endl;
        cout << "             \\  \\::/       \\  \\:\\        \\  \\:\\                    \\__\\/    \\  \\::/          \\__\\/    \\  \\:\\         \\__\\/       /__/:/   " << endl;
        cout << "              \\__\\/         \\__\\/         \\__\\/                              \\__\\/                     \\__\\/                     \\__\\/    " << endl;
        logo = 3;
        break;
    case 3:
        cout << "               ___           ___           ___                                  ___                         ___                        ___     " << endl;
        cout << "              /  /\\         /  /\\         /  /\\                   ___          /  /\\          ___          /  /\\           ___        /  /\\    " << endl;
        cout << "             /  /::\\       /  /::\\       /  /::\\                 /__/\\        /  /::\\        /__/\\        /  /::\\         /__/\\      /  /::\\   " << endl;
        cout << "            /  /:/\\:\\     /  /:/\\:\\     /  /:/\\:\\                \\  \\:\\      /  /:/\\:\\       \\  \\:\\      /  /:/\\:\\        \\__\\:\\    /__/:/\\:\\  " << endl;
        cout << "           /  /:/  \\:\\   /  /::\\ \\:\\   /  /::\\ \\:\\                \\__\\:\\    /  /::\\ \\:\\       \\__\\:\\    /  /::\\ \\:\\       /  /::\\  _\\_ \\:\\ \\:\\ " << endl;
        cout << "          /__/:/_\\_ \\:\\ /__/:/\\:\\_\\:\\ /__/:/\\:\\_\\:\\               /  /::\\  /__/:/\\:\\ \\:\\      /  /::\\  /__/:/\\:\\_\\:\\   __/  /:/\\/ /__/\\ \\:\\ \\:\\" << endl;
        cout << "          \\  \\:\\__/\\_\\/ \\__\\/~|::\\/:/ \\__\\/  \\:\\/:/              /  /:/\\:\\ \\  \\:\\ \\:\\_\\/     /  /:/\\:\\ \\__\\/~|::\\/:/  /__/\\/:/~~  \\  \\:\\ \\:\\_\\/" << endl;
        cout << "           \\  \\:\\ \\:\\      |  |:|::/       \\__\\::/              /  /:/__\\/  \\  \\:\\ \\:\\      /  /:/__\\/    |  |:|::/   \\  \\::/      \\  \\:\\_\\:\\  " << endl;
        cout << "            \\  \\:\\/:/      |  |:|\\/        /  /:/              /__/:/        \\  \\:\\_\\/     /__/:/         |  |:|\\/     \\  \\:\\       \\  \\:\\/:/  " << endl;
        cout << "             \\  \\::/       |__|:|~        /__/:/               \\__\\/          \\  \\:\\       \\__\\/          |__|:|~       \\__\\/        \\  \\::/   " << endl;
        cout << "              \\__\\/         \\__\\|         \\__\\/                                \\__\\/                       \\__\\|                      \\__\\/    " << endl;
        logo = 0;
        break;
    }
}
int t = 0;
void menu(){
    int a;
    logoshow();
    bool loopmenu = true;
    bool newlogo = false;
    SetConsoleTextAttribute(hOut2, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    //cout << "Gra Tetris"<<endl;
    cout << "1. Gra" << endl;
    cout << "2. Tablica wynikow" << endl;
    cout << "3. Wyjscie" << endl;
    cout << "Wybierz opcje: ";
    while (loopmenu) {
        if (kbhit()) {
            char key;

            key = getch();

            switch (key)
            {
            case '1':
                loopmenu = false;
                gra();
                break;
            case '2':
                loopmenu = false;
                scoreboard();
                break;
            case '3':
                loopmenu = false;
                break;
            }
        }
        else {
            t++;
            Sleep(1);
        }
        if (t > 200) {
            system("cls");
            loopmenu = false;
            newlogo = true;
            t = 0;
        }
    }
    if (newlogo) {
        menu();
    }
}


