#include <GL/gl.h>
#include <cmath>

#include "MathFunctions.h"

class Icosahedron{

private:
	
public:

	Icosahedron(){}

	void draw(float scale, float x, float y, float z)
	{
		glTranslatef(x, y, z);

		static GLfloat X = .525731112119133606;
		static GLfloat Z = .850650808352039932;

		static GLfloat vdata[12][3] = {
			{-X, 0.f, Z}, {X, 0.f, Z}, {-X, 0.f, -Z}, {X, 0.f, -Z},
			{0.f, Z, X}, {0.f, Z, -X}, {0.f, -Z, X}, {0.f, -Z, -X},
			{Z, X, 0.f}, {-Z, X, 0.f}, {Z, -X, 0.f}, {-Z, -X, 0.f}
		};
		
		static GLuint tindices[20][3] = {
			{0,4,1}, {0,9,4}, {9,5,4}, {4,5,8}, {4,8,1},    
			{8,10,1}, {8,3,10}, {5,3,8}, {5,2,3}, {2,7,3},    
			{7,10,3}, {7,6,10}, {7,11,6}, {11,0,6}, {0,1,6}, 
			{6,1,10}, {9,0,11}, {9,11,2}, {9,2,5}, {7,2,11}
		};

		glScalef(scale, scale, scale);

		for (int i = 0; i < 20; i++) { 
			   subdivide(&vdata[tindices[i][0]][0],       
			             &vdata[tindices[i][1]][0],       
			             &vdata[tindices[i][2]][0], 3); 
			}
		glTranslatef(-x, -y, -z);
		glScalef(1/scale, 1/scale, 1/scale);

	}
};