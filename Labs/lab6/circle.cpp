//circle.cpp

#include "circle.hpp"

Circle::Circle(string name, string color, float radius) : Shape(name, color), radius(radius) {}

void Circle::set_r (float r){
	
	this->radius = r;
	
}

//float get_r (){
	
	// return this->radius;
	
// }

float Circle::area(){
	
	return Shape::area(this->radius);
	
}

void Circle::print_data(){
	
	cout << "This is a circle, " << this->get_name() << " with color " << this->get_color() << " and radius: " << this->radius << endl;
	
}