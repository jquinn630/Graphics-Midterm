// Rollercoaster-Midterm Project
// main.cpp
// Written by Taylor Seale and John Quinn

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
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <ctype.h>
#include <fstream>
#include <sstream>
#include "camera.h"
#include "controlpts.h"
#include "bezier.h"
#include "coaster.h"
#include "light.h"
#include "material.h"

#define PI 3.14159

using namespace std;

// declare window size global variables
int windowWidth = 512, windowHeight = 512;

// bezier curve points.
vector<controlpts> points; // holds points read in from file
vector<bezier> track;
int numPoints;   // holds total number of control points

// scenery variables
int numObjectst1;
int numObjectst2;
vector<controlpts> objt1;
vector<controlpts> objt2;

// frame counter
int framecount=0;

// hold fps;
int fps;

// keeps track to time
int currentTime=0;
int prevTime=0;

// declare pi as a floating point global var
float pi = 3.14159;

// declare global variables to handles mouse interaction
GLint leftClick, rightClick;    // holds state of left and right mouse buttons.
float oldx=0, oldy=0;    // holds previous x and y position of the mouse

GLint id; // id number for menu
GLuint trackList;

GLuint GrassTexHandle;
int GrassTexWidth, GrassTexHeight;

// declare global camera object
camera myCam(30.0, 2.00, 1.80,0,0,0);  // declares camera object
camera fpCam(30.0,2.00,1.80,0,0,0);  // first person camera object

// declare lights
// light 1
float lightCol[4] = { 1, 1, 1, 1};
float ambientCol[4] = { 0.2, 0.2, 0.2, 1.0 };
float lPosition[4] = { 0, 10, 0, 1 };
float specularLightCol[4] = { 0.3, 0.3, 0.3, 1 };	
light mainLight(lightCol,specularLightCol,ambientCol,lPosition,GL_LIGHT0);
//light2
float lightCol2[4]={0,1,0,1};
float ambientCol2[4]={0,0,0,1};
float lPosition2[4]={0,0,0,1};
float specularLightCol2[4]={1,1,1,1};
light changeLight(lightCol2,specularLightCol2,ambientCol2,lPosition2,GL_LIGHT1);

//declare coaster object;
coaster myCoaster;

void drawGround() {
  //glEnable( GL_TEXTURE_2D );
   // glBindTexture(  GL_TEXTURE_2D, GrassTexHandle );
  glDisable(GL_LIGHTING);
    glBegin(GL_QUADS);{
      //glNormal3f( 0, 0, 1 );
      glColor3f(0.4,0.4,0.4);
      glTexCoord2f( 0, 0 );
      glVertex3f(-15,-5,-15);

      //glNormal3f( 0, 0, 1 );
      glTexCoord2f( 1, 0 );
      glVertex3f(15,-5,-15);

      //glNormal3f( 0, 0, 1 );
      glTexCoord2f( 1, 1 );
      glVertex3f(15,-5,15);

      //glNormal3f( 0, 0, 1 );
      glTexCoord2f( 0, 1 );
      glVertex3f(-15,-5,15);
    };glEnd();
    glEnable(GL_LIGHTING);
    //glDisable(GL_TEXTURE_2D);
}

void drawTrackPiece(){
  glDisable(GL_LIGHTING);
    glBegin(GL_LINES);{
        glColor3f(1.0,1.0,1.0);
        glVertex3f(0,0,-0.5);
        glVertex3f(0,0,0.5);
        glVertex3f(-0.25,0,0.5);
        glVertex3f(0.25,0,0.5);
        glVertex3f(-0.25,0,-0.5);
        glVertex3f(0.25,0,-0.5);
        glColor3f(0.0,0.0,0.0);
    };glEnd();
  glEnable(GL_LIGHTING);
}

void drawTrackSupport(float height){
  glDisable(GL_LIGHTING);
    glBegin(GL_LINES);{
        glColor3f(0.0,0.0,0.0);
        glVertex3f(0,0,0);
        glVertex3f(0,-height-5.0,0);
    };glEnd();
  glEnable(GL_LIGHTING);
}

