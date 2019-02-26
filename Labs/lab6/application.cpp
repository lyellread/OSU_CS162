// application.cpp - main

#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "square.hpp"

int main(){

	Rectangle newrec("rec1", "green", 44.3, 82.33);
	Rectangle secondrec("rec2", "green", 12.12, 11.11);
	
	cout << newrec.area() << endl;
	cout << secondrec.area() << endl;
	
	newrec.print_data();
	secondrec.print_data();
	
	
	
	Circle newcirc ("cricle1", "purple", 69.69);
	Circle secondcirc ("circle2", "yellow-orange with a touch of green", 12.222);
	
	cout << newcirc.area() << endl;
	cout << secondcirc.area() << endl;
	
	newcirc.print_data();
	secondcirc.print_data();
	
	
	
	Square newsquare ("sq1", "gold", 12.01);
	Square secondsq ("sq2", "orange", 1222);
	
	cout << newsquare.area() << endl;
	cout << secondsq.area() << endl;
	
	newsquare.print_data();
	secondsq.print_data();
}