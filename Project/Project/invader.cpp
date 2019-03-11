#include "Invader.h"
#include <allegro5/allegro_primitives.h>
#include <iostream>
using namespace std;

invader::invader() {
	xpos = 0;
	ypos = 0;
	alive = true;
	direction = 'r';
	lastDirection = 'l';
	stepCount = 0;
}

invader::invader(int x, int y) {
	xpos = x;
	ypos = y;
	alive = true;
	direction = 'r';
	lastDirection = 'l';
	stepCount = 0;
}

void invader::initInvader(int x, int y) {
	xpos = x;
	ypos = y;
	alive = true;
	stepCount = 0;

}

void invader::move() {
	stepCount++;
	cout << "direction " << direction << endl;
	if (direction == 'r') {
		xpos += 20;
		if (stepCount > 4) {
			direction = 'd';
			lastDirection = 'r';
			stepCount = 0;
		}
	}
	else if (direction == 'l') {
		xpos -= 20;
		if (stepCount > 4) {
			direction = 'd';
			lastDirection = 'l';
			stepCount = 0;

			}
		}
	else if (direction == 'd'){
		ypos += 20;
		if (lastDirection == 'l') {
			direction = 'r';
		}
		else {
			direction = 'l';
		}
	}

}


void invader::fire(int x, int y) {
	alive = true;
	xpos = x;
	ypos = y;
}

void invader::kill() {
	alive = false;
}

void invader::draw() {
	al_draw_filled_rectangle(xpos, ypos, xpos + 30, ypos + 30, al_map_rgb(0, 255, 155));
}

int invader::getX() {
	return xpos;
}
int invader::getY() {
	return ypos;
}
bool invader::isAlive() {
	return alive;
}