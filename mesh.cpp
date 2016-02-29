#include "mesh.h"

void Mesh::Transform(Point3 centroid, float scale, Point3 rotation){
	for(int i=0; i<this->faces.size(); i++){     
        this->faces[i].Transform(centroid, scale, rotation);
    }
}
