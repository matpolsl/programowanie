#include <iostream>
#include "prototyp.h"

using namespace std;

const int max = 1024;

int main() {
	char T1[max]{};
	char T2[max]{};
	cout << "Podaj zdanie 1:";
	cin.getline(T1, max);
	cout << "Podaj zdanie 2:";
	cin.getline(T2, max);
	if (anagramy(T1,T2)) {
		cout << "To jest anagram";
	}
	else {
		cout << "Nie, To nie jest anagram";
	}
	system("Pause");
}