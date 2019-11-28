#include "prototyp.h"
#include <iostream>

using namespace std;

void odwroc(char* s, char* t){
	int i = 0;
	for (; (int)*t != '\0'; t++) {
		i++;
	}
	t--;
	for (;i>=0;t--,i--,s++) {
		*s = *t;
	}
	s--;
	*s = '\0';
}
