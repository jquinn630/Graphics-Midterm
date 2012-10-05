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
#include "material.h"

#define PI 3.14159
bool cartStart=true;

	//declare materials
	//rollercoaster body
	float matdiffCol[4] = { 0.8, 0.0, 0.05 };	// reddish				
	float matspecCol[4] = { 1.0, 1.0, 0.0 };					
	float matambCol[4] = { 0.8, 0.8, 0.8 };
	material bodyMat(matdiffCol, matspecCol, matambCol, 90.0);

	// rollercoaster wheel
	float matdiffCol2[4] = {0.0,0.0,0.0 };	// black			
	float matspecCol2[4] = { 0.1, 0.1, 0.1 };    // doesn't reflect as much					
	float matambCol2[4] = { 0.2, 0.2, 0.2 };
	material wheelMat(matdiffCol2,matspecCol2,matambCol2,40.0);


void drawWheel(float x, float y, float z){
	glPushMatrix();{
		glColor3f(0.0,0.0,0.0);
		glTranslatef(x,y,z);
		glutSolidTorus(0.25, 0.01, 100, 100);
	};glPopMatrix();
}

void cart::drawCart(bezier bez, float offset){
	if (cartStart){
		cartStep+=offset;
		cartStart=false;
	}
	controlpts point1=bez.computeCurve(cartStep);	

	glPushMatrix();{
		//glColor3f(1.0,0.0,0.0);
		// rotate for theta
		glTranslatef(point1.getX(), point1.getY(), point1.getZ());
		glRotatef(point1.getTheta()+90, 0.0, 1.0, 0.0);
		glRotatef(point1.getPhi(), 0.0, 0.0, 1.0);
		glTranslatef(-point1.getX(),-point1.getY(),-point1.getZ());
		// position cart on track
		glTranslatef(point1.getX(), point1.getY()+0.5, point1.getZ());
		bodyMat.setMaterial();
		glutSolidCube(1.0);
		wheelMat.setMaterial();
		//glColor3f(0.0,0.0,0.0);
		drawWheel(0.25,-0.25,0.5);
		drawWheel(-0.25,-0.25,0.5);
		//glColor3f(1.0,1.0,1.0);
		drawWheel(0.25,-0.25,-0.5);
		drawWheel(-0.25,-0.25,-0.5);
	};glPopMatrix();
	cartX=point1.getX();
	cartY=point1.getY()+0.5;
	cartZ=point1.getZ();
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





