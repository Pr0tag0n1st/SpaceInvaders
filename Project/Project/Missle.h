#pragma once
#include <array>

class missile {
private:
	double xPos;
	double yPos;
	bool alive;
	char shape;
	float points[8];
	double timer;

public:
	missile();
	void initMissile(int x, int y);
	void move();
	void kill();
	void draw();
	void fire(int x, int y);
	bool hit(int x, int y);
	bool isAlive();
	int getX();
	int getY();
};