#include "mainwindow.h"
#include "gamemenu.h"

void GameMenu::startGame() {
	parent->start();
}
void GameMenu::quitGame() {
	parent->close();
}

GameMenu::GameMenu(MainWindow *_par) {
	parent = _par;

	startAction = new QAction("Start", this);
	addAction(startAction);
	connect(startAction, SIGNAL(triggered()), this, SLOT(startGame()));
	
	quitAction = new QAction("Quit", this);
	addAction(quitAction);
	connect(quitAction, SIGNAL(triggered()), this, SLOT(quitGame()));

	addSeparator();

	nameLabel = new QLabel("Player Name: ");
	addWidget(nameLabel);
	nameEdit = new QLineEdit();
	addWidget(nameEdit);

	setMovable(false);
}

QString GameMenu::getName() {
	return nameEdit->text();
}

GameMenu::~GameMenu() {
	delete startAction;
	delete quitAction;
	delete nameLabel;
	delete nameEdit;
}

