#ifndef POLYGON2_H
#define POLYGON2_H

#include <vector>
#include "point2.h"
#include "line.h"

class Polygon2{
	public:
		std::vector<Point2> vertices;
		std::vector<Line> lines;
		int ymin;
		int ymax;
		void Transform(Point2 centroid, float scale, float rotation);
		void ProduceLines();
};

#endif
