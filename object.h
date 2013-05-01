#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <QGraphicsPixmapItem>

class Object : public QGraphicsPixmapItem {
public:
	Object(const std::string &fn);
	//~Object();

	//void draw();

private:
/*
	float x, y;
	float w, h;
*/
};

#endif
