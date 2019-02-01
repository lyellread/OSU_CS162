// == PLAYER.HPP - PLAYER CLASS HEADER FILE == //

#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>

#include "hand.hpp"

using namespace std;

class Player {
	
	private:
		
		Hand hand;
		int * racks;
		int current_racks;
	
	public:
	
		Player();
		~Player();
		
		void add_rack (int card_number);
		void print_hand();
		int get_hand_size();
		void add_card_to_hand (Card card_to_add);
		Card pop_n_from_hand (int card_number);
		int check_for_racks();
		void rack_manager();
		void print_racks();
		int get_rack_number();
		int n_in_hand(int card_number);
		void go_fish (Card card_drawn);

};


#endif