#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <QGraphicsPixmapItem>

class Object : public QGraphicsPixmapItem {
public:
	Object(const std::string &fn);
	
	int xVel() const;
	void xVel(int);
	int yVel() const;
	void yVel(int);
	void vel(int, int);
	
	bool hit(Object*);
	
	virtual void update();
	
private:
	int xVel_, yVel_;
};

#endif
