#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "Globals.h"
#include "Bullet.h"
using namespace std;

enum KEYS {
	KEY_LEFT, KEY_RIGHT, KEY_Z
};


int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *player = NULL;
	double player_x = SCREEN_W / 2.0;
	double player_y = SCREEN_H - 50;
	bool key[3] = { false, false, false };
	bool redraw = true;
	bool doexit = false;

	al_init();
	al_init_image_addon();
	al_install_keyboard();
	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(SCREEN_W, SCREEN_H);


}