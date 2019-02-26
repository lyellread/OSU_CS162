//rectangle.hpp

#ifndef RECTANGLE
#define RECTANGLE

#include "shape.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Rectangle : public Shape {
private:
  float width;
  float height;
public:
  
  Rectangle(string name, string color, float width, float height);
  
  void set_w_h (float w, float h);
  float get_w ();
  float get_h ();
  float area();
  void print_data ();
  
};

#endif