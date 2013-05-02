#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "object.h"
#include "globals.h"

struct Coin : public Object {
	Coin() : Object("res/coin.png") {
		setPos(random(0, 640), random(0, 480));
	}
	char getType() const { return 'c'; }
};

#endif

