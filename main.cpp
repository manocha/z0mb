#include <QtGui/QApplication>

#include "globals.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;
	openScores();
	
	w.show();

	return a.exec();
}

/*
milestone 6a
high scores saved between program executions.
you write names and high scores to a file when the program is exited.
the file is read upon starting up the program (if it exists),
and created fresh if it doesn't exist.

at least 3-levels.
the background color/image must be different between the levels
higher levels are to be harder – not necessarily faster.

at least 2 items that have a player-aware AI
(i.e., they track the player, or avoid being hit)
*/
