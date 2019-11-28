#include <iostream>

using namespace std;

const int max = 1024;

int main() {
	int T[max]{};
	int x;
	cout << "Podaj liczbe: ";
	cin >> x;
	int  i = -1;
	while (x != 0) {
		i++;
		T[i] = x % 2;
		x /= 2;
	}
	for (; i >= 0; i--) {
		cout << T[i];
	}
	
	system("Pause");
}