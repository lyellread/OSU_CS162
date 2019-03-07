
/*********************************************************************
** Program Filename:bat.hpp
** Author:Lyell Read
** Date:3/4/2019
** Description:header file for the class bat
** Input:None
** Output:Text-Based
*********************************************************************/

#ifndef __BAT_HPP
#define __BAT_HPP

#include "event.hpp"
#include "player.hpp"

class Bat : public Event {
	
	private:
	
		int type;
		
	public:
	
		Bat();
		int get_type();
		void percept();
		void encounter(Player * player);
		char get_debug_type();
};

#endif