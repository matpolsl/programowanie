#include <iostream>

using namespace std;

const int max = 1024;

int main() {
	char T[max]{};
	char P[7] = "piesek";
	char k[6] = "kotek";
	cout << "Podaj zdanie:";
	cin.getline(T, max);
	int y = 0;
	for (int i = 0; (int)T[i] != '\0'; i++) {
		if (T[i] == k[y]) {
			y++;
			if (y >= 5) {
				int j = i;
				while ((int)T[j] != '\0') {
					j++;
				}
				for (; j>i; j--) {
					 T[j]= T[j - 1];
				}
				for (int j = 0; j<=y; j++) {
					T[i-y+j+1] = P[j];
				}
				y = 0;
			}
		}
	}
	for (int i = 0; (int)T[i] != '\0'; i++) {
		cout << T[i];
	}
	system("Pause");
}