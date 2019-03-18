#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class bunker{
private:
	int xPos;
	int yPos;
	int health;
	bool alive;
	ALLEGRO_BITMAP*hit0 = NULL;
	ALLEGRO_BITMAP*hit1 = NULL;
	ALLEGRO_BITMAP*hit2 = NULL;
public:
	bunker(int x, int y);
	bool isHit(int x, int y);
	void draw();
	void kill();
	bool isAlive();
	int getX();
	int getY();
};