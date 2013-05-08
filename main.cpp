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
