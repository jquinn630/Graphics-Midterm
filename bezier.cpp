#include "bezier.h"

bezier::bezier(controlpts a, controlpts b, controlpts c, controlpts d)
{
	first=a;
	second=b;
	third=c;
    fourth=d;
}

controlpts bezier::computeCurve(float t)
{
	// calculate x coefficients
	float xa= -1 * p0.getX() +3*p1.getX() - 3*p2.getX() +p3.getX();
	float xb= 3*p0.getX() - 6*p1.getX() +3*p2.getX();
	float xc= -3*p0.getX() + 3*p1.getX();
	float xd= p0.getX();
	
	// calculate y coefficients
	float ya= -1 * p0.getY() +3*p1.getY() -3*p2.getY() +p3.getY();
	float yb= 3*p0.getY() - 6*p1.getY() +3*p2.getY();
	float yc= -3*p0.getY() + 3*p1.getY();
	float yd= p0.getY();
	
	// calculate z coefficients
	float za= -1 * p0.getZ() +3*p1.getZ() -3*p2.getZ() +p3.getZ();
	float zb= 3*p0.getZ() - 6*p1.getZ() +3*p2.getZ();
	float zc= -3*p0.getZ() + 3*p1.getZ();
	float zd= p0.getZ();
	
	// calculate
    float xpos=xa*t*t*t+xb*t*t+xc*t+xd;
    float ypos=ya*t*t*t+yb*t*t+yc*t+yd;
    float zpos=za*t*t*t+zb*t*t+zc*t+zd;
    
    return controlPts(xpos,ypos,zpos);

}