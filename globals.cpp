#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "globals.h"

int random(int a, int b) {
	int tmp = (rand()%(b-a))+a;
	srand(time(NULL)*tmp);
	return tmp;
}

std::fstream fs;
void openScores() {
	using std::ios_base;
	if(fs.is_open()) fs.close();

	fs.open("scores.txt");
	if(!fs.is_open())
		fs.open("scores.txt", ios_base::in | ios_base::out | ios_base::trunc);
}

void saveScore(std::string name, int score) {
	fs << name << " " << score << std::endl;
}
