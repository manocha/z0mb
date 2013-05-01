#include "mainwindow.h"
#include "gameview.h"

void GameView::handleTimer() {
	player->update();
	if(player->hit(obj))
		parent->setStatus("colliding");
	else
		parent->setStatus("not colliding");
}

GameView::GameView(MainWindow *_par) {
	parent = _par;

	scene = new QGraphicsScene();
	setScene(scene);
	setSceneRect(0, 0, WINDOW_MAX_X, WINDOW_MAX_Y);

	setMinimumSize(WINDOW_MAX_X+2, WINDOW_MAX_Y+2);

	obj = new Object("res/crawler.png");
	obj->setPos(50, 50);
	
	player = new Player();
	scene->addItem(player);
	player->setPos(WINDOW_MAX_X/2, WINDOW_MAX_Y/2);
	player->setSpeed(3);
	
	timer = new QTimer(this);
	timer->setInterval(20);
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
}

void GameView::start() {
	timer->start();
	scene->addItem(obj);
}

void GameView::show() {
	QGraphicsView::show();
}

void GameView::keyPressEvent(QKeyEvent *_event) {
	player->control(true, _event);
}
void GameView::keyReleaseEvent(QKeyEvent *_event) {
	player->control(false, _event);
}

GameView::~GameView() {
	timer->stop();
	delete timer;
	delete obj;
	delete player;
	delete scene;
}
