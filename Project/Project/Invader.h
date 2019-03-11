#pragma once
class invader {
private:
	int xpos;
	int ypos;
	bool alive;
	char direction;
	int stepCount;
	char lastDirection;

public:
	invader();
	invader(int x, int y);
	void initInvader(int x, int y);
	void move();
	void kill();
	void draw();
	void fire(int x, int y);
	bool isAlive();
	int getX();
	int getY();

};