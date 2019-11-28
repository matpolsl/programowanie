#include "prototyp.h"

void litery(char* s, char* t){
	bool Z[128]{};
	int i = 0;
	for (; *t != '\0'; t++) {
		if ((int)*t > 'A' && (int)*t < 'Z') *t = ((int)*t + 32);
		Z[(int)*t] = true;
	}
	t--;
	for (int i=0; i < 127; i++) {
		if (Z[i]) {
			*s = (char)i;
			s++;
		}
	}
	*s = '\0';
}
