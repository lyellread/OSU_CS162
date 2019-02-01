// == DECK.CPP - FUNCTION DEFENITIONS FOR DECK CLASS == //

#include "deck.hpp"


//==== Constructors and Destructors ====//

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

Deck::~Deck(){
	
	//cout << "Deck Destructor Called" << endl;
	
}

//==== Getters and Setters and Member Functions ====//

void Deck::print_deck () {
	
	int suit, number;
	//cout << "== DEBUGGING DECK PRINTOUT START:" << endl;
	
	for (int card = 0; card <52; ++card){
		suit = this->deck[card].get_suit();
		number = this->deck[card].get_number();
		
		//cout << "Deck has element with suit: " << suit << " and number " << number << "." << endl;		
	}
}

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

int Deck::get_deck_size () {
	
	return this->deck_size;
	
}

Card Deck::pop_from_deck(){
	
	Card temp_holder;
	--this->deck_size;
	
	return this->deck[deck_size];
}

	