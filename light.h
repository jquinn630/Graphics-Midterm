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

class light {

	public:
	light(float *, float *, float *, float *);
	
	private:
	int diffCol[4];
	int specCol[4];
	int ambCol[4];
	int lPos[4];
};