void drawCameraPoint(){
  glutSolidSphere(0.2,100,100); // draw a sphere
}

void drawTree()
{
  glColor3f(0,1,0);
  glPushMatrix();
    glRotatef(270,1,0,0);
    glTranslatef(0, 0, 0.5);
    glutSolidCone(1,2.0,5,5);
  glPopMatrix();

  glDisable(GL_LIGHTING);
  GLUquadric *trunk = gluNewQuadric();
  glColor3f(0.6,0.4,0.2);
  glPushMatrix();
    glRotatef(270,1,0,0);
    gluCylinder(trunk, 0.5, 0.5, 0.5, 25, 25);
  glEnable(GL_LIGHTING);
  glPopMatrix();

}

// draws a bezier curve based on control points
void generateTrackList(){
  trackList = glGenLists(1); // create the list
  glNewList(trackList,GL_COMPILE);
  int support=0;
  unsigned int pcount=0;
  glPushMatrix();
      drawGround();
  glPopMatrix();
  for (unsigned int i=0; i<track.size(); i++){
    if(pcount<track.size()){
    	for (float t=0; t<=track[pcount].getMaxLength(); t+=0.5){
        	controlpts temp = track[i].computeCurve(t);
          glPushMatrix();{
               glTranslatef(temp.getX(),temp.getY(),temp.getZ());
               glRotatef(temp.getTheta()+90, 0.0, 1.0, 0.0);
               glRotatef(temp.getPhi(), 0.0, 0.0, 1.0);
               glTranslatef(-temp.getX(),-temp.getY(),-temp.getZ());
               // position track
               glTranslatef(temp.getX(),temp.getY(),temp.getZ());
        	     drawTrackPiece();
          };glPopMatrix();
          if ((support%5)==0){
            glPushMatrix();{
                 glTranslatef(temp.getX(),temp.getY(),temp.getZ());
                 drawTrackSupport(temp.getY());
            };glPopMatrix();
          }
          support++;
      }
    pcount++;
    }
  }
  for (unsigned int i=0; i<objt1.size(); i++)
    {
      glPushMatrix(); {
          glTranslatef(objt1[i].getX(), objt1[i].getY()+5, objt1[i].getZ());
          drawTree();      // draws scenery for object type 1
       }; glPopMatrix();
    }
  glDisable( GL_COLOR_MATERIAL );
  for (unsigned int i=0; i<objt2.size(); i++)
	{
		glPushMatrix(); {
         	 glTranslatef(objt2[i].getX(), objt2[i].getY()+6, objt2[i].getZ());
			glutSolidOctahedron();
		}; glPopMatrix();
	}
  glEnable(GL_COLOR_MATERIAL);
  glEndList();
} 

// animates a red sphere to follow the bezier curve.
void animateBezier()
{
     glPushMatrix(); {
        myCoaster.drawCoaster(track);
    }; glPopMatrix(); 
}

// function to handle menu attached to middle button
void myMenu(int value)
{
	if (value==1)
	{
		exit(0);
	}
	if (value==2)
	{
		myCam.set_mode(1);
		myCam.set_atx(myCoaster.firstCart.getCartX());
		myCam.set_aty(myCoaster.firstCart.getCartY());
		myCam.set_atz(myCoaster.firstCart.getCartZ());
		myCam.set_theta(2.00);
		myCam.set_theta(1.80);
	}
	if (value==3)
	{
		myCam.set_mode(2);
		myCam.set_theta(-PI/3);
		myCam.set_phi(PI/2.8);
		myCam.set_eyex(30);
		myCam.set_eyey(20);
		myCam.set_eyez(20);
	}

}

