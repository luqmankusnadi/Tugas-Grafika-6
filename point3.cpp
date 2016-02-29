#include "point3.h"

Point3::Point3(){
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Point3::Point3(float x, float y,  float z){
	this->x = x;
	this->y = y;
	this->z = z;
}

Point3 Point3::operator+(const Point3& other){
	Point3 result(this->x + other.x, this->y + other.y, this->z + other.z);
	return result;
}
Point3 Point3::operator-(const Point3& other){
	Point3 result(this->x - other.x, this->y - other.y, this->z - other.z);
	return result;
}
Point3 Point3::operator*(const Point3& other){
	Point3 result(this->x * other.x, this->y * other.y, this->z * other.z);
	return result;
}
Point3 Point3::operator/(const Point3& other){
	Point3 result(this->x / other.x, this->y / other.y, this->z / other.z);
	return result;
}
void Point3::operator=(const Point3& other){
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

void Point3::Transform(Point3 centroid, float scale, Point3 rotation){
	float xnew;
	float ynew;
	float znew;
    float PI = 3.14159265;
	Point3 rad;
	rad.x = rotation.x * PI / 180.0f;
	rad.y = rotation.y * PI / 180.0f;
	rad.z = rotation.z * PI / 180.0f;
	
	this->x -= centroid.x;
	this->y -= centroid.y;
	this->z -= centroid.z;
	//scale
	if(scale != 1){
		this->x *= scale;
		this->y *= scale;
		this->z *= scale;
	}
	//rotate
	if(rotation.x != 0){
		ynew = (this->y * cos(rad.x)) - (this->z * sin(rad.x));
		znew = (this->y * sin(rad.x)) + (this->z * cos(rad.x));
		this->y = ynew;
		this->z = znew;
	}
	if(rotation.y != 0){
		xnew = (this->x * cos(rad.y)) + (this->z * sin(rad.y));
		znew = -(this->x * sin(rad.y)) + (this->z * cos(rad.y));
		this->x = xnew;
		this->z = znew;
	}
	if(rotation.z != 0){
		xnew = (this->x * cos(rad.z)) - (this->y * sin(rad.z));
		ynew = (this->x * sin(rad.z)) + (this->y * cos(rad.z));
		this->x = xnew;
		this->y = ynew;
	}
	
	this->x += centroid.x;
	this->y += centroid.y;
	this->z += centroid.z;
}

float Point3::Distance(Point3 point){
	Point3 diff = (*this) - point;
	return (float)sqrt((double)(diff.x*diff.x + diff.y*diff.y + diff.z*diff.z));
}


