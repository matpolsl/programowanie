#include <iostream>

using namespace std;

const int max = 1024;

int main() {
	char T[max]{};
	cout << "Podaj zdanie:";
	cin.getline(T, max);
	int y = 0;
	int max = 0;
	for (int i = 0; (int)T[i] != '\0'; i++) {
		if (T[i] == 'o') {
			y++;
			if (max < y) {
				max = y;
			}
		}
		else {
			y = 0;
		}
	}
	cout << "W podanym ciagu znak 'o' wystepuje: " << max << " razy";
	system("Pause");
}