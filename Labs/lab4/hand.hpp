// == HAND.HPP - HAND CLASS HEADER FILE == //

#ifndef HAND
#define HAND

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>

#include "card.hpp"

using namespace std;

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
		int get_hand_size ();
		int remove_all_n (int card_number);
		
};


#endif