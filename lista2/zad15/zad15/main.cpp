#include <iostream>
#include "prototyp.h"
using namespace std;

const int max = 1024;


int main() {
	char T[max]{};
	cout << "Podaj slowo: ";
	cin.getline(T, max); 
	char Wynik[max]{};
	char* W = Wynik;
	litery(W, T);
	cout << Wynik;
	system("Pause");
}