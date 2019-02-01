// == HAND.CPP - FUNCTION DEFENITIONS FOR HAND CLASS == //

#include "hand.hpp"

//==== Constructors and Destructors ====//

Hand::Hand(){

	//cout << "Hand Constructor Called" << endl;
	
	this->hand = new Card[52]; //inefficient but works.
	this->current_hand_size = 0;
}

Hand::~Hand(){
	//cout << "Hand Destructor Called" << endl;

	delete[] this->hand;
	
}

//==== Getters and Setters and Member Functions====//

void Hand::add_card_to_hand(Card card_to_add){
	
	this->hand[this->current_hand_size] = card_to_add;
	++this->current_hand_size;
	
}

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

int Hand::get_number_at_element(int element){
	
	return this->hand[element].get_number();

}

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

int Hand::get_hand_size(){
	
	return (current_hand_size);
	
}
	
		
		
		
		
		
		
		
		
		
		
		
