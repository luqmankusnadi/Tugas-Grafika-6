#include "polygon2.h"

void Polygon2::Transform(Point2 centroid, float scale, float rotation){
	for(int i=0; i<this->vertices.size(); i++){     
        this->vertices[i].Transform(centroid, scale, rotation);
    }
}

void Polygon2::ProduceLines() {
	this->vertices = vertices;
	ymin = 2000;
	ymax = -1;
	int xmax = -1;
	int xmin = 2000;
	for (int i = 0; i < vertices.size(); i++) {
		if ((int)vertices[i].y > (int)vertices[(i+1)%vertices.size()].y) {
		  Line line;
		  line.phigh.y = (int)vertices[i].y;
		  line.phigh.x = (int)vertices[i].x;
		  line.plow.y = (int)vertices[(i+1)%vertices.size()].y;
		  line.plow.x = (int)vertices[(i+1)%vertices.size()].x;
		  lines.push_back(line);
		}
		else if ((int)vertices[i].y < (int)vertices[(i+1)%vertices.size()].y) {
		  Line line;
		  line.plow.y = (int)vertices[i].y;
		  line.plow.x = (int)vertices[i].x;
		  line.phigh.y = (int)vertices[(i+1)%vertices.size()].y;
		  line.phigh.x = (int)vertices[(i+1)%vertices.size()].x;
		  lines.push_back(line);
		}
		if ((int)vertices[i].y > ymax) 
		  ymax = (int)vertices[i].y;
		if ((int)vertices[i].y < ymin)
		  ymin = (int)vertices[i].y;
		if ((int)vertices[i].x > xmax) 
		  xmax = (int)vertices[i].x;
		if ((int)vertices[i].x < xmin)
		  xmin = (int)vertices[i].x;
		//printf("titik ke-%d : (%d, %d)\n", i, vertices[i].x, vertices[i].y);
	}
	this->ymin = ymin;
	this->ymax = ymax;
}
