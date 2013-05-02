#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "object.h"
#include "player.h"

class Zombie : public Object {
public:
	Zombie(const std::string &_fn);
	bool dead();
	void die();

private:
	bool dead_;
};

struct Crawler : public Zombie {
	Crawler(int = 0);
	void update();
};

class Follower : public Zombie {
public:
	Follower(Player*);
	void update();
private:
	Player *p_;
};

#endif
