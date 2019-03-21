/*********************************************************************
** Program Filename:player.hpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Header file for class: Player
** Input:na
** Output:na
*********************************************************************/


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "maze_person.hpp"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

class Player : public MazePerson {
	
	private:
	
	int skills_stored;
	int row;
	int col;
	int level;
	
	
	public:
	
	Player();
	int get_move();
	void add_skill();
	void reset_skills();
	int get_skills();
	void remove_skill();
	void set_location (int level, int row, int col);
	int get_col();
	int get_row();
	int get_level();
	
	// void set_location (int row, int col);
	// int get_row();
	// int get_col();
	
};

#endif

