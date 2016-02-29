#include "polygon3.h"

void Polygon3::Transform(Point3 centroid, float scale, Point3 rotation){
	for(int i=0; i<this->vertices.size(); i++){     
        this->vertices[i].Transform(centroid, scale, rotation);
    }
}

Point3 Polygon3::GetCentroid(){
	Point3 centroid(0,0,0);
	for(int i=0; i<this->vertices.size(); i++){     
        centroid = centroid + this->vertices[i];
    }
    centroid.x /= this->vertices.size();
    centroid.y /= this->vertices.size();
    centroid.z /= this->vertices.size();
    return centroid;
}
