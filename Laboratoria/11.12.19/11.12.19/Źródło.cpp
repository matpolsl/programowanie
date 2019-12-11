#include <iostream>
#include <string>
using namespace std;
void statystyka(double* T, int rozmiar) {
	double max = T[0];
	double min = T[0];
	double mediana;
	for (int i = 0; i < rozmiar; i++) {
		if (T[i] > max) max = T[i];
		if (T[i] < min) min = T[i];
		for (int j = 1; j < rozmiar - i; j++) {

			if (T[j - 1] < T[j])
				swap(T[j - 1], T[j]);
		}
	}
	if (rozmiar % 2 == 0) {
		mediana = (T[rozmiar / 2] + T[(rozmiar / 2) - 1]) / 2;
	}
	else {
		mediana = T[rozmiar / 2];
	}
	cout << "MAX:" << max<<endl;
	cout << "Min:" << min << endl;
	cout << "Mediana:" << mediana;
}

void szukaj(string T[], int rozmiar, string fraza) {
	for (int i = 0; i < rozmiar; i++) {
		if (T[i].find(fraza)<sizeof(T[i])) cout << T[i] << endl;
		//cout << T[i].find(fraza)<<endl;
	}
}

int main() {
	/*
	int a;
	cout << "Wprowadz wielkosc tablicy: ";
	cin >> a;
	double *Tab = new double[a];
	double* W = Tab;
	for (int i = 0; i < a; i++) {
		cout << "Tab[" << i << "] = ";
		cin >> *W;
		W++;
	}
	statystyka(Tab, a);
	delete[] Tab;
	*/
	int a;
	cout << "Wprowadz wielkosc tablicy: ";
	cin >> a;
	string* Tab = new string[a];
	for (int i = 0; i < a; i++) {
		cout << "Tab[" << i << "] = ";
		cin >> Tab[i];
	}
	string findz = "kot";
	szukaj(Tab, a, findz);
	//statystyka(Tab, a);
	delete[] Tab;
	system("Pause");
}