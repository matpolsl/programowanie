#include <iostream>

using namespace std;

//const int max = 1024;

int main() {
	char T[3] = {'a','b','c'};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				for (int y = 0; y < 3; y++) {
					cout << T[i] << T[j] << T[k] << T[y] <<"  ";
				}
				cout << endl;
			}
			cout << endl;
		}
		cout << endl;
	}
	system("Pause");
}