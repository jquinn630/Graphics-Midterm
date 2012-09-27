
#ifdef __APPLE__
	#include <GLUT/glut.h>
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/glut.h>
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

#ifndef BEZIER_H
#define BEZIER_H

#include <iostream>
#include <cmath>
#include "controlpts.h"

class bezier {
	
	public:
	bezier(controlpts w, controlpts x, controlpts y, controlpts z);
	controlpts computeCurve(float t);
	
	private:
	controlpts first;
	controlpts second;
	controlpts third;
	controlpts fourth;
	
};

#endif