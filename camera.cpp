// Taylor Seale
// camera.cpp
// Computer Graphics - CSE 40166
// implementation for arcball cam

#include "camera.h"
#include <math.h>

camera::camera(float cTheta,float cPhi,float cRadius,float oX,float oY,float oZ){
	cameraTheta=cTheta;
	cameraPhi=cPhi;
	cameraRadius=cRadius;
	objX=oX;
	objY=oY;
	objZ=oZ;
	computeArcballPosition(cameraTheta,cameraPhi,cameraRadius,cameraX,cameraY,cameraZ);
}

void camera::computeArcballPosition(float theta, float phi, float radius,
                            float &x, float &y, float &z) {
    x = radius * sinf(theta)*sinf(phi);
    y = radius * -cosf(phi);
    z = radius * -cosf(theta)*sinf(phi);
}