/*****************************************************************************************
.______        ______    __       __       _______ .______                       
|   _  \      /  __  \  |  |     |  |     |   ____||   _  \                      
|  |_)  |    |  |  |  | |  |     |  |     |  |__   |  |_)  |                     
|      /     |  |  |  | |  |     |  |     |   __|  |      /                      
|  |\  \----.|  `--'  | |  `----.|  `----.|  |____ |  |\  \----.                 
| _| `._____| \______/  |_______||_______||_______|| _| `._____|                 
                                                                                 
  ______   ______        ___           _______.___________. _______ .______      
 /      | /  __  \      /   \         /       |           ||   ____||   _  \     
|  ,----'|  |  |  |    /  ^  \       |   (----`---|  |----`|  |__   |  |_)  |    
|  |     |  |  |  |   /  /_\  \       \   \       |  |     |   __|  |      /     
|  `----.|  `--'  |  /  _____  \  .----)   |      |  |     |  |____ |  |\  \----.
 \______| \______/  /__/     \__\ |_______/       |__|     |_______|| _| `._____|
                                                                                 
 Midterm Project
 October 8, 2012                                                                                 
 WRITTEN BY: John Quinn (jquinn11) & Taylor Seale (tseale)
 FOR: Computer Graphics - CSE 40166
 AT: University of Notre Dame, Fall 2012
 
 Animates a group of roller coaster carts continuously around a track. Use the concepts
  of: bezier curves, 3D drawing, cameras & menus, OpenAL, materials & lighting, 
  text & file I/O.
*****************************************************************************************/

MAKE AND RUN:
	-At the command line executing "make" will compile the code
	-To run the code, you must pass in an appropriately formatted .csv file as such
		./midterm <filename>
	-Appropriate formatting of the .csv file...	
		<number of control points>
		<control point x> <control point y> <control point z>
		...
		<number of trees>
		<tree x> <tree y> <tree z>
		...
		<number of octahedrons>
		<oct x> <oct y> <oct z>
		...
	-Enjoy!
	
USAGE:
	MENUS:
		-Right-Click to access menus
			-Arcball Camera
			-Free Camera
	CONTROLS:
		-Arcball Camera
			-Left-Click & Drag
				-Rotate the camera around the coaster
			-[SHIFT]+Left-Click & Drag
				-Zoom the camera in/out
		-Free Camera
			-'W'
				-Move forwards
			-'S'
				-Move backwards
			-Left-Click & Drag
				-Change heading

KNOWN BUGS:
	-Issue with phi value interpretations
	-Odd flicker in first person viewport when changing splines
		
CONTRIBUTIONS:
	-To see each individuals contributions visit...
		https://github.com/jquinn630/Graphics-Midterm/commits/master/
		
		
		
		
		
		
		