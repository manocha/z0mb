#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "globals.h"

int random(int a, int b) {
	int tmp = (rand()%(b-a))+a;
	srand(time(NULL)*tmp);
	return tmp;
}
