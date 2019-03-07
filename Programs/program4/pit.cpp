
/*********************************************************************
** Program Filename:pit.cpp
** Author:Lyell Read
** Date:3/4/2019
** Description:Declarations for the class pit
** Input:None
** Output:Text-Based
*********************************************************************/


#include <iostream>
#include "pit.hpp"

using std::cout;
using std::endl;

/*********************************************************************
** Function:pit
** Description:pit constructor
** Parameters:
** Pre-Conditions:
** Post-Conditions:pit created
*********************************************************************/ 

Pit::Pit() : Event(2) {this->type = 2;}

/*********************************************************************
** Function:percept
** Description:give percept for pit
** Parameters:
** Pre-Conditions:
** Post-Conditions:percept give 
*********************************************************************/ 

void Pit::percept() {
	
	cout << "You feel a light breeze." << endl;
	
}

/*********************************************************************
** Function:encounter
** Description:gives percept
** Parameters:player * player
** Pre-Conditions:
** Post-Conditions:encounter is given
*********************************************************************/ 

void Pit::encounter(Player * player){
	
	player->is_dead = 1;
	cout << "You fell in a pit. You die." << endl;
	
}


/*********************************************************************
** Function:get_type
** Description:returns type
** Parameters:int start_row, int start_col, int size
** Pre-Conditions:
** Post-Conditions:type is returned
*********************************************************************/ 

int Pit::get_type(){
	
	return this->type;
	
}

/*********************************************************************
** Function:get_debug_type
** Description:returns the character to be used in debugging
** Parameters:
** Pre-Conditions:
** Post-Conditions:char returned
*********************************************************************/ 

char Pit::get_debug_type(){
	
	return 'P';
	
}