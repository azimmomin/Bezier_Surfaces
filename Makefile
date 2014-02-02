all: 
	g++ -g -O2 *.cpp -o bezier -lglut -lGLU

clean: 
	rm -rf *o bezier
