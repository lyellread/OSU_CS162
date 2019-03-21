/*********************************************************************
** Program Filename:maze_location.cpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Implementation file for class: MazeLocation
** Input:na
** Output:na
*********************************************************************/


#include "maze_location.hpp"

/*********************************************************************
** Function:MazeLocation
** Description:constructor
** Parameters:char display_character, bool is_occupiable_param
** Pre-Conditions:na
** Post-Conditions:values assigned, object constructed.
*********************************************************************/ 


MazeLocation::MazeLocation(char display_character, bool is_occupiable_param){
	
	this->display_character = display_character;
	this->is_occupiable_bool = is_occupiable_param;
	
}