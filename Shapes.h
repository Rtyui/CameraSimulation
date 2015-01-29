#pragma once
void drawtriangle(float *v1, float *v2, float *v3) 
{ 
	glBegin(GL_TRIANGLES); 
		glColor3f(1, 1, 0);
		glNormal3fv(v1); glVertex3fv(v1); 
		glColor3f(1, 0, 0);  
		glNormal3fv(v2); glVertex3fv(v2);   
		glColor3f(0, 1, 0); 
		glNormal3fv(v3); glVertex3fv(v3);    
	glEnd(); 
}