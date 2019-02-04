/*********************************************************************
** Program Filename:game.hpp
** Author:Lyell Read
** Date:2/3/2019
** Description:prototypes for the game class
** Input:na
** Output:na
*********************************************************************/


#ifndef GAME
#define GAME

#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

#include "deck.hpp"
#include "player.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getchar;

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
