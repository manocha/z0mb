#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "object.h"

class MainWindow;

#define WINDOW_MAX_X 640
#define WINDOW_MAX_Y 480

class GameView : public QGraphicsView {
	Q_OBJECT
    
public:
	explicit GameView(MainWindow*);
	~GameView();

	void start();
	void show();
    
private:
	QGraphicsScene *scene;
	MainWindow *parent;

	int score;
	Object *obj;
	
	//Player player;
	//Zombie *zombies;
	//Object *objects;
};

#endif
