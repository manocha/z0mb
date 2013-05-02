#include "gameview.h"
#include "player.h"

Player::Player(GameView *_p) : Object("res/player.png") {
	parent = _p;
	lives = MAX_PLAYER_LIVES;
	playerSpeed = 0;
}

int Player::getLives() const { return lives-1; }
void Player::resetLives() { lives = MAX_PLAYER_LIVES; }
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
			case Qt::Key_Up:
			case Qt::Key_Down:
			case Qt::Key_Left:
			case Qt::Key_Right:
				if(bullets.size() < MAX_PLAYER_BULLETS) {
					if(_event->key() == Qt::Key_Left)
						bullets.push_back(new Bullet(x(), y(), 1));
					else if(_event->key() == Qt::Key_Up)
						bullets.push_back(new Bullet(x(), y(), 2));
					else if(_event->key() == Qt::Key_Right)
						bullets.push_back(new Bullet(x(), y(), 3));
					else if(_event->key() == Qt::Key_Down)
						bullets.push_back(new Bullet(x(), y(), 4));
					parent->scene->addItem(bullets.back()); break;
				}
		}
	}
}

void Player::update() {
	Object::update();
	for(int i = bullets.size()-1; i >= 0; i--) {
		bullets[i]->update();
		if(bullets[i]->offstage()) {
			parent->scene->removeItem(bullets[i]);
			delete bullets[i];
			bullets.erase(bullets.begin()+i);
		}
	}
}

bool Player::dead() {
	return(lives <= 0);
}
void Player::die() {
	if(lives > 0)
		lives--;
}

void Player::emptyBullets() {
	for(int i = bullets.size()-1; i >= 0; i--) {
		parent->scene->removeItem(bullets[i]);
		delete bullets[i];
		bullets.erase(bullets.begin()+i);
	}
}

Player::~Player() {
	emptyBullets();
}

