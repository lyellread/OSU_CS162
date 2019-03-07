
/*********************************************************************
** Program Filename:player.cpp
** Author:Lyell Read
** Date:3/4/2019
** Description:Declarations for the class player
** Input:None
** Output:Text-Based
*********************************************************************/


#include "player.hpp"

/*********************************************************************
** Function:Player
** Description:player constructor
** Parameters:int start_row, int start_col, int size
** Pre-Conditions:none
** Post-Conditions:player class is created.
*********************************************************************/ 

Player::Player(int start_row, int start_col, int size){
	
	this->start_row = start_row;
	this->start_col = start_col;
	
	this->row = start_row;
	this->col = start_col;
	
	this->size = size;
	this->arrows = 3;
	this->is_dead = 0;
	this->has_gold = 0;

}

/*********************************************************************
** Function:move
** Description:move the player
** Parameters:int direction
** Pre-Conditions:none
** Post-Conditions:player moved
*********************************************************************/ 


void Player::move (int direction){
	int temp = 0;
	
	if (direction < 2){ //sourth or north//
		temp = this->row + ((direction * 2) - 1); // 0 or 1 --> -1 or 1
		if (!(temp == (this->size) || temp == -1)){
			this->row = temp;
		}
	}
	else{
		temp = this->col + (((direction - 2) * 2) -1);
		if (!(temp == (this->size) || temp == -1)){
			this->col = temp;
		}
	}
}

/*********************************************************************
** Function:at_start
** Description:checks if the player is at the start position
** Parameters:int start_row, int start_col, int size
** Pre-Conditions:
** Post-Conditions:returned if player is at start
*********************************************************************/ 


int Player::at_start(){
	
	if (this->start_row == this->row && this->start_col == this->col){return 1;}
	else {return 0;}
}

