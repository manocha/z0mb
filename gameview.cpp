#include "mainwindow.h"
#include "gameview.h"

GameView::GameView(MainWindow *_par) {
	parent = _par;

	scene = new QGraphicsScene();
	setScene(scene);
	setSceneRect(0, 0, WINDOW_MAX_X, WINDOW_MAX_Y);

	setMinimumSize(WINDOW_MAX_X+2, WINDOW_MAX_Y+2);

	obj = new Object("res/player.png");
	scene->addItem(obj);
	
	obj->setPos(WINDOW_MAX_X/2, WINDOW_MAX_Y/2);
}

void GameView::start() {

}

void GameView::show() {
	QGraphicsView::show();
}

GameView::~GameView() {
	delete obj;
	delete scene;
}
