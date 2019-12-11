#include <iostream>
#include "funkcje.h"

using namespace std;
 

int main() {
	//Zadanie 1
	/*
	char napis[1024];
	cout << "Wprowadz tekst: ";
	cin.getline(napis, 1024);
	odwroc(napis);
	*/

	//Zadanie 2
	/*
	char napis[1024];
	cout << "Wprowadz tekst: ";
	cin.getline(napis, 1024);
	cout << "Liter jest: "<<zliczlitery(napis)<<endl;
	*/
	//Zadanie 3
	/*
	cout << "Wprowadz liczbe: ";
	int a;
	cin >> a;
	wypiszBinarnie(a);
	*/
	//Zadanie 4
	double Tablica[4][4] = { {1,5,2,1},{0,0,3,3}, {2,1,3,1},{2,2,1,1} };
	cout << "Antyprzekatna: " << antyprzekatna(Tablica);
	system("pause");
}