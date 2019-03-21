/*********************************************************************
** Program Filename:ta.hpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Header file for class: TA
** Input:na
** Output:na
*********************************************************************/


#ifndef TA_HPP
#define TA_HPP

#include "maze_person.hpp"

#include <iostream>
#include <random>

using std::cout;
using std::endl;

class TA : public MazePerson {
	
	private:
		
		int appeased_turns_left;
	
	public:
	
	TA();
	int get_move();
	
	bool get_is_appeased();
	void appease();
	void appease(int turns);
	void decrement_appeasal();

	
};

#endif