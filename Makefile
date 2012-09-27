CXX    = g++
CFLAGS = -Wall -g

ifeq ($(shell uname), Darwin)
    LIBS = -framework GLUT -framework OpenGL -framework Cocoa
else
    LIBS = -lglut -lGL -lGLU -lGLEW
endif

FREEGLUT = /afs/nd.edu/user37/ccl/software/external/freeglut
ifneq "$(wildcard $(FREEGLUT))" ""
    INCPATH += -I$(FREEGLUT)/include
    LIBPATH += -L$(FREEGLUT)/lib -Wl,--rpath -Wl,$(FREEGLUT)/lib
endif

GLEW = /afs/nd.edu/user37/ccl/software/external/glew
ifneq "$(wildcard $(GLEW))" ""
    INCPATH += -I$(GLEW)/include
    LIBPATH += -L$(GLEW)/lib -Wl,--rpath -Wl,$(GLEW)/lib
endif

all: midterm

clean:
	rm -f *.o midterm

depend:
	rm -f Makefile.bak
	mv Makefile Makefile.bak
	sed '/^# DEPENDENCIES/,$$d' Makefile.bak > Makefile
	echo '# DEPENDENCIES' >> Makefile
	$(CXX) -MM *.cpp >> Makefile

.c.o: 	
	$(CXX) $(CFLAGS) $(INCPATH) -c -o $@ $<

.cc.o: 	
	$(CXX) $(CFLAGS) $(INCPATH) -c -o $@ $<

.cpp.o: 	
	$(CXX) $(CFLAGS) $(INCPATH) -c -o $@ $<

midterm: main.o camera.o bezier.o controlpts.o 
	$(CXX) $(CFLAGS) $(INCPATH) -o $@ $^ $(LIBPATH) $(LIBS)
	

# DEPENDENCIES
main.o: main.cpp
camera.o: camera.cpp
bezier.o: bezier.cpp
controlpts.o: controlpts.cpp
