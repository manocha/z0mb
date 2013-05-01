#include "zombie.h"

///*ZOMBIE*///

Zombie::Zombie(const std::string &_fn) : Object(_fn) {
	dead_ = false;
}
bool Zombie::dead() { return dead_; }
void Zombie::die() {
	dead_ = true;
}

///*CRAWLER*///

int rand(int a, int b) {
	srand(time(NULL));
	return (rand()%(b-a))+a;
}

Crawler::Crawler(int _mult) : Zombie("res/crawler.png") {
	int tmp = rand(0, 100);
	if(tmp < 50) {
		setPos(0, rand(0, 480));
		xVel(rand(1 , 5)+_mult);
	} else {
		setPos(640, rand(0, 480));
		xVel(-rand(1, 5)-_mult);
	}
}

void Crawler::update() {
	Object::update();
	if(x() >= 680 || x() <= -40) die();
}

///*FOLLOWER*///

Follower::Follower() : Zombie("res/follower.png") {}

