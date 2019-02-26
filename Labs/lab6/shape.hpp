// Shape.hpp - Header for shape class

#ifndef SHAPE
#define SHAPE

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Shape {
private:
  string name;
  string color;
public:
  Shape();
  Shape(string name, string color);
  ~Shape();
  
  string get_name();
  string get_color();
  
  void set_name (string name);
  void set_color (string color);
  
  float area();
  float area(float radius);
  float area(float width, float height);
};

#endif