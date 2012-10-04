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
  void set_upy(double);
  double get_upz();
  void set_upz(double);
  double get_dirx();
  void set_dirx(double);
  double get_diry();
  void set_diry(double);
  double get_dirz();
  void set_dirz(double);
  void set_radius(double);
  double get_radius();
  void set_theta(double);
  double get_theta();
  void set_phi(double);
  double get_phi();
  int get_mode();
  void set_mode(int);
  // function that sets 9 camera parameters based on radius, theta, phi for an arcball model
  void calculate_pos_arcball();
  // function that updates camera orientation, for an arcball model
  void update_pos_arcball();
  // function that sets 9 camera parameters for a free cam model
  void calculate_pos_free();
  // function that updates camerea orientation for a free cam model
  void update_pos_free();

  void calculate_first_person(float,float,float,float,float,float);
  void update_first_person(float,float,float,float,float,float);
  
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
  // variables that hold direction camera is looking at
  double dirx;
  double diry;
  double dirz;
  // variable that determines camera mode, 1 for arcball, 2 for free cam 3 for first person
  int mode;

};