//rectangle.cpp

#include "rectangle.hpp"

Rectangle::Rectangle(string name, string color, float width, float height) : Shape(name, color), width(width), height(height) {}

void Rectangle::set_w_h (float w, float h){
	
	this->width = w;
	this->height = h;
	
}

float Rectangle::get_w(){
	
	return this->width;
	
}

float Rectangle::get_h(){
	
	return this->height;
	
}

float Rectangle::area(){
	
	return Shape::area(this->width, this->height);
	
}

void Rectangle::print_data(){
	
	cout << "This is a rectangle, " << this->get_name() << " with color " << this->get_color() << " and dimensions: " << this->width << " X " << this->height << endl;
	
}