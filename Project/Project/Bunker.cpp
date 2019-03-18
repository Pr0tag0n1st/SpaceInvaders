#include "Bunker.h"
#include<iostream>
using namespace std;

bunker::bunker(int x, int y) {
	xPos = x;
	yPos = y;
	alive = true;
	health = 3;
	hit0 = al_load_bitmap("undamagedbunker.jpg");
	hit1 = al_load_bitmap("damagedbunker.jpg");
	hit2 = al_load_bitmap("breakingbunker.jpg");
}

bool bunker::isHit(int x, int y) {
	if ((x > xPos) && (x + 5 < xPos + 25) && y + 10 == yPos) {
		cout << "bunker hit" << endl;
		health--;
		return true;
	}
	else
		return false;
}

void bunker::kill() {
	if (health == 0) {
		alive = false;
	}
}

void bunker::draw() {
	switch (health) {
	case 3:
		al_draw_bitmap(hit0, xPos, yPos, 0);
		break;
	case 2:
		al_draw_bitmap(hit1, xPos, yPos, 0);
		break;
	case 1:
		al_draw_bitmap(hit2, xPos, yPos, 0);
		break;
	}
}

bool bunker::isAlive() {
	return alive;
}
int bunker::getX() {
	return xPos;
}
int bunker::getY() {
	return yPos;
}
