//square.hpp

#ifndef SQUARE
#define SQUARE

#include "shape.hpp"
#include "rectangle.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Square : public Rectangle{
	public:
	
	Square(string name, string color, float side);
	
	float area();
	void print_data();
	
};

#endif