void firstPerson(){
  glMatrixMode(GL_MODELVIEW);             
  glLoadIdentity(); 
  glDrawBuffer( GL_BACK );
  glViewport(windowHeight-windowHeight/3,windowWidth-windowWidth/3,windowWidth/3,windowHeight/3);
  glScissor(windowHeight-windowHeight/3,windowWidth-windowWidth/3,windowWidth/3,windowHeight/3);
  glEnable(GL_SCISSOR_TEST);
  glClearDepth(1.0);
  glClearColor(0,0,1,1);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glDisable(GL_SCISSOR_TEST);
  glPushMatrix();
    fpCam.update_first_person(myCoaster.eyex,myCoaster.eyey,myCoaster.eyez,
                              myCoaster.atx,myCoaster.aty,myCoaster.atz);
    glEnable( GL_COLOR_MATERIAL );
    glCallList(trackList);
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-0.5, windowWidth-0.5, -0.5, windowHeight-0.5, -1, 1);
  glColor3f(1,1,1);
  glLineWidth(5);
  glBegin(GL_LINE_LOOP);
      glVertex2f(windowWidth,0);
      glVertex2f(0,0);
      glVertex2f(0,windowHeight);
      glVertex2f(windowWidth,windowHeight);
  glEnd();
  glDisable( GL_COLOR_MATERIAL );
  glLineWidth(1);
}

//render scene function.  draws everything to scene.
void renderScene(void)  {
    //update the modelview matrix based on the camera's position
    glMatrixMode(GL_MODELVIEW);             
    glLoadIdentity();	
    //clear the render buffer and depth buffer
	glDrawBuffer( GL_BACK );
    glClearColor(0,0,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport( 0, 0, windowWidth, windowHeight);
    glPushMatrix();
        // set camera position
    if ( myCam.get_mode()==1)
    {
	     myCam.set_atx(myCoaster.firstCart.getCartX());
      myCam.set_aty(myCoaster.firstCart.getCartY());
      myCam.set_atz(myCoaster.firstCart.getCartZ());
	  myCam.update_pos_arcball();

	}
	
	else if (myCam.get_mode()==2)
	{
      myCam.set_eyex(myCam.get_eyex());
      myCam.set_eyey(myCam.get_eyey());
      myCam.set_eyez(myCam.get_eyez());
	    myCam.update_pos_free();
	}
  glPushMatrix(); {
     animateBezier();
    }; glPopMatrix();

      glEnable( GL_COLOR_MATERIAL );
    glCallList(trackList);
    glPopMatrix();

    glClear(GL_FRAMEBUFFER | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);

	glPushMatrix();
      glOrtho(-1,1,-1,1,-1,1);
    	glViewport(0, windowHeight-windowHeight/12, windowWidth/12, windowHeight/12);
    	glLoadIdentity();
      glColor3f(0,0,0);
    	char c[10];
    	sprintf(c, "%d", fps);
    	string temp=string(c);
      glRasterPos3i(0,0,0);
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'F');
    	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'P');
     	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'S');
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ':');
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
        	for (unsigned int i=0; i<temp.size(); i++)
        	{
        		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, temp[i] );
       		} 
      glMatrixMode(GL_PROJECTION);
  glPopMatrix();

  glPushMatrix();
    firstPerson();
  glPopMatrix();
  glDisable( GL_COLOR_MATERIAL );
  glMatrixMode(GL_MODELVIEW);
  glFlush();
      //push the back buffer to the screen
    glutSwapBuffers();
}

void normalKeys(unsigned char key, int x, int y)  
{
    //kindly quit if the user requests!
        if (key == 27)
			exit(0);
		
	if (myCam.get_mode()==2)
	{
		float movement=.3;
	if(key == 'w')
    {
       // move in
        myCam.set_eyex(myCam.get_eyex() + myCam.get_dirx()*movement);
        myCam.set_eyey(myCam.get_eyey() + myCam.get_diry()*movement);
        myCam.set_eyez(myCam.get_eyez() + myCam.get_dirz()*movement);
    }
    if(key == 's')
    {
		// move out
        myCam.set_eyex(myCam.get_eyex() - myCam.get_dirx()*movement);
        myCam.set_eyey(myCam.get_eyey() - myCam.get_diry()*movement);
        myCam.set_eyez(myCam.get_eyez() - myCam.get_dirz()*movement);
    }
    }
    glutPostRedisplay();

}

