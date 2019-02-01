// == CARD.HPP - CARD CLASS HEADER FILE == //

#ifndef CARD
#define CARD

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

class Card {
	
	private:
		
		int number;
		int suit;
	
	public:
	
		Card();
		Card(int number, int suit);
		~Card();

		void set_number(int number);
		void set_suit(int suit);
		
		int get_number();
		int get_suit();
		
};


#endif