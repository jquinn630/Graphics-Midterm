// controlpoints.h
// definition of controlpts class
// Written by John Quinn

#ifdef __APPLE__
	#include <GLUT/glut.h>
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/glut.h>
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

#ifndef CONTROLPTS_H
#define CONTROLPTS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

class controlpts
{
  friend controlpts operator -(controlpts &x, controlpts &y);
  friend controlpts operator *(float x, const controlpts& y);
  friend controlpts operator *( const controlpts& y, float x);

  public:
  controlpts(double a=0, double b=0, double c=0);
  double getX();
  double getY();
  double getZ();
  
  private:
  double x;
  double y;
  double z;
  
};

#endif