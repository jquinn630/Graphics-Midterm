// Taylor Seale & John Quinn
// Computer Graphics Midterm
// car.h

// header file for a single coaster car

#include "bezier.h"

class cart{
	public:
		void drawCart(bezier,float);
		float getCartX();
		float getCartY();
		float getCartZ();
		float geteyeX();
		float geteyeY();
		float geteyeZ();
		float getatX();
		float getatY();
		float getatZ();
		float getStep();
		void setStep(float);
		void incStep();
		int getCount();
		void setCount(int);
		void incCount();
	private:
		float cartX,cartY,cartZ;
		float cartTheta,cartPhi;
		float cartStep;
		int cartPcount;
};