
/*********************************************************************
** Program Filename:pit.hpp
** Author:Lyell Read
** Date:3/4/2019
** Description:header file for the class pit
** Input:None
** Output:Text-Based
*********************************************************************/

#ifndef __PIT_HPP
#define __PIT_HPP

#include "event.hpp"
#include "player.hpp"

class Pit : public Event {
	
	private:
	
		int type;
		
	public:
	
		Pit();
		int get_type();
		void percept();
		void encounter(Player * player);
		char get_debug_type();
};

#endif