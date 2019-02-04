/*********************************************************************
** Program Filename:deck.cpp
** Author:Lyell Read
** Date:2/3/2019
** Description:deck class function definitions
** Input:na
** Output:na
*********************************************************************/

#include "deck.hpp"

//==== Constructors and Destructors ====//

/*********************************************************************
** Function:Deck
** Description:constructor
** Parameters:none
** Pre-Conditions:nothing
** Post-Conditions:class created
*********************************************************************/ 

Deck::Deck(){

	//cout << "Deck Constructor Called" << endl;
	
	//Set all the ranks and suits for all the cards
	for (int suit = 0; suit <4; ++suit){
		for (int number = 0; number < 13; ++ number){
			//cout << "Creating Card with s,n: " << suit << "," << number << "." << endl;
			this->deck[suit * 13 + number].set_suit(suit);
			this->deck[suit * 13 + number].set_number(number);
		}
	}
	
	this->deck_size = 52;
	shuffle_deck();
}

/*********************************************************************
** Function:~Deck
** Description:destructor
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:class destroyed
*********************************************************************/ 

Deck::~Deck(){
	
	//cout << "Deck Destructor Called" << endl;
	
}

//==== Getters and Setters and Member Functions ====//

/*********************************************************************
** Function:print_deck
** Description:prints deck for debug
** Parameters:
** Pre-Conditions:
** Post-Conditions:printed deck
*********************************************************************/ 

void Deck::print_deck () {
	
	int suit, number;
	//cout << "== DEBUGGING DECK PRINTOUT START:" << endl;
	
	for (int card = 0; card <52; ++card){
		suit = this->deck[card].get_suit();
		number = this->deck[card].get_number();
		
		//cout << "Deck has element with suit: " << suit << " and number " << number << "." << endl;		
	}
}

/*********************************************************************
** Function:shuffle_deck
** Description:shuffles deck
** Parameters:
** Pre-Conditions:
** Post-Conditions:shuffled deck
*********************************************************************/ 


void Deck::shuffle_deck(){
	
	srand(time(NULL));
	
	Card temp_holder;
	for (int index_current = 0; index_current < 52; ++index_current){
		int index_1 = rand()%52;
		temp_holder = this->deck[index_1];
		this->deck[index_1] = this->deck[index_current];
		this->deck[index_current] = temp_holder;
	}
}

/*********************************************************************
** Function:get_deck_size
** Description:returns size of deck
** Parameters:
** Pre-Conditions:
** Post-Conditions:deck size returned
*********************************************************************/ 


int Deck::get_deck_size () {
	
	return this->deck_size;
	
}

/*********************************************************************
** Function:pop_from_deck
** Description:returns the card popped from the deck
** Parameters:
** Pre-Conditions:
** Post-Conditions:card returned
*********************************************************************/ 


Card Deck::pop_from_deck(){
	
	Card temp_holder;
	--this->deck_size;
	
	return this->deck[deck_size];
}

	