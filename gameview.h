#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <vector>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>

#include "object.h"
#include "player.h"

class MainWindow;

#define WINDOW_MAX_X 640
#define WINDOW_MAX_Y 480

class GameView : public QGraphicsView {
	Q_OBJECT
	friend class MainWindow;
    
public:
	explicit GameView(MainWindow*);
	~GameView();

	void start();
	void show();
	
	void keyPressEvent(QKeyEvent*);
	void keyReleaseEvent(QKeyEvent*);

private:
	QGraphicsScene *scene;
	QTimer *timer;
	MainWindow *parent;

	int score;
	
	Object *obj;
	Player *player;
	//Zombie *zombies;
	//Object *objects;

public slots:
	void handleTimer();
};

#endif
