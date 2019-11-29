#include <iostream>

using namespace std;
const int N = 3;
void swap(int& a, int& b) {
	int c = a; a = b; b = c;
}
void out(int T[]){
	for (int i = 0; i < N; i++) cout << T[i]; 
	cout << endl;
}

void permutacje(int T[N], int ix) {
	if (ix < N - 1)
	{
		for (int i = ix; i < N; i++)
		{
			swap(T[ix], T[i]); 
			permutacje(T, ix + 1);
			swap(T[ix], T[i]); 
		}
	}
	else out(T); 
}
int main() {
	int T[8] = { 1,2,3,4,5,6,7,8 };
	permutacje(T, 0);
	int s = 1;
	for (int i = 2; i <= N; i++) {
		s *= i;
	}
	cout << "Jest ich: " << s;
	
	system("Pause");
}