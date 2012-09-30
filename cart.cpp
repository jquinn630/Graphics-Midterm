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
#include <math.h>
#include "cart.h"

#define PI 3.14159

void drawWheel(float x, float y, float z){
	glPushMatrix();{
		glColor3f(0.0,0.0,0.0);
		glTranslatef(x,y,z);
		glutSolidTorus(0.25, 0.01, 100, 100);
	};glPopMatrix();
}

void cart::drawCart(float xa, float xb, float xc, float xd, float ya, float yb, float yc, float yd, float za, float zb, float zc, float zd, float step){
	// current cart position
	cartX=xa*step*step*step+xb*step*step+xc*step+xd;
	cartY=ya*step*step*step+yb*step*step+yc*step+yd;
	cartZ=za*step*step*step+zb*step*step+zc*step+zd;
	// next cart position (used to calculate theta & phi headings)
	step+=.004;
	float nextCartX=xa*step*step*step+xb*step*step+xc*step+xd;
	float nextCartY=ya*step*step*step+yb*step*step+yc*step+yd;
	float nextCartZ=za*step*step*step+zb*step*step+zc*step+zd;
	// calculate cartTheta
	float deltaX = nextCartX - cartX;
	float deltaY = nextCartY - cartY;
	float deltaZ = nextCartZ - cartZ;
	cartTheta = atan(deltaX/deltaZ)*(180.0/PI);
	// calculate cartPhi
	cartPhi = atan(deltaY/deltaX)*(180.0/PI);
	glPushMatrix();{
		glColor3f(1.0,0.0,0.0);
		// rotate for theta & phi
		glTranslatef(cartX, cartY, cartZ);
		//glRotatef(cartPhi, 0.0, 0.0, 1.0);
		glRotatef(cartTheta+90, 0.0, 1.0, 0.0);
		glTranslatef(-cartX, -cartY, -cartZ);
		// position cart on track
		glTranslatef(cartX,cartY,cartZ);
		glutSolidCube(1.0);
		drawWheel(0.25,-0.25,0.5);
		drawWheel(-0.25,-0.25,0.5);
		drawWheel(0.25,-0.25,-0.5);
		drawWheel(-0.25,-0.25,-0.5);
	};glPopMatrix();

}