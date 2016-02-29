#ifndef POINT3_H
#define POINT3_H

#include <cmath>

class Point3{
	public:
		float x;
		float y;
		float z;
		Point3();
		Point3(float x, float y, float z);
		Point3 operator+(const Point3& other);
		Point3 operator-(const Point3& other);
		Point3 operator*(const Point3& other);
		Point3 operator/(const Point3& other);
		void operator=(const Point3& other);
		void Transform(Point3 centroid, float scale, Point3 rotation);
		float Distance(Point3 point);
};

#endif
