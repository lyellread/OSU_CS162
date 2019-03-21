/*********************************************************************
** Program Filename:player.cpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Implementation file for class: Player
** Input:na
** Output:na
*********************************************************************/


#include "player.hpp"

/*********************************************************************
** Function:Player
** Description:constructor
** Parameters:
** Pre-Conditions:
** Post-Conditions:constructed
*********************************************************************/ 

Player::Player(){
	
	this->skills_stored = 0;
	
}

/*********************************************************************
** Function:get_move
** Description:returns user input on wasdup
** Parameters:
** Pre-Conditions:
** Post-Conditions:reutrned
*********************************************************************/ 

int Player::get_move(){
	
	char direction;
	string raw;
	cin >> raw;
	direction = raw[0];
	
	while (!(direction == 'w' || 
		direction == 'a' || 
		direction == 's' || 
		direction == 'd' || 
		direction == 'u' || 
		direction == 'p')){
			cin >> raw;
			direction = raw[0];
		}
		
	return int(direction);
	
}

/*********************************************************************
** Function:add_skill
** Description:adds a skill
** Parameters:
** Pre-Conditions:
** Post-Conditions:added
*********************************************************************/ 

void Player::add_skill(){
	
	this->skills_stored++;
	
}

/*********************************************************************
** Function:reset_skills
** Description:resets skills
** Parameters:
** Pre-Conditions:
** Post-Conditions:reset
*********************************************************************/ 

void Player::reset_skills(){
	
	this->skills_stored = 0;
	
}

/*********************************************************************
** Function:get_skills
** Description:getter for skills
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 

int Player::get_skills(){
	
	return this->skills_stored;
	
}

/*********************************************************************
** Function:remove_skill
** Description:removes one skill
** Parameters:
** Pre-Conditions:
** Post-Conditions:decremented
*********************************************************************/ 

void Player::remove_skill(){
	
	this->skills_stored--;
	
}

/*********************************************************************
** Function:set_location
** Description:sets location to the location passed
** Parameters:int level, int row, int col
** Pre-Conditions:
** Post-Conditions:set
*********************************************************************/ 

void Player::set_location (int level, int row, int col){
	
	this->level = level;
	this->row = row;
	this->col = col;
	
}

/*********************************************************************
** Function:get_col
** Description:gets this players col
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 

int Player::get_col(){

	return this->col;
	
}

/*********************************************************************
** Function:get_row
** Description:gets this player's row
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 


int Player::get_row(){

	return this->row;
	
}

/*********************************************************************
** Function:get_level
** Description:returns this player's level
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 

int Player::get_level(){
	
	return this->level;
	
}
