//matrix.hpp -- header


#ifndef __MATRIX_HPP
#define __MATRIX_CPP

#include <iostream>
#include "exceptions.hpp"

using std::cout;
using std::endl;

template <class T>
class Matrix {
	private:
		int _rows;
		int _cols;
		T** data;
	public:
		Matrix(int rows, int cols);
		~Matrix();
		int rows(){return this->_rows;};
		int cols(){return this->_cols;};
		T& at(int row, int col);
		void add(Matrix<T>& to_add);
};

template <class T>
Matrix<T>::Matrix(int rows, int cols){
	
	this->data = new T * [rows];
	for (int i=0; i<rows; ++i){
		this->data[i] = new T [cols];
	}
	
	this->_rows = rows;
	this->_cols = cols;
	
	cout << "== Completed Generation" << endl;
}

template <class T>
Matrix<T>::~Matrix(){
	
	for (int i=0; i<this->_rows; ++i){
		delete[] this->data[i];
	}
	delete[] this->data;
	
	cout << "== Completed Destruction" << endl;
}

template <class T>
T& Matrix<T>::at(int row, int col){
	
	if (row > this->_rows-1){cout << "==== ERROR THROWN: OUT OF RANGE: ROWS" << endl; throw OutOfRangeException();}
	if (col > this->_cols-1){cout << "==== ERROR THROWN: OUT OF RANGE: COLS" << endl; throw OutOfRangeException();}
	
	return this->data[row][col];
	
}

template <class T>
void Matrix<T>::add(Matrix<T>& to_add){
	
	if (to_add.rows() != this->_rows || to_add.cols() != this->_cols){cout << "==== ERROR THROWN: SIZE EXCEPTION" << endl; throw SizeMismatchException();}
	
	for (int i = 0; i < this->_rows; ++i){
		for (int j = 0; j < this->_cols; ++j){
			T temp = to_add.at(i,j);
			this->data[i][j] += temp;
		}
	}
}









#endif