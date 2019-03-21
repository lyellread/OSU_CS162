//application.cpp

#include "matrix.hpp"
#include <cstdlib>

#include <iostream>

using std::cout;
using std::endl;
using std::cerr;
using std::exception;
using std::srand;
using std::rand;


int main(){
	
	srand(time(NULL));
	
	
	// Matrix<float> float_matrix(5,6);
	// Matrix<float> float_matrix_two(5,6);
	
	// try{
		
		// for (int i = 0; i < 5; ++i){
			// for (int j = 0; j < 6; ++j){
				// float &temp = float_matrix.at(i,j);
				// temp = (rand()%66)/2.3;
				
				// float &temp_two = float_matrix_two.at(i,j);
				// temp_two = 2.3;
			// }
		// }
		
		// for (int i = 0; i < 5; ++i){
			// for (int j = 0; j < 6; ++j){
				// float &temp = float_matrix.at(i,j);
				// float &temp_two = float_matrix_two.at(i,j);
				// cout << "Temp One (" << i << ", " << j << ") == " << temp << "\t\t";
				// cout << "Temp Two (" << i << ", " << j << ") == " << temp_two << endl;
			// }
		// }
		
		// //Matrix<float> &float_matrix_two_ref = float_matrix_two;
		// float_matrix.add (float_matrix_two);
		
		// cout << "\n" << endl;
		
		// for (int i = 0; i < 5; ++i){
			// for (int j = 0; j < 6; ++j){
				// float &temp = float_matrix.at(i,j);
				// float &temp_two = float_matrix_two.at(i,j);
				// cout << "Temp One (" << i << ", " << j << ") == " << temp << "\t\t";
				// cout << "Temp Two (" << i << ", " << j << ") == " << temp_two << endl;
			// }
		// }		
		
	// }catch(exception& e){
		// cerr << e.what() << endl;
	// }catch(...){
		// cerr << "Some Exception was Thown... Unsure..." << endl;
	// }
	
	
	Matrix<int> int_matrix(3,3);
	Matrix<int> int_matrix_two(3,3);
	
	try{
		
		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 3; ++j){
				int &temp = int_matrix.at(i,j);
				temp = (rand()%66);
				
				int &temp_two = int_matrix_two.at(i,j);
				temp_two = 22;
			}
		}
		
		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 3; ++j){
				int &temp = int_matrix.at(i,j);
				int &temp_two = int_matrix_two.at(i,j);
				cout << "Temp One (" << i << ", " << j << ") == " << temp << "\t\t";
				cout << "Temp Two (" << i << ", " << j << ") == " << temp_two << endl;
			}
		}
		
		//Matrix<int> &int_matrix_two_ref = int_matrix_two;
		int_matrix.add (int_matrix_two);
		
		cout << "\n" << endl;
		
		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 3; ++j){
				int &temp = int_matrix.at(i,j);
				int &temp_two = int_matrix_two.at(i,j);
				cout << "Temp One (" << i << ", " << j << ") == " << temp << "\t\t";
				cout << "Temp Two (" << i << ", " << j << ") == " << temp_two << endl;
			}
		}		
		
	}catch(exception& e){
		cerr << e.what() << endl;
	}catch(...){
		cerr << "Some Exception was Thown... Unsure..." << endl;
	}
	
}