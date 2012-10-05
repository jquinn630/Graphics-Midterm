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
bool cartStart=true;

void drawWheel(float x, float y, float z){
	glPushMatrix();{
		glColor3f(0.0,0.0,0.0);
		glTranslatef(x,y,z);
		glutSolidTorus(0.25, 0.01, 100, 100);
	};glPopMatrix();
}

<<<<<<< HEAD
void cart::drawCart(bezier bez, float step){
	controlpts point1=bez.computeCurve(step);
	controlpts eyePoint=bez.computeCurve(step+1);
    controlpts atPoint=bez.computeCurve(step+2);
=======
void cart::drawCart(bezier bez, float offset){
	if (cartStart){
		cartStep+=offset;
		cartStart=false;
	}

	controlpts point1=bez.computeCurve(cartStep);	
>>>>>>> First Person Viewport in the corner

	glPushMatrix();{
		glColor3f(1.0,0.0,0.0);
		// rotate for theta
		glTranslatef(point1.getX(), point1.getY(), point1.getZ());
		glRotatef(point1.getTheta()+90, 0.0, 1.0, 0.0);
		glRotatef(point1.getPhi(), 0.0, 0.0, 1.0);
		glTranslatef(-point1.getX(),-point1.getY(),-point1.getZ());
		// position cart on track
		glTranslatef(point1.getX(), point1.getY()+0.5, point1.getZ());
		glutSolidCube(1.0);
		glColor3f(0.0,0.0,0.0);
		drawWheel(0.25,-0.25,0.5);
		drawWheel(-0.25,-0.25,0.5);
		glColor3f(1.0,1.0,1.0);
		drawWheel(0.25,-0.25,-0.5);
		drawWheel(-0.25,-0.25,-0.5);
	};glPopMatrix();
	cartX=point1.getX();
	cartY=point1.getY()+0.5;
	cartZ=point1.getZ();
<<<<<<< HEAD
	
		// get coordinates for first person camera
	eyeX=eyePoint.getX();
	eyeY=eyePoint.getY()+0.5;
	eyeZ=eyePoint.getZ();
	atX=atPoint.getX();
	atY=atPoint.getY()+0.5;
	atZ=atPoint.getZ();
=======
>>>>>>> First Person Viewport in the corner
}

float cart::getCartX(){
	return cartX;
}

float cart::getCartY(){
	return cartY;
}

float cart::getCartZ(){
	return cartZ;
}

float cart::getStep(){
	return cartStep;
}

void cart::setStep(float s){
	cartStep=s;
}

void cart::incStep(){
	cartStep+=0.1;
}

int cart::getCount(){
	return cartPcount;
}

void cart::setCount(int c){
	cartPcount=c;
}

void cart::incCount(){
	cartPcount++;
}





