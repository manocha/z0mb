#include "bullet.h"

Bullet::Bullet
(int _px, int _py, int _dir) : Object("res/bullet.png") {
	setPos(_px, _py);
	switch(_dir) {
		case 1: vel(-MAX_BULLET_SPEED, 0); break;
		case 2: vel(0, -MAX_BULLET_SPEED); break;
		case 3: vel(MAX_BULLET_SPEED, 0); break;
		case 4: vel(0, MAX_BULLET_SPEED); break;
	}
}

bool Bullet::offstage() {
	if(x() >= 680 || x() <= -40) return true;
	if(y() >= 520 || y() <= -40) return true;
	return false;
}
