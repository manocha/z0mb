#ifndef BULLET_H
#define BULLET_H

#include "object.h"

#define MAX_BULLET_SPEED 5

struct Bullet : public Object {
	Bullet(int, int, int);
	bool offstage();
};

#endif
