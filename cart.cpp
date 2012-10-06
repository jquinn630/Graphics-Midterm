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
float wheelTheta=0;

	//declare materials
	//rollercoaster body
	float matdiffCol[4] = { 0.4,0.0,0.0};	// reddish				
	float matspecCol[4] = { 1.0, 1.0, 1.0 };					
	float matambCol[4] = { 0.8, 0.8, 0.8 };
	material bodyMat(matdiffCol, matspecCol, matambCol, 128.0);

	// rollercoaster wheel
	float matdiffCol2[4] = {0.0,0.0,0.0 };	// black			
	float matspecCol2[4] = { 0.1, 0.1, 0.1 };    // doesn't reflect as much					
	float matambCol2[4] = { 0.2, 0.2, 0.2 };
	material wheelMat(matdiffCol2,matspecCol2,matambCol2,40.0);

cart::cart(){
	cartStart=true;
}

void drawTire(float size){
	// use GLUT primative to draw tire
	glColor3f(0.0,0.0,0.0);
	glutSolidTorus(size/8.0,size/4.0,50,50);
}

void drawHubcap(float size, float x, float y, float z){
	// draw hubcap that will spin as car moves
	glDisable(GL_LIGHTING);
	glColor3f(0.8,0.8,0.8);
	glVertex3f(x,y,z);
	glBegin(GL_TRIANGLE_FAN);{
		for (float angle=0.0; angle<(2*PI); angle+=0.01){
			glVertex3f(x+(cos(angle)*size/8),y+(sin(angle)*size/8),z+0.01);
		}
	};glEnd();
	// cross on hubcap to make movement obvious
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);{ // black
		glVertex3f(x+size/8,y+size/8,z+0.02);
		glVertex3f(x-size/8,y-size/8,z+0.02);
	}glEnd();
	glBegin(GL_LINES);{
		glVertex3f(x-size/8,y+size/8,z+0.02);
		glVertex3f(x+size/8,y-size/8,z+0.02);
	}glEnd();
	glEnable(GL_LIGHTING);
}

void drawWheel(float size, float x, float y, float z){
	// combine the hubcap and the tire
	glPushMatrix();{
		glTranslatef(x,y,z);
		drawTire(size);
	};glPopMatrix();
	glPushMatrix();{
			glTranslatef(x, y, z);
			glRotatef(wheelTheta, 0.0, 0.0, 1.0);       //Rotate about the y-axis
			glTranslatef(-x, -y, -z);
			drawHubcap(size,x,y,z);
			wheelTheta++;
	};glPopMatrix();
}

void cart::drawCart(bezier bez, float offset){
	if (cartStart){
		cartStep+=offset;
		cartStart=false;
	}
	controlpts point1=bez.computeCurve(cartStep);	

	glPushMatrix();{
		// rotate for theta & phi
		glTranslatef(point1.getX(), point1.getY(), point1.getZ());
		glRotatef(point1.getTheta()+90, 0.0, 1.0, 0.0);
		glRotatef(point1.getPhi(), 0.0, 0.0, 1.0);
		glTranslatef(-point1.getX(),-point1.getY(),-point1.getZ());
		// position cart on track
		glTranslatef(point1.getX(), point1.getY()+0.5, point1.getZ());
		bodyMat.setMaterial();
		glutSolidCube(1.0);
		wheelMat.setMaterial();
		glPushMatrix();
			drawWheel(0.7,0.25,-0.45,0.5);
		glPopMatrix();
		glPushMatrix();
			drawWheel(0.7,-0.25,-0.45,0.5);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.25,-0.45,-0.5);
			glRotatef(180, 0.0, 1.0, 0.0);
			glTranslatef(-0.25,0.45,0.5);
			drawWheel(0.7,0.25,-0.45,-0.5);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-0.25,-0.45,-0.5);
			glRotatef(180, 0.0, 1.0, 0.0);
			glTranslatef(0.25,0.45,0.5);
			drawWheel(0.7,-0.25,-0.45,-0.5);
		glPopMatrix();
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





