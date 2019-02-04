/*********************************************************************
** Program Filename:deck.hpp
** Author:Lyell Read
** Date:2/3/2019
** Description:prototypes for the deck class
** Input:na
** Output:na
*********************************************************************/


#ifndef DECK
#define DECK

#include <ctime>
#include <cstdlib>

#include "card.hpp"

//using namespace std;

class Deck {
	
	private:
		
		Card deck[52];
		int deck_size;
	
	public:
	
		Deck();
		~Deck();
		
		int get_deck_size();
		void print_deck ();
		void shuffle_deck ();
		Card pop_from_deck ();
		
		
};


#endif