// controls camera with mouse movement
void cameraControl( int x, int y)
{
   if (leftClick==GLUT_DOWN)
   {
    // update camera angles
    myCam.set_theta(myCam.get_theta() + (x-oldx)*.01);
    myCam.set_phi(myCam.get_phi() + (y-oldy)*.01);
    // restrict phi
     if(myCam.get_phi() <= 0)
		myCam.set_phi(0+0.001);
	 if(myCam.get_phi() >= pi)
		myCam.set_phi(pi-0.001);
      
    glutPostRedisplay();
  }
  
 else if (rightClick==GLUT_DOWN)
 {
       myCam.set_radius(myCam.get_radius() + (y-oldy) * 0.03);  // change the radius based on movement
     // don't allow the camera radius to go below a set minimum or above a set maximum
     if(myCam.get_radius() < 10.0) 
        myCam.set_radius (10.0);
     if(myCam.get_radius() > 50.0) 
        myCam.set_radius (50.0);
  	glutPostRedisplay();
  }
  // update old x and y positions
  oldx=x;
  oldy=y;
}

// controls the state of mouse based on usere clicking.
void clickControl(int button, int state, int x, int y)
{  
 
 	GLint mod=glutGetModifiers();
    if(button == GLUT_LEFT_BUTTON && mod!=GLUT_ACTIVE_SHIFT)
       {
        leftClick= state;  // save info if left click
        }
    else if(button == GLUT_LEFT_BUTTON && mod==GLUT_ACTIVE_SHIFT)  
       {
        rightClick = state; // save info if right click  
        }

    // update old x and y position
    oldx = x;
    oldy = y;
}


