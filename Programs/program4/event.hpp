
/*********************************************************************
** Program Filename:event.hpp
** Author:Lyell Read
** Date:3/4/2019
** Description:header file for the class event
** Input:None
** Output:Text-Based
*********************************************************************/

#ifndef __EVENT_HPP
#define __EVENT_HPP

#include "player.hpp"


class Event {
	
	private:
	
		int type;
		
	public:
	
		Event(int param);
		virtual void percept() = 0;
		virtual void encounter(Player * player) = 0;
		virtual int get_type() = 0;
		virtual char get_debug_type() = 0;
		
};

#endif