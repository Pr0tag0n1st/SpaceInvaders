#include "Missle.h"
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include "Globals.h"

using namespace std;

missile::missile() {
	xPos = 0;
	yPos = 0;
	alive = false;
	if (rand() % 2 == 0)
		shape = 'c';
	else
		shape = 's';
	cout << "initmissile" << endl;
}

void missile::initMissile(int x, int y) {
	xPos = x;
	yPos = y;
	alive = false;
	if (rand() % 2 == 0)
		shape = 'c';
	else
		shape = 's';

}

void missile::move() {
	yPos += 10;
	if (yPos > SCREEN_H)
		alive = false;
}

void missile::fire(int x, int y) {
	alive = true;
	xPos = x;
	yPos = y;
}



void missile::kill() {
	alive = false;
}

void missile::draw() {
	if (shape == 'c') {
		al_draw_filled_rectangle(xPos, yPos, xPos + 2, yPos + 15, al_map_rgb(255, 255, 255));
		al_draw_filled_rectangle(xPos - 5, yPos + 10, xPos + 7, yPos + 12, al_map_rgb(255, 255, 255));
	}
	else if (shape == 's') {
		points[0] = xPos;		points[1] = yPos;
		points[2] = xPos + 5;	points[3] = yPos + 5;
		points[4] = xPos - 5;	points[5] = yPos - 5;
		points[6] = xPos;		points[7] = yPos + 15;

		al_draw_ribbon(points, 8, al_map_rgb(255, 255, 255), 2, 4);
	}
}

bool missile::hit(int x, int y) {
	if ((xPos > x) && (xPos < x + 24) && (yPos < y + 44) && (yPos > y)) {
		alive = false;
		return true;
	}
	else
		return false;
}

int missile::getX() {
	return xPos;
}

int missile::getY() {
	return yPos;
}

bool missile::isAlive() {
	return alive;
}