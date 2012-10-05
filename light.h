// definition of light class for rollercoaster
// light.h
// john quinn and taylor seale

// definition of light class for rollercoaster
// light.h
// john quinn and taylor seale

#include <iostream>

#ifdef __APPLE__
	#include <GLUT/glut.h>
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/glut.h>
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

#ifndef LIGHT_H
#define LIGHT_H

class light {

	public:
	light(float *, float *, float *, float *);//, int);
	float getX();
	float getY();
	float getZ();
	void setX(float);
	void setY(float);
	void setZ(float);
	void updateLight();
	
	
	private:
	float diffCol[4];
	float specCol[4];
	float ambCol[4];
	float lPos[4];
	int lightNum;
};

#endif