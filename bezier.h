#ifndef BEZIER_H
#define BEZIER_H

#include <iostream>
#include <cmath>
#include "controlpts.h"

class bezier{
	public:
	bezier(controlpts a, controlpts b, controlpts c, controlpts d);
	controlpts computeCurve(float t);
	
	private:
	controlpts first;
	controlpts second;
	controlpts third;
	controlpts fourth;
	
};

#endif