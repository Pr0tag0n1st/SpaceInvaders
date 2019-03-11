#include "Bullet.h"
#include <allegro5/allegro_primitives.h>
#include <iostream>
using namespace std;

void bullet::initBullet(int x, int y) {
	xPos = x;
	yPos = y;
	alive = false;
	cout << "Are you initialized " << endl;
}

void bullet::move() {
	yPos -= 8;
	cout << "Moving pal" << endl;
	if (yPos < 0) {
		alive = false;
		cout << "Death state " << alive << endl;
	}
}


void bullet::fire(int x, int y) {
	cout << "Fire" << endl;
	alive = true;
	xPos = x;
	yPos = y;
}

void bullet::kill() {
	alive = false;
}

void bullet::draw() {
	al_draw_filled_rectangle(xPos, yPos, xPos + 2, yPos + 10, al_map_rgb(255, 255, 255));
	cout << "Draw " << endl;
}

int bullet::getX() {
	return xPos;
}

int bullet::getY() {
	return yPos;
}

bool bullet::isAlive() {
	return alive;
}