//********************************************************************************
// void myTimer(int value)
//
//  We have to take an integer as input per GLUT's timer function prototype;
//  but we don't use that value so just ignore it. We'll register this function
//  once at the start of the program, and then every time it gets called it
//  will perpetually re-register itself and tell GLUT that the screen needs
//  be redrawn. yes, I said "needs be."
//********************************************************************************
void myTimer(int value) {
    
    if(myCoaster.atStep>=(track[myCoaster.atCount].getMaxLength()-0.1))
      {
      myCoaster.atStep=0;
      myCoaster.atCount++;
      }  
      else
      {
        myCoaster.atStep+=0.1;
      }

    if (myCoaster.atCount>=track.size()){
      myCoaster.atStep=0;
      myCoaster.atCount=0;
    }


    if(myCoaster.eyeStep>=(track[myCoaster.eyeCount].getMaxLength()-0.1))
      {
      myCoaster.eyeStep=0;
      myCoaster.eyeCount++;
      }  
      else
      {
        myCoaster.eyeStep+=0.1;
      }

    if (myCoaster.eyeCount>=track.size()){
      myCoaster.eyeStep=0;
      myCoaster.eyeCount=0;
    }

    if(myCoaster.firstCart.getStep()>=(track[myCoaster.firstCart.getCount()].getMaxLength()-0.1))
      {
      myCoaster.firstCart.setStep(0);
      myCoaster.firstCart.incCount();
      }  
      else
      {
        myCoaster.firstCart.incStep();
      }

    if (myCoaster.firstCart.getCount()>=track.size()){
    	myCoaster.firstCart.setStep(0);
      myCoaster.firstCart.setCount(0);
	  }

    if(myCoaster.secondCart.getStep()>=(track[myCoaster.secondCart.getCount()].getMaxLength()-0.1))
      {
      myCoaster.secondCart.setStep(0);
      myCoaster.secondCart.incCount();
      }  
      else
      {
        myCoaster.secondCart.incStep();
      }

    if (myCoaster.secondCart.getCount()>=track.size()){
      myCoaster.secondCart.setStep(0);
      myCoaster.secondCart.setCount(0);
    }

    if(myCoaster.thirdCart.getStep()>=(track[myCoaster.thirdCart.getCount()].getMaxLength()-0.1))
      {
      myCoaster.thirdCart.setStep(0);
      myCoaster.thirdCart.incCount();
      }  
      else
      {
        myCoaster.thirdCart.incStep();
      }

    if (myCoaster.thirdCart.getCount()>=track.size()){
      myCoaster.thirdCart.setStep(0);
      myCoaster.thirdCart.setCount(0);
    }

    if(myCoaster.fourthCart.getStep()>=(track[myCoaster.fourthCart.getCount()].getMaxLength()-0.1))
      {
      myCoaster.fourthCart.setStep(0);
      myCoaster.fourthCart.incCount();
      }  
      else
      {
        myCoaster.fourthCart.incStep();
      }

    if (myCoaster.fourthCart.getCount()>=track.size()){
      myCoaster.fourthCart.setStep(0);
      myCoaster.fourthCart.setCount(0);
    }
    
   if(changeLight.getB()<1&&changeLight.getG()==1)
    {
    	changeLight.setB(changeLight.getB()+.005);
    }
    else if(changeLight.getB()>=1&&changeLight.getG()==1)
    {
    	changeLight.setB(1);
    	changeLight.setG(0);
    }
    else if (changeLight.getR()<1&&changeLight.getB()==1)
    {
		changeLight.setR(changeLight.getR()+.005);
	}
	else if(changeLight.getR()>=1&&changeLight.getB()==1)
    {
    	changeLight.setR(1);
    	changeLight.setB(0);
    }
    else if (changeLight.getG()<1&&changeLight.getR()==1)
    {
		changeLight.setG(changeLight.getG()+.005);
	}
	else if(changeLight.getG()>=1&&changeLight.getR()==1)
    {
    	changeLight.setG(1);
    	changeLight.setR(0);
    }
    changeLight.updateLight();

	// tell GLUT to update the display
    glutPostRedisplay();
	// and register our timer again
    glutTimerFunc((unsigned int)(1000.0 / 60.0), myTimer, 0);
}

//********************************************************************************
//  void resizeWindow(int w, int h)
//
//      We will register this function as GLUT's reshape callback.
//   When the window is resized, the OS will tell GLUT and GLUT will tell
//   us by calling this function - GLUT will give us the new window width
//   and height as 'w' and 'h,' respectively - so save those to our global vars.
//********************************************************************************
void resizeWindow(int w, int h) {
    float aspectRatio = w / (float)h;
	
    windowWidth = w;
    windowHeight = h;

    //update the viewport to fill the window
    glViewport( 0, 0, w, h );

    //update the projection matrix with the new window properties
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    /* TODO: set up the proper projection */
	gluPerspective( 45.0f, aspectRatio, 0.1, 1000 );
}

bool registerOpenGLTexture(unsigned char *textureData, 
               unsigned int texWidth, unsigned int texHeight, 
               GLuint &textureHandle) {
    if(textureData == 0) {
        fprintf(stderr,"Cannot register texture; no data specified.");
        return false;
    }
  
  // TODO: Setup Step 2-3 generate texture handle and bind texture
  glGenTextures( 1, &textureHandle );
  glBindTexture( GL_TEXTURE_2D, textureHandle );

  
  // TODO: Setup Step 4
  // TODO: set color mode
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);  // GL_MODULATE or GL_DECAL
  
  // TODO: set min/mag filters
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);  // a MIN Filter MUST BE SET
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
  // TODO: set wrapping options
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // GL_REPEAT or GL_CLAMP
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    GLenum errCode;
    const GLubyte *errString;
  
    if ((errCode = glGetError()) != GL_NO_ERROR) {
        errString = gluErrorString(errCode);
        fprintf(stderr,"Cannot register texture; OpenGL error: %s.", errString);
        return false;
    } 
  
  // TODO: Setup Step 5 register image
    glTexImage2D( GL_TEXTURE_2D,  // specifying a 2D texture
         0,         // level of the texture map - used for mipmapping
         GL_RGB,      // internal format of image data
         texWidth,      // texture width
         texHeight,     // texture height
         0,         // border width - used for filtering
         GL_RGB,      // type of texels to use
         GL_UNSIGNED_BYTE,  // how is the data stored in array
         textureData    // pointer to array of image data
         );
    return true;
}

