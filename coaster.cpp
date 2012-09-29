// Taylor Seale & John Quinn
// Computer Graphics Midterm
// coaster.cpp

// implementation file for a coaster object which connects a bunch of cart objects using composition

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
#include "coaster.h"

void coaster::drawCoaster(float x, float y, float z, float theta, float phi){
	cart firstCart;
	cart secondCart;
	cart thirdCart;
	firstCart.drawCart(x,y,z,theta,phi);
	secondCart.drawCart(x+1,y+1,z+1,theta,phi);
	thirdCart.drawCart(x+2,y+2,z+2,theta,phi);
}