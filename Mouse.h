#include <iostream>
using namespace std;

class Mouse {
private:
	float x;
	float y;
	float dx;
	float dy;
	ALLEGRO_MOUSE_STATE ms;
public:
	Mouse(){
	x = 500;
	y = 300;
	dx = 0;
	dy = 0;
	}

	void resetMouse(ALLEGRO_DISPLAY *display){
		al_set_mouse_xy(display, 500, 300);
	}

	void update(ALLEGRO_DISPLAY *display){
		dx = ms.x - x;
		dy = ms.y - y;

		resetMouse(display);
		x = 500;
		y = 300;
		setMouseState();
	}

	float getDx(){
		return dx;
	}

	float getDy(){
		return dy;
	}

	void setMouseState(){
		al_get_mouse_state(&ms);
	}

};