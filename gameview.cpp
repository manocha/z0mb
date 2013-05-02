#include "mainwindow.h"
#include "gameview.h"
#include "globals.h"
#include "environment.h"

///*SLOTS*///

void GameView::handleTimer() {
	//update player
	player->update();
	//update zombies
	for(unsigned int i = 0; i < zombies.size(); i++) {
		zombies[i]->update();
		//check zombies interaction with player
		if(player->hit(zombies[i])) {
			player->die(); //kill player
			//reset
			emptyZombies();
			player->setPos(WINDOW_MAX_X/2, WINDOW_MAX_Y/2);
			if(player->dead()) {
				parent->setStatus(parent->menu->getName() + " dead");
				timer->stop();
				spawnTimer->stop();
			}
			else parent->setStatus(parent->menu->getName() + " has "
				+ QString::number(player->getLives()) + " live(s) left");
			sleep(1);
			break;
		}
		//check zombie state
		if(zombies[i]->dead()) {
			scene->removeItem(zombies[i]);
			delete zombies[i];
			zombies.erase(zombies.begin()+i);
			i--;
		}
	}
	//update coins
	for(unsigned int i = 0; i < objects.size(); i++) {
		if(player->hit(objects[i])) {
			//remove coin
			scene->removeItem(objects[i]);
			delete objects[i];
			objects.erase(objects.begin()+i);
			//update score
			score++;
			txt->setText(parent->menu->getName() + ": " + QString::number(score));
			//add new coin
			objects.push_back(new Coin());
			scene->addItem(objects.back());
		}
	}
}

void GameView::spawnZombies() {
	int tmp = random(1, 5);
	if(tmp == 3)
		zombies.push_back(new Follower(player));
	else
		zombies.push_back(new Crawler);
	scene->addItem(zombies.back());
}

///*CONSTRUCTORS AND INITIALIZERS*///

GameView::GameView(MainWindow *_par) : score(0) {
	parent = _par; //init

	//scene & size
	scene = new QGraphicsScene();
	setScene(scene);
	setSceneRect(0, 0, WINDOW_MAX_X, WINDOW_MAX_Y);

	setMinimumSize(WINDOW_MAX_X+2, WINDOW_MAX_Y+2);

	//player
	player = new Player();
	scene->addItem(player);
	player->setPos(WINDOW_MAX_X/2, WINDOW_MAX_Y/2);
	player->setSpeed(3);
	
	//timers
	timer = new QTimer(this);
	timer->setInterval(20);
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	
	spawnTimer = new QTimer(this);
	spawnTimer->setInterval(1000);
	connect(spawnTimer, SIGNAL(timeout()), this, SLOT(spawnZombies()));
	
	//init objs
	objects.push_back(new Coin());
	scene->addItem(objects.back());
	
	//init score
	txt = new QGraphicsSimpleTextItem("-");
	txt->setPos(10, 10);
	scene->addItem(txt);
}

void GameView::start() {
	emptyZombies();
	player->setPos(WINDOW_MAX_X/2, WINDOW_MAX_Y/2);
	score = 0;
	
	timer->start();
	spawnTimer->start();
	
	txt->setText(parent->menu->getName() + ": " + QString::number(score));
}

void GameView::show() {
	QGraphicsView::show();
}

///*FUNCTIONS WITH A FUNCTION*///

void GameView::emptyZombies() {
	for(int i = zombies.size()-1; i >= 0; i--) {
		scene->removeItem(zombies[i]);
		delete zombies[i];
		zombies.erase(zombies.begin()+i);
	}
}

void GameView::emptyObjects() {
	for(int i = objects.size()-1; i >= 0; i--) {
		scene->removeItem(objects[i]);
		delete objects[i];
		objects.erase(objects.begin()+i);
	}
}

///*EVENTS*///

void GameView::keyPressEvent(QKeyEvent *_event) {
	player->control(true, _event);
}
void GameView::keyReleaseEvent(QKeyEvent *_event) {
	player->control(false, _event);
}

///*DESTRUCTOR*///

GameView::~GameView() {
	timer->stop(); delete timer;
	spawnTimer->stop(); delete spawnTimer;
	emptyZombies();
	emptyObjects();
	delete player;
	delete scene;
}
