#include "mainwindow.h"
#include "gameview.h"

GameView::GameView(MainWindow *_par) {
	parent = _par;

	scene = new QGraphicsScene();
	setScene(scene);
	
	setFixedSize(WINDOW_MAX_X, WINDOW_MAX_Y);
}

void GameView::show() {
	QGraphicsView::show();
}

GameView::~GameView() {
	delete scene;
}
