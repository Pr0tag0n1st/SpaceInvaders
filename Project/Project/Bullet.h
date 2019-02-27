#pragma once
class bullet {
private:
	int xPos;
	int yPos;
	bool alive;

public:
	void initBullet(int x, int y);
	void move();
	void kill();
	void draw();
	void fire(int x, int y);
	
	bool isAlive();
	int getX();
	int getY();

};