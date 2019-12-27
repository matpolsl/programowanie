#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "Tetris-menu.h"
#include "Tetris-game.h"
#include <conio.h>
#pragma warning(disable:4996) //usuniêcie b³êdu kompilacji 



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
void menu(){
    int a;
    char b;
    cout << " #####  ######     #       ####### ####### ####### ######  ###  #####" << endl;
    cout << "#     # #     #   # #         #    #          #    #     #  #  #     #" << endl;
    cout << "#       #     #  #   #        #    #          #    #     #  #  #" << endl;
    cout << "#  #### ######  #     #       #    #####      #    ######   #   #####" << endl;
    cout << "#     # #   #   #######       #    #          #    #   #    #        #" << endl;
    cout << "#     # #    #  #     #       #    #          #    #    #   #  #     #" << endl;
    cout << " #####  #     # #     #       #    #######    #    #     # ###  #####" << endl;
    cout << "1. Gra" << endl;
    cout << "2. Tablica wynikow" << endl;
    cout << "3. Wyjscie" << endl;
    cout << "Wybierz opcje: ";
    cin >> a;
    if (a == 1) {
        ini();
        while (!gameoverf())
            gameloop();
        system("cls");
        cout << "Game over" << endl << "Twoj wynik to: " <<score()<< endl << "Czy chcesz zapisac go nqa tablicy?:[t/n]";
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
    if (a == 2) {
        scoreboard();
       
    }
    if (a == 3) {

    }
}


