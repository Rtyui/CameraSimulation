#pragma once
#include "Shapes.h"

void normalize(float v[3])
{
	GLfloat d = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
	if(d == 0.f)
		return;
		
	v[0] /= d;
	v[1] /= d;
	v[2] /= d;
}

void normcrossprod(float v1[3], float v2[3], float out[3])
{
	out[0] = v1[1] * v2[2] - v1[2] * v2[1];
	out[1] = v1[2] * v2[0] - v1[0] * v2[2];
	out[2] = v1[0] * v2[1] - v1[1] * v2[0];
	normalize(out);
}

void subdivide(float *v1, float *v2, float *v3, long depth)
{
   GLfloat v12[3], v23[3], v31[3];
   GLint i;

   if (depth == 0) {
      drawtriangle(v1, v2, v3);
      return;
   }
   for (i = 0; i < 3; i++) {
      v12[i] = v1[i]+v2[i];
      v23[i] = v2[i]+v3[i];
      v31[i] = v3[i]+v1[i];
   }
   normalize(v12);
   normalize(v23);
   normalize(v31);
   subdivide(v1, v12, v31, depth-1);
   subdivide(v2, v23, v12, depth-1);
   subdivide(v3, v31, v23, depth-1);
   subdivide(v12, v23, v31, depth-1);
}