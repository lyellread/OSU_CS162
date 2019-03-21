/*********************************************************************
** Program Filename:wall.cpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Implementation file for class: Wall
** Input:na
** Output:na
*********************************************************************/

#include "wall.hpp"
// #include "maze_location.hpp"

/*********************************************************************
** Function:Wall
** Description:constructor, inheritor
** Parameters:
** Pre-Conditions:
** Post-Conditions:wall is inherited.
*********************************************************************/ 

Wall::Wall() : MazeLocation ('#', 0) {}

/*********************************************************************
** Function:get_display_character
** Description:returns display character
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 

char Wall::get_display_character(){
	
	return this->display_character;
	
}

/*********************************************************************
** Function:get_is_occupiable
** Description:returns if this is occupiable
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 

bool Wall::get_is_occupiable(){
	
	return this->is_occupiable_bool;
	
}