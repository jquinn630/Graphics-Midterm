// Taylor Seale & John Quinn
// Computer Graphics Midterm
// cart.cpp

// implementation file for a single coaster car

#ifdef __APPLE__
	#include <GLUT/glut.h>
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/glut.h>
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

#include "cart.h"

void cart::drawCart(float x, float y, float z, float theta, float phi){
	cartX=x;
	cartY=y;
	cartZ=z;
	cartTheta=theta;
	cartPhi=phi;
	glPushMatrix();{
		glColor3f(1.0,0.0,0.0);
		glTranslatef(cartX,cartY,cartZ);
		glutSolidCube(1.0);
	};glPopMatrix();
}