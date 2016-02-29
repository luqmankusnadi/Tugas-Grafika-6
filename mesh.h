#ifndef MESH_H
#define MESH_H

#include <vector>
#include "polygon3.h"
#include "point3.h"

class Mesh{
	public:
		std::vector<Polygon3> faces;
		void Transform(Point3 centroid, float scale, Point3 rotation);
};

#endif
