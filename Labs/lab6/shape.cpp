// shape.cpp - function defenitions for shape class

#include "shape.hpp"

Shape::Shape () {
	
	cout << "Shape Constructor Called" << endl;
	
}

Shape::Shape (string name, string color){
	
	cout << "Shape Constructor Called With Color " << color << " and Name " << name << endl;

	this->name = name;
	this->color = color;
	
}

Shape::~Shape () {
	
	cout << "Shape Destructor Called" << endl;
	
}

string Shape::get_name(){
	
	return this->name;
	
}

string Shape::get_color(){
	
	return this->color;
	
}

void Shape::set_name(string name){
	
	this->name = name;
	
}

void Shape::set_color(string color){
	
	this->color = color;
	
}

float Shape::area(){
	
	return 0.0;
	
}

float Shape::area(float radius){
	
	return (3.14 * radius * radius);
	
}

float Shape::area(float width, float height){
	
	return (width * height);
	
}