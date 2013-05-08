#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <vector>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>

#include "object.h"
#include "player.h"
#include "zombie.h"

class MainWindow;

#define WINDOW_MAX_X 640
#define WINDOW_MAX_Y 480

class GameView : public QGraphicsView {
	Q_OBJECT
	friend class MainWindow;
	friend class Player;
    
public:
	explicit GameView(MainWindow*);
	~GameView();

	void start();
	void show();
	
	void keyPressEvent(QKeyEvent*);
	void keyReleaseEvent(QKeyEvent*);

private:
	void emptyZombies();
	void emptyObjects();

	QGraphicsScene *scene;
	QTimer *timer, *spawnTimer;
	MainWindow *parent;
	
   QGraphicsSimpleTextItem *txt;
	int score;
	int level;
	
	std::vector<Zombie*> zombies;
	Player *player;
	std::vector<Object*> objects;

public slots:
	void handleTimer();
	void spawnZombies();
};

#endif
