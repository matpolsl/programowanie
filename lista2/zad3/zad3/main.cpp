#include <iostream>

using namespace std;

const int max = 1024;

int main() {
	char T[max]{};
	cout << "Podaj zdanie:";
	cin.getline(T, max);
	for (int i = 0; (int)T[i] != '\0'; i++) {
		if (T[i] > 'a' && T[i] < 'z') cout << (char)(T[i] - 32);
		if (T[i] > ' ') {

		}
		if (T[i] > 'A' && T[i] < 'Z') cout << T[i];

	}
	system("Pause");
}