/*********************************************************************
** Program Filename:wall.hpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Header file for class: Wall
** Input:na
** Output:na
*********************************************************************/



#ifndef __WALL_HPP
#define __WALL_HPP

#include <iostream>
#include "maze_location.hpp"

using std::cout;
using std::endl;

class Wall : public MazeLocation {
	
	public:
	
	Wall();
	
	//void display_space_data();
	char get_display_character();
	bool get_is_occupiable();

	void set_has_explorer(bool set) {};
	void set_is_start(bool set) {};
	void set_is_end(bool set) {};
	void set_is_ladder(bool set){};
	bool is_ladder(){return 0;};
	bool has_explorer(){return 0;};
	bool is_start(){return 0;};
	bool is_end(){return 0;};
	void set_has_instructor(bool set){};
	bool has_instructor(){return 0;};
	void set_has_ta(bool set){};
	bool has_ta(){return 0;};
	void set_has_skill(bool set){};
	bool has_skill(){return 0;};
};

#endif