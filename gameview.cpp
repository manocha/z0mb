#include <iostream>

#include "mainwindow.h"
#include "gameview.h"

void GameView::handleTimer() {
	player->update();
	for(int i = 0; i < zombies.size(); i++) {
		zombies[i]->update();
		if(player->hit(zombies[i])) {
			player->die();
			zombies.clear();
			player->setPos(WINDOW_MAX_X/2, WINDOW_MAX_Y/2);
			if(player->dead()) {
				parent->setStatus(parent->menu->getName() + " dead");
				timer->stop();
				spawnTimer->stop();
			}
			else parent->setStatus(parent->menu->getName() + " has "
				+ QString::number(player->getLives()) + " live(s) left");
			sleep(1);
		}
		if(zombies[i]->dead()) {
			scene->removeItem(zombies[i]);
			delete zombies[i];
			zombies.erase(zombies.begin()+i);
			scene->clear();
			i--;
			
			std::cout << "removing" << std::endl;
		}
	}
	/*
	if(player->hit(coin)) {
	//increment score
	}
	*/
}

int random(int a, int b) {
	srand(time(NULL));
	return (rand()%(b-a))+a;
}

void GameView::spawnZombies() {
	int tmp = random(1, 5);
	if(tmp == 3)
		zombies.push_back(new Follower);
	else
		zombies.push_back(new Crawler);
	scene->addItem(zombies.back());
}

GameView::GameView(MainWindow *_par) {
	parent = _par;

	scene = new QGraphicsScene();
	setScene(scene);
	setSceneRect(0, 0, WINDOW_MAX_X, WINDOW_MAX_Y);

	setMinimumSize(WINDOW_MAX_X+2, WINDOW_MAX_Y+2);

	obj = new Crawler();
	scene->addItem(obj);
	
	player = new Player();
	scene->addItem(player);
	player->setPos(WINDOW_MAX_X/2, WINDOW_MAX_Y/2);
	player->setSpeed(3);
	
	timer = new QTimer(this);
	timer->setInterval(20);
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	
	spawnTimer = new QTimer(this);
	spawnTimer->setInterval(1000);
	connect(spawnTimer, SIGNAL(timeout()), this, SLOT(spawnZombies()));
}

void GameView::start() {
	if(!player->dead()) {
		timer->start();
		spawnTimer->start();
	}
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