bool readPPM(string filename, int &imageWidth, int &imageHeight, unsigned char* &imageData) {
    FILE *fp = fopen(filename.c_str(), "r");
    int temp, maxValue;
    fscanf(fp, "P%d", &temp);
    if(temp != 3) {
        fprintf(stderr, "Error: PPM file is not of correct format! (Must be P3, is P%d.)\n", temp);
        fclose(fp);
        return false;
    }
  
    //got the file header right...
    fscanf(fp, "%d", &imageWidth);
    fscanf(fp, "%d", &imageHeight);
    fscanf(fp, "%d", &maxValue);
  
    //now that we know how big it is, allocate the buffer...
    imageData = new unsigned char[imageWidth*imageHeight*3];
    if(!imageData) {
        fprintf(stderr, "Error: couldn't allocate image memory. Dimensions: %d x %d.\n", imageWidth, imageHeight);
        fclose(fp);
        return false;
    }
  
    //and read the data in.
    for(int j = 0; j < imageHeight; j++) {
        for(int i = 0; i < imageWidth; i++) {
            int r, g, b;
            fscanf(fp, "%d", &r);
            fscanf(fp, "%d", &g);
            fscanf(fp, "%d", &b);
      
            imageData[(j*imageWidth+i)*3+0] = r;
            imageData[(j*imageWidth+i)*3+1] = g;
            imageData[(j*imageWidth+i)*3+2] = b;
        }
    }
    
    fclose(fp);
    return true;
}

// function that calculates fps.
void calculatefps()
{
   // increment framecount
   framecount++;
   currentTime=glutGet(GLUT_ELAPSED_TIME);
   // get elapsed time
   int difference = currentTime-prevTime;
   if (difference > 1000) // every second
   {
   	 fps=framecount/(difference/1000.0); // get current fps
   	 prevTime=currentTime;  // update time
   	 framecount=0;  //reset framecount.
   }
}

// calculate fps when program is idle
void idle ()
{
	calculatefps();
  glutPostRedisplay ();
}

//********************************************************************************
//	registerCallbacks()
//
//	Register all of our callbacks with GLUT.  Just a way to clean up our 
//		intialization process by breaking each section into its own function.
//********************************************************************************
void registerCallbacks() {
	// ASCII keydown callback
    glutKeyboardFunc( normalKeys );
	// display to screen callback
    glutDisplayFunc( renderScene );
	// window reshape callback
    glutReshapeFunc( resizeWindow );
	// register our timer with GLUT
	glutTimerFunc( (unsigned int)(1000.0 / 60.0), myTimer, 0 );
    // clicking control that helps aid the arcball
	glutMouseFunc(clickControl);
	// control for the arcball camera
	glutMotionFunc( cameraControl);
	// call idle func for fps counts
	glutIdleFunc(idle);
}

