#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <QKeyEvent>

#include "object.h"
#include "bullet.h"

class GameView;

#define MAX_PLAYER_LIVES 4
#define MAX_PLAYER_BULLETS 4

class Player : public Object {
public:
	Player(GameView*);
	~Player();
	
	int getLives() const;
	void resetLives();
	int getSpeed() const;
	void setSpeed(int);
	
	void control(bool down, QKeyEvent*);
	void update();

	bool dead();
	void die();

	std::vector<Bullet*> bullets;

private:
	void emptyBullets();
	
	int lives, playerSpeed;
	
	GameView *parent;
};

#endif
