/*********************************************************************
** Program Filename:maze_location.hpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Header file for class: MazeLocation
** Input:na
** Output:na
*********************************************************************/

#ifndef __MAZE_LOCATION_HPP
#define __MAZE_LOCATION_HPP

#include "maze_person.hpp"

class MazeLocation {
	
	public:
	
	char display_character;
	bool is_occupiable_bool;
	
	//MazePerson * room_occupant;
	
	MazeLocation(char display_character, bool is_occubiable);
	
	virtual char get_display_character () = 0;
	virtual bool get_is_occupiable() = 0;
	//virtual void display_space_data() = 0;
	
	virtual void set_has_explorer(bool set) = 0;
	virtual bool has_explorer() = 0;	
	
	virtual void set_has_instructor(bool set) = 0;
	virtual bool has_instructor() = 0;	
	
	virtual void set_has_ta(bool set) = 0;
	virtual bool has_ta() = 0;

	virtual void set_is_start(bool set) = 0;
	virtual bool is_start() = 0;

	virtual void set_is_end(bool set) = 0;
	virtual bool is_end() = 0;

	virtual void set_is_ladder(bool set) = 0;
	virtual bool is_ladder() = 0;
	
	virtual void set_has_skill(bool set) = 0;
	virtual bool has_skill() = 0;
	
	
	
	
};
	
#endif