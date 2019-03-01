//exceptions -- header

#include <exception>


class OutOfRangeException : public std::exception {
public:
  virtual const char* what() const throw() {
    return "=err=> Access to out of bounds location not permitted; Exception Thrown.";
  }
};

class SizeMismatchException : public std::exception {
public:
  virtual const char* what() const throw() {
    return "=err=> Tryna add two matricies of different sizes; Exception Thrown.";
  }
};