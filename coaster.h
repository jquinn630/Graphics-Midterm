// Taylor Seale & John Quinn
// Computer Graphics Midterm
// coaster.h

// header file for a coaster object which connects a bunch of cart objects using composition

#include "bezier.h"
#include "cart.h"

class coaster{
	public:
		void drawCoaster(bezier,float);
		cart firstCart;
};