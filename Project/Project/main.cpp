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

	player = al_load_bitmap("Spaceship.png");
	if (player == NULL)
		cout << "ship didn't load" << endl;

	bullet b1;
	b1.initBullet(0, 0);

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));
	
	al_flip_display();

	al_start_timer(timer);

	while (!doexit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//Timer Section////////////////////////
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (key[KEY_LEFT] && player_x >= 4.0) {
				player_x -= 4.0;
			}
			if (key[KEY_RIGHT] && player_x <= SCREEN_W - 50) {
				player_x += 4.0;
			}
			if (key[KEY_Z] && b1.isAlive()) {
				cout << "pew" << endl;
				b1.fire(player_x + 30, player_y + 5);
			}
			if (b1.isAlive())
				b1.move();

			redraw = true;
		}

	}

}