//********************************************************************************
//  void initScene()
//
//  A basic scene initialization function; should be called once after the
//      OpenGL context has been created. Doesn't need to be called further.
//      Just sets up a few function calls so that our main() is cleaner.
//********************************************************************************
void initScene() {
	// tell OpenGL to perform depth testing with the Z-Buffer to perform hidden
	//		surface removal.  We will discuss this more very soon.
    glEnable( GL_DEPTH_TEST );
	
	//******************************************************************
    // this is some code to enable a default light for the scene;
    // feel free to play around with this, but we won't talk about
    // lighting in OpenGL for another couple of weeks yet.
    glEnable( GL_LIGHTING );
    
    mainLight.updateLight();
    changeLight.updateLight();
    
    id = glutCreateMenu(myMenu);
    glutAddMenuEntry("Quit", 1);
    glutAddMenuEntry("Arcball Mode", 2);
    glutAddMenuEntry("Freecam Mode", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
       	
    // tell OpenGL not to use the material system; just use whatever we 
	// pass with glColor*()
		glEnable( GL_COLOR_MATERIAL );
    glColorMaterial( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );
	//******************************************************************
	
    // tells OpenGL to blend colors across triangles. Once lighting is
    // enabled, this means that objects will appear smoother - if your object
    // is rounded or has a smooth surface, this is probably a good idea;
    // if your object has a blocky surface, you probably want to disable this.
     unsigned char *GrassTexData;
      if( readPPM( "grass.ppm", GrassTexWidth, GrassTexHeight, GrassTexData ) )
    printf( "Successfully read in image grass.ppm\n" );
    
  // TODO: Setup Steps 2-5
  if( registerOpenGLTexture( GrassTexData, GrassTexWidth, GrassTexHeight, GrassTexHandle ) )
    printf( "Successfully registered texture with handle %d\n", GrassTexHandle );
    glShadeModel( GL_SMOOTH );
    generateTrackList();
    glDisable(GL_COLOR_MATERIAL);
}

int main(int argc, char* argv[]) {
    // create a double-buffered GLUT window with depth buffer at (50,50) with 
	// predefined windowsize
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowPosition( 50, 50 );
    glutInitWindowSize( windowWidth, windowHeight );
    glutCreateWindow( "Rollercoaster" );
    
    // handle file
	FILE *dataFile;		// used to open data file
    string hold;    // buffer that holds data read in from file
    char c;         // character buffer
    
    vector<float> rawpoints;
    
    if (!(dataFile = fopen (argv[1], "r")))  // open file
	{
	  cout << "File read failed." << endl;	// if file can't be read, give appropriate error message.
	}
     else
	{
  	  while (!feof (dataFile))  // for the whole file
  	  {
  	    c=fgetc(dataFile);  // get next character
  	    if ( c!= ','  && c!='\n')
  	    {
  	    	hold.push_back(c);
  	    }  // put all characters of a particular float into a buffer.
  	    else 
  	    {
  	    	rawpoints.push_back(atof(hold.c_str()));  // put floating number in vector
  	    	hold.clear(); // clear buffer
  	    }
  	  }
  	      fclose (dataFile);  // close file
	}
	
	// store points in vector of control points
	numPoints=rawpoints[0];
	int numcounter;
	for(int i=1; i<=numPoints*3; i+=3)
	{
		controlpts temp(rawpoints[i],rawpoints[i+1],rawpoints[i+2]);
		points.push_back(temp);
		numcounter=i;
	}
	
	numObjectst1=rawpoints[numcounter+3];
	
	int numcounter2;
	for (int j=numcounter+4; j<numcounter+4+(numObjectst1*3);  j+=3)
	{
	   	controlpts temp(rawpoints[j],rawpoints[j+1],rawpoints[j+2]);
		objt1.push_back(temp);
		numcounter2=j;
	}
	
	numObjectst2=rawpoints[numcounter2+3];
	
	for (int k=numcounter2+4; k<numcounter2+4+(numObjectst2*3);  k+=3)
	{
	   	controlpts temp(rawpoints[k],rawpoints[k+1],rawpoints[k+2]);
		objt2.push_back(temp);
	} 
	
	
	for (unsigned int i=0; i<points.size()-3; i+=3)
	{
		bezier temp =bezier(points[i], points[i+1], points[i+2], points[i+3]);
		track.push_back(temp);
	} 

	// register all of our callbacks with GLUT
	registerCallbacks();
	
    // do some basic OpenGL setup
    initScene();

    // and enter the GLUT loop, never to exit.
    glutMainLoop();

    return(0);
}
