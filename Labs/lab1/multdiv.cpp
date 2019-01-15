//MULTDIV -- LYELL READ

#include "multdiv.hpp"

using namespace std;


float float_round (float num){
	//inspired by and similar to the post here: https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/
	//because the code is so short, it is quite similar. 
	
	float out = (int)(num*100 +.5);
	return (float)out/100;
}


int s_to_i (string input){
	int output=0;
	for (int str_index=0; str_index < input.length(); str_index++){

		int multiplier = input.length()-(str_index+1);
		int working_digit = int(input[str_index])-48;

		for (int iterator=0; iterator < multiplier; iterator++){
			working_digit*=10;
		}//this works by usign ones, tens, hundreds...

		output+=working_digit;
	}
	return output;
}

int string_Is_Int (string input){
	for (int i=0; i<input.length(); ++i){
		if (input[i]>57 || input[i]<48) return 0;
	}
	return 1;
}

int parameter_Check(string parameter, int low, int high){
	if (string_Is_Int(parameter)){
		int int_Parameter = s_to_i (parameter);
    if (int_Parameter >= low && int_Parameter <= high){
      return int_Parameter;
    }
	}
	cout << "BREAKING GRACEFULLY ~ INPUT PROVIDED IS NOT A VALID NUMBER" << endl;
	exit(EXIT_FAILURE);
}



struct multdiv_entry ** generate_tables(int n){

	multdiv_entry ** grid = new multdiv_entry*[n];
	for (int i=0; i<n; i++){
		grid [i] = new multdiv_entry[n];
	}
	
	return grid;
}

void free_memory (struct multdiv_entry** grid, int n){
	
	for (int i=0; i<n; i++){
		delete[] grid[i];
	}
	delete[] grid;
}

void print_tables (struct multdiv_entry** grid, int n){ //switch + check for struct use correct
	
	cout << "Multiplication Table: \n\n\n";
	
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
		
			cout << grid[i][j].mul << "\t";
		
		}
	cout << "\n";
	}
	
	cout << "\n\n\nDivision Table: \n\n\n";

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
		
			cout << grid[i][j].div << "\t";
		
		}
	cout << "\n";
	}
	
}

void populate (struct multdiv_entry** grid, int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
		
			grid [i][j].mul= (i+1)*(j+1);
			grid [i][j].div= float_round((float(i)+1)/(float(j)+1));

		}
	}
}
