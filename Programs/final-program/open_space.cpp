/*********************************************************************
** Program Filename:open_space.cpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Implementation file for class: OpenSpace
** Input:na
** Output:na
*********************************************************************/



#include "open_space.hpp"
// #include "maze_location.hpp"

/*********************************************************************
** Function:OpenSpace
** Description:constructor
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:constucted ;)
*********************************************************************/ 


OpenSpace::OpenSpace() : MazeLocation (' ', 1) {
	
	//this->room_occupant = NULL;

}

/*********************************************************************
** Function:get_display_character
** Description:returns the appropriate display character for the cell.
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 


char OpenSpace::get_display_character(){
	if (this->space_has_explorer){return '*';}
	if (this->space_is_ladder) {return 'L';}
	if (this->space_is_start){return 'S';}
	if (this->space_has_instructor){return 'I';}
	if (this->space_has_skill){return '$';}
	if (this->space_has_ta){return 'T';}
	if (this->space_is_end){return 'E';}
	return this->display_character;
	
}

/*********************************************************************
** Function:get_is_occupiable
** Description:getter
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 

bool OpenSpace::get_is_occupiable(){return this->is_occupiable_bool;}

/*********************************************************************
** Function:set_has_explorer
** Description:setter
** Parameters:bool set
** Pre-Conditions:
** Post-Conditions:set
*********************************************************************/ 

void OpenSpace::set_has_explorer(bool set){this->space_has_explorer = set;}
/*********************************************************************
** Function:set_is_start
** Description:setter
** Parameters:bool set
** Pre-Conditions:
** Post-Conditions:set
*********************************************************************/ 

void OpenSpace::set_is_start(bool set){this->space_is_start = set;}
/*********************************************************************
** Function:set_is_end
** Description:setter
** Parameters:bool set
** Pre-Conditions:
** Post-Conditions:set
*********************************************************************/ 

void OpenSpace::set_is_end(bool set){this->space_is_end = set;}

/*********************************************************************
** Function: has_explorer
** Description:getter
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 

bool OpenSpace::has_explorer(){return this->space_has_explorer;}

/*********************************************************************
** Function:set_is_ladder
** Description:setter
** Parameters:bool set
** Pre-Conditions:
** Post-Conditions:set
*********************************************************************/ 

void OpenSpace::set_is_ladder(bool set){this->space_is_ladder = set;}

/*********************************************************************
** Function:is_ladder
** Description:getter
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 

bool OpenSpace::is_ladder(){return this->space_is_ladder;}

/*********************************************************************
** Function:is_start
** Description:getter
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 

bool OpenSpace::is_start(){return this->space_is_start;}

/*********************************************************************
** Function:is_end
** Description:getter
**Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 

bool OpenSpace::is_end(){return this->space_is_end;}
/*********************************************************************
** Function:set_has_instructor
** Description:setter
** Parameters:bool set
** Pre-Conditions:
** Post-Conditions:set
*********************************************************************/ 

void OpenSpace::set_has_instructor(bool set){this->space_has_instructor = set;}

/*********************************************************************
** Function:has_instructor
** Description:getter
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 
	
bool OpenSpace::has_instructor(){return this->space_has_instructor;}
/*********************************************************************
** Function:set_has_ta
** Description:setter
** Parameters:bool set
** Pre-Conditions:
** Post-Conditions:set
*********************************************************************/ 

void OpenSpace::set_has_ta(bool set){this->space_has_ta = set;}

/*********************************************************************
** Function:has_ta
** Description:getter
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 

bool OpenSpace::has_ta(){return this->space_has_ta;}
/*********************************************************************
** Function:set_has_skill
** Description:setter
** Parameters:bool set
** Pre-Conditions:
** Post-Conditions:set
*********************************************************************/ 

void OpenSpace::set_has_skill(bool set){this->space_has_skill = set;}

/*********************************************************************
** Function:has_skill
** Description:getter
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 

bool OpenSpace::has_skill(){return this->space_has_skill;}