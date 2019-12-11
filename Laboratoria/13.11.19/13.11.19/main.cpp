#include <random>
#include <iostream>
using namespace std;
random_device device;
mt19937 generator(device());
uniform_int_distribution<int> pole(0, 9);
uniform_int_distribution<int> kierunek(0, 3);

void ustaw_statek(int maszt,int p[10][10]) {
	bool flaga = 1;
	int pol = maszt;
	int k;
	while (flaga) {
		int x = pole(generator);
		int y = pole(generator);
		if (p[x][y] == 0) {
			p[x][y] = maszt;
			pol--;
			while (flaga) {
				switch (k = kierunek(generator)) {
				case 0:
					if (x - pol < 0) break;
					for (int i = 1; i <= pol; i++) {
						if (p[x - i][y] != 0) break;
					}
					for (int i = 1; i <= pol; i++) {
						p[x - i][y] = maszt;
					}
					flaga = 0;
					break;
				case 1:
					if (y + pol > 9) break;
					for (int i = 1; i <= pol; i++) {
						if (p[x][y + i] != 0) break;
					}
					for (int i = 1; i <= pol; i++) {
						p[x][y + i] = maszt;
					}
					flaga = 0;
					break;
				case 2:
					if (x + pol > 9) break;
					for (int i = 1; i <= pol; i++) {
						if (p[x + i][y] != 0) break;
					}
					for (int i = 1; i <= pol; i++) {
						p[x + i][y] = maszt;
					}
					flaga = 0;
					break;
				case 3:
					if (y - pol < 0) break;
					for (int i = 1; i <= pol; i++) {
						if (p[x][y - i] != 0) break;
					}
					for (int i = 1; i <= pol; i++) {
						p[x][y - i] = maszt;
					}
					flaga = 0;
					break;
				}
			}
				if (!flaga) {
					switch (k) {
					case 0:
						for (int i = -1; i <= pol+1; i++) {
							if (x - i > -1 && y - 1 > -1)p[x - i][y - 1] = -1;
							if(x-i>-1 && y + 1 < 10)p[x - i][y + 1] = -1;
						}
						p[x -pol - 1][y] = -1;

						p[x + 1][y] = -1;
						break;
					case 1:
						for (int i = -1; i <= pol+1; i++) {
							if (x - 1 > -1 && y + i < 10)p[x - 1][y + i] = -1;
							if (x + 1 < 10 && y + i < 10)p[x + 1][y + i] = -1;
						}
						p[x][y + pol + 1] = -1;
						p[x][y - 1] = -1;
						break;
					case 2:
						for (int i = -1; i <= pol+1; i++) {
							if (x - i > -1 && y - 1 > -1)p[x + i][y - 1] = -1;
							if (x + i < 10 && y + 1 < 10)p[x + i][y + 1] = -1;
						}
						p[x - 1][y] = -1;
						p[x +pol + 1][y] = -1;
						break;
					case 3:
						for (int i = -1; i <= pol+1; i++) {
							if (x - i > -1 && y - i >-1)p[x-1][y - i] = -1;
							if (x + i < 10 && y - i >-1)p[x+1][y - i] = -1;
						}
						p[x][y - pol - 1] = -1;
						p[x][y + 1] = -1;
						break;
					}
				}
			}
			
		}
}

void ustaw_statki(int p[10][10]) {
	int maszt4 = 1;
	int maszt3 = 2;
	int maszt2 = 3;
	int maszt1 = 4;
	for (int i = 0; i < maszt4; i++) {
		ustaw_statek(4,p);
	}
	for (int i = 0; i < maszt3; i++) {
		//ustaw_statek(3, p);
	}
	for (int i = 0; i < maszt2; i++) {
		//ustaw_statek(2, p);
	}
}
void wyswietl(int p[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout.width(2);
			cout << p[i][j]<<" ";
		}
		cout << endl;
	}
}
int main() {
	int plansza[10][10]{};
	ustaw_statki(plansza);
	wyswietl(plansza);
	system("pause");
}