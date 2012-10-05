// material.h
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

#ifndef MATERIAL_H
#define MATERIAL_H

class material {
	public:
	material(float *, float *, float *, float);
	void setMaterial();
	
	private:
	float diffCol[4];
	float specCol[4];
	float ambCol[4];
	float shine;
};


#endif
