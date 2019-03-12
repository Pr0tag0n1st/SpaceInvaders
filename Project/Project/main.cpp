#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "Globals.h"
#include "Bullet.h"
#include "Invader.h"
#include "Missle.h"
#include <list>
using namespace std;

enum KEYS {
	KEY_LEFT, KEY_RIGHT, KEY_Z
};


int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *player = NULL;
	int counter = 0;
	double player_x = SCREEN_W / 2.0;
	double player_y = SCREEN_H - 50;
	bool key[3] = { false, false, false };
	bool redraw = true;
	bool doexit = false;

	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();
	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(SCREEN_W, SCREEN_H);

	player = al_load_bitmap("spaceship.png");
	if (player == NULL)
		cout << "ship didn't load" << endl;

	bullet b1;
	b1.initBullet(0, 0);

	list<invader *> enemies;
	list<invader *>::iterator iter;

	for (int i = 0; i < 5; i++) {
		invader *alien = new invader(50 + i * 100, 100);
		enemies.push_back(alien);
	}

	list<missile *> bombs;
	list<missile *>::iterator iter2;

	for (int i = 0; i < 5; i++) {
		missile *bomb = new missile();
		bombs.push_back(bomb);
	}

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

			counter++;
			if (counter % 75 == 0)
				for (iter = enemies.begin(); iter != enemies.end(); iter++)
					(*iter)->move();
			if (key[KEY_LEFT] && player_x >= 4.0) {
				player_x -= 4.0;
			}
			if (key[KEY_RIGHT] && player_x <= SCREEN_W - 22) {
				player_x += 4.0;
			}
			if (key[KEY_Z] && !b1.isAlive()) {
				cout << "pew" << endl;
				b1.fire(player_x + 11, player_y);
			}
			if (b1.isAlive())
				b1.move();

			for (iter = enemies.begin(); iter != enemies.end(); iter++) {
				if (b1.hit((*iter)->getX(), (*iter)->getY()))
					(*iter)->kill();
			}

			redraw = true;
		}

		//input section
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			break;
			}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;
			case ALLEGRO_KEY_Z:
				key[KEY_Z] = true;
				break;
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}

		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;
			case ALLEGRO_KEY_Z:
				key[KEY_Z] = false;
				break;
			}
		}
		
		
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			if (b1.isAlive())
				b1.draw();
			for (iter = enemies.begin(); iter != enemies.end(); iter++)
				(*iter)->draw();

			al_draw_bitmap(player, player_x, player_y, 0);
			al_flip_display();
		}
	}
	al_destroy_bitmap(player);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	return 0;
}