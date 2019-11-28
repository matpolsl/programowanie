#include <iostream>
#include "prototyp.h"
using namespace std;

const int max = 1024;


int main() {
	char T[max]{};
	cout << "Podaj slowo: ";
	cin.getline(T, max);
	char* tab = T;
	char Tt[max];
	char* wsk = &Tt[0];
	odwroc(wsk,tab);
	cout << Tt;
	system("Pause");
}