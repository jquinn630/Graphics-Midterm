// John Quinn
// camera.cpp
// implementation of an arcball camera class for use in openGL

#ifdef __APPLE__
	#include <GLUT/glut.h>
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/glut.h>
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "camera.h" 

  // constructor
camera::camera(double radius, double theta, double phi, double x , double y , double z)
{
  cameraRadius=radius;
  cameraPhi=phi;
  cameraTheta=theta;
  atx=x;
  aty=y;
  atz=z;
  upx=0;
  upy=1;
  upz=0;
  mode=1;
  dirx=0;
  diry=0;
  dirz=0;
  calculate_pos_arcball();
}
  // get and set functions for private data members.
double camera::get_eyex()
{
	return eyex;
}

void camera::set_eyex( double x)
{
	eyex=x;
}

double camera::get_eyey()
{
	return eyey;
}

void camera::set_eyey( double y)
{
	eyey=y;
}

double camera::get_eyez()
{
	return eyez;
}

void camera::set_eyez( double z)
{
	eyez=z;
}

double camera::get_atx()
{
	return atx;
}

void camera::set_atx( double x)
{
	atx=x;
}

double camera::get_aty()
{
	return aty;
}

void camera::set_aty( double y)
{
	aty=y;
}

double camera::get_atz()
{
	return atz;
}

void camera::set_atz( double z)
{
	atz=z;
}

double camera::get_upx()
{
	return upx;
}

void camera::set_upx( double x)
{
	upx=x;
}

double camera::get_upy()
{
	return upy;
}

void camera::set_upy( double y)
{
	upy=y;
}

double camera::get_upz()
{
	return upz;
}

void camera::set_upz( double z)
{
	upz=z;
}
 
void camera::set_radius(double r)
{
	cameraRadius=r;
}

double camera::get_radius()
{
	return cameraRadius;
}

void camera::set_theta(double t)
{
	cameraTheta=t;
}

double camera::get_theta()
{
	return cameraTheta;
}

void camera::set_phi(double p)
{
	cameraPhi=p;
}

double camera::get_phi()
{
	return cameraPhi;
}

int camera::get_mode()
{
	return mode;
}

void camera::set_mode(int x)
{
	mode=x;
}

double camera::get_dirx()
{
	return dirx;
}

void camera::set_dirx(double x)
{
	dirx=x;
}

double camera::get_diry()
{
	return diry;
}

void camera::set_diry(double y)
{
	diry=y;
}

double camera::get_dirz()
{
	return dirz;
}

void camera::set_dirz(double z)
{
	dirz=z;
}

// function that sets 9 camera parameters based on radius, theta, phi, for arcball
void camera::calculate_pos_arcball()
{
	// use spherical coordinates to update position
	 set_eyex(cameraRadius * sin(cameraTheta)*sin(cameraPhi));
     set_eyey(cameraRadius * -cos(cameraPhi));
     set_eyez(cameraRadius * -cos(cameraTheta)*sin(cameraPhi));	
}

//updates camera position, for arcball
void camera::update_pos_arcball()
{
    // updates camera position based on any variable changes.
    calculate_pos_arcball();
    // calls the appropriate glu function
	gluLookAt( eyex, eyey, eyez, 
			   atx, aty, atz,
			   upx, upy, upz );
}

// updates 9 camera parameters for free cam
void camera::calculate_pos_free()
{
    dirx=  sinf(cameraTheta)*sinf(cameraPhi);
    dirz = -cosf(cameraTheta)*sinf(cameraPhi);
    diry = -cosf(cameraPhi);
    //normalize directional vector
    float mag = sqrt( dirx*dirx + diry*diry + dirz*dirz );
    dirx /= mag;  diry /= mag;  dirz /= mag;
}

// function that updates camerea orientation for a free cam model
void camera::update_pos_free()
{
	// update camera position based on variable changes for free cam
	calculate_pos_free();
   // calls look at function
	gluLookAt( eyex, eyey, eyez, 
			   eyex+dirx, eyey+diry, eyez+dirz,
			   upx, upy, upz );
}

void camera::calculate_first_person(float x, float y, float z)
{
	// use spherical coordinates to update position
	 set_eyex(x);
     set_eyey(y);
     set_eyez(z);	
}

//updates camera position, for arcball
void camera::update_first_person(float x, float y, float z)
{
    // updates camera position based on any variable changes.
    calculate_first_person(x,y,z);
    // calls the appropriate glu function
	gluLookAt( eyex, eyey, eyez, 
			   atx, aty, atz,
			   upx, upy, upz );
}