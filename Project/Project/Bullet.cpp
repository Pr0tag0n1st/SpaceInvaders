#include "Bullet.h"
#include <allegro5/allegro_primitives.h>
#include <iostream>
using namespace std;

void bullet::initBullet(int x, int y) {
	xPos = x;
	yPos = y;
	alive = false;
}

void bullet::move() {
	yPos -= 10;
	if (yPos < 0)
		alive = false;
}


void bullet::fire(int x, int y) {
	alive = true;
	xPos = x;
	yPos = y;
}

void bullet::kill() {
	alive = false;
}

void bullet::draw() {
	al_draw_filled_rectangle(xPos, yPos, xPos + 3, yPos + 15, al_map_rgb(255, 255, 0));
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