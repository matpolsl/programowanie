#include <iostream>
#include <stdlib.h> 

using namespace std;

const int max = 1024;

int main() {
	char T[max]{};
	cout << "Podaj zdanie:";
	cin.getline(T, max);
	int i = 0;
	int liczba = 0;
	bool minus = false;
	if (T[0] == '-') {
		minus = true;
		i++;
	}
	for (; (int)T[i] != '\0'; i++) {
		if ((T[i] - '0') <= 9 && (T[i] - '0' )>=0) {
			liczba = liczba * 10 + (T[i] - '0');
		}
		else {
			break;
		}
	}
	if (minus) liczba *= -1;
	cout << liczba;
	system("Pause");
}