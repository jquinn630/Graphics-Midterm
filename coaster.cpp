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

void coaster::drawCoaster(float theta, float phi, float xa, float xb, float xc, float xd, float ya, float yb, float yc, float yd, float za, float zb, float zc, float zd, float step){
	cart firstCart;
	cart secondCart;
	cart thirdCart;
	firstCart.drawCart(theta,phi,xa,xb,xc,xd,ya,yb,yc,yd,za,zb,zc,zd,step);
	secondCart.drawCart(theta,phi,xa,xb,xc,xd,ya,yb,yc,yd,za,zb,zc,zd,step-0.1);
	thirdCart.drawCart(theta,phi,xa,xb,xc,xd,ya,yb,yc,yd,za,zb,zc,zd,step-0.2);
}