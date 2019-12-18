#include <iostream>

using namespace std;
int ile_bitow_roznicy(unsigned int a, unsigned int b) {
	unsigned int bity =  a ^ b;
	int i = 0;
	int wynik = 0;
	do{
		if ((bity >> i) % 2) wynik++;;
		i++;
	} while (pow(2, i) < bity);
	return wynik;
}
int licza_1(unsigned int a){
	int i = 0;
	int bity = 0;
	do {
		if ((a >> i) % 2) bity++;;
		i++;
	} while (pow(2, i) < a);
	return bity;
}
int liczb_z_1(unsigned int a) {
	int one = licza_1(a);
	int wynik = 0;
	for (int j = 1; j < a; j++) {
		if (one == licza_1(j)) wynik++;
	}
	return wynik;
}
void drukujBinarnie(unsigned int n)
{
	int bity[32]{};
	int* i = &bity[31];
	for (int j = 0; j < 32; j++)
	{
		*i -- = (n >> j) & 1 ? 1 : 0;
	}
	i = bity;
	for (int j = 0; j < 32; j++)
	cout << *i++;
	cout << endl;
}
struct Osoba {
	string imie;
	string nazwisko;
	int wiek;
	void drukuj(Osoba s) {
		cout << s.imie << " " << s.nazwisko << " ";
		cout << " Wieku: " << s.wiek << endl;
	}
};





int main() {
	/*
	//Zadanie 1
	unsigned int x = 15;
	drukujBinarnie(x);
	cout<<endl;
	unsigned int y = 10;
	drukujBinarnie(y);
	cout << endl;
	cout << "Liczby roznia sie na: " << ile_bitow_roznicy(x, y)<< " bitach";
	*/
	/*
	//Zadanie 2
	unsigned int x = 1150;
	drukujBinarnie(x);
	cout << endl;
	cout << "Liczb mniejszych od: " << x << endl << "Majacych tyle samo 1 w postaci binarnej jest: " << liczb_z_1(x);
	*/
	//Zadanie 3
	Osoba* Tab = new Osoba[20];
	Tab[0] = { "Jan", "Kowalski", 18 };
	Tab[0].drukuj(Tab[0]);
	system("pause");
}