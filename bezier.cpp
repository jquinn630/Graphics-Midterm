#include "bezier.h"
#include "controlpts.h"
#include <cmath>

using namespace std;

#define PI 3.14159

bezier::bezier(controlpts w, controlpts x, controlpts y, controlpts z)
{
	first=controlpts(w);
	second=controlpts(x);
	third=controlpts(y);
	fourth=controlpts(z);
	
	maxLength=computeMaxLength();
}

float bezier::computeMaxLength()
{

	// calculate x coefficients
	float xa= -1 * first.getX() +3*second.getX() - 3*third.getX() +fourth.getX();
	float xb= 3*first.getX() - 6*second.getX() +3*third.getX();
	float xc= -3*first.getX() + 3*second.getX();
	float xd= first.getX();
	
	// calculate y coefficients
	float ya= -1 * first.getY() +3*second.getY() -3*third.getY() +fourth.getY();
	float yb= 3*first.getY() - 6*second.getY() +3*third.getY();
	float yc= -3*first.getY() + 3*second.getY();
	float yd= first.getY();
	
	// calculate z coefficients
	float za= -1 * first.getZ() +3*second.getZ() -3*third.getZ() +fourth.getZ();
	float zb= 3*first.getZ() - 6*second.getZ() +3*third.getZ();
	float zc= -3*first.getZ() + 3*second.getZ();
	float zd= first.getZ();
	
	float length=0.0;
	// get first point for curve
	float oldx=xd;
    float oldy=yd;
    float oldz=zd;
    float xpos, ypos, zpos;
    
	for (float t=0; t<1.0; t+=.01)
	{
		xpos=xa*t*t*t+xb*t*t+xc*t+xd;
    	ypos=ya*t*t*t+yb*t*t+yc*t+yd;
        zpos=za*t*t*t+zb*t*t+zc*t+zd;
    	length+=sqrt((xpos-oldx)*(xpos-oldx)+(ypos-oldy)*(ypos-oldy)+(zpos-oldz)*(zpos-oldz));
    	oldx=xpos;
    	oldy=ypos;
    	oldz=zpos;
    	lookUp.push_back(length);
	}
	return length;
}

float bezier::getMaxLength()
{
	return maxLength;
}

controlpts bezier::computeCurve(float s)
{
	// calculate x coefficients
	float xa= -1 * first.getX() +3*second.getX() - 3*third.getX() +fourth.getX();
	float xb= 3*first.getX() - 6*second.getX() +3*third.getX();
	float xc= -3*first.getX() + 3*second.getX();
	float xd= first.getX();
	
	// calculate y coefficients
	float ya= -1 * first.getY() +3*second.getY() -3*third.getY() +fourth.getY();
	float yb= 3*first.getY() - 6*second.getY() +3*third.getY();
	float yc= -3*first.getY() + 3*second.getY();
	float yd= first.getY();
	
	// calculate z coefficients
	float za= -1 * first.getZ() +3*second.getZ() -3*third.getZ() +fourth.getZ();
	float zb= 3*first.getZ() - 6*second.getZ() +3*third.getZ();
	float zc= -3*first.getZ() + 3*second.getZ();
	float zd= first.getZ();
 
    float t,ratio;
	for (unsigned int i=0; i<lookUp.size()-1; i++)
	{
		if (s>lookUp[i]&&s<lookUp[i+1])
		  {
			t=float(i)/100;	
		  	float difference=lookUp[i+1]-lookUp[i];
		  	float sstep=s-lookUp[i];
		  	ratio=sstep/difference;
		  	ratio*=.01;
		  	t+=ratio; 
		  	break;
		  }
	}

	// calculate
    float xpos=xa*t*t*t+xb*t*t+xc*t+xd;
    float ypos=ya*t*t*t+yb*t*t+yc*t+yd;
    float zpos=za*t*t*t+zb*t*t+zc*t+zd;
    t+=.005;
	float nextX=xa*t*t*t+xb*t*t+xc*t+xd;
	float nextY=ya*t*t*t+yb*t*t+yc*t+yd;
	float nextZ=za*t*t*t+zb*t*t+zc*t+zd;
	// calculate Theta
	float deltaX = nextX - xpos;
	float deltaY = nextY - ypos;
	float deltaZ = nextZ - zpos;
	float theta = atan(deltaX/deltaZ);
	// calculate Phi
	float phi = abs(asin(deltaY/sqrt(deltaX*deltaX+deltaY*deltaY+deltaZ*deltaZ)));
    return controlpts(xpos,ypos,zpos,theta,phi);
}
