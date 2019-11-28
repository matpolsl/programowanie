#include <iostream>

using namespace std;

const int max = 1000;

int main() {
	bool T[max][max]{};
	int K[max];
	int k=1001;
	while (k >= 1000) {
		cout << "Podaj ilosc kratek:";
		cin >> k;
	}
	for (int i = 0; i < k; i++) {
		cout << i + 1 << ". ";
		cin >> K[i];
	}
	int x = 500;
	int y = 500;
	bool f = true;
	T[x][y] = true;
	for (int i = 0; i < k; i++) {
		if (K[i] == 1) {
			if (!(T[++x][y]))T[x][y] = true;
			else {
				f = false;
				break;
			}
		}
		if (K[i] == 2) {
			if (!(T[--x][y]))T[x][y] = true;
			else {
				f = false;
				break;
			}
		}
		if (K[i] == 3) {
			if (!(T[x][--y]))T[x][y] = true;
			else {
				f = false;
				break;
			}
		}
		if (K[i] == 4) {
			if (!(T[x][++y]))T[x][y] = true;
			else {
				f = false;
				break;
			}
		}
	}
	if (f) cout << "Poprawny ciag";
	else cout << "niepoprawny ciag";
	system("Pause");
}