#include <iostream>

using namespace std;
const int max = 1024;

int main() {
	char T[max];
	cout << "Podaj imie:";
	cin >> T;
	int suma=0;
	for (int i = 0; T[i] != '\0'; i++) {
		if(T[i]=='a' || T[i] == 'A') suma++;
	}
	cout << suma;
}