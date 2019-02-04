/*********************************************************************
** Program Filename:hand.cpp
** Author:Lyell Read
** Date:2/3/2019
** Description:hand class function definitions
** Input:na
** Output:na
*********************************************************************/


#include "hand.hpp"

//==== Constructors and Destructors ====//

/*********************************************************************
** Function:Hand
** Description:constructor
** Parameters:none
** Pre-Conditions:nothing
** Post-Conditions:class created
*********************************************************************/ 

Hand::Hand(){

	//cout << "Hand Constructor Called" << endl;
	
	this->hand = new Card[52]; //inefficient but works.
	this->current_hand_size = 0;
}

/*********************************************************************
** Function:~Hand
** Description:destructor
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:class destroyed
*********************************************************************/ 

Hand::~Hand(){
	//cout << "Hand Destructor Called" << endl;

	delete[] this->hand;
	
}

//==== Getters and Setters and Member Functions====//

/*********************************************************************
** Function:add_card_to_hand
** Description:add a card to the hand
** Parameters:card_to_add
** Pre-Conditions:
** Post-Conditions:card added
*********************************************************************/ 


void Hand::add_card_to_hand(Card card_to_add){
	
	this->hand[this->current_hand_size] = card_to_add;
	++this->current_hand_size;
	
}

/*********************************************************************
** Function:print_hand
** Description:prints hand for user
** Parameters:
** Pre-Conditions:
** Post-Conditions:hand printed
*********************************************************************/ 


void Hand::print_hand(){
	
	int suit, number;
	
	cout << "\nHand Contents:\n";

	for (int i=0; i<this->current_hand_size; ++i){
		
		suit = this->hand[i].get_suit();
		number = this->hand[i].get_number();
		cout << " + Suit: " << suit << ", Number: " << number << endl;
	}
	
	cout << "\n";
}

/*********************************************************************
** Function:check_for_racks
** Description:checks for racks
** Parameters:
** Pre-Conditions:
** Post-Conditions:returns the number of the rack or -1
*********************************************************************/ 


int Hand::check_for_racks(){
	
	int counter;
	
	for (int number=0; number < 13; ++number){
		counter = 0;
		for (int card=0; card<this->current_hand_size; ++card){
			if (this->hand[card].get_number() == number){
				++counter;
			}
		}
		if (counter == 4){
			return number;
		}
	}
	
	return -1; 
}

/*********************************************************************
** Function:pop_n_from_hand
** Description:pops a card from hand
** Parameters:number
** Pre-Conditions:
** Post-Conditions:card of number is popped from hand
*********************************************************************/ 


Card Hand::pop_n_from_hand (int number){
	
	Card temp_card;
	Card dne_return(-1, -1);
	
	for (int card=0; card<this->current_hand_size; ++card){
		if (this->hand[card].get_number() == number){
	
			//swap the current card to the end of the hand;
			temp_card = this->hand[card];
			this->hand[card] = this->hand[this->current_hand_size-1];
			this->hand[current_hand_size-1] = temp_card;
			
			
			//zero that last digit.
			this->hand[current_hand_size-1].set_number(6969);
			this->hand[current_hand_size-1].set_suit(6969);
			
			--this->current_hand_size;
			
			return temp_card;
		}
	}
	return dne_return;
}

/*********************************************************************
** Function:get_number_at_element
** Description:gets number at element element
** Parameters:element
** Pre-Conditions:
** Post-Conditions:returns the number at element
*********************************************************************/ 


int Hand::get_number_at_element(int element){
	
	return this->hand[element].get_number();

}

/*********************************************************************
** Function:remove_all_n
** Description:removes all of a number n
** Parameters:number
** Pre-Conditions:
** Post-Conditions:all cards removed
*********************************************************************/ 


int Hand::remove_all_n(int card_number){
	
	int cards_removed;
	Card temp;
	
	do {
		
		temp = pop_n_from_hand (card_number);
		
		if (temp.get_number() != -1){//we got a card were trying to remove...
			
			cards_removed++;
			
		}
	}while(temp.get_number() != -1);
	
	return cards_removed;
	
}

/*********************************************************************
** Function:get_hand size
** Description:returns hand size
** Parameters:
** Pre-Conditions:
** Post-Conditions:hand size returned
*********************************************************************/ 


int Hand::get_hand_size(){
	
	return (current_hand_size);
	
}
	
		
		
		
		
		
		
		
		
		
		
		
