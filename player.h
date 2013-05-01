#ifndef PLAYER_H
#define PLAYER_H

#include <QKeyEvent>

#include "object.h"
//#include "bullet.h"

class Player : public Object {
public:
	Player();

	/*
	shoot();
	burstAttack();
	die();
	*/
	
	int getSpeed() const;
	void setSpeed(int);
	
	void control(bool down, QKeyEvent*);
	void update();

private:
	//Bullet *bullets; ???
	int lives, playerSpeed;
};

#endif
