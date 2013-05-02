#include "environment.h"

Mine::Mine(int _x, int _y) : Object("res/mine.png") {
	setPos(_x, _y);
	lifespan = MAX_MINE_LIFESPAN;
}

bool Mine::dead() { return lifespan <= 0; }

void Mine::update() {
	Object::update();
	setRotation(lifespan);
	if(lifespan > 0) lifespan--;
}
