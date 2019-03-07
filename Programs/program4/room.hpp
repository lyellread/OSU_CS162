
/*********************************************************************
** Program Filename:room.hpp
** Author:Lyell Read
** Date:3/4/2019
** Description:header file for the class room
** Input:None
** Output:Text-Based
*********************************************************************/

#ifndef __ROOM_HPP
#define __ROOM_HPP

#include "event.hpp"
#include <iostream>

using std::endl;
using std::cout;


class Room {
	
	public:
	
		Event *room_event;	
	
		Room();
		int has_event();
		void debug_print();
		void set_room_event(Event *to_add);
		
};
		
#endif