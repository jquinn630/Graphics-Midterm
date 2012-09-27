// controlpts.cpp
// implementation of the controlpts class
// Written by John Quinn

#include "controlpts.h"

controlpts::controlpts(double a, double b, double c)
{
	x=a;
	y=b;
	z=c;
}

double controlpts::getX()
{
	return x;
}
 
double controlpts::getY()
{
	return y;
}

double controlpts::getZ()
{
	return z;
}

controlpts operator *( controlpts& y, float x)
{
	return controlpts(y.getX()*x, y.getY()*x, y.getZ()*x);
}  // multiplies point by scalar

controlpts operator *(float x, controlpts& y)
{
	return controlpts(y.getX()*x, y.getY()*x, y.getZ()*x);
}  // multiplies point by scalar

controlpts operator -(controlpts &x, controlpts &y)
{
	return controlpts(x.getX()-y.getX(), x.getY()-y.getY(), x.getZ()-y.getZ());
} // returns vector between two points

