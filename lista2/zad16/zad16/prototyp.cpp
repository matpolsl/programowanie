#include "prototyp.h"

bool anagramy(char* s, char* t){
	int I1[128]{}; 
	int I2[128]{};
	for (; *s != '\0'; s++) {
		I1[(int)*s]++;
	}
	for (; *t != '\0'; t++) {
		I2[(int)*t]++;
	}
	for (int i = 0; i <= 127; i++) {
		if (I1[i] != I2[i]) return false;
	}
	return true;
}
