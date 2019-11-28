#include <iostream>

using namespace std;

const int max = 1024;

int main() {
	char T[max]{};
	cout << "Podaj s³owo:";
	cin.getline(T,max);
	int suma = 0;
	for (int i = 0; (int)T[i] != '\0'; i++) {
		suma++;
	}
	suma--;
	for (; suma >= 0; suma--) {
		cout << T[suma];
	}
	system("Pause");
}