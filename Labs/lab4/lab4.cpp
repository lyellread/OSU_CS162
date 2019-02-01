// LAB4.CPP - Control File //

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
#include "deck.hpp"
#include "hand.hpp"

int main() {

	Deck lab4_deck;
	lab4_deck.shuffle_deck();
	Hand lab4_hand;
	
	Card temp_card;
	for (int i=0; i<7; ++i){
		
		temp_card = lab4_deck.pop_from_deck();
		lab4_hand.add_card_to_hand(temp_card);
		
	}
	
	lab4_hand.print_hand();
}