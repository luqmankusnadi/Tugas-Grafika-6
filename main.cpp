#include <iostream>
#include <vector>
#include "input.h"
#include "framebuffer.h"
#include "camera.h"
#include "polygon3.h"
#include "point3.h"
#include "polygon2.h"
#include "point2.h"
#include "mesh.h"
#include "matrix.h"

int main(){
	Framebuffer framebuffer;

	Camera camera;
	camera.viewer.z = 400;
	camera.center.x = 1024/2;
	camera.center.y = 768/2;
	camera.position = Point3(0,0,-100);

	Mesh cube;

	Polygon3 face1;
	face1.vertices.push_back(Point3(-20,-20,-20));
	face1.vertices.push_back(Point3(20,-20,-20));
	face1.vertices.push_back(Point3(20,20,-20));
	face1.vertices.push_back(Point3(-20,20,-20));
	cube.faces.push_back(face1);
	
	Polygon3 face2;
	face2.vertices.push_back(Point3(-20,-20,20));
	face2.vertices.push_back(Point3(20,-20,20));
	face2.vertices.push_back(Point3(20,20,20));
	face2.vertices.push_back(Point3(-20,20,20));
	cube.faces.push_back(face2);
	
	Polygon3 face3;
	face3.vertices.push_back(Point3(20,-20,-20));
	face3.vertices.push_back(Point3(20,20,-20));
	face3.vertices.push_back(Point3(20,20,20));
	face3.vertices.push_back(Point3(20,-20,20));
	cube.faces.push_back(face3);
	
	Polygon3 face4;
	face4.vertices.push_back(Point3(-20,-20,-20));
	face4.vertices.push_back(Point3(-20,20,-20));
	face4.vertices.push_back(Point3(-20,20,20));
	face4.vertices.push_back(Point3(-20,-20,20));
	cube.faces.push_back(face4);
	
	Polygon3 face5;
	face5.vertices.push_back(Point3(-20,20,-20));
	face5.vertices.push_back(Point3(20,20,-20));
	face5.vertices.push_back(Point3(20,20,20));
	face5.vertices.push_back(Point3(-20,20,20));
	cube.faces.push_back(face5);
	
	Polygon3 face6;
	face6.vertices.push_back(Point3(-20,-20,-20));
	face6.vertices.push_back(Point3(20,-20,-20));
	face6.vertices.push_back(Point3(20,-20,20));
	face6.vertices.push_back(Point3(-20,-20,20));
	cube.faces.push_back(face6);
	
	set_conio_terminal_mode();
	
	initMatrix();
	vector<Polygon2> polygons;
	while(1){
		framebuffer.ClearScreen();
		//poly2.Transform(Point2(200,200), 1, 10);
		//camera.position.z -= 1;
		
		polygons = camera.Project(cube);
		initMatrix();
		for(int i = 0; i < polygons.size(); i ++){
			polygons[i].ProduceLines();
			framebuffer.FillPolygon(polygons[i], (Color32){255,100,100,255}, freeMatrix);
			framebuffer.DrawPolygon(polygons[i], (Color32){255,255,255,255});
			
		}
		framebuffer.SwapBuffers();
		
		
		char c = getch();
		if(c == 'w'){ 
			cube.Transform(Point3(0,0,0), 1, Point3(-2,0,0));
		} 
		else if(c == 's'){ 
			cube.Transform(Point3(0,0,0), 1, Point3(2,0,0));
		}
		else if(c == 'a'){ 
			cube.Transform(Point3(0,0,0), 1, Point3(0,2,0));
		}
		else if(c == 'd'){ 
			cube.Transform(Point3(0,0,0), 1, Point3(0,-2,0));
		}
		else if(c == 'x'){
			break;
		}
	}
	
	//delete &framebuffer;
	
	return 0;
}
