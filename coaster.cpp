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
#include "bezier.h"

void coaster::drawCoaster(bezier bez, float step){
	cart firstCart;
	//cart secondCart;
	//cart thirdCart;

	firstCart.drawCart(bez,step);
	//secondCart.drawCart(bez,step-1.5);
	//thirdCart.drawCart(bez,step-3.0);
}