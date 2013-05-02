#include <cmath>
#include "zombie.h"
#include "globals.h"

///*ZOMBIE*///

Zombie::Zombie(const std::string &_fn) : Object(_fn) {
	dead_ = false;
}
bool Zombie::dead() { return dead_; }
void Zombie::die() { dead_ = true; }

///*CRAWLER*///

Crawler::Crawler(int _mult) : Zombie("res/crawler.png") {
	int tmp = random(0, 2);
	if(tmp == 1) {
		setPos(0, random(0, 480));
		xVel(random(1 , 5)+_mult);
	} else {
		setPos(640, random(0, 480));
		xVel(-random(1, 5)-_mult);
	}
}

void Crawler::update() {
	Object::update();
	if(x() >= 680 || x() <= -40) die();
}

///*FOLLOWER*///

Follower::Follower(Player *_p) : Zombie("res/follower.png") {
	p_ = _p;
	int tmp = random(0, 4);
	switch(tmp) {
		case 1: setPos(random(0, 640), -20); break;
		case 2: setPos(660, random(0, 480)); break;
		case 3: setPos(random(0, 640), 500); break;
		case 4: setPos(-20, random(0, 480)); break;
	}
}

void Follower::update() {
	int dx = p_->x()-x(), dy = p_->y()-y();
	float angle = atan2(dy, dx);
	xVel(2*cos(angle));
	yVel(2*sin(angle));
	Object::update();
}

