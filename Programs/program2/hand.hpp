/*********************************************************************
** Program Filename:hand.hpp
** Author:Lyell Read
** Date:2/3/2019
** Description:prototypes for the hand class
** Input:na
** Output:na
*********************************************************************/


#ifndef HAND
#define HAND

#include <iostream>

#include "card.hpp"

using std::cout;
using std::endl;

class Hand {
	
	private:
		
		Card * hand;
		int current_hand_size;
		
		
		
	public:
	
		Hand();
		~Hand();
		
		void add_card_to_hand (Card card_to_add);
		Card pop_n_from_hand (int card_number);
		void print_hand ();
		int check_for_racks ();
		int get_number_at_element (int element);
		int get_hand_size ();
		int remove_all_n (int card_number);
		
};


#endif