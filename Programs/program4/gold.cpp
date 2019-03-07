
/*********************************************************************
** Program Filename:gold.cpp
** Author:Lyell Read
** Date:3/4/2019
** Description:Declarations for the class gold
** Input:None
** Output:Text-Based
*********************************************************************/


#include <iostream>
#include "gold.hpp"

using std::cout;
using std::endl;


/*********************************************************************
** Function:gold
** Description:gold constructor
** Parameters:
** Pre-Conditions:
** Post-Conditions:gold created
*********************************************************************/ 

Gold::Gold() : Event(1) {this->type = 1;}

/*********************************************************************
** Function:percept
** Description:give percept for gold
** Parameters:
** Pre-Conditions:
** Post-Conditions:percept give 
*********************************************************************/ 

void Gold::percept() {
	
	cout << "You see a glimmer out of the corner of your eye." << endl;
	
}

/*********************************************************************
** Function:encounter
** Description:gives percept
** Parameters:player * player
** Pre-Conditions:
** Post-Conditions:encounter is given
*********************************************************************/ 

void Gold::encounter(Player * player){
	
	player->has_gold = 1;
	cout << "You collected the gold." << endl;
	
}


/*********************************************************************
** Function:get_type
** Description:returns type
** Parameters:int start_row, int start_col, int size
** Pre-Conditions:
** Post-Conditions:type is returned
*********************************************************************/ 

int Gold::get_type(){
	
	return this->type;
	
}

/*********************************************************************
** Function:get_debug_type
** Description:returns the character to be used in debugging
** Parameters:
** Pre-Conditions:
** Post-Conditions:char returned
*********************************************************************/ 

char Gold::get_debug_type(){
	
	return 'G';
	
}