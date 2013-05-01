#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "gameview.h"
#include "gamemenu.h"

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	explicit MainWindow();
	~MainWindow();
	
	void setStatus(const QString&);
	
	void start();
	void show();

private:
	GameView *view;
	GameMenu *menu;
};

#endif
