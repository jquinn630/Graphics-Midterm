// Taylor Seale & John Quinn
// Computer Graphics Midterm
// car.h

// header file for a single coaster car

#include "bezier.h"

class cart{
	public:
		void drawCart(bezier, float);
		float getCartX();
		float getCartY();
		float getCartZ();
		float geteyeX();
		float geteyeY();
		float geteyeZ();
		float getatX();
		float getatY();
		float getatZ();
	private:
		float cartX,cartY,cartZ;
		float cartTheta,cartPhi;
		float eyeX,eyeY,eyeZ;
		float atX,atY,atZ;
};