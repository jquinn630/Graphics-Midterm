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

#include "coaster.h"
#include "bezier.h"

bool coasterStart=true;

void coaster::drawCoaster(vector<bezier> &bez){
	bezier bez1 = bez[firstCart.getCount()];
	firstCart.drawCart(bez1,1.2);
	bezier bez2 = bez[secondCart.getCount()];
	secondCart.drawCart(bez2,0);

	if (coasterStart){
		eyeStep=firstCart.getStep()+1;
		atStep=eyeStep+1.1;
		coasterStart=false;
	}
	bezier bezAt = bez[atCount];
	bezier bezEye = bez[eyeCount];

	controlpts eyeCam=bezEye.computeCurve(eyeStep);
	controlpts atCam=bezAt.computeCurve(atStep);

	eyex=eyeCam.getX();
	eyey=eyeCam.getY()+0.5;
	eyez=eyeCam.getZ();

	atx=atCam.getX();
	aty=atCam.getY()+0.5;
	atz=atCam.getZ();
}