#include "bezier.h"
#include "controlpts.h"

bezier::bezier(controlpts w, controlpts x, controlpts y, controlpts z)
{
	first=controlpts(w);
	second=controlpts(x);
	third=controlpts(y);
	fourth=controlpts(z);
}

controlpts bezier::computeCurve(float t)
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
	
	// calculate
    float xpos=xa*t*t*t+xb*t*t+xc*t+xd;
    float ypos=ya*t*t*t+yb*t*t+yc*t+yd;
    float zpos=za*t*t*t+zb*t*t+zc*t+zd;
    
    return controlpts(xpos,ypos,zpos);

}