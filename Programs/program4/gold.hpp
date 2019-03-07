
/*********************************************************************
** Program Filename:gold.hpp
** Author:Lyell Read
** Date:3/4/2019
** Description:header file for the class gold
** Input:None
** Output:Text-Based
*********************************************************************/

#ifndef __GOLD_HPP
#define __GOLD_HPP

#include "event.hpp"
#include "player.hpp"

class Gold : public Event {
	
	private:
	
		int type;
		
	public:
	
		Gold();
		int get_type();
		void percept();
		void encounter(Player * player);
		char get_debug_type();
};

#endif