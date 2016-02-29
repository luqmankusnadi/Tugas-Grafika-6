all:
	g++ -o exec main.cpp framebuffer.cpp point2.cpp point3.cpp polygon2.cpp polygon3.cpp mesh.cpp camera.cpp matrix.cpp input.c -lm -std=c++11 
    
run:
	sudo ./exec
