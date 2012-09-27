Name: John Quinn
NetID: jquinn11
Homework 4: Bezier Curve
	"Bezier Curve"
	
High Level Description:
This program draws a bezier curve based on a list of points that are input.  The points in the list are drawn as white spheres around a grid of lines that serves as a reference point.  These points are then connected by yellow lines to form a control cage.  The appropriate bezier curve is drawn, four control points at a time.  A red sphere is then animated along the curve, going back to the beginning when it reaches the end.  A camera, implemented as a class, allows the user to change perspective.

Usage:
Left clicking and moving allows the user to rotate the camera around the scene.  Right clicking and moving allows the user to zoom in and out.  Middle clicking gives the user a popup menu that allows them to quit.  The escape key can also be used to quit the program.

Compiling:
Use the included makefile.  Type make to compile and make clean to remove.  The executable produced is called hw4

Known Bugs:
There are currently no known bugs.

QUESTIONS:
1. For an object oriented structure, it might be nice to have a class for each primitive.  A point class would bundle an x,y, and z together and ensure that they do not get separated.  Likewise, the other primitive classes would do the same.  It would be very nice to create classes for primitives that aren't already supported.  If you were going to draw a lot of circles, it would be great to have a circle class that could could be instantiated many times.  

2. To start off, it is probably necessary to have basic get/set functions for the x,y, and z coordinates.  A translate function that would translate all coordinates based on given values would probably very useful too.  You could have a pointer to a primitive that the point belongs to that is set to NULL if the point doesn't belong to anything.  You could do this if all primitive classes were derived from a base primitive class.  You could also implement reflect functions that reflect the point over the x,y, and z axes.