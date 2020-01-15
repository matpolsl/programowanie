#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(string plik, string wynik, int klucz){
	//Zadanie 2
	//plik = "a.txt";
	ifstream szyf(plik);
	ofstream zaszyf(wynik);
	cout << plik;
	if (szyf.is_open()) {
		char z;
		while (!szyf.eof()){
			szyf.get(z);
			zaszyf << (z + klucz) % 256;
		}
		szyf.close(); 
		zaszyf.close();
	}
	else cout << "Nie mozna otworzyc plik." << endl;


	//Zadanie 1

	//ifstream bazaR("kwadratowa.txt");
	//
	//double arg[124];
	//double war[124];
	//string a;
	//string b;
	//int i = 0;
	//while (bazaR >> a >> b) {
	//	cout << a;
	//	arg[i] = stod(a);
	//	war[i] = stod(b);
	//	i++;
	//}
	//bazaR.close();
	//for (int j = 0; j < i; j++) {
	//	cout << "f(" << arg[j] << ") = " << war[j] << endl;
	//}

	


	system("pause");
}