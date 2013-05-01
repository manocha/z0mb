#include <QStatusBar>

#include "mainwindow.h"

MainWindow::MainWindow()  {
	view = new GameView(this);
	setCentralWidget(view);
	
	menu = new GameMenu(this);
	addToolBar(menu);
	
	setWindowTitle("z0mb");
}

void MainWindow::setStatus(const QString& _txt) {
    statusBar()->showMessage(_txt);
}

void MainWindow::start() {
	QString tmp = menu->getName();
	if(tmp != NULL) {
		view->start();
		setStatus("welcome to z0mb, " + tmp);
	} else {
		setStatus("err - plz enter valid player name");
	}
}

void MainWindow::show() {
	view->show();
	QMainWindow::show();
}

MainWindow::~MainWindow() {
	delete view;
	delete menu;
}

