// Taylor Seale
// camera.h
// Computer Graphics - CSE 40166
// header file for a class implementation of an arcball cam

class camera{
	public:
		camera(float,float,float,float,float,float); // non-default camera constructor
		void computeArcballPosition(float,float,float,float &,float &,float &); // recompute the orientation of the camera
		float cameraTheta, cameraPhi, cameraRadius;
		float cameraX, cameraY, cameraZ;            // camera position in cartesian coordinates
		float objX,objY,objZ;
};