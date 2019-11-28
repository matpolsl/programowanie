#include <iostream>

using namespace std;

const int max = 1024;

int main() {
	char T[max]{};
	int I[128]{};
	cout << "Podaj zdanie:";
	cin.getline(T, max);
	for (int i = 0; (int)T[i] != '\0'; i++) {
		I[(int)T[i]]++;
	}
	for (int i = 0; i<= 127; i++) {
		if (I[i] > 0) cout << (char)i << " : " << I[i] << endl;
	}
	system("Pause");
}