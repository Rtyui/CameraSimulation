#include <allegro5/allegro.h>
#include <allegro5/allegro_opengl.h>
#include <allegro5/allegro_image.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>

#include "AllegroEnvironment.h"

int main(int argc, char *argv[]){


	AllegroEnvironment allegroEnvironment;

	allegroEnvironment.startTimer();
	while(allegroEnvironment.getRunning())
	{
		allegroEnvironment.waitForEvent();
		allegroEnvironment.handleEvent();
		allegroEnvironment.checkRedraw();
	}

	allegroEnvironment.destroyElements();

	return 0;

}