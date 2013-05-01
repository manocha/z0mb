#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QToolBar>
#include <QAction>
#include <QLabel>
#include <QLineEdit>
#include <QString>

class MainWindow;

class GameMenu : public QToolBar {
	Q_OBJECT
	
public:
	explicit GameMenu(MainWindow*);
	~GameMenu();
	
	QString getName();
	
private:
	QAction *startAction, *quitAction;
	QLabel *nameLabel;
	QLineEdit *nameEdit;
	MainWindow *parent;
	
public slots:
	void startGame();
	void quitGame();
};

#endif
