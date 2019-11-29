#include <iostream>
#include <random>
using namespace std;
random_device device;
mt19937 generator(device());
int A, B, suma;
void losujliczby() {
	uniform_int_distribution<int> a(1, 99);
	A=a(generator);
	uniform_int_distribution<int> b(1, 100-A);
	B=b(generator);
}

int main() {
	char ODP;
	bool flaga = true;
	while (flaga) {
		ODP = '0';
		losujliczby();
		cout << "Jaka jest suma liczb " << A << " + " << B << " = ?" << endl;
		cin >> suma;
		if (suma == (A + B)) {
			cout << "Dobrze" << endl;
		}
		else {
			cout << "Niestety zle" << endl;
		}
		bool O = 1;
		while (O){
			cout << "Czy bawimy sie dalej [T/N]?";
			cin >> ODP;
			if (ODP == 'N') {
				flaga = false;
				O = 0;
			}
			else {
				if (ODP == 'T') {
					O = 0;
				}
			}
		}
	}
	system("pause");
}