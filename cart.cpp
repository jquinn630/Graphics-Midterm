// Taylor Seale & John Quinn
// Computer Graphics Midterm
// cart.cpp

// implementation file for a single coaster car

#include "cart.h"

cart::cart(){}

void cart::drawCart(float x, float y, float z, float theta, float phi){
	cartX=x;
	cartY=y;
	cartZ=z;
	cartTheta=theta;
	cartPhi=phi;
}