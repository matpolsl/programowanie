#include <iostream>
using namespace std;

int main() {
	double T[10];
	for (int i = 0; i < 10; i++) {
		cout <<i+1<<". ";
		cin >> T[i];
	}
	double min = T[0];
	double max = T[0];
	for (int i = 0; i < 10; i++) {
		if (T[i] > max) max = T[i];
		if (T[i] < min) min = T[i];
	}
	cout << "Najmniejsza to:" << min << endl;
	cout << "Najwieksza to:" << max << endl;
	system("Pause");
}