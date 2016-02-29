#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include "mesh.h"
#include "point3.h"
#include "point2.h"
#include "polygon2.h"
#include "polygon3.h"

class Camera{
	public:
		Point3 position;
		Point3 rotation;
		Point3 viewer;
		Point2 center;
		Camera();
		Camera(Point3 position, Point3 rotation, Point3 viewer);
		Point2 Project(Point3& point);
		Polygon2 Project(Polygon3& polygon);
		std::vector<Polygon2> Project(Mesh& mesh);
};

#endif
