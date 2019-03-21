/*********************************************************************
** Program Filename:open_space.hpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Header file for class: OpenSpace
** Input:na
** Output:na
*********************************************************************/


#ifndef __OPEN_SPACE_HPP
#define __OPEN_SPACE_HPP

#include <iostream>
#include "maze_location.hpp"

using std::cout;
using std::endl;

class OpenSpace : public MazeLocation {
	
	private:
	
	bool space_has_explorer;
	bool space_has_instructor;
	bool space_has_ta;
	bool space_has_skill;
	bool space_is_start;
	bool space_is_end;
	bool space_is_ladder;
	
	
	public:
	
	OpenSpace();
	
	char get_display_character();
	bool get_is_occupiable();
	//void display_space_data();
	
	void set_has_explorer(bool set);
	bool has_explorer();
	
	void set_has_instructor(bool set);
	bool has_instructor();
	
	void set_has_ta(bool set);
	bool has_ta();
	
	void set_has_skill(bool set);
	bool has_skill();
	
	void set_is_start(bool set);
	bool is_start();
	
	void set_is_end(bool set);
	bool is_end();
	
	void set_is_ladder(bool set);
	bool is_ladder();
	
	
	
	
	
};

#endif