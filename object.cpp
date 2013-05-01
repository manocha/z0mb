#include "object.h"

Object::Object(const std::string &fn) {
	setPixmap(QPixmap(fn.c_str()));
	setOffset(-this->boundingRect().width()/2,
				 -this->boundingRect().height()/2);
}

/*
void Object::draw() {
	//paint();
}

Object::~Object() {

}
*/
