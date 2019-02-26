//square.cpp

#include "square.hpp"

Square::Square(string name, string color, float side) : Rectangle(name, color, side, side) {}

void Square::print_data(){
	
	Rectangle::print_data();
	
}

float Square::area(){
	
	return Rectangle::area();
	
}
