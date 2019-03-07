
/*********************************************************************
** Program Filename:wumpus.cpp
** Author:Lyell Read
** Date:3/4/2019
** Description:Declarations for the class wumpus
** Input:None
** Output:Text-Based
*********************************************************************/


#include <iostream>
#include "wumpus.hpp"

using std::cout;
using std::endl;


/*********************************************************************
** Function:Wumpus
** Description:wumpus constructor
** Parameters:
** Pre-Conditions:
** Post-Conditions:wumpus created
*********************************************************************/ 

Wumpus::Wumpus() : Event(4) {this->type = 4;}

/*********************************************************************
** Function:percept
** Description:give percept for wumpus
** Parameters:
** Pre-Conditions:
** Post-Conditions:percept give 
*********************************************************************/ 

void Wumpus::percept() {
	
	cout << "You smell the foulest of stenches..." << endl;
	
}

/*********************************************************************
** Function:encounter
** Description:gives percept
** Parameters:player * player
** Pre-Conditions:
** Post-Conditions:encounter is given
*********************************************************************/ 

void Wumpus::encounter(Player * player){
	
	player->is_dead = 1;
	cout << "The Wumpus wakes up and eats you hole. You die." << endl;
	
}

/*********************************************************************
** Function:get_type
** Description:returns type
** Parameters:int start_row, int start_col, int size
** Pre-Conditions:
** Post-Conditions:type is returned
*********************************************************************/ 

int Wumpus::get_type(){
	
	return this->type;
	
}

/*********************************************************************
** Function:get_debug_type
** Description:returns the character to be used in debugging
** Parameters:
** Pre-Conditions:
** Post-Conditions:char returned
*********************************************************************/ 

char Wumpus::get_debug_type(){
	
	return 'W';
	
}