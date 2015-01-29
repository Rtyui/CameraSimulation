#include <iostream>
using namespace std;
#include <allegro5/allegro.h>
#include <allegro5/allegro_opengl.h>
#include <allegro5/allegro_image.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>

#include "Model3D.h"
#include "Model3D3.h"
#include "Icosahedron.h"
#include "Display.h"
#include "Mouse.h"
#include "Camera.h"
#include "Terrain.h"

class AllegroEnvironment{
private:
	Display display;
	Mouse mouse;
	Keyboard keyboard;
	Camera camera;

	static const int TIMER_FPS = 60;

	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *queue;
	ALLEGRO_EVENT event;

	bool redraw;
	bool running;

	Model3D *taraba;

public:
	AllegroEnvironment(){
		al_init();
		al_install_mouse();
		al_install_keyboard();
		al_init_image_addon();
		display.createDisplay();
		timer = al_create_timer(1.0 / TIMER_FPS);
		queue = al_create_event_queue();

		redraw = false;
		running = true;
		registerEvents();

		setProjection();
		taraba  = new Model3D("stall.obj");

		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_TEXTURE_2D);

		float mat_ambient[] = {1, 1, 1, 1};
		float mat_diffuse[] = {1, 1, 1, 1};
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);


	}

	void registerEvents(){
		al_register_event_source(queue, al_get_timer_event_source(timer));
		al_register_event_source(queue, al_get_display_event_source(display.getDisplay()));
		al_register_event_source(queue, al_get_mouse_event_source());
		al_register_event_source(queue, al_get_keyboard_event_source());
	}

	void setProjection(){
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		gluPerspective(45, display.getFactor(), 1.5f, 1000.f);
	}

	void setModelview(){
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}

	void render(){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		setModelview();
		camera.setPerspective();

		//Draw Terrain
		Terrain::drawTerrain(-20, -20, 20, 20);

		//Draw ball
		//Icosahedron ball;
		//ball.draw(0.1f, 0, 1, -10);

		taraba -> draw();

		al_flip_display();
	}

	void destroyElements(){
		display.destroy();
		al_destroy_event_queue(queue);
		al_destroy_timer(timer);
		delete taraba;
	}

	void startTimer(){
		al_start_timer(timer);
	}

	void waitForEvent(){
		al_wait_for_event(queue, &event);
	}

	void handleEvent(){
		switch(event.type)
		{
			case ALLEGRO_EVENT_TIMER:
				redraw = true;
				mouse.update(display.getDisplay());
				camera.update(keyboard.getKeys());
				break;
				
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				running = false;
				break;
				
			case ALLEGRO_EVENT_KEY_DOWN:
				keyboard.handleKeyDown(event);
				keyboard.isEscPressed(redraw, running);
				break;
				
			case ALLEGRO_EVENT_KEY_UP:
				keyboard.handleKeyUp(event);
				break;
				
			case ALLEGRO_EVENT_MOUSE_AXES:
				mouse.setMouseState();
				mouse.update(display.getDisplay());
				camera.rotate(mouse.getDx(), mouse.getDy());
				break;
		}
	}

	void checkRedraw(){

		if(redraw){
			redraw = false;
			render();
		}
	}

	bool getRunning(){
		return running;
	}

};