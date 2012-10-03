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

void cart::drawCart(bezier bez, float step){
	controlpts point1=bez.computeCurve(step);

	glPushMatrix();{
		glColor3f(1.0,0.0,0.0);
		// rotate for theta
		glTranslatef(point1.getX(), point1.getY(), point1.getZ());
		glRotatef(point1.getTheta()+90, 0.0, 1.0, 0.0);
		glTranslatef(-point1.getX(),-point1.getY(),-point1.getZ());
		// position cart on track
		glTranslatef(point1.getX(), point1.getY()+0.5, point1.getZ());
		glutSolidCube(1.0);
		drawWheel(0.25,-0.25,0.5);
		drawWheel(-0.25,-0.25,0.5);
		drawWheel(0.25,-0.25,-0.5);
		drawWheel(-0.25,-0.25,-0.5);
	};glPopMatrix();
}

