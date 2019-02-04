/*********************************************************************
** Program Filename:card.cpp
** Author:Lyell Read
** Date:2/3/2019
** Description:card class function definitions
** Input:na
** Output:na
*********************************************************************/

#include "card.hpp"

//==== Constructors and Destructors ====//

/*********************************************************************
** Function:Card
** Description:constructor
** Parameters:none
** Pre-Conditions:nothing
** Post-Conditions:class created
*********************************************************************/ 

Card::Card() {
	
	//cout << "Card Constructor Called" << endl;
	this->number = 0;
	this->suit = 0;
	
}

/*********************************************************************
** Function:Card
** Description:constructor
** Parameters:number, suit
** Pre-Conditions:nothing
** Post-Conditions:class created
*********************************************************************/ 

Card::Card(int number, int suit){

	//cout << "Card Constructor Called" << endl;
	
	this->number = -1;
	this->suit = -1;
}

/*********************************************************************
** Function:~Card
** Description:destructor
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:class destroyed
*********************************************************************/ 

Card::~Card() {
	//cout << "Card Destructor Called" << endl;

	//cout << "Deleting Card..." << endl;
	
}

//==== Getters and Setters ====//

/*********************************************************************
** Function:set_number
** Description:sets number
** Parameters:number
** Pre-Conditions:na
** Post-Conditions:number set
*********************************************************************/ 

void Card::set_number(int number){
	
	this->number = number;
	
}

/*********************************************************************
** Function:set_suit
** Description:sets suuit
** Parameters:suit
** Pre-Conditions:na
** Post-Conditions:suit set
*********************************************************************/ 

void Card::set_suit(int suit){
	
	this->suit = suit;
	
}

/*********************************************************************
** Function:get_number
** Description:gets number
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:number got
*********************************************************************/ 

int Card::get_number(){
	
	return this->number;
	
}

/*********************************************************************
** Function:get_suit
** Description:gets suit
** Parameters:
** Pre-Conditions:na
** Post-Conditions:suit got
*********************************************************************/ 

int Card::get_suit(){
	
	return this->suit;
	
}