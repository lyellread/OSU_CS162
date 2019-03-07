
/*********************************************************************
** Program Filename:bat.cpp
** Author:Lyell Read
** Date:3/4/2019
** Description:Declarations for the class bat
** Input:None
** Output:Text-Based
*********************************************************************/

#include <iostream>
#include "bat.hpp"

using std::cout;
using std::endl;


/*********************************************************************
** Function:Bat
** Description:bat constructor
** Parameters:
** Pre-Conditions:
** Post-Conditions:bat created
*********************************************************************/ 

Bat::Bat() : Event(3) {this->type = 3;}

/*********************************************************************
** Function:percept
** Description:give percept for bat
** Parameters:
** Pre-Conditions:
** Post-Conditions:percept give 
*********************************************************************/ 

void Bat::percept() {
	
	cout << "You hear the flutter of wings." << endl;
	
}

/*********************************************************************
** Function:encounter
** Description:gives percept
** Parameters:player * player
** Pre-Conditions:
** Post-Conditions:encounter is given
*********************************************************************/ 

void Bat::encounter(Player * player){
	
	player->is_dead = 1;
	cout << "You get eaten alive by a pack of bats in the room you just entered. You die." << endl;
	
}


/*********************************************************************
** Function:get_type
** Description:returns type
** Parameters:int start_row, int start_col, int size
** Pre-Conditions:
** Post-Conditions:type is returned
*********************************************************************/ 

int Bat::get_type(){
	
	return this->type;
	
}

/*********************************************************************
** Function:get_debug_type
** Description:returns the character to be used in debugging
** Parameters:
** Pre-Conditions:
** Post-Conditions:char returned
*********************************************************************/ 

char Bat::get_debug_type(){
	
	return 'B';
	
}