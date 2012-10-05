// implementation of material class for rollercoaster
// material.cpp
// john quinn and taylor seale

#ifdef __APPLE__
	#include <GLUT/glut.h>
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/glut.h>
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

#include "material.h"

using namespace std;

material::material(float *a, float *b, float *c, float s)
{
	// precondition: the four float arrays passed in are of size 4.
	for (int i=0; i<4; i++)
	{
	      diffCol[i]=a[i];
	      specCol[i]=b[i];
	      ambCol[i]=c[i];
	}
	shine=s;	
}

void material::setMaterial()
{
	glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, diffCol );
	glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, specCol );
	glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, shine);		
	glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, ambCol );
}