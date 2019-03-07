
/*********************************************************************
** Program Filename:room.cpp
** Author:Lyell Read
** Date:3/4/2019
** Description:Declarations for the class room
** Input:None
** Output:Text-Based
*********************************************************************/


#include "room.hpp"

/*********************************************************************
** Function:Room
** Description:room constructor
** Parameters:
** Pre-Conditions:
** Post-Conditions:room created
*********************************************************************/ 

Room::Room(){
	
	this->room_event = NULL;
	
}

/*********************************************************************
** Function:has_event
** Description:returns the type or -1
** Parameters:
** Pre-Conditions:
** Post-Conditions:int returned
*********************************************************************/ 

int Room::has_event(){
	
	if (this->room_event != NULL){return this->room_event->get_type();}
	else{return -1;}
	
}

/*********************************************************************
** Function:debug_print
** Description:prints the debugging type of a room
** Parameters:
** Pre-Conditions:
** Post-Conditions:char printed
*********************************************************************/ 

void Room::debug_print(){
	
	//cout << "==== This Room Pointer: " << this->room_event << endl;
	
	if (this->room_event == NULL){cout << 0;}
	else {cout << this->room_event->get_debug_type();}
	
}

/*********************************************************************
** Function:set_room_event
** Description:sets the room's event
** Parameters:
** Pre-Conditions:
** Post-Conditions:room event set
*********************************************************************/ 

void Room::set_room_event(Event *to_add){
		
	this->room_event = to_add;
		
}