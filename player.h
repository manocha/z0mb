#ifndef PLAYER_H
#define PLAYER_H

#include <QKeyEvent>

#include "object.h"
//#include "bullet.h"

#define MAX_PLAYER_LIVES 4

class Player : public Object {
public:
	Player();

	/*
	shoot();
	burstAttack();
	*/
	
	int getLives() const;
	void resetLives();
	int getSpeed() const;
	void setSpeed(int);
	
	void control(bool down, QKeyEvent*);

	bool dead();
	void die();

private:
	//Bullet *bullets; ???
	int lives, playerSpeed;
};

#endif
