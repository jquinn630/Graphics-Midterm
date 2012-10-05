// implementation of light class for rollercoaster
// light.cpp
// john quinn and taylor seale

#include "light.h"
#ifdef __APPLE__
	#include <GLUT/glut.h>
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/glut.h>
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

using namespace std;

light::light(float *a, float *b, float *c, float *d)//, int name)
{
	// precondition: the four float arrays passed in are of size 4.
	for (unsigned int i=0; i<4; i++)
	{
		diffCol[i]=a[i];
		specCol[i]=b[i];
		ambCol[i]=c[i];
		lPos[i]=d[i];
	}
	
	lightNum=0;

}

float light::getX()
{
	return lPos[0];
}

float light::getY()
{
	return lPos[1];
}
	
float light::getZ()
{
	return lPos[2];
}

void light::setX(float x)
{
	lPos[0]=x;
}

void light::setY(float y)
{
	lPos[1]=y;
}

void light::setZ(float z)
{
	lPos[2]=z;
}

void light::updateLight()
{
	glLightfv( GL_LIGHT0, GL_POSITION,lPos );
    glLightfv( GL_LIGHT0, GL_DIFFUSE,diffCol );
    glLightfv( GL_LIGHT0, GL_AMBIENT, ambCol );
    glLightfv( GL_LIGHT0, GL_SPECULAR, specCol );
    glEnable( GL_LIGHT0 );
}


