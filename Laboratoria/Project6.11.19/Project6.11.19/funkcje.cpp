#include <iostream>
#include "funkcje.h"

using namespace std;

void odwroc(char tekst[]){
	cout << "Odwrocony tekst to: ";
	int rozmiar;
	int i = 0;
	while (tekst[i] != 0) {
		i++;
	}
	if (tekst[i] == 0) {
		i--;
	}
	for (; i >= 0; i--) {
		cout << tekst[i];
	}
	cout << endl;
}

int zliczliteryA(char tekst[])
{
	int rozmiar;
	int i = 0;
	int a = 0;
	while (tekst[i] != 0) {
		i++;
	}
	if (tekst[i] == 0) {
		i--;
	}
	rozmiar = i;
	for (i = 0; i <= rozmiar; i++) {
		if (tekst[i] == 'A' || tekst[i] == 'a') a++;
	}
	return a;
}

int zliczlitery(char tekst[])
{
	int rozmiar;
	int i = 0;
	int a = 0;
	while (tekst[i] != 0) {
		i++;
	}
	if (tekst[i] == 0) {
		i--;
	}
	rozmiar = i;
	for (i = 0; i <= rozmiar; i++) {
		if ((tekst[i]>='a' && tekst[i]<='z') || (tekst[i] >= 'A' && tekst[i] <= 'Z')) a++;
	}
	return a;
}

void wypiszBinarnie(int n){
	int T[32] = {};
	int i = 31;
	cout << "Podstaæ binarna liczby " << n << ":" << endl;
	while (n != 0) {
		T[i] = n%2;
		n = n / 2;
		i--;
	}
	for (int j = 0; j < 32; j++) {
		if (j % 8 == 0 && j!=0) cout << "  ";
		cout << T[j];
	}
}

double antyprzekatna(double tab[4][4]){
	double zwrot=1;
	for (int i = 3, j=0; i >= 0; i--, j++) {
		zwrot = zwrot * tab[j][i];
	}
	return zwrot;
}

