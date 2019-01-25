/*********************************************************************
** Program Filename:explore_econdata.cpp
** Author:Lyell Read
** Date:1/17/2018
** Description:This is one part of a program that interactively displays economic data to the user. This part contains only the main function.
** Input:User input, File input
** Output:Text based output about economic data.
*********************************************************************/

#include "econdata.hpp"

/*********************************************************************
** Function:main
** Description:call functions to allocate memory, call menu_1 and then manage the exit process.
** Parameters:int argc, char ** argv
** Pre-Conditions:prpogram executed
** Post-Conditions:program done, mem cleared
*********************************************************************/ 

int main (int argc, char ** argv) {
	
	parameter_check(argc, argv);
	
	int state_count;
	ifstream is(argv[1]);
	if (!is.good()){
		cout << "BREAKING AS FILE DOES NOT EXIST. BYE!" << endl;
		exit(EXIT_FAILURE);
	}
	
	is >> state_count;
	
	state * state_array = allocate_states(state_count);
	
	read_state_data(state_array, state_count, is);
	
	//print_all(state_array, state_count);
	
	menu_1(state_array, state_count);
	free_state_county_data(state_array, state_count);
	
	cout << "NOTE: ALL MEMORY SUCCESSFULLY FREED!" << endl;
	
	//exit(EXIT_SUCCESS);
	
}
