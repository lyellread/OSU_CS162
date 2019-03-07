//game.hpp

#ifndef __GAME_HPP
#define __GAME_HPP

#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <cstdlib>

#include "bat.hpp"
#include "event.hpp"
#include "gold.hpp"
#include "pit.hpp"
#include "room.hpp"

/*********************************************************************
** Program Filename:game.hpp
** Author:Lyell Read
** Date:3/4/2019
** Description:header file for the class game
** Input:None
** Output:Text-Based
*********************************************************************/

#include "player.hpp"
#include "wumpus.hpp"

using std::stoi;
using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::srand;
using std::rand;
using std::cin;

class Game {
	
	private:
	
		Player * player;
		
		int size;
		int wumpus_is_dead;
		
		Gold * gold_event;
		Pit * pit_event;
		Bat * bat_event;
		Wumpus * wumpus_event;
	
		vector <vector <Room> > map;
	
	public:
	
		Game (int row, int col, int size);
		~Game();
		void fill_map();
		void print_map();
		void assign_events(int event);
		void play_game();
		void turn_menu();
		void percepts_and_events();
		void kill_wumpus();
		void wake_wumpus();
		int string_is_int(string input);
		int input_on_range(int low, int high);
		int get_event_at_offset(int row_offset, int col_offset);
		void get_percept_at_offset(int row_offset, int col_offset);
		void shoot(int direction);
		void clear_screen();
				
};

#endif