/*********************************************************************
** Program Filename:instructor.cpp
** Author:Lyell Read
** Date:3/20/2019
** Description:Implementation file for class: Instructor
** Input:na
** Output:na
*********************************************************************/


#include "instructor.hpp"

/*********************************************************************
** Function:Instructor
** Description:blank constructor
** Parameters:
** Pre-Conditions:
** Post-Conditions:created
*********************************************************************/ 

Instructor::Instructor(){}

/*********************************************************************
** Function:get_move
** Description:gets the instructor move
** Parameters:
** Pre-Conditions:
** Post-Conditions:none
*********************************************************************/ 

int Instructor::get_move(){
	
	return 0;
	
}

/*********************************************************************
** Function:set_satisfied
** Description:sets satisfication level
** Parameters:int set
** Pre-Conditions:
** Post-Conditions:set
*********************************************************************/ 

void Instructor::set_satisfied(int set){
	
	if (!(this->satisfied)){
		cout << "Instructor has been satisfied." << endl;
		this->satisfied = set;
	}
	
}

bool Instructor::get_satisfied(){
	
	return this->satisfied;
	
}
