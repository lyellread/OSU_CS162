// == CARD.CPP - FUNCTION DEFENITIONS FOR CARD CLASS == //

#include "card.hpp"

//==== Constructors and Destructors ====//

Card::Card() {
	
	//cout << "Card Constructor Called" << endl;
	this->number = 0;
	this->suit = 0;
	
}

Card::Card(int number, int suit){

	//cout << "Card Constructor Called" << endl;
	
	this->number = -1;
	this->suit = -1;
}

Card::~Card() {
	//cout << "Card Destructor Called" << endl;

	//cout << "Deleting Card..." << endl;
	
}

//==== Getters and Setters ====//

void Card::set_number(int number){
	
	this->number = number;
	
}

void Card::set_suit(int suit){
	
	this->suit = suit;
	
}

int Card::get_number(){
	
	return this->number;
	
}

int Card::get_suit(){
	
	return this->suit;
	
}