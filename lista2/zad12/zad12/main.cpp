#include <iostream>

using namespace std;

const int max = 1024;

int main() {
	char T[max]{};
	cout << "Podaj 2 liczby odzielone przecinkiem:";
	cin.getline(T, max);
	bool d = false;
	int L[2]{};
	for (int i = 0; (int)T[i] != '\0'; i++) {
		if (T[i] == ',') {
			d = true;
		}
		else {
			if (d) {
				L[1] = L[1] * 10 + (T[i] - '0');
			}
			else {
				L[0] = L[0] * 10 + (T[i] - '0');
			}
		}
		
	}
	cout << "Wynik wynosi: " << (L[0]+L[1]);
	system("Pause");
}