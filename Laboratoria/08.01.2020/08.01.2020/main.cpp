#include <iostream>
#include<fstream>
#include<string>

using namespace std;
bool polacz(string plikA, string plikB, string wynik) {
	 fstream odczytA(plikA,ios::in | ios::binary);
	 fstream odczytB(plikB,ios::in | ios::binary);
	 string linia;
	 ofstream plik(wynik,ios::binary);
	 if (odczytA.is_open()) {
		 while (!odczytA.eof()) {
			 getline(odczytA, linia);
			 plik << linia;
			 plik << endl;
		 }
	 }
	 else {
		 return false;
	 }
	 if (odczytB.is_open()) {
		 while (!odczytB.eof()) {
			 getline(odczytB, linia);
			 plik << linia;
			 plik << endl;
		 }
	 }
	 else {
		 return false;
	 }
	 return true;
}
double kwadrat(double x) {
	return pow(x, 2);
}
void zapiszFun(double (*f)(double x), double a, double b, int n, string nazwa_pliku) {
	double dx = (b - a) / n;
	ofstream plik(nazwa_pliku);
	for (int i = 0; i <= n; i++) {
		plik << (a + i * dx) << '\t' << f((a + i * dx)) << ";";
		plik << endl;
	}

}



int main() {
	//Zad1

	//if (polacz("a.txt", "b.txt", "wynik.txt")) {
	//	cout << "Operacja powiodla sie";
	//}
	//else {
	//	cout << "Operacja nie powiodla sie";
	//}
	//Zad2

	//zapiszFun(kwadrat, 0, 10, 100, "kwadratowa.txt");

	system("pause");
}