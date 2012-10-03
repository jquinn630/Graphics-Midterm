// Taylor Seale & John Quinn
// Computer Graphics Midterm
// car.h

// header file for a single coaster car

#include "bezier.h"

class cart{
	public:
		void drawCart(bezier, float);
	private:
		float cartX,cartY,cartZ;
		float cartTheta,cartPhi;
};