
/*********************************************************************
** Program Filenamewumpus.hpp
** Author:Lyell Read
** Date:3/4/2019
** Description:header file for the class wumpus
** Input:None
** Output:Text-Based
*********************************************************************/

#ifndef __WUMPUS_HPP
#define __WUMPUS_HPP

#include "event.hpp"
#include "player.hpp"

class Wumpus : public Event {
	
	private:
	
		int type;
		
	public:
	
		Wumpus();
		int get_type();
		void percept();
		void encounter(Player * player);
		char get_debug_type();
};

#endif