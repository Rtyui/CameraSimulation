#pragma once

class Terrain{
	
	public:
		static void drawTerrain(float x1, float z1, float x2, float z2){
			float w = (x2 - x1) / 20;
			float h = (z2 - z1) / 20;
			glBegin(GL_QUADS);
				for(int i = 0; i < 21; i++){
					for(int j = 0; j < 21; j++)
					{
						glColor3f(i * 0.05, 0, 0.04 * j);
						glVertex3f(x1 + j * w, 0, z1 + i * h);
						glVertex3f(x1 + j * w, 0, z1 + (i + 1) * h);
						glVertex3f(x1 + (j + 1) * w, 0, z1 + (i + 1) * h);
						glVertex3f(x1 + (j + 1) * w, 0, z1 + i * h);
					}
				}
			glEnd();
		}
};