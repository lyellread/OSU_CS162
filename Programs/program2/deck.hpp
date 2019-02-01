// == DECK.HPP - DECK CLASS HEADER FILE == //

#ifndef DECK
#define DECK

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