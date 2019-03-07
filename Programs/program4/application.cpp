
/*********************************************************************
** Program Filename:application.cpp
** Author:Lyell Read
** Date:3/4/2019
** Description:application code (main)
** Input:None
** Output:Text-Based
*********************************************************************/


#include <iostream>
#include <string>

#include "game.hpp"

using std::cout;
using std::endl;
using std::string;


/*********************************************************************
** Function:string_Is_Int
** Description:checks a string is integer
** Parameters: string input
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int string_is_int (string input){
	for (int i=0; i<input.length(); ++i){
		if (input[i]>57 || input[i]<48) return 0;
	}
	return 1;
}


/*********************************************************************
** Function:parameter_Check
** Description: checks the parameters are cool
** Parameters:string parameter
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int parameter_check(string parameter, int low, int high){
	if (string_is_int(parameter)){
		int int_Parameter = stoi (parameter);
		if (int_Parameter >= low && int_Parameter <= high){
			return int_Parameter;
		}
	}
	cout << "==ERROR: Out of Range or Not String." << endl;
	exit(EXIT_FAILURE);
}


/*********************************************************************
** Function:main
** Description:main
** Parameters:int argc, char * argv
** Pre-Conditions:
** Post-Conditions:game done
*********************************************************************/ 


int main (int argc, char ** argv) {
	
	cout << "==Application Started" << endl;
	
	if (argc != 2) {cout << "==ERROR: Too Many or Too Few Arguments" << endl; exit(EXIT_FAILURE);}
	int map_rows = parameter_check(argv[1], 4, 40); //arbitrary max 40 set. 

	string input;
	int play_again = 1;
	
	while (play_again){
		
		Game newgame(0,0,map_rows);
		newgame.play_game();
	
		cout << "\n\n\nPlay Again (1|0):";
		cin >> input;
		play_again = parameter_check(input, 0, 1);
		if (play_again == 0){return 1;}
		cout << "\nHow many rows? (4..40):";
		cin >> input;
		map_rows = parameter_check(input, 4, 40);
	}
	
}