// Taylor Seale & John Quinn
// Computer Graphics Midterm
// coaster.h

// header file for a coaster object which connects a bunch of cart objects using composition

#include "bezier.h"
#include "cart.h"
#include "material.h"

class coaster{
	public:
		void drawCoaster(vector<bezier> &);
		cart firstCart;
		cart secondCart;
		cart thirdCart;
		cart fourthCart;
		float eyex,eyey,eyez;
		float atx,aty,atz;
		float eyeStep,atStep;
		float eyeCount,atCount;
};