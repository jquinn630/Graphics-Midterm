// John Quinn
// camera.h
// definition of an arcball camera class for use in openGL

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

class camera {

  public:
  // constructor
  camera(double, double, double,double, double, double); 
  // get and set functions for private data members.
  double get_eyex();
  void set_eyex( double);
  double get_eyey();
  void set_eyey( double);
  double get_eyez();
  void set_eyez( double);
  double get_atx();
  void set_atx( double);
  double get_aty();
  void set_aty( double);
  double get_atz();
  void set_atz( double);
  double get_upx();
  void set_upx( double);
  double get_upy();
  void set_upy( double);
  double get_upz();
  void set_upz( double);
  void set_radius(double);
  double get_radius();
  void set_theta(double);
  double get_theta();
  void set_phi(double);
  double get_phi();
  // function that sets 9 camera parameters based on radius, theta, phi
  void calculate_pos();
  // function that updates camera orientation
  void update_pos();
  
  private:
  // variables pertaining to the arcballs
  double cameraRadius;
  double cameraPhi;
  double cameraTheta;
  // variables that hold camera's position
  double eyex;
  double eyey;
  double eyez;
  // variables that hold the point camera is looking at
  double atx;
  double aty;
  double atz;
  // variables that hold the up vector of the camera
  double upx;
  double upy;
  double upz;

};