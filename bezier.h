#ifndef BEZIER_H
#define BEZIER_H

#include <iostream>
#include <cmath>
#include <vector>
#include "controlpts.h"

using namespace std;

class bezier{
	public:
	bezier(controlpts a, controlpts b, controlpts c, controlpts d);
	float computeMaxLength();
	controlpts computeCurve(float t);
	controlpts computeAnimation(float s);
	float getMaxLength();
	
	private:
	controlpts first;
	controlpts second;
	controlpts third;
	controlpts fourth;
	float maxLength;
	vector<float> lookUp;
	
};

#endif