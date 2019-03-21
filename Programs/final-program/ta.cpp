/*********************************************************************
** Program Filename:ta.cpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Implementation file for class: TA
** Input:na
** Output:na
*********************************************************************/


#include "ta.hpp"

/*********************************************************************
** Function:TA
** Description:blank constructor
** Parameters:
** Pre-Conditions:
** Post-Conditions:constructed
*********************************************************************/ 

TA::TA(){}

/*********************************************************************
** Function:get_move
** Description:gets the ta's move
** Parameters:
** Pre-Conditions:
** Post-Conditions:returns ta's move
*********************************************************************/ 

int TA::get_move(){
	
	int direction = rand()%4;
	
	//0..3
	switch (direction) {
		
		case 0:
			
			return int('w');
			break;
			
		case 1:
		
			return int('a');
			break;
			
		case 2: 
		
			return int('s');
			break;
			
		case 3:
		
			return int('d');
			break;
			
	}
		
	cout << "ERROR ON GET MOVE" << endl;
	
}

/*********************************************************************
** Function:get_is_appeased
** Description:returns bool if ta is appeased
** Parameters:
** Pre-Conditions:
** Post-Conditions:returned
*********************************************************************/ 

bool TA::get_is_appeased(){ 

	if (this->appeased_turns_left >0){
		
		return 1;
		
	}
	
	else{
		
		return 0;
		
	}
	
}

/*********************************************************************
** Function:appease
** Description:appeases the TA
** Parameters:
** Pre-Conditions:
** Post-Conditions:appeased
*********************************************************************/ 

void TA::appease(){
	
	this->appeased_turns_left = 10;
	
}

/*********************************************************************
** Function:appease
** Description:overloaded appease to blank out appeasal level
** Parameters:int turns
** Pre-Conditions:
** Post-Conditions:appeasal set to turns
*********************************************************************/ 

void TA::appease(int turns){
	
	this->appeased_turns_left = turns;
	
}

/*********************************************************************
** Function:decrement_appeasal
** Description:decrements the appeasal level of the ta
** Parameters:
** Pre-Conditions:
** Post-Conditions:decremented
*********************************************************************/ 

void TA::decrement_appeasal(){
	if (this->appeased_turns_left > 0){
	this->appeased_turns_left --;
	}
	
}

