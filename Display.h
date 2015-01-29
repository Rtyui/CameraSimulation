#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_opengl.h>

class Display{
	
private:
	static const int WIDTH = 1280;
	static const int HEIGHT = 720;

	ALLEGRO_DISPLAY *display;
public:
	Display(){
		display = 0;
	}

	void createDisplay(){
		al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_REQUIRE);
		al_set_new_display_option(ALLEGRO_SAMPLES, 4, ALLEGRO_SUGGEST);
		al_set_new_display_flags(ALLEGRO_OPENGL);
		display = al_create_display(WIDTH, HEIGHT);
		al_set_window_title(display, "Game");
		glClearColor(0.f, 0.f, 0.f, 0.f);
		glViewport(0, 0, WIDTH, HEIGHT);
		glEnable(GL_DEPTH_TEST);
	} 
 
	void destroy(){
		al_destroy_display(display);
	}

	ALLEGRO_DISPLAY* getDisplay(){
		return display;
	}

	float getFactor(){
		return (float)(WIDTH) / HEIGHT;
	}
};