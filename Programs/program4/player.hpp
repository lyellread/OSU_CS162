
/*********************************************************************
** Program Filename:player.hpp
** Author:Lyell Read
** Date:3/4/2019
** Description:header file for the class player
** Input:None
** Output:Text-Based
*********************************************************************/

#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include <iostream>

using std::cout;
using std::endl;

class Player{
		
	public:
	
		int start_row;
		int start_col;
		int size;
		int row;
		int col;
		int is_dead;
		int has_gold;
		int arrows;
	
		Player(int start_row, int start_col, int size);
		
		void move(int direction);
		int at_start();
		
};	
		
#endif