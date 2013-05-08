#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>
#include <fstream>

int random(int a, int b);

extern std::fstream fs;
void openScores();
void saveScore(std::string name, int score);

#endif
