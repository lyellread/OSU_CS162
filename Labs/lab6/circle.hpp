//circle.hpp

#ifndef CIRCLE
#define CIRCLE

#include "shape.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Circle : public Shape {
private:
  float radius;
public:
  
  Circle(string name, string color, float radius);
  
  void set_r (float r);
  float get_r ();
  void print_data ();
  float area();
  
};

#endif