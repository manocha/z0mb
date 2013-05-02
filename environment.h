#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "object.h"
#include "globals.h"

struct Coin : public Object {
	Coin() : Object("res/coin.png") {
		setPos(random(0, 640), random(0, 480));
	}
	char getType() { return 'c'; };
};

#define MAX_MINE_LIFESPAN 200;

class Mine : public Object {
public:	
	Mine(int, int);

	char getType() { return 'm'; }
	bool dead();
	
	void update();

private:
	int lifespan;
};

#endif

