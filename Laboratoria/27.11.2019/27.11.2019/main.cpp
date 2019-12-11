#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
	if (argc == 4) {
		int a =  atof(argv[1]);
		int b = atof(argv[3]);
		if (*argv[2] == '+') {
			cout << (a + b);
		}
		if (*argv[2] == '-') {
			cout << (a - b);
		}
		if (*argv[2] == 'x') {
			cout << (a * b);
		}
		if (*argv[2] == '/') {
			cout << (a / b);
		}
	}

}
