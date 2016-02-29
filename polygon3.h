#ifndef POLYGON3_H
#define POLYGON3_H

#include <vector>
#include "point3.h"

class Polygon3{
	public:
		std::vector<Point3> vertices;
		void Transform(Point3 centroid, float scale, Point3 rotation);
		Point3 GetCentroid();
};

#endif
