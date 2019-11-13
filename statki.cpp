#include <iostream>
#include <random>
using namespace std;
random_device device;
mt19937 generator(device());
uniform_int_distribution<int> plansza(0, 9);
uniform_int_distribution<int> kierunek(1, 4);
void ustaw_statek(int maszt,int p[10][10]) {
	bool flaga = 1;
	while (flaga) {
		int x = plansza(generator);
		int y = plansza(generator);
		int k;
		if (p[x][y] == 0) {
			p[x][y] = maszt;
			//cout << "p[" << x << "][" << y << "]" << endl;
			int pol = maszt - 1;
			int licz = 0;
			while (flaga) {
				if (licz > 40) {
					cout << "Podczas wykonywania funkcji wstapil blad!" << endl;
					break;
				}

				bool error = 0;
				switch (k = kierunek(generator)) {
				case 1:
					if (!(x - pol >= 0)) break;
					for (int i = 1; i <= pol; i++) {
						if (p[x - i][y] != 0) {
							licz++;
							error = 1;
							break;
						}
					}
					if (error) break;
					for (int i = 1; i <= pol; i++) {
						p[x - i][y] = maszt;
					}
					flaga = 0;
					break;
				case 2:
					if (!(y + pol < 10)) break;
					for (int i = 1; i <= pol; i++) {
						if (p[x][y + i] != 0) {
							licz++;
							error = 1;
							break;
						}
					}
					if (error) break;
					for (int i = 1; i <= pol; i++) {
						p[x][y + i] = maszt;
					}
					flaga = 0;
					break;
				case 3:
					if (!(x + pol < 10)) break;
					for (int i = 1; i <= pol; i++) {
						if (p[x + i][y] != 0) {
							licz++;
							error = 1;
							break;
						}
					}
					if (error) break;
					for (int i = 1; i <= pol; i++) {
						p[x + i][y] = maszt;
					}
					flaga = 0;
					break;
				case 4:
					if (!(y - pol >= 0)) break;
					for (int i = 1; i <= pol; i++) {
						if (p[x][y - i] != 0) {
							licz++;
							error = 1;
							break;
						}
					}
					if (error) break;
					for (int i = 1; i <= pol; i++) {
						p[x][y - i] = maszt;
					}
					flaga = 0;
					break;
				}
			}
			switch (k) {
			case 1:
				if (x - pol >= 0) {
					for (int i = -1; i <= maszt; i++) {
						if (x - i >= 0 && y - 1 >= 0 && p[x - i][y - 1] == 0) p[x - i][y - 1] = -1;
						if (x - i >= 0 && y + 1 < 10 && p[x - i][y + 1] == 0) p[x - i][y + 1] = -1;
					}
				}
				if (x + 1 < 10 && p[x + 1][y] == 0) p[x + 1][y] = -1;
				if (x - maszt >= 0 && p[x - maszt][y] == 0) p[x - maszt][y] = -1;
				break;
			case 2:
				if (y + pol <= 9) {
					for (int i = -1; i <= maszt; i++) {
						if (x - 1 >= 0 && y + i < 10 && p[x - 1][y + i] == 0) p[x - 1][y + i] = -1;
						if (x + 1 < 10 && y + i < 10 && p[x + 1][y + i] == 0) p[x + 1][y + i] = -1;
					}
				}
				if (y - 1 >= 0 && p[x][y - 1] == 0) p[x][y - 1] = -1;
				if (y + maszt < 10 && p[x][y + maszt] == 0) p[x][y + maszt] = -1;
				break;
			case 3:
				if (x + pol <= 9) {
					for (int i = -1; i <= maszt; i++) {
						if (x + i < 10 && y - 1 >= 0 && p[x + i][y - 1] == 0) p[x + i][y - 1] = -1;
						if (x + i < 10 && y + 1 < 10 && p[x + i][y + 1] == 0) p[x + i][y + 1] = -1;
					}
				}
				if (x - 1 >= 0 && p[x - 1][y] == 0) p[x - 1][y] = -1;
				if (x + maszt < 10 && p[x + maszt][y] == 0) p[x + maszt][y] = -1;
				break;
			case 4:
				if (y - pol >= 0) {
					for (int i = -1; i <= maszt; i++) {
						if (x - 1 >= 0 && y - i >= 0 && p[x - 1][y - i] == 0) p[x - 1][y - i] = -1;
						if (x + 1 < 10 && y - i >= 0 && p[x + 1][y - i] == 0) p[x + 1][y - i] = -1;
					}
				}
				if (y + 1 < 10 && p[x][y + 1] == 0) p[x][y + 1] = -1;
				if (y - maszt >= 0 && p[x][y - maszt] == 0) p[x][y - maszt] = -1;
				break;
			}
		}
		else {
			flaga = 1;
			//cout << "error" << endl;
		}
	}
}

void ustaw_statki(int p[10][10]) {
	int maszt4 = 1;
	int maszt3 = 2;
	int maszt2 = 3;
	int maszt1 = 4;
	for (int i = 0; i < maszt4; i++) ustaw_statek(4, p);
	for (int i = 0; i < maszt3; i++) ustaw_statek(3, p);
	for (int i = 0; i < maszt2; i++) ustaw_statek(2, p);
	for (int i = 0; i < maszt1; i++) ustaw_statek(1, p);
}

void wyswietl_plansze(int p[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout.width(3);
			if(p[i][j]>0) cout <<"[~]";
			else cout << "[ ]";
			//cout << p[i][j];
		}
		cout << endl;
	}
}
void wyswietl_plansze_debug(int p[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout.width(2);
			cout << p[i][j];
		}
		cout << endl;
	}
}
int main(){
	int plansza[10][10] = {};
	ustaw_statki(plansza);
	wyswietl_plansze(plansza);
	cout << endl;
	wyswietl_plansze_debug(plansza);
	system("pause");
}
