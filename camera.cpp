#include "camera.h"

Camera::Camera(){
	this->position = Point3();
	this->rotation = Point3();
	this->viewer = Point3(0,0,1);
	this->center = Point2(0,0);
}
Camera::Camera(Point3 position, Point3 rotation, Point3 viewer){
	this->position = position;
	this->rotation = rotation;
	this->viewer = viewer;
	this->center = Point2(0,0);
}

Point2 Camera::Project(Point3& point){
	float PI = 3.14159265f/180.0f;
	Point3 rad;
	rad.x = this->rotation.x * PI;
	rad.y = this->rotation.y * PI;
	rad.z = this->rotation.z * PI;
	Point3 t;
	t = point - this->position;
	Point3 r;
	r.x = cos(rad.y)*(sin(rad.z)*t.y + cos(rad.z)*t.x) - sin(rad.y)*t.z;
	r.y = sin(rad.x)*(cos(rad.y)*t.z + sin(rad.y)*(sin(rad.z)*t.y + cos(rad.z)*t.x)) + cos(rad.x) * (cos(rad.z)*t.y - sin(rad.z)*t.x);
	r.z = cos(rad.x)*(cos(rad.y)*t.z + sin(rad.y)*(sin(rad.z)*t.y + cos(rad.z)*t.x)) - sin(rad.x) * (cos(rad.z)*t.y - sin(rad.z)*t.x);
	
	Point2 result;
	result.x = this->viewer.z * r.x / r.z - this->viewer.x + this->center.x;   
	result.y = this->viewer.z * r.y / r.z - this->viewer.y + this->center.y;  
	
	//std::cout << "r "<< t.x << "," << t.y << "," << t.z << "\n";
	//std::cout << "point "<< result.x << "," << result.y << "\n";
	return result;
}
Polygon2 Camera::Project(Polygon3& polygon){
	Polygon2 result;
	for(int i=0; i<polygon.vertices.size(); i++){     
        result.vertices.push_back(Project(polygon.vertices[i]));
       //std::cout << result.vertices[i].x << "," << result.vertices[i].y << "\n";
    }
    return result;
}


std::vector<Polygon2> Camera::Project(Mesh& mesh){
	std::map<float, Polygon2> polygons;
	std::vector<Polygon2> results;
		
	for(int i=0; i<mesh.faces.size(); i++){
		polygons[this->position.Distance(mesh.faces[i].GetCentroid())] = Project(mesh.faces[i]);
    }
	for (std::map<float, Polygon2>::reverse_iterator it=polygons.rbegin(); it!=polygons.rend(); ++it){
		results.push_back(it->second);
	}
	return results;
}
