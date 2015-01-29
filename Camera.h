#include <cmath>
#include "Keyboard.h"
using namespace std;

class Camera {
	private:

		float x;
		float y;
		float z;
		float rotationX;
		float rotationY;
		float sensitivity;
		float speed;
		float maxRotX;

	public:

		Camera(){
			x = 0;
			y = 1.8;
			z = 0;
			rotationX = 0;
			rotationY = 0;
			sensitivity = 0.1;
			speed = 0.096;
			maxRotX = 90;
		}

		void setPerspective(){
			if(rotationX > maxRotX) rotationX = maxRotX;
			if(rotationX < -maxRotX) rotationX = -maxRotX;
			glRotatef(rotationX, 1, 0, 0);
			glRotatef(rotationY, 0, 1, 0);
			glTranslatef(-x, -y, z);
		}

		void update(bool keys[])
		{
			if(keys[W]) moveForward();
			if(keys[S]) moveBackward();
			if(keys[A]) moveLeft();
			if(keys[D]) moveRight();
		}

		void moveForward()
		{
			x += sin(rotationY * ALLEGRO_PI / 180) * speed;
			z += cos(rotationY * ALLEGRO_PI / 180) * speed;
		}

		void moveBackward()
		{
			x -= sin(rotationY * ALLEGRO_PI / 180) * speed;
			z -= cos(rotationY * ALLEGRO_PI / 180) * speed;
		}

		void moveLeft()
		{
			x += sin((rotationY - 90) * ALLEGRO_PI / 180) * speed;
			z += cos((rotationY - 90) * ALLEGRO_PI / 180) * speed;
		}

		void moveRight()
		{
			x += sin((rotationY + 90) * ALLEGRO_PI / 180) * speed;
			z += cos((rotationY + 90) * ALLEGRO_PI / 180) * speed;
		}

		void rotate(float rx, float ry){
			rotationX += ry * sensitivity;
			rotationY += rx * sensitivity;
		}
};