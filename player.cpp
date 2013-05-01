#include "player.h"

Player::Player() : Object("res/player.png") {
	lives = 3;
	playerSpeed = 0;
}

int Player::getSpeed() const { return playerSpeed; }
void Player::setSpeed(int _speed) { playerSpeed = _speed; }

void Player::control(bool _down, QKeyEvent *_event) {
	if(_down) {
		switch(_event->key()) {
			case Qt::Key_A: xVel(-playerSpeed); break;
			case Qt::Key_D: xVel(playerSpeed); break;
			case Qt::Key_W: yVel(-playerSpeed); break;
			case Qt::Key_S: yVel(playerSpeed); break;
		}
	} else {
		switch(_event->key()) {
			case Qt::Key_A:
				if(xVel() < 0) xVel(0); break;
			case Qt::Key_D:
				if(xVel() > 0) xVel(0); break;
			case Qt::Key_W:
				if(yVel() < 0) yVel(0); break;
			case Qt::Key_S:
				if(yVel() > 0) yVel(0); break;
		}
	}
}

void Player::update() {
	setPos(x()+xVel(), y()+yVel());
}
