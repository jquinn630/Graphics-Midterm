// Taylor Seale & John Quinn
// Computer Graphics Midterm
// coaster.h

// header file for a coaster object which connects a bunch of cart objects using composition

#include "bezier.h"
#include "cart.h"

class coaster{
	public:
		void drawCoaster(vector<bezier> &);
		cart firstCart;
		cart secondCart;
		cart thirdCart;
		void computeEye();
		void computeAt();
		float eyex,eyey,eyez;
		float atx,aty,atz;
		float eyeStep,atStep;
		float eyeCount,atCount;
};