#include "object.h"

Object::Object(const std::string &fn) : xVel_(0), yVel_(0) {
	setPixmap(QPixmap(fn.c_str()));
	setOffset(-this->boundingRect().width()/2,
				 -this->boundingRect().height()/2);
}

int Object::xVel() const { return xVel_; }
void Object::xVel(int _x) {xVel_ = _x; }
int Object::yVel() const { return yVel_; }
void Object::yVel(int _y) { yVel_ = _y; }
void Object::vel(int _x, int _y) { xVel_ = _x; yVel_ = _y; }

//ugly hittest function (very slow? probably)
bool Object::hit(Object* _obj) {
	if(x()-this->boundingRect().width()/2 > _obj->x()-_obj->boundingRect().width()/2
	&& x()-this->boundingRect().width()/2 < _obj->x()+_obj->boundingRect().width()/2) {
		if(y()-this->boundingRect().height()/2 > _obj->y()-_obj->boundingRect().height()/2
		&& y()-this->boundingRect().height()/2 < _obj->y()+_obj->boundingRect().height()/2) {
			return true;
		}
		else if(y()+this->boundingRect().height()/2 < _obj->y()+_obj->boundingRect().height()/2
		&& y()+this->boundingRect().height()/2 > _obj->y()-_obj->boundingRect().height()/2) {
			return true;
		}
	}
	else if(x()+this->boundingRect().width()/2 < _obj->x()+_obj->boundingRect().width()/2
	&& x()+this->boundingRect().width()/2 > _obj->x()-_obj->boundingRect().width()/2) {
		if(y()-this->boundingRect().height()/2 > _obj->y()-_obj->boundingRect().height()/2
		&& y()-this->boundingRect().height()/2 < _obj->y()+_obj->boundingRect().height()/2) {
			return true;
		}
		else if(y()+this->boundingRect().height()/2 < _obj->y()+_obj->boundingRect().height()/2
		&& y()+this->boundingRect().height()/2 > _obj->y()-_obj->boundingRect().height()/2) {
			return true;
		}
	}
	
	return false;
}
