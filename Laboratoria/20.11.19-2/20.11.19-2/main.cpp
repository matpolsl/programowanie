#include <iostream>
#include <random>
using namespace std;
random_device device;
mt19937 generator(device());

void generujlosoweliczby(int* wsk, int rozmiar, int a, int b) {
	uniform_int_distribution<int> losuj(a, b);
	for (int i = 0; i < rozmiar; i++) {
		*wsk = losuj(generator);
		wsk++;
	}
}
void wypiszliczby(int* wsk, int rozmiar) {
	for(int i=0;i<rozmiar;i++){
		cout << *wsk << " ";
		wsk++;
	}
}
int max(int* wsk, int rozmiar) {
	int max = -1;
	for (int i = 0; i < rozmiar; i++) {
		if (*wsk > max) max = *wsk;
		wsk++;
	}
	return max;
}
void formatuj(char* z) {
	while (*z != '\0') {
		if (*z <= 'a' || *z >= 'z') {
			if (!(*z == ' ')) {
				cout << *z;
			}
			else {
				
			}
		}
		else {
			cout << (char)(*z - 32);
			//cout << (int)(*z)<<" ";
		}
		z++;
	}
		
	}
int main() {
	const int r = 1024;
	//int tab[r] = {};
	//int* wskaznik = tab;
	//generujlosoweliczby(wskaznik, r, 5, 10);
	//wypiszliczby(wskaznik, r);
	//cout << endl;
	//cout << max(wskaznik, 10);
	char zdanie[r]{};
	cout << "Podaj zdanie: ";
	cin.getline(zdanie, r);
	formatuj(zdanie);
	system("pause");
}