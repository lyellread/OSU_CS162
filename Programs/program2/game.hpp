// == GAME.HPP - GAME CLASS HEADER FILE == //

#ifndef GAME
#define GAME

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <climits>
#include <ctime>
#include <cmath>
#include <random>
#include <cstdlib>
#include <bits/stdc++.h>

#include "deck.hpp"
#include "player.hpp"

using namespace std;

class Game {
	
	private:
		
		Deck deck;
		Player players[2];	
	
	public:
	
		Game();
		~Game();
		
		void deal_cards();
		int check_for_win ();
		void clear_screen();
		int prompt_player (int player_number);
		void play_turn (int player_number, int enemy_player_num);
		void play_computer_turn (int player_number, int enemy_player_num);
		int computer_choice(int player_number);
		void manage_gameplay ();
		
